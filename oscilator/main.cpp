#include <iostream>

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

double momentum = 1000;
double given = 0;
double series[10000];
FILE *datek;

double collison(double force) {
    //constanmt f
    //double f = fo;
    given += force;
    return force;

}
double collisonlinear(double t) {
    //constanmt f
    double c=10;
    given += c*t;
    return c*t;

}

double euler(double force) {
    double m, x, v, a, t, dt, tmax, k;
    m = 1;
    x = 0;
    v = 0;
    a = 0;
    t = 0;
    k = 1;
    int dex = 0;
    dt = 0.0001;
    tmax = 100;
    for (t = 0; given < momentum; t += dt) {
        x += v * dt;
        v += a * dt;
        a = (collison(force) - x * k) / m;
        //series[dex] = x;
        dex++;
        //std::cout << x << "\n";
    }
    std::cout<<k*x*x/2+m*v*v/2;
    return k*x*x/2+m*v*v/2;

}
void makeGraph(char* myString,double chaing){
    datek=fopen(myString,"w");
    for(double i=1;i<200;i+=1){
        fprintf(datek,"%E\n ",   euler(momentum/i));
        given=0;
    }
    fclose(datek);
}

int main() {
    makeGraph("sus.txt",10);
    return 0;
}
