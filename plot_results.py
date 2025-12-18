import pandas as pd
import matplotlib.pyplot as plt

#Load the C++ Data
data =pd.read_csv("percolation.csv")

#plot 

plt.figure (figsize=(10,6))
plt.plot(data["p"],data["probability_of_percolation"],marker='o',color='b',linestyle='-')

#Style...... make it look like a physics paper 

plt.axvline(x=0.593, color='r', linestyle='--', label='Critical Threshold (0.593)')
plt.title(f"Percolation Phase Transition (Grid Size 20x20)")
plt.xlabel("Site Vacancy Probability (p)")
plt.ylabel("Probability of System Percolating")
plt.grid(True)
plt.legend()

plt.show()