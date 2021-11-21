import os
import main
from main import PasswordValidator

directory = os.getcwd()
path = open("{dir}/{file}".format(dir=directory, file="2020/shared/input_day02.txt"))
validator = PasswordValidator(path)

validator.validate()

print("Valid Passwords:")
print(len(validator.valid_passwords))
