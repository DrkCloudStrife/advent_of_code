# frozen_string_literal: true

require 'pathname'

# Generates Ruby template for AoC
class ScaffoldTemplate

  def initialize(day, year = nil)
    @day_str = day.to_s
    @year = year
    @dir = Pathname.new(__FILE__).
      realpath.dirname.join('../','../')
  end

  def generate
    # validate whether the chalenge file already exists
    validate

    # Generate challenge file
    challenge_path.write(challenge_template)
    # Generate spec file
    challenge_spec_path.write(challenge_spec_template)
    challenge_fixture_path.write('')
    # Generate shared file
    challenge_puzzle_path.write('')
  end

  def cleanup
    challenge_path.delete if challenge_path.exist?
    challenge_spec_path.delete if challenge_spec_path.exist?
    challenge_fixture_path.delete if challenge_fixture_path.exist?
    challenge_puzzle_path.delete if challenge_puzzle_path.exist?
  end

  private

  attr_reader :day_str, :dir

  def challenge_template
    <<~EOF
    # frozen_string_literal: true

    require 'pathname'

    class Day#{day}

      attr_reader :filename, :data

      def initialize(filename)
        @filename = Pathname.new(filename)
        @data = @filename.read.split("\\n")
      end

      def part_one
        filename.each_line do |line|
          solve_challenge(line)
        end
      end

      def part_two
        filename.each_line do |line|
          solve_challenge(line, part_two: true)
        end
      end

      private

      def solve_challenge(line, part_two: false)
        return "one" unless part_two
        return "two"
      end
    end
    EOF
  end

  def challenge_spec_template
    <<~EOF
    require_relative '../../../#{year}/ruby/day#{day}.rb'

    RSpec.describe Day#{day} do
      let(:filename) { Pathname.new("./spec/fixtures/#{year}/\#{described_class.name.downcase}_sample.txt") }
      let(:subject) { described_class.new(filename) }

      xcontext 'part one' do
        describe '#part_one' do
          it 'should return one' do
            expect(subject.part_one).to eq('one')
          end
        end
      end

      xcontext 'part two' do
        describe '#part_two' do
          it 'should return two' do
            expect(subject.part_two).to eq('two')
          end
        end
      end
    end
    EOF
  end

  def challenge_path
    dir.join(year, 'ruby', "day#{day}.rb")
  end

  def challenge_spec_path
    dir.join('spec', year, 'ruby', "day#{day}_spec.rb")
  end

  def challenge_puzzle_path
    dir.join(year, 'shared', "day#{day}.txt")
  end

  def challenge_fixture_path
    dir.join('spec', 'fixtures', year, "day#{day}_sample.txt")
  end

  def day
    return day_str if day_str.size > 1

    "0#{day_str}"
  end

  def validate
    if challenge_path.exist?
      if prompt("challenge files already exist, overwrite? [y/N]").strip != "y"
        puts "Not overwriting existing file."
        exit(1)
      else
        puts "Overwriting challenge file"
      end
    end
  end

  def prompt(message)
    puts message
    return gets
  end

  def year
    (@year || Time.now.year).to_s
  end

end
