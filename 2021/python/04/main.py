class Solution(object):

    def __init__(self, data):
        self.drawings = None
        self.players = []
        self.__reset_counters()

        board = 0
        board_data = []
        for i, row in enumerate(data):
            if i == 0:
                self.drawings = row.strip().split(',')
            else:
                if row == '\n': continue
                board_data.append(row.split())

            if len(board_data) == 5:
                self.players.append(BingoBoard(board_data))
                board_data = []

        print('player boards', self.players)

    def pt1(self):
        for drawing in self.drawings:
            for player in self.players:
                player.play(drawing)

    def pt2(self):
        self.__reset_counters()
        print("TBD")

    def __reset_counters(self):
        self.counter = 0

# Bingo board
class BingoBoard(object):

    def __init__(self, data):
        self.play_board = data
        self.position = {}
        self.__construct_board_positions()
        self.columns = {
            "row": [0 for r in range(len(data[0]))],
            "col": [0 for r in range(len(data))],
        }

    def play(self, val):
        print('play board', val)

    def __construct_board_positions(self):
        for i, row in enumerate(self.play_board):
            idx = 0
            for val in row:
                idx += 1
                self.position[val] = (idx, i)
