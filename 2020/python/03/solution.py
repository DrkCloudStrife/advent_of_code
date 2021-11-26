import os
import main
from main import TreeCounter

path = os.path.dirname(os.path.realpath(__file__))
path = open("{dir}/{file}".format(dir=path, file="../../shared/input_day03.txt"))
counter = TreeCounter(path)

counter.traverse_pt1()
print("Part 1 Solution:")
print(len(counter.trees_encountered))

print('Part 2 Solution:')
print(counter.traverse_pt2())
