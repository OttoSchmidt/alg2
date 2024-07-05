from binarytree import build
import csv

values = []

with open("heap.txt", "r") as file:
    reader = csv.reader(file)

    for row in reader:
        for value in row:
            values.append(int(value))

for line in file:
    values.append(int(line))

file.close()

root = build(values)
print(root)