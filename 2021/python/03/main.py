class Solution(object):

    def __init__(self, data):
        self.data = []
        self.bit_frequencies = []
        [self.data.append(row.strip()) for row in data]
        self.__prepare_data()
        self.__reset_counters()

    def pt1(self):
        gamma = epsilon = ""
        for frequency in self.bit_frequencies:
            gamma += self.__get_max(frequency)
            epsilon += self.__get_min(frequency)
        gamma_rate = int(gamma, 2)
        epsilon_rate = int(epsilon, 2)
        self.counter = gamma_rate * epsilon_rate

    def pt2(self):
        self.__reset_counters()
        oxygen = self.data[:]
        co2 = self.data[:]
        iterations = len(self.data[0])

        for idx in range(iterations):
            frequencies = self.__get_frequencies(oxygen)
            frequency = frequencies[idx]
            comparator_max = self.__get_max(frequency)
            comparator_min = self.__get_min(frequency)

            if len(oxygen) > 1:
                for col_idx, row in enumerate(oxygen):
                    comparator = comparator_max
                    if comparator_max == comparator_min:
                        comparator = '1'
                    if row[idx] != comparator and len(list(filter(None, oxygen))) > 1:
                        oxygen[col_idx] = None

            if len(co2) > 1:
                for col_idx, row in enumerate(co2):
                    comparator = comparator_min
                    if comparator_max == comparator_min:
                        comparator = '0'
                    if row[idx] != comparator and len(filter(None, co2)) > 1:
                        co2[col_idx] = None

            oxygen = list(filter(None, oxygen))
            co2 = list(filter(None, co2))

        oxygen_rating = int(oxygen[0], 2)
        co2_rating = int(co2[0], 2)
        self.counter = oxygen_rating * co2_rating

    def __reset_counters(self):
        self.counter = 0

    def __prepare_data(self):
        self.bit_frequencies = self.__get_frequencies(self.data)

    def __get_frequencies(self, data):
        row_len = len(data[0])
        frequencies = [{ '0':0, '1':0 } for _row in range(row_len)]
        for bits in data:
            for idx, bit in enumerate(bits):
                frequencies[idx][bit] += 1

        return frequencies

    def __get_max(self, frequency):
        return max(frequency, key=frequency.get)

    def __get_min(self, frequency):
        return min(frequency, key=frequency.get)
