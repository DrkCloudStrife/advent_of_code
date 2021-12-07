class Solution(object):
    def __init__(self, data):
        self.players = []
        self.data = data.readlines()
        self.drawings = None
        self.__reset_counters()

    def pt1(self):
        for drawing in self.drawings:
            for player in self.players:
                player.play(drawing)

                if player.has_bingo():
                    self.bingo_winner = player
                    self.bingo_drawing = drawing
                    break

            if self.bingo_winner != None:
                break
        unmarked_sum = self.__sum_list(self.bingo_winner.remaining_numbers())
        self.counter = unmarked_sum * int(self.bingo_drawing)

    def pt2(self):
        self.__reset_counters()

        for idx, drawing in enumerate(self.drawings):
            for player in self.players:
                if player.has_won is True:
                    continue

                player.play(drawing)
                if player.has_bingo():
                    self.bingo_winner, self.bingo_drawing = [player, drawing]

        unmarked_sum = self.__sum_list(self.bingo_winner.remaining_numbers())
        self.counter = unmarked_sum * int(self.bingo_drawing)

    def __reset_counters(self):
        self.bingo_winner = None
        self.bingo_drawing = None
        self.counter = 0

        board = 0
        board_data = []
        if len(self.players) == 0:
            for i, row in enumerate(self.data):
                if i == 0:
                    self.drawings = row.strip().split(',')
                else:
                    if row == '\n': continue
                    board_data.append(row.split())

                if len(board_data) == 5:
                    self.players.append(BingoBoard(board_data))
                    board_data = []
        else:
            [player.reset_board() for player in self.players]

    def __sum_list(self, list_1):
        return reduce(lambda item1, item2: item1 + item2, list_1)

# Bingo board
class BingoBoard(object):
    BINGO_METRIC = 5

    def __init__(self, data):
        self.__data = data
        self.position = {}
        self.reset_board()
        self.__construct_board_positions()

    def reset_board(self):
        self.has_won = False
        self.play_board = self.__data[:]
        self.columns = {
            "row": [0 for r in range(len(self.__data[0]))],
            "col": [0 for r in range(len(self.__data))],
        }

    def play(self, val):
        try:
            x, y = self.position[val]
            self.columns['row'][x] += 1
            self.columns['col'][y] += 1
            self.play_board[x][y] = None
        except:
            pass

    def has_bingo(self):
        if self.BINGO_METRIC in self.columns['row'] or self.BINGO_METRIC in self.columns['col']:
            self.has_won = True

        return self.has_won

    def remaining_numbers(self):
        return self.__flat_board()

    def __flat_board(self):
        flat_list = []

        for element in self.play_board:
            if type(element) is list:
                for item in element:
                    if item is None: continue
                    if type(item) is str: item = int(item)
                    flat_list.append(item)
            else:
                if item is None: continue
                if type(item) is str: item = int(item)
                flat_list.append(element)

        return flat_list

    def __construct_board_positions(self):
        for row_idx, row in enumerate(self.play_board):
            col_idx = 0
            for val in row:
                self.position[val] = (row_idx, col_idx)
                col_idx += 1
