class Solution(object):

    def __init__(self, data):
        self.drawings = None
        self.data = []
        self.__reset_counters()

        board = 0
        for i, row in enumerate(data):
            if i == 0:
                self.drawings = row.strip().split()
            elif row.strip() == '' and len(self.data) != 0:
                board += 1
                continue
            elif row.strip() != '':
                try:
                    self.data[board].append(row.split())
                except IndexError:
                    self.data.append([row.split()])

        print(self.data)

    def pt1(self):
        print("TBD")

    def pt2(self):
        self.__reset_counters()
        print("TBD")

    def __reset_counters(self):
        self.counter = 0
