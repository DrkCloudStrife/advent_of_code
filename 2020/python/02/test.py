import os
import main
from main import PasswordValidator

path = os.path.dirname(os.path.realpath(__file__))
path = open("{dir}/{file}".format(dir=path, file="../../../spec/fixtures/2020_02_sample.txt"))
validator = PasswordValidator(path)

validator.validate_pt1()

print("Day 2 - Part 1 match?")
print(len(validator.valid_passwords) == 2)

validator.validate_pt2()
print("Day 2 - Part 2 match?")
print(len(validator.valid_passwords) == 1)
