#include <iostream>

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

double momentum = 1000;//giblana količina istrelka
double given = 0;//gibalna količina klade
//double series[10000]; nepotrebno
FILE *datek;

double collison(double force) {//funkcija ki poda konstantno silo
    given += force;
    return force;

}//vem da to nebi raabila biti metoda ampapak s tem lažje nakazujem da je lahko funkcija
double collisonlinear(double t) {
    //constanmt f
    double c=10;
    given += c*t;
    return c*t;

}

double euler(double force) {
    double m, x, v, a, t, dt, tmax, k;
    m = 1;                               //določam vrednosti
    x = 0;
    v = 0;
    a = 0;
    t = 0;
    k = 1;
    dt = 0.001;
    for (t = 0; given < momentum; t += dt) {
        x += v * dt;
        v += a * dt;
        a = (collison(force) - x * k) / m;
        //series[dex] = x;
        //std::cout << x << "\n";
    }
    x += v * dt;//dodatene tick hitrosti zato da za zelo majhne trke
    v += a * dt;
   // std::cout<<k*x*x/2+m*v*v/2;   4
    double W=    k*x*x/2+m*v*v/2;
    double w=1;/* w= sqrt(k/m) sam si bom življenje prišoparu računalniku ker sta oba dva 1 */
    std::cout<<m*v+k*sqrt(2*W/k)*(1-cos(t))<<", "; //ocna za konservacijo gibalne količine
    return k*x*x/2+m*v*v/2;

}
void makeGraph(char* myString,double chaing){
    datek=fopen(myString,"w");
    for(double i=1;i<20000;i+=1){
        fprintf(datek,"%E\n ",   euler(momentum/i));
        given=0;
    }
    fclose(datek);
}

int main() {
    makeGraph("data.txt",10);//metoda ki naredi datoteko
  // std::cout<<1.0/(int)2;
  //std::cout<<cos(3.14);
    return 0;
}
