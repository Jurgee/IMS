import matplotlib.pyplot as plt
import numpy as np
import re as re
import sys

CAR_MAX_VELOCITY = 38


# Function to map velocity to color
def velocity_to_color(velocity):
    normalized_speed = velocity / CAR_MAX_VELOCITY
    return (normalized_speed, 0, 1 - normalized_speed)  # Blue to Red gradient


def get_data(file="data.txt"):
    with open(file) as f:
        line = f.readline()
        while re.search("[a-zA-Z]", line) is not None:
            line = f.readline()
        return [l.strip().split("|") for l in f.readlines()]


source = sys.argv[1]
data = get_data(source)

# Convert lines to a 2D array
road_state = np.zeros((len(data), len(data[0])))
for i, line in enumerate(data):
    for j, char in enumerate(line):
        if char.isdigit():
            road_state[i, j] = int(char)


# Create a colorful plot
fig, ax = plt.subplots()

for i in range(len(data)):
    for j in range(len(data[0])):
        if road_state[i, j] > 0:
            color = velocity_to_color(road_state[i, j])
            ax.scatter(i, j, color=color, s=2)

# Customize plot appearance
ax.set_xlabel("Time")
ax.set_ylabel("Distance on the Road")
ax.set_title("Road State Over Time")
ax.set_aspect("equal")
ax.grid(True)

# Specify the file name based on the variable name
file_name = "plot_{}.png".format(source)

# Save the plot as a PNG file
fig.savefig(file_name)

# Show the plot
# plt.show()
