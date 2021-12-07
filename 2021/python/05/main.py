class Solution(object):

    def __init__(self, data):
        self.__data = data
        self.lines = []
        self.__format_lines()
        self.__reset_counters()

    def pt1(self):
        # Need to find lines that have horizontal or veritcal lines only
        for line in self.lines:
            cover_x, cover_y = line
            if len(cover_x) == 1 or len(cover_y) == 1:
                print('yay?', line)
        print("TBD")

    def pt2(self):
        self.__reset_counters()
        print("TBD")

    def __format_lines(self):
        for line in self.__data:
            input_1, input_2 = line.split(' -> ')
            x1, y1 = input_1.split(',')
            x2, y2 = input_2.split(',')
            if x1 > x2:
                cover_x = range(int(x2), int(x1)+1)
            else:
                cover_x = range(int(x1), int(x2)+1)
            if y1 > y2:
                cover_y = range(int(y2), int(y1)+1)
            else:
                cover_y = range(int(y1), int(y2)+1)
            self.lines.append([cover_x, cover_y])
        print(self.lines)

    def __reset_counters(self):
        self.counter = 0
        self.overlaps = []
