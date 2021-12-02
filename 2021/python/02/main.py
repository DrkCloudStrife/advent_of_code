import re

class Solution(object):

    def __init__(self, data):
        self.data = []
        self.__reset_counters()

        for row in data:
            self.data.append(row.strip())

    def pt1(self):
        for directions in self.data:
            direction, amount = directions.split(' ')
            amount = int(amount)
            if direction == 'forward':
                self.horizontal += amount
            elif direction == 'up':
                self.depth -= amount
            else:
                self.depth += amount
        self.counter = self.horizontal * self.depth

    def pt2(self):
        self.__reset_counters()
        print("TBD")

    def __reset_counters(self):
        self.depth = 0
        self.horizontal = 0
        self.counter = 0
