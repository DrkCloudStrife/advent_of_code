# frozen_string_literal: true

require 'pathname'

class Day02

  attr_reader :filename, :data

  def initialize(filename)
    @filename = Pathname.new(filename)
    @data = @filename.read.split("\n")
  end

  def part_one
    challenge = data.inject({}) do |acc, game|
      game_name, rounds = game.split(':')
      puts game_name
      acc[game_name] ||= {}
      round_num = 0
      rounds.split(';').each do |colors|
        round_num += 1
        acc[game_name][round_num.to_s] ||= {}

        colors.split(',').each do |color|
          num, col = color.chomp.split(' ')
          acc[game_name][round_num.to_s][col] ||= 0
          acc[game_name][round_num.to_s][col] += num.to_i
          puts acc
          acc
        end
      end

      return acc
    end
    puts challenge.inspect
  end

  def part_two
    return "two"
  end
end
