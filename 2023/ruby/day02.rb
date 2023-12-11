# frozen_string_literal: true

require 'pathname'

class Day02

  def initialize(filename)
    @filename = Pathname.new(filename)
    @data = @filename.read.split("\n")
  end

  def part_one
    return "one"
  end

  def part_two
    return "two"
  end
end
