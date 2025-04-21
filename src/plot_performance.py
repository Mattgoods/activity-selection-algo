import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

# Read the CSV file
df = pd.read_csv('performance_results.csv')

# Plot Running Time vs Input Size
plt.figure(figsize=(10, 5))
plt.plot(df['input_size'], df['running_time_ms'], marker='o', label='Measured Time')
# Plot theoretical O(N log N) for comparison (scaled for visibility)
N = df['input_size']
plt.plot(N, (df['running_time_ms'][0] / (N[0]*np.log2(N[0]))) * N * np.log2(N), '--', label='O(N log N) (scaled)')
plt.xlabel('Input Size (N)')
plt.ylabel('Running Time (ms)')
plt.title('Running Time vs Input Size')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('running_time_vs_input_size.png')
plt.show()

# Plot Peak Memory Usage vs Input Size
plt.figure(figsize=(10, 5))
plt.plot(df['input_size'], df['peak_memory_kb'], marker='o', color='orange')
plt.xlabel('Input Size (N)')
plt.ylabel('Peak Memory Usage (GB)')
plt.title('Peak Memory Usage vs Input Size')
plt.grid(True)
plt.tight_layout()
plt.savefig('peak_memory_vs_input_size.png')
plt.show()
