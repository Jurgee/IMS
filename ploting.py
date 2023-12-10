import matplotlib.pyplot as plt
import numpy as np
import re
import sys

CAR_MAX_VELOCITY = 38


# Function to map velocity to color
def velocity_to_color(velocity):
    normalized_speed = velocity / CAR_MAX_VELOCITY
    return (normalized_speed, 0, 1 - normalized_speed)  # Blue to Red gradient


def get_data(source):
    lines = source.readlines()

    # Skip lines until numeric data is found
    for line in lines:
        if not re.search("[a-zA-Z]", line):
            break

    return [l.strip().split("|") for l in lines]


def main():
    if len(sys.argv) >= 2:
        title = source
        source = open(sys.argv[1], "r")
    else:
        title = "stdin"
        source = sys.stdin

    data = get_data(source)

    # Convert lines to a 2D array with None for empty cells
    road_state = np.full((len(data), len(data[0])), None, dtype=object)
    for i, line in enumerate(data):
        road_state[i, :] = [int(char) if char.isdigit() else None for char in line]

    # Create a colorful plot
    fig, ax = plt.subplots()

    # Use numpy indexing for better performance
    nonzero_indices = np.nonzero(road_state != None)  # Filter out None values
    velocities = road_state[nonzero_indices]
    colors = np.array([velocity_to_color(v) for v in velocities])

    ax.scatter(nonzero_indices[1], nonzero_indices[0], color=colors, s=2)

    # Customize plot appearance
    ax.set_ylabel("Time")
    ax.set_xlabel("Distance on the Road")
    ax.set_title("Road State Over Time")
    ax.set_aspect("equal")
    ax.grid(True)

    # Specify the file name based on the variable name
    file_name = f"plot_{title}.png"

    # Save the plot as a PNG file
    fig.savefig(file_name)

    # Show the plot
    # plt.show()


if __name__ == "__main__":
    main()
