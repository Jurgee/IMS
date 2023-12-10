import matplotlib.pyplot as plt

CAR_MAX_VELOCITY = 38


def main():
    # Create a figure without axes
    fig, ax = plt.subplots()
    ax.set_axis_off()

    # Add legend
    legend_labels = ["Nulová rychlost", "Maximální rychlost"]

    # Create a legend with specified handles and labels
    legend = ax.legend(
        handles=[
            plt.Line2D(
                [0],
                [0],
                marker="o",
                color="w",
                label=legend_labels[0],
                markerfacecolor="blue",
                markersize=5,
            ),
            plt.Line2D(
                [0],
                [0],
                marker="o",
                color="w",
                label=legend_labels[1],
                markerfacecolor="red",
                markersize=5,
            ),
        ],
        loc="center",
    )

    # Set a higher DPI for better resolution
    dpi = 1000

    # Specify the file name based on the variable name
    file_name = "legend_plot.png"

    # Save the plot as a PNG file with higher DPI
    fig.savefig(file_name, dpi=dpi)


if __name__ == "__main__":
    main()
