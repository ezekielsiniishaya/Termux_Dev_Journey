import numpy as np
import matplotlib.pyplot as plt

# Time axis
t = np.linspace(0, 2 * np.pi, 1000)
vin = 10 * np.sin(t)  # Corrected input voltage

# Clipping threshold
clip_level = -4.7
vout = np.copy(vin)
vout[vout > clip_level] = clip_level  # clip the positive part

# Plotting
plt.figure(figsize=(10, 5))
plt.plot(
    t,
    vin,
    label="Input Voltage $V_{in} = 10\\sin(\\omega t)$",
    linestyle="--",
    color="gray",
)
plt.plot(t, vout, label="Output Voltage $V_{out}$ (Clipped at -4.7V)", color="blue")
plt.axhline(clip_level, color="red", linestyle=":", label="Clipping Level (-4.7V)")
plt.title("Biased Positive Clipper Output")
plt.xlabel("Time (rad)")
plt.ylabel("Voltage (V)")
# plt.grid(True)
# plt.legend()
plt.tight_layout()
plt.show()
