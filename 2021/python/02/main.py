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
        for directions in self.data:
            direction, amount = directions.split(' ')
            amount = int(amount)

            if direction == 'forward':
                self.horizontal += amount
                if self.aim != 0:
                    additional_depth = (self.aim * amount)
                    self.depth += additional_depth
            elif direction == 'up':
                self.aim -= amount
                if self.aim < 0:
                    self.aim = 0
            else:
                self.aim += amount

        self.counter = self.horizontal * self.depth

    def __reset_counters(self):
        self.aim = 0
        self.depth = 0
        self.horizontal = 0
        self.counter = 0
