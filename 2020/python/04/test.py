import os
from main import PasswordValidator

path = os.path.dirname(os.path.realpath(__file__))
path_1 = open("{dir}/{file}".format(dir=path, file="../../../spec/fixtures/2020_04_sample.txt"))
validator = PasswordValidator(path_1)

print("Passport validity match?")
validator.validate_pt1()
print(len(validator.valid_passports) == 2)

print("Part 2 validity match?")
path_2 = open("{dir}/{file}".format(dir=path, file="../../../spec/fixtures/2020_04_pt2_sample.txt"))
validator2 = PasswordValidator(path_2)
validator.validate_pt2()
print(len(validator.valid_passports) == 4)
