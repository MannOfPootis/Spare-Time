#include <iostream>

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

double momentum = 1000;//giblana količina istrelka
double given = 0;//gibalna količina klade
//double series[10000]; nepotrebno
double     dt = 0.01;
static double m, x, v, a, t, tmax, k;

FILE *datek;

double collison(double force) {
    if(given>=momentum){return 0;}
//funkcija ki poda konstantno silo
    if(given+force>=momentum){force=momentum-given;}    //we doin a bit to much ifs but fk it

    given += force;//I sure do love my floating point errors
    return force;

}//vem da to nebi raabila biti metoda ampapak s tem lažje nakazujem da je lahko funkcija
double collisonlinear(double t) {
    //constanmt f
    if(given>=momentum){return 0;}
    given += t;
    return t;

}
double eulerTruncInverse(int i) {

    for (double t = 1; given < momentum; t += dt) {
        a = (collison(momentum/(t*i)) - x * k) / m;
        v += a * dt;

        x += v * dt;

        //series[dex] = x;
        //std::cout << x << "\n";
    }
    // x += v * dt;//dodatene tick hitrosti zato da za zelo majhne trke
    //  v += a * dt;
    std::cout<<k*x*x/2+m*v*v/2;
    //do<uble W=    k*x*x/2+m*v*v/2;
    //double w=1;/* w= sqrt(k/m) sam si bom življenje prišoparu računalniku ker sta oba dva 1 */
    //std::cout<<m*v+k*sqrt(2*W/k)*(1-cos(t))<<", "; //ocna za konservacijo gibalne količine
    return k*x*x/2+m*v*v/2;

}
double eulerTruncLin(int i) {

    for (t = 0; given < momentum; t += dt) {
        a = (collison(momentum/i*t) - x * k) / m;
        v += a * dt;

        x += v * dt;

        //series[dex] = x;
        //std::cout << x << "\n";
    }
   // x += v * dt;//dodatene tick hitrosti zato da za zelo majhne trke
  //  v += a * dt;
    std::cout<<k*x*x/2+m*v*v/2;
    double W=    k*x*x/2+m*v*v/2;
    double w=1;/* w= sqrt(k/m) sam si bom življenje prišoparu računalniku ker sta oba dva 1 */
    //std::cout<<m*v+k*sqrt(2*W/k)*(1-cos(t))<<", "; //ocna za konservacijo gibalne količine
    return k*x*x/2+m*v*v/2;

}
double euler(double force,double tmax) {

   // tmax=40;
    for (t = 0; t<tmax; t += dt) {
        a = (collison(force) - x * k) / m;
        v += a * dt;

        x += v * dt;
        //series[dex] = x;
        //std::cout << x << "\n";
    }
   // x += v * dt;//dodatene tick hitrosti zato da za zelo majhne trke
  //  v += a * dt;
    //std::cout<<k*x*x/2+m*v*v/2;
  //  double W=    k*x*x/2+m*v*v/2;
    //double w=1;/* w= sqrt(k/m) sam si bom življenje prišoparu računalniku ker sta oba dva 1 */
    //std::cout<<m*v+k*sqrt(2*W/k)*(1-cos(t))<<", "; //ocna za konservacijo gibalne količine
    return k*x*x/2+m*v*v/2;

}

double eulerTrunc(int i) {
   /* m = 1;                               //določam vrednosti
    x = 0;
    v = 0;
    a = 0;
    t = 0;
    k = 1;*/
    for (double t = 0; given < momentum; t += dt) {
        a = (collison(momentum/i) - x * k) / m;
        v += a * dt;

        x += v * dt;

        //series[dex] = x;
        //std::cout << x << "\n";
    }
   // x += v * dt;//dodatene tick hitrosti zato da za zelo majhne trke
    //v += a * dt;
    std::cout<<k*x*x/2+m*v*v/2;

    return k*x*x/2+m*v*v/2;

}
void makeGraph(char* myString,double chaing){

    datek=fopen(myString,"w");
    for(double i=1;i<200;i+=1){
        m = 10;                               //določam vrednosti
        x = 0;
        v = 0;
        a = 0;
        t = 0;
        k = 10;
        fprintf(datek,"%E\n ",   eulerTrunc(i))/*euler(momentum/i,200))*/;
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
