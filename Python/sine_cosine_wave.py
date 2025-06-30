import numpy as np
import matplotlib.pyplot as plt

# Define the time range (0 to 2π)
theta = np.linspace(0, 2*np.pi, 1000)  # 1000 points from 0 to 2π
sin_wave = np.sin(theta)  # Sine wave
cos_wave = np.cos(theta)  # Cosine wave

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(theta, sin_wave, label='sin(θ)', color='blue', linewidth=2)
plt.plot(theta, cos_wave, label='cos(θ)', color='red', linestyle='--', linewidth=2)

# Add labels and grid
plt.title('Sine vs Cosine Waves (0 to 2π)', fontsize=14)
plt.xlabel('Angle (θ in radians)', fontsize=12)
plt.ylabel('Amplitude', fontsize=12)
plt.xticks([0, np.pi/2, np.pi, 3*np.pi/2, 2*np.pi],
           ['0', 'π/2', 'π', '3π/2', '2π'])
plt.grid(True, linestyle='--', alpha=0.6)
plt.axhline(0, color='black', linewidth=0.5)  # x-axis line
plt.legend(fontsize=12)

# Highlight phase difference (π/2)
plt.annotate('Phase Shift = π/2 (90°)', xy=(np.pi/2, 0), xytext=(np.pi/2 + 0.5, 0.3),
             arrowprops=dict(facecolor='green', shrink=0.05), fontsize=10)

plt.show()
