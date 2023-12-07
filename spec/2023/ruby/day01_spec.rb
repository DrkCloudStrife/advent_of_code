require_relative '../../../2023/ruby/day01.rb'

RSpec.describe Day01 do
  let(:subject) { described_class.new(filename) }

  context 'part one' do
    let(:filename) { Pathname.new("./spec/fixtures/2023/#{described_class.name.downcase}_sample.txt") }

    describe "#part_one" do
      it 'should return 142' do
        expect(subject.part_one).to eq(142)
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


  context 'part two' do
    let(:filename) { Pathname.new("./spec/fixtures/2023/#{described_class.name.downcase}_part2_sample.txt") }

    describe "#part_two" do
      it 'should return 281' do
        expect(subject.part_two).to eq(281)
      end
    end

    describe "#find_digits" do
      it 'should return 29 for first row' do
        expect(subject.find_digits(filename.readlines[0], part_two: true)).to eq(29)
      end

      it 'should return 83 for row 2' do
        expect(subject.find_digits(filename.readlines[1], part_two: true)).to eq(83)
      end

      it 'should return 13 for row 3' do
        expect(subject.find_digits(filename.readlines[2], part_two: true)).to eq(13)
      end

      it 'should return 24 for row 4' do
        expect(subject.find_digits(filename.readlines[3], part_two: true)).to eq(24)
      end

      it 'should return 42 for row 5' do
        expect(subject.find_digits(filename.readlines[4], part_two: true)).to eq(42)
      end

      it 'should return 14 for row 6' do
        expect(subject.find_digits(filename.readlines[5], part_two: true)).to eq(14)
      end

      it 'should return 76 for row 7' do
        expect(subject.find_digits(filename.readlines[6], part_two: true)).to eq(76)
      end
    end
  end

end
