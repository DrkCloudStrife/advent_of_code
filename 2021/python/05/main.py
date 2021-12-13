class Solution(object):

    def __init__(self, data):
        self.__data = data
        self.lines = []
        self.__format_lines()
        self.__reset_counters()

    def pt1(self):
        covers = {}
        counter = 0
        for line in self.lines:
            cover_x, cover_y = line
            if len(cover_x) == 1:
                counter += 1
                x = cover_x[0]
                for ny in cover_y:
                    key = (x,ny)
                    if key not in covers:
                        covers[key] = 0
                    covers[key] += 1
            elif len(cover_y) == 1:
                counter += 1
                y = cover_y[0]
                for nx in cover_x:
                    key = (nx,y)
                    if key not in covers:
                        covers[key] = 0
                    covers[key] += 1

        self.counter = self.__get_overlap_count(covers)

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

    def __reset_counters(self):
        self.counter = 0
        self.overlaps = []

    def __get_overlap_count(self, covers):
        counter = 0

        for (coords, count) in covers.items():
            if count > 1:
                counter += 1

        return counter

