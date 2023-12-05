class Day01

  attr_reader :filename, :data

  def initialize(filename)
    @filename = filename
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
    return "two"
  end

  # Return first and last digit in a row
  def find_digits(line)
    [
      line.match(/\d/),
      line.reverse.match(/\d/)
    ].join.to_i
  end
end
