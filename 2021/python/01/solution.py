import os
import main
from main import DepthMeasurement

path = os.path.dirname(os.path.realpath(__file__))
file_data = open("{dir}/{file}".format(dir=path, file="../../shared/input_day01.txt"))
validator = DepthMeasurement(file_data)

print("Part 1 Solution:")
validator.pt1()
print(validator.depth_counter)

print("Part 2 Solution:")
validator.pt2()
print(validator.depth_counter)
