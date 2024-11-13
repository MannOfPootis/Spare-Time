import matplotlib.pyplot as plt
import numpy as np
import math as meth
x=np.linspace(0,100*np.pi,1000)
#y=np.linspace(1,2,10)
r=0.5*np.pi
y=(np.sqrt(r**2-(x%(np.pi)-0.5*np.pi)**2))
for i in range(len(y)):
    if((x[i]%(2*np.pi))>np.pi):#yes this is fkin ugly as ballls i know
        y[i]=-y[i];

plt.figure()
y_fft = np.fft.fft(y)
frequencies = np.fft.fftfreq(len(y), d=(x[1] - x[0]))
amplitude_spectrum = np.abs(y_fft)
#freq = np.fft.fftfreq(x.y[-1])
ax=plt.subplot(1,2,1)
plt.axis("equal")
ax.plot(x,y)

plt.figure()
plt.plot(frequencies[:len(frequencies) // 2], amplitude_spectrum[:len(amplitude_spectrum) // 2])  # Only plot positive frequencies


#plt.axis("equal")
#plt.plot(x,y)
plt.show()