class TreeCounter(object):
    TREE = '#'
    SNOW = '.'
    MOVE_RIGHT = 3
    MOVE_DOWN = 1

    def __init__(self, data):
        self.terrain = []
        self.__reset_placements()
        self.max_row_idx = None
        self.max_col_idx = None

        for slope in data:
            current_slope = self.__parse_slope(slope)
            if self.max_row_idx is None:
                self.max_row_idx = len(current_slope) - 1
            self.terrain.append(current_slope)

        self.max_col_idx = len(self.terrain) - 1

    def traverse_pt1(self):
        return self.__traverse(self.MOVE_RIGHT, self.MOVE_DOWN)

    def traverse_pt2(self):
        l1 = len(self.__traverse(1, 1))
        l2 = len(self.traverse_pt1())
        l3 = len(self.__traverse(5,1))
        l4 = len(self.__traverse(7,1))
        l5 = len(self.__traverse(1,2))

        return l1 * l2 * l3 * l4 * l5

    def __parse_slope(self, slope):
        items = list(slope)
        slopes = []

        for item in items:
            item = item.strip()
            if item == '':
                continue
            slopes.append(item)

        return slopes

    def __reset_placements(self):
        self.trees_encountered = []
        self.current_row_idx = 0
        self.current_col_idx = 0

    def __traverse(self, right, down):
        self.__reset_placements()
        for slope in self.terrain:
            row_idx = self.current_row_idx + right
            col_idx = self.current_col_idx + down
            if row_idx > self.max_row_idx:
                row_idx = -1 + (row_idx - self.max_row_idx)

            if col_idx > self.max_col_idx:
                continue
            if self.terrain[col_idx][row_idx] == self.TREE:
                self.trees_encountered.append([col_idx, row_idx])
            self.current_row_idx = row_idx
            self.current_col_idx = col_idx

        return self.trees_encountered
