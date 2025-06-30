import matplotlib.pyplot as plt
import numpy as np

# Define the piecewise function
def f(x):
    if 0 <= x < 2:
        return 1.5 * x + 5   # Line from (0,5) to (2,8)
    elif 2 <= x < 4:
        return 8             # Horizontal line at y=8
    elif 4 <= x < 6:
        return -1.5 * x + 14 # Line from (4,8) to (6,5)
    elif 6 <= x < 8:
        return x - 1         # Line from (6,5) to (8,7)
    elif 8 <= x < 10:
        return 7             # Horizontal line at y=7
    elif 10 <= x <= 12:
        return -0.5 * x + 12 # Line from (10,7) to (12,6)
    else:
        return None

# Generate x and y values
x = np.linspace(0, 12, 1000)
y = np.array([f(xi) for xi in x])

# Plot the graph
plt.figure(figsize=(10, 6))
plt.plot(x, y, 'b-', linewidth=2, label='y = f(x)')

# Highlight key points and intervals
plt.scatter([0, 2, 4, 6, 8, 10, 12], 
            [f(0), f(2), f(4), f(6), f(8), f(10), f(12)], 
            color='red', zorder=5)
plt.axhline(y=8, color='gray', linestyle='--', alpha=0.3)
plt.axhline(y=7, color='gray', linestyle='--', alpha=0.3)
plt.axhline(y=6, color='gray', linestyle='--', alpha=0.3)

# Add labels and grid
plt.xlabel('x', fontsize=12)
plt.ylabel('y', fontsize=12)
plt.title('Piecewise Function Graph', fontsize=14)
plt.legend()
plt.grid(True, linestyle='--', alpha=0.6)
plt.xticks(np.arange(0, 13, 1))
plt.yticks(np.arange(4, 9, 1))

plt.show()
