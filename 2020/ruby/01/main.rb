require 'pathname'

class ExpenseReporter

  attr_accessor :expenses, :expense1, :expense2, :expense3

  DESIRED_EXPENSE = 2020;

  # @input [Pathname] filename
  def initialize(filename)
    @expenses = filename.read.split("\n")
  end

  def two_expenses
    reset_expenses

    expenses.each_with_index do |exp1, idx|
      @expense1 = exp1.to_i
      expenses.each_with_index do |exp2, idx2|
        @expense2 = exp2.to_i
        break if (expense1 + expense2) == DESIRED_EXPENSE
      end

      break if (expense1 + expense2) == DESIRED_EXPENSE
    end

    expense1 * expense2
  end

  # TODO: Refactor
  def three_expenses
    reset_expenses
    expenses.each_with_index do |exp1, idx|
      @expense1 = exp1.to_i

      expenses.each_with_index do |exp2, idx2|
        next if idx == idx2
        @expense2 = exp2.to_i

        expenses.each_with_index do |exp3, idx3|
          next if idx == idx3
          next if idx2 == idx3
          @expense3 = exp3.to_i

          break if (expense1 + expense2 + expense3) == DESIRED_EXPENSE
        end
        break if (expense1 + expense2 + expense3) == DESIRED_EXPENSE
      end

      break if (expense1 + expense2 + expense3) == DESIRED_EXPENSE
    end

    expense1 * expense2 * expense3
  end

  def solve
    puts "Solution for 2 Expenses:"
    puts two_expenses
    puts "Solution for 3 Expenses:"
    puts three_expenses
  end

  private

  def reset_expenses
    @expense1 = @expense2 = nil
  end

end

@dir = Pathname.new(__FILE__).realpath.dirname

## Run
@file = @dir.join('../../shared/input_day01.txt')
reporter = ExpenseReporter.new(@file)
puts reporter.solve
