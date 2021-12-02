import os
from main import DepthMeasurement

path = os.path.dirname(os.path.realpath(__file__))
file_data = open("{dir}/{file}".format(dir=path, file="../../../spec/fixtures/2021_01_sample.txt"))
validator =  DepthMeasurement(file_data)

print("Depth validator matches?")
validator.pt1()
print(validator.depth_counter == 7)

print("Depth validator matches?")
validator.pt2()
print(validator.depth_counter == 5)
