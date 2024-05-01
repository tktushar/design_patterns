import numpy as np

# Define the number of samples
num_samples = 100000

# Function to calculate the integrand
def integrand(phi, d, theta):
    return 2 * d * (np.cos(phi - theta) - (np.cos(phi) + np.sin(phi)))

# Function to perform Monte Carlo simulation
def monte_carlo_simulation(num_samples, theta):
    total = 0
    for _ in range(num_samples):
        phi = np.random.uniform(0, 2*np.pi)
        d = np.random.uniform(0, 1)
        total += integrand(phi, d, theta)
    return total / num_samples

# Theta value (the angle to the flag)
theta = np.random.uniform(0, 2*np.pi)  # Choose a random theta for the simulation

# Perform Monte Carlo simulation
result = monte_carlo_simulation(num_samples, theta)

# Multiply by probability density functions
probability = result * (1 / (2 * np.pi)) * (1 / 2)

print("Probability of Aaron winning:", probability)