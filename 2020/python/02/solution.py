import os
import main
from main import PasswordValidator

path = os.path.dirname(os.path.realpath(__file__))
path = open("{dir}/{file}".format(dir=path, file="../../shared/input_day02.txt"))

validator = PasswordValidator(path)
validator.validate_pt1()
print("Part 1 | Valid Passwords: {}".format(len(validator.valid_passwords)))

validator.validate_pt2()
print("Part 2 | Valid Passwords: {}".format(len(validator.valid_passwords)))
