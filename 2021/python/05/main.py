class Solution(object):

    def __init__(self, data):
        self.max_covers = [0,0]
        self.__data = data
        self.lines = []
        self.__format_lines()
        self.__reset_counters()

    def pt1(self):
        for line in self.lines:
            cover_x, cover_y = line
            if len(cover_x) == 1:
                x = cover_x[0]
                for ny in cover_y:
                    key = (x,ny)
                    if key not in self.covers:
                        self.covers[key] = 0
                    self.covers[key] += 1
            elif len(cover_y) == 1:
                y = cover_y[0]
                for nx in cover_x:
                    key = (nx,y)
                    if key not in self.covers:
                        self.covers[key] = 0
                    self.covers[key] += 1

        self.counter = self.__get_overlap_count()

    def pt2(self):
        self.__reset_counters()
        print("TBD")

    def __format_lines(self):
        max_x = 0
        max_y = 0
        for line in self.__data:
            input_1, input_2 = line.split(' -> ')
            x1, y1 = [int(n) for n in input_1.split(',')]
            x2, y2 = [int(n) for n in input_2.split(',')]
            if x1 > x2:
                cover_x = range(int(x2), int(x1)+1)
                if x1 > max_x: max_x = x1
            else:
                cover_x = range(int(x1), int(x2)+1)
                if x2 > max_x: max_x = x2
            if y1 > y2:
                cover_y = range(int(y2), int(y1)+1)
                if y1 > max_y: max_y = y1
            else:
                cover_y = range(int(y1), int(y2)+1)
                if y2 > max_y: max_y = y2
            self.lines.append([cover_x, cover_y])
        self.max_covers = [max_x, max_y]

    def __reset_counters(self):
        self.counter = 0
        self.overlaps = []
        self.covers = {}

    def __get_overlap_count(self):
        count = 0

        for (coords, count) in self.covers.items():
            if count > 1:
                count += 1

        return count

    def __print_covers(self):
        visual_covers = ""

        for y in range(0, int(self.max_covers[1])+1):
            visual_row = ""
            for x in range(0, int(self.max_covers[0])+1):
                key = (x, y)
                if key in self.covers:
                    visual_row += str(self.covers[key])
                else:
                    visual_row += '.'

            visual_covers += "{}\n".format(visual_row)

        print(visual_covers)
