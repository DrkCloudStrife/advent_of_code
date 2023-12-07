# frozen_string_literal: true

require 'pathname'

class Day01

  attr_reader :filename, :data

  LETTER_NUM = {
    'one' => 1,
    'two' => 2,
    'three' => 3,
    'four' => 4,
    'five' => 5,
    'six' => 6,
    'seven' => 7,
    'eight' => 8,
    'nine' => 9
  }.freeze

  def initialize(filename)
    @filename = Pathname.new(filename)
    @data = @filename.read.split("\n")
  end

  def part_one
    total = 0
    filename.each_line do |line|
      total += find_digits(line)
    end

    return total
  end

  def part_two
    total = 0
    filename.each_line do |line|
      digits = find_digits(line, part_two: true)
      total += digits
    end

    return total
  end

  # Return first and last digit in a row
  def find_digits(line, part_two: false)
    regex = generate_regex(part_two)
    matches = line.scan(regex).flatten

    matches += matches if matches.length == 1

    [
      LETTER_NUM.fetch(matches.first, matches.first),
      LETTER_NUM.fetch(matches.last, matches.last)
    ].join.to_i
  end

  private

  def generate_regex(with_letters)
    regex = '(?=('
    regex += '\d'
    regex += "|#{LETTER_NUM.keys.join('|')}" if with_letters
    regex += '))'
    return /#{regex}/
  end
end
