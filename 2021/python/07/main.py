import math
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

    def pt2(self, position= None):
        self.__reset_counters()
        if position is None:
            counter = Counter(self.data)
            movements = {}
            sorted_positions = sorted(counter.elements())
            for pos in range(sorted_positions[0], sorted_positions.pop()+1):
                movements[pos] = self.__solve_for(pos, True)

            self.counter = min(movements.values())
        else:
            self.counter = self.__solve_for(position, True)


    def __reset_counters(self):
        self.counter = 0

    def __solve_for(self, position, part_2 = False):
        movements = 0

        for h_pos in self.data:
            movement = 0
            if h_pos > position:
                movement = (h_pos - position)
            elif h_pos < position:
                movement = (position - h_pos)

            if part_2 is True:
                offset = math.floor(movement * (movement + 1) / 2)
                movements += offset
            else:
                movements += movement


        return movements
