import matplotlib.pyplot as plt
import numpy as np
import math as meth
mxpwr=14
numpts=mxpwr+1
phy=np.pi/3
r0=1.3
frc=100
xi=[]
yi=[]
for counter in range(numpts*frc):
    #print("",r0,"**",counter,"/",frc)
    xi.append((r0**(counter/frc)) * meth.cos((counter/frc)*phy))
    yi.append((r0**(counter/frc)) * meth.sin((counter/frc)*phy))


x = np.array(xi)
y = np.array(yi)

plt.axis("equal")
plt.plot(x, y)
plt.grid()
plt.show()

