import os
from main import Solution

path = os.path.dirname(os.path.realpath(__file__))
file_data = open("{dir}/{file}".format(dir=path, file="../../../spec/fixtures/2021_05_sample.txt"))
validator =  Solution(file_data.readlines())

print("Validator test matches?")
validator.pt1()
print(validator.counter == 5)

print("Validator test matches?")
validator.pt2()
print(validator.counter == 12)
