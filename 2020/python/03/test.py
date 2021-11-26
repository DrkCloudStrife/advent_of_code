import os
import main
from main import TreeCounter

path = os.path.dirname(os.path.realpath(__file__))
path = open("{dir}/{file}".format(dir=path, file="../../../spec/fixtures/2020_03_sample.txt"))
counter = TreeCounter(path)

counter.traverse_pt1()
print("Trees counted match?")
print(len(counter.trees_encountered) == 7)
