import csv
import matplotlib.pyplot as plt

sizes = []

bubble = []
selection = []
insertion = []
merge = []
quick = []

with open("sorting_times.csv", "r") as file:

    reader = csv.DictReader(file)

    for row in reader:

        sizes.append(int(row["Size"]))

        bubble.append(float(row["Bubble"]))
        selection.append(float(row["Selection"]))
        insertion.append(float(row["Insertion"]))
        merge.append(float(row["Merge"]))
        quick.append(float(row["Quick"]))


plt.plot(sizes, bubble, marker='o', label="Bubble Sort")
plt.plot(sizes, selection, marker='o', label="Selection Sort")
plt.plot(sizes, insertion, marker='o', label="Insertion Sort")
plt.plot(sizes, merge, marker='o', label="Merge Sort")
plt.plot(sizes, quick, marker='o', label="Quick Sort")

plt.xlabel("Input Size")
plt.ylabel("Time (seconds)")

plt.title("Sorting Algorithm Time Comparison")

plt.legend()

plt.grid(True)

plt.show()