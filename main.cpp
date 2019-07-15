/*This code is an example of the Runge-Kutta (RK4) algorithm to solve
 differential equations. We use this to solve an initial value problem*/

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;


double myfunc(double t, double y);
double k1(double h, double t, double y);
double k2(double h, double t, double y);
double k3(double h, double t, double y);
double k4(double h, double t, double y);
double y_new(double h, double t, double y);
double t_new(double h, double t);
double iterations = 1000000;
double h = 0.001;

int main(int argc, char** argv) {
    //y(t_0) = y_0
    double y = 0;
    double t = 0;
    
    std::remove("RK_data.txt");
    ofstream data;
    
    for (int i=0; i < iterations; i++){
        data.open ("RK_data.txt", ios::app);
        data.precision(10);
        data << t << "\t" << y << endl;
        data.close();
        t = t_new(h,t);
        y = y_new(h,t,y);   
    }
    
    return 0;
}

double myfunc(double t, double y){
    double y_dot = 2.*cos(t)*sin(t);
    return y_dot;
}
double k1(double h, double t, double y){
    double k_1 = h*myfunc(t,y);
    return k_1;
}
double k2(double h, double t, double y){
    double k_2 = h*myfunc((t+(h/2.)),(y+(k1(h,t,y)/2)));
    return k_2;
}
double k3(double h, double t, double y){
    double k_3 = h*myfunc((t+(h/2.)),(y+(k2(h,t,y)/2)));
    return k_3;
}
double k4(double h, double t, double y){
    double k_3 = h*myfunc((t+(h/2.)),(y+(k3(h,t,y)/2)));
    return k_3; 
}
double y_new(double h, double t, double y){
    double ynew = y + (1./6.)*(k1(h,t,y) + 2*k2(h,t,y) + 2*k3(h,t,y) + k4(h,t,y));
    return ynew;
}
double t_new(double h, double t){
    double tnew = t + h;
    return tnew;
}





