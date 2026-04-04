import numpy as np # type: ignore
import matplotlib.pyplot as plt

# Time array for 2 bit durations
t = np.linspace(0, 2, 1000)

# Carrier frequency
f = 5  # 5 Hz for illustration
omega = 2 * np.pi * f

# QAM components (4-QAM / QPSK-like)
# QAM uses two signals:
#  - In-phase (I): cosine component
#  - Quadrature (Q): sine component

I = np.cos(omega * t)  # In-phase
Q = np.sin(omega * t)  # Quadrature

# Example QAM signal: linear combination of I and Q with different amplitudes
qam_signal = 0.7 * I + 0.7 * Q

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(t, I, label='In-Phase Component (I)', linestyle='--')
plt.plot(t, Q, label='Quadrature Component (Q)', linestyle='--')
plt.plot(t, qam_signal, label='Combined QAM Signal (I + Q)', color='purple')

plt.title("QAM Signal: Combination of ASK and PSK (I and Q Components)")
plt.xlabel("Time (s)")
plt.ylabel("Amplitude")
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()
