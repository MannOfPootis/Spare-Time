import matplotlib.pyplot as plt
import numpy as np
import math as meth
def Fibonacci(n):
    # Check if input is 0 then it will
    # print incorrect input
    if n < 0:
        print("Incorrect input")

    # Check if n is 0
    # then it will return 0
    elif n == 0:
        return 0

    # Check if n is 1,2
    # it will return 1
    elif n == 1 or n == 2:
        return 1

    else:
        return Fibonacci(n - 1) + Fibonacci(n - 2)

def GR(n):
    return Fibonacci(n)/Fibonacci(n-1)
numseeds=200
k=GR(10)
phy=1
r0=1
xi=[]
yi=[]
for seed in range(numseeds):
    phy += 2 * np.pi / k
   # if(phy>np.pi*2):
        #phy = phy % 2 * np.pi
    r0+=1;
    xi.append(r0*meth.cos(phy))
    yi.append(r0 * meth.sin(phy))


x = np.array(xi)
y = np.array(yi)

plt.axis("equal")
plt.scatter(x, y,s=r0/10)
plt.show()