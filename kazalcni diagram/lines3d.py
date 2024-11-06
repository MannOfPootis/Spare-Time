"""
================
Parametric curve
================

This example demonstrates plotting a parametric curve in 3D.
"""

import matplotlib.pyplot as plt
import numpy as np
def an(n):
    return 2/(2*n-1)
def fx(t,n):
    x=0;
    for i in range(n):
        x+=an(i)*np.sin((2*i-1)*t)
    return x
def fk(t,n):
    return(2/1*np.sin(t)+2/3*np.sin(3*t))
def fy(t,n):
    x = 0;
    for i in range(n):
        x+=0#an(i) * np.cos((2*i-1) * t)
    return x
ax = plt.figure().add_subplot(projection='3d')

# Prepare arrays x, y, z
n=10;
steps=200
x=[]
y=[]
for i in range(steps):
    x.append(fx(i/10,n))
    y.append(fy(i/10,n))

ax.plot(x, y, range(steps), label='parametric curve')
ax.legend()
#print(an(1),an(2),an(3))

#plt.plot(x,range(steps))
#plt.plot(range(steps),y)
plt.show()
