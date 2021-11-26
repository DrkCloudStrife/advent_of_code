class TreeCounter(object):
    TREE = '#'
    SNOW = '.'
    MOVE_RIGHT = 3
    MOVE_DOWN = 1

    def __init__(self, data):
        self.terrain = []
        self.trees_encountered = []
        self.current_row_idx = 0
        self.current_col_idx = 0
        self.max_row_idx = None
        self.max_col_idx = None

        for slope in data:
            current_slope = self.__parse_slope(slope)
            if self.max_row_idx is None:
                self.max_row_idx = len(current_slope) - 1
            self.terrain.append(current_slope)

        self.max_col_idx = len(self.terrain) - 1

    def traverse_pt1(self):
        for slope in self.terrain:
            row_idx = self.current_row_idx + self.MOVE_RIGHT
            col_idx = self.current_col_idx + self.MOVE_DOWN
            if row_idx > self.max_row_idx:
                row_idx = -1 + (row_idx - self.max_row_idx)

            if col_idx > self.max_col_idx:
                continue
            if self.terrain[col_idx][row_idx] == self.TREE:
                self.trees_encountered.append([col_idx, row_idx])
            self.current_row_idx = row_idx
            self.current_col_idx = col_idx

    def __parse_slope(self, slope):
        items = list(slope)
        slopes = []

        for item in items:
            item = item.strip()
            if item == '':
                continue
            slopes.append(item)

        return slopes
