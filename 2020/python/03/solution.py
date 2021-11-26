import os
import main
from main import TreeCounter

path = os.path.dirname(os.path.realpath(__file__))
path = open("{dir}/{file}".format(dir=path, file="../../shared/input_day03.txt"))
counter = TreeCounter(path)

counter.traverse_pt1()
print("Trees counted:")
print(len(counter.trees_encountered))
