class DepthMeasurement(object):

    def __init__(self, data):
        self.sonar_depths = []
        self.__reset_depth_counter()

        for row in data:
            self.sonar_depths.append(int(row.strip()))

    def pt1(self):
        prev_depth = None
        current_depth = None
        for depth in self.sonar_depths:
            prev_depth = current_depth
            current_depth = depth
            if prev_depth is None:
                continue
            if prev_depth < current_depth:
                self.depth_counter += 1

    def pt2(self):
        self.__reset_depth_counter()
        print('TBD')

    def __reset_depth_counter(self):
        self.depth_counter = 0
