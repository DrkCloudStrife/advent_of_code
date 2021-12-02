class DepthMeasurement(object):

    def __init__(self, data):
        self.sonar_depths = []
        self.__reset_depth_counter()

        for row in data:
            self.sonar_depths.append(int(row.strip()))

    def pt1(self):
        self.__count_depths(self.sonar_depths)

    def pt2(self):
        self.__reset_depth_counter()
        tree_records = []
        for idx, depth in enumerate(self.sonar_depths):
            current_tree = self.sonar_depths[idx:idx+3]
            if len(current_tree) == 3:
                tree_records.append(reduce(lambda t1, t2: t1 + t2, current_tree))
            else:
                continue

        self.__count_depths(tree_records)

    def __reset_depth_counter(self):
        self.depth_counter = 0

    def __count_depths(self, data):
        prev_depth = None
        current_depth = None
        for depth in data:
            prev_depth = current_depth
            current_depth = depth
            if prev_depth is None:
                continue
            if prev_depth < current_depth:
                self.depth_counter += 1
