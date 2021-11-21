import os
import main
from main import PasswordValidator

directory = os.getcwd()
path = open("{dir}/{file}".format(dir=directory, file="spec/fixtures/2020_02_sample.txt"))
validator = PasswordValidator(path)

validator.validate()

print(len(validator.valid_passwords) == 2)
