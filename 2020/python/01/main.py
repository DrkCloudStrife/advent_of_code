import os

class ExpenseReporter(object):
    DESIRED_EXPENSE = 2020

    def __init__(self, filename):
        self.expenses = []
        for row in filename:
            self.expenses.append(int(row))
        filename.close()

    def two_expenses(self):
        entries = [0,0]
        current_expense = 0

        for idx, expense1 in enumerate(self.expenses):
            entries[0] = expense1

            for idx2, expense2 in enumerate(self.expenses):
                if idx == idx2:
                    continue

                entries[1] = expense2
                current_expense = self.__sum(entries)

                if current_expense == self.DESIRED_EXPENSE:
                    break

            if current_expense == self.DESIRED_EXPENSE:
                break

        return self.__multiply(entries)

    def three_expenses(self):
        entries = [0,0,0]
        current_expense = 0

        for idx, expense1 in enumerate(self.expenses):
            entries[0] = expense1

            for idx2, expense2 in enumerate(self.expenses):
                if idx == idx2:
                    continue
                entries[1] = expense2

                for idx3, expense3 in enumerate(self.expenses):
                    if (idx == idx3) or (idx2 == idx3):
                        continue
                    entries[2] = expense3
                    current_expense = self.__sum(entries)
                    if current_expense == self.DESIRED_EXPENSE:
                        break

                current_expense = self.__sum(entries)
                if current_expense == self.DESIRED_EXPENSE:
                    break

            current_expense = self.__sum(entries)
            if current_expense == self.DESIRED_EXPENSE:
                break

        return self.__multiply(entries)

    def execute(self):
        print("Solution for 2 Expenses:")
        print(self.two_expenses())
        print("Solution for 3 Expenses:")
        print(self.three_expenses())

    def __sum(self,entries):
        return reduce(lambda e1, e2: e1 + e2, entries)

    def __multiply(self,entries):
        return reduce(lambda e1, e2: e1 * e2, entries)

directory = os.getcwd()
path = open("{dir}/{file}".format(dir=directory, file="2020/shared/input_day01.txt"))
report = ExpenseReporter(path)

report.execute()
