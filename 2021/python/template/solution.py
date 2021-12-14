import os
import main
from main import Solution

input_file = "input_day01.txt"
path = os.path.dirname(os.path.realpath(__file__))
file_data = open("{dir}/../../shared/{file}".format(dir=path, file=input_file))
validator = Solution(file_data.read().splitlines())

print("Part 1 Solution:")
validator.pt1()
print(validator.counter)

print("Part 2 Solution:")
validator.pt2()
print(validator.counter)
