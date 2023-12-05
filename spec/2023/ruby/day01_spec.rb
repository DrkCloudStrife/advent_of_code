require_relative '../../../2023/ruby/day01.rb'

RSpec.describe Day01 do
  let(:filename) { Pathname.new("./spec/fixtures/2023/#{described_class.name.downcase}_sample.txt") }
  let(:subject) { described_class.new(filename) }

  describe "#part_one" do
    it 'should return one' do
      expect(subject.part_one).to eq(142)
    end
  end

  describe "#part_two" do
    it 'should return two' do
      expect(subject.part_two).to eq('two')
    end
  end

  describe "#find_digits" do
    it 'should return 12 for first row' do
      expect(subject.find_digits(filename.readlines[0])).to eq(12)
    end

    it 'should return 38 for seond row' do
      expect(subject.find_digits(filename.readlines[1])).to eq(38)
    end

    it 'should return 15 for third row' do
      expect(subject.find_digits(filename.readlines[2])).to eq(15)
    end

    it 'should return 77 for last row' do
      expect(subject.find_digits(filename.readlines[3])).to eq(77)
    end
  end

end
