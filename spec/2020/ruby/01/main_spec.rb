require_relative '../../../../2020/ruby/01/main.rb'

RSpec.describe ExpenseReporter do
  let(:filename) { Pathname.new("./spec/fixtures/2020_ruby_01_sample.txt") }
  let(:report) { described_class.new(filename) }

  describe "#two_expenses" do
    it "should find two expenses matching #{described_class::DESIRED_EXPENSE}" do
      expect(report.two_expenses).to eq(514579)
    end
  end
end
