import matplotlib.pyplot as plt
import numpy as np

from matplotlib import cm
from matplotlib.ticker import LinearLocator

fig, ax = plt.subplots(subplot_kw={"projection": "3d"})
N=200;
V=0.00042
h=0.18
S=V/h
l=0.195
ro=918
n=0.05
g=9.81
r=6.35/2000
# Make data.
X = np.linspace(r/2, r*1.5, N)
Y = np.linspace(l/2, l*1.5, N)
X, Y = np.meshgrid(X, Y)
R = np.sqrt(S*np.log((V/S+Y)/Y)*8*n*Y/(np.pi*ro*g*X**4))
Z = R

# Plot the surface.
surf = ax.plot_surface(X, Y, Z, cmap=cm.coolwarm,
                       linewidth=0, antialiased=False)

# Customize the z axis.
#ax.set_zlim(-1.01, 1.01)
ax.set_xlabel('Polmer')
ax.set_ylabel('Dolžina')
ax.set_zlabel('Čas')
ax.zaxis.set_major_locator(LinearLocator(10))
# A StrMethodFormatter is used automatically
ax.zaxis.set_major_formatter('{x:.02f}')

# Add a color bar which maps values to colors.
fig.colorbar(surf, shrink=0.5, aspect=5)

plt.show()