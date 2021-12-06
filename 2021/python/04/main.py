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
                self.players.append(BingoBoard(board_data, "Player {}".format(i)))
                board_data = []

        print('player boards', self.players)

    def pt1(self):
        bingo_winner = None
        bingo_drawing = None

        for drawing in self.drawings:
            for player in self.players:
                player.play(drawing)

                if player.has_bingo():
                    bingo_winner = player
                    bingo_drawing = drawing
                    break

            if bingo_winner != None:
                break

    def pt2(self):
        self.__reset_counters()
        print("TBD")

    def __reset_counters(self):
        self.counter = 0

# Bingo board
class BingoBoard(object):

    def __init__(self, data, player_name):
        self.name = player_name
        self.play_board = data
        self.position = {}
        self.__construct_board_positions()
        self.columns = {
            "row": [0 for r in range(len(data[0]))],
            "col": [0 for r in range(len(data))],
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
        print(self.name, 'bingo?', self.columns)
        return True

    def __construct_board_positions(self):
        for row_idx, row in enumerate(self.play_board):
            col_idx = 0
            for val in row:
                self.position[val] = (col_idx, row_idx)
                col_idx += 1
