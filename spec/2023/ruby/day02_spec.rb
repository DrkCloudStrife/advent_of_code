require_relative '../../../2023/ruby/day02.rb'

RSpec.describe Day02 do
  let(:filename) { Pathname.new("./spec/fixtures/2023/#{described_class.name.downcase}_sample.txt") }
  let(:subject) { described_class.new(filename) }

  context 'part one' do
    describe '#part_one' do
      it 'should return one' do
        expect(subject.part_one).to eq('one')
      end
    end
  end

  context 'part two' do
    describe '#part_two' do
      it 'should return two' do
        expect(subject.part_two).to eq('two')
      end
    end
  end
end
