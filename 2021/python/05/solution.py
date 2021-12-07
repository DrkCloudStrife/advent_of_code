import os
import main
from main import Solution

path = os.path.dirname(os.path.realpath(__file__))
file_data = open("{dir}/{file}".format(dir=path, file="../../shared/input_day05.txt"))
validator = Solution(file_data.readlines())

print("Part 1 Solution:")
validator.pt1()
print(validator.counter)

print("Part 2 Solution:")
validator.pt2()
print(validator.counter)
