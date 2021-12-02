class Solution(object):

    def __init__(self, data):
        self.data = []
        self.__reset_counters()

        for row in data:
            self.data.append(row.strip())

    def pt1(self):
        print("TBD")

    def pt2(self):
        self.__reset_counters()
        print("TBD")

    def __reset_counters(self):
        self.counter = 0
