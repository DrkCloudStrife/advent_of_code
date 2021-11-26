import os
import main
from main import PasswordValidator

path = os.path.dirname(os.path.realpath(__file__))
path = open("{dir}/{file}".format(dir=path, file="../../../spec/fixtures/2020_04_sample.txt"))
validator = PasswordValidator(path)

validator.validate_pt1()
print("Passport validity match?")
print(len(validator.valid_passports) == 2)
