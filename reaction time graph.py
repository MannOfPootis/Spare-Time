from time import time
import matplotlib.pyplot as plt
import numpy as np
import time
import random as rand
def stDev(arry):#zanka za izračunanje standardne deviacije

    summation=sum(arry)
    avg=summation/len(arry)
    for xi in arry:
        summation+=(xi-avg)**2
    return np.sqrt(summation/len(arry))
#zanka za pdstranjevanje grobih npak(napake ki se pre več razlikujejo da bi bile razumne)
def grNpk(lst):
    groba=4#idk kuk tole more bit
    std=stDev(lst)
    avg=sum(lst)/len(lst)#prob obstaja bol optimalna pot do tega
    for elm in lst:
        if(abs(avg-elm)>std*groba):
            lst.remove(elm)
    return lst
#from scipy.stats import gaussian_kd
#ax = plt.figure().add_subplot()d

numTests=20
maxDelay=5
avg =0
print("hello world")
time.sleep(5*rand.random())

times= []
for count in range(numTests):
    time.sleep(maxDelay*rand.random())
    start=time.time();
    input("react");
    end= time.time();
    delta=end-start
    avg+=delta
    print(delta)
    if(delta!=0):
        times.append(end-start)
    else:
        numTests-=1


#for
times=grNpk(times)
print(np.array(times))
print(np.array(range(5)))
avg=avg/numTests;

ax = plt.subplots()
x=np.array(range(len(times)))
y=np.array(times)
plt.axhline(y=avg,color='r')
#stDev(times,avg,numTests)
#sus.scatter(x,y)
plt.scatter(x,y)
plt.errorbar(x, y, yerr=stDev(times),fmt='o')
#fig,nrer=plt.subplots()
#nrer.plot(np.array(times))

plt.show()


def pootis():
    return 0
