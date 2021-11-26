import os
from main import PasswordValidator

path = os.path.dirname(os.path.realpath(__file__))
path = open("{dir}/{file}".format(dir=path, file="../../shared/input_day04.txt"))
validator = PasswordValidator(path)

validator.validate_pt1()
print('Part 1 Solution:')
print(len(validator.valid_passports))
