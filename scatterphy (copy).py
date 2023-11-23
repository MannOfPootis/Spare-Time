import numpy as np
import matplotlib.pyplot as plt

from uncertainties import ufloat
from uncertainties.umath import *

# define data
x = np.array([1, 2, 3, 4])
y = np.array([10, 20, 30, 40])
measurements = [ufloat(1.5, 0.1), ufloat(2, 0.1), ufloat(3.03, 0.1), ufloat(4, 0.1)];
weights = [ufloat(11, 0.5), ufloat(20, 10), ufloat(36, 0.1), ufloat(40, 0.1)];

x = np.array([m.nominal_value for m in measurements])
y = np.array([m.nominal_value for m in weights])
xer=np.array([m.std_dev for m in measurements])
yer=np.array([m.std_dev for m in weights])
#x=np.array(x);

# find line of best fit
a, b = np.polyfit(x, y, 1)

# add points to plot
plt.errorbar(x, y,xerr=xer,yerr=yer,fmt='o', label='Data with Errors')
print(a)
print(b)

# add line of best fit to plot
plt.plot(x, a * x + b)
plt.show()
