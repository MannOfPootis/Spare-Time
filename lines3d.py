"""
================
Parametric curve
================

This example demonstrates plotting a parametric curve in 3D.
jas sem primer iz interneta spremenil, da se je ujemal z našo enačbo
"""

import matplotlib.pyplot as plt
import numpy as np
ax = plt.figure().add_subplot(projection='3d')

# Prepare arrays x, y, z
theta = np.linspace(-4 * np.pi, 4 * np.pi, 100)#mogoče zgleda
t = np.linspace(-2, 6, 1000)
T=5
r0=1
z0=0.5

z = z0*t
x = r0 * np.sin(2*np.pi*t/T)
y = r0 * np.cos(2*np.pi*t/T)
zero=0*t+1

ax.plot(x, y, z, label='parametric curve')
ax.plot(x,zero,z,label='x- komponenta')
ax.plot(zero,y,z,label='y- komponenta')

ax.legend()

plt.show()
