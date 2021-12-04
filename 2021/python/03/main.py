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
        print("TBD")

    def __reset_counters(self):
        self.counter = 0

    def __prepare_data(self):
        row_len = len(self.data[0])
        self.bit_frequencies = [{ '0':0, '1':0 } for _row in range(row_len)]
        for bits in self.data:
            for idx, bit in enumerate(bits):
                self.bit_frequencies[idx][bit] += 1

    def __get_max(self, frequency):
        return max(frequency, key=frequency.get)

    def __get_min(self, frequency):
        return min(frequency, key=frequency.get)
