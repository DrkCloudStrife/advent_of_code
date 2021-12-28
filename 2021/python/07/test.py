import os
from main import Solution

test_file = "2021_07_sample.txt"
path = os.path.dirname(os.path.realpath(__file__))
file_data = open("{dir}/../../../spec/fixtures/{file}".format(dir=path, file=test_file))
validator = Solution(file_data.read().splitlines())

print("Solution validator matches?")
validator.pt1()
print(validator.counter == None)

print("Solution validator matches?")
validator.pt2()
print(validator.counter == None)
