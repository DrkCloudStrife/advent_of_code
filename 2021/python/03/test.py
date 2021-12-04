import os
from main import Solution

path = os.path.dirname(os.path.realpath(__file__))
file_data = open("{dir}/{file}".format(dir=path, file="../../../spec/fixtures/2021_03_sample.txt"))
validator =  Solution(file_data)

print("Validator matches?")
validator.pt1()
print(validator.counter == 198)

print("Validator matches?")
validator.pt2()
print(validator.counter == 230)
