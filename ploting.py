import matplotlib.pyplot as plt
import numpy as np
import re
import sys

CAR_MAX_VELOCITY = 38


# Function to map velocity to color
def velocity_to_color(velocity):
    normalized_speed = velocity / CAR_MAX_VELOCITY
    return (normalized_speed, 0, 1 - normalized_speed)  # Blue to Red gradient


def get_data(file="data.txt"):
    with open(file) as f:
        # Use a more efficient way to skip lines with letters
        for line in f:
            if not re.search("[a-zA-Z]", line):
                break
        return [l.strip().split("|") for l in f.readlines()]


def create_road_state(data):
    # Use list comprehension for a more concise and potentially faster approach
    return np.array(
        [[int(char) if char.isdigit() else 0 for char in line] for line in data]
    )


def plot_road_state(road_state, file_name):
    # Use numpy functions to find indices where road_state is greater than 0
    indices = np.argwhere(road_state > 0)

    # Create a colorful plot using a single scatter call
    colors = [velocity_to_color(road_state[i, j]) for i, j in indices]
    plt.scatter(indices[:, 1], indices[:, 0], color=colors, s=1)

    # Customize plot appearance
    plt.xlabel("Distance on the Road")
    plt.ylabel("Time")
    plt.title("Road State Over Time")
    plt.gca().set_aspect("equal")
    plt.grid(True)

    # Save the plot as a PNG file
    plt.savefig(file_name)

    # Show the plot
    # plt.show()


def main():
    source = sys.argv[1]
    data = get_data(source)
    road_state = create_road_state(data)

    # Specify the file name based on the variable name
    file_name = "plot_{}.png".format(source)

    plot_road_state(road_state, file_name)


if __name__ == "__main__":
    main()
