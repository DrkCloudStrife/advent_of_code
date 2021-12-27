import os
from main import Solution

path = os.path.dirname(os.path.realpath(__file__))
file_data = open("{dir}/{file}".format(dir=path, file="../../../spec/fixtures/2021_06_sample.txt"))
validator = Solution(file_data.read().splitlines())

print("Solution validator matches?")
validator.pt1()
print(validator.counter == 5934)

print("Solution validator matches?")
validator.pt2()
print(validator.counter == 26984457539)
