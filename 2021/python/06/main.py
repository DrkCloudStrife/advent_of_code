class Solution(object):

    MAX_DAY_CYCLES = 80

    def __init__(self, data):
        self.data = []
        self.fish = []

        for row in data:
            [self.data.append(int(n)) for n in row.split(',')]

        self.__reset_counters()

    def pt1(self):
        for day in range(self.MAX_DAY_CYCLES):
            for fish in self.fish:
                result = fish.update_timer()
                if isinstance(result, Lanternfish):
                    self.fish.append(result)

        self.counter = len(self.fish)

    def pt2(self):
        self.__reset_counters()
        fishes = [0,0,0,0,0,0,0,0,0] # not relying on former solution

        for fish in self.data:
            fishes[fish] = fishes[fish]+1

        for day in range(256):
            newborn = False
            newborn_count = 0
            # We check for any newborn fish
            if fishes[0] > 0:
                newborn = True
                newborn_count = fishes[0]

            # We shift the array by 1
            fishes.append(fishes.pop(0))
            # We append newborns to the "7th day" cycle
            if newborn == True:
                fishes[6] = fishes[6] + newborn_count

        # Tally up the fish
        for fish in fishes:
            self.counter += fish

    def __reset_counters(self):
        self.counter = 0
        self.fish = []
        for timer in self.data:
            self.fish.append(Lanternfish(int(timer)))

class Lanternfish(object):

    DEFAULT_TIME_TO_BREED = 6
    OFFSPRING_TIME_TO_BREED = 8

    def __init__(self, time_to_breed, newborn = False):
        self.time_to_breed = time_to_breed
        self.is_newborn = newborn

    def update_timer(self):
        return self.__check_timer()

    def __check_timer(self):
        if self.is_newborn:
            self.is_newborn = False
            return self.time_to_breed

        if self.time_to_breed == 0:
            self.time_to_breed = self.DEFAULT_TIME_TO_BREED
            return Lanternfish(self.OFFSPRING_TIME_TO_BREED, True)
        else:
            self.time_to_breed -= 1
