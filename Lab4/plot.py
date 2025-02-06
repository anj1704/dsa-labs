import matplotlib.pyplot as plt

# Read data from file
with open("/Users/anjaneyabajaj/Documents/Semester_2-2/CS_F211_DSA/labs/Lab4/iterativeMergeSortBenchmarks.txt", "r") as file:
    data = [line.strip().split(",") for line in file]

# Extract input size and time taken
input_sizes = [int(entry[0]) for entry in data]
times_taken = [float(entry[1]) for entry in data]

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(input_sizes, times_taken, marker='o', linestyle='-')
plt.title('Iterative Merge Sort Benchmarks')
plt.xlabel('Input Size')
plt.ylabel('Time Taken (seconds)')
plt.xscale('log')  # Log scale for better visualization of large input sizes
plt.yscale('log')  # Log scale for better visualization of large time values
plt.grid(True)
plt.show()
