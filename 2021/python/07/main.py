from collections import Counter

class Solution(object):

    def __init__(self, data):
        self.data = []
        self.__reset_counters()

        for row in data:
            [self.data.append(int(n)) for n in row.split(',')]

    def pt1(self, most_common = None):
        if most_common is None:
            counter = Counter(self.data)
            movements = {}
            for common in counter.most_common():
                movements[common[0]] = self.__solve_for(common[0])
            self.counter = min(movements.values())
        else:
            self.counter = self.__solve_for(most_common)

    def pt2(self):
        self.__reset_counters()
        print("TBD")

    def __reset_counters(self):
        self.counter = 0

    def __solve_for(self, position):
        movements = 0

        for h_pos in self.data:
            if h_pos > position:
                # subtract to position
                movements += (h_pos - position)
            elif h_pos < position:
                # add to position
                movements += (position - h_pos)

        return movements
