import matplotlib.pyplot as plt

# Function to read data from text file
def read_data_from_file(file_path):
    with open(file_path, 'r') as file:
        data = file.readlines()

    # Convert each line to a float for y values, skipping empty or non-numeric lines
    y_data = []
    for line in data:
        line = line.strip()  # Remove leading/trailing whitespace
        if line:  # Check if the line is not empty
            try:
                y_data.append(float(line))  # Try to convert to float
            except ValueError:
                print(f"Warning: Skipping non-numeric line: {line}")

    # Generate x values as the index of each y value
    x_data = list(range(1, len(y_data) + 1))  # X values: 1, 2, 3, ..., N

    return x_data, y_data

# Function to plot the data
def plot_data(x, y):
    plt.figure(figsize=(8, 6))
    plt.plot( y, linestyle='-', color='b')
    plt.title('Data from Text File (Single Column)')
    plt.xlabel('Index')
    plt.ylabel('Values')
    plt.grid(True)
    plt.savefig("fig4.png")
    plt.show()

# Path to your text file
file_path = 'data.txt'  # Replace with the path to your file

# Read the data from the file
x, y = read_data_from_file(file_path)

# Plot the data
plot_data(x, y)
