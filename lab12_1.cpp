#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double x[], int M, double y[]){
    double max = x[0], min = x[0];
    double sumsd;
    double geo = 1;
    double hm;
    for(int i=0; i<M; i++){
        y[0] += x[i];
        sumsd += pow(x[i],2);
        geo *= x[i]; 
        hm += 1/x[i];
        if(x[i]>max) max = x[i];
        if(x[i]<min) min=x[i];
    }
    double n = M;
    y[0] /=M;
    y[1] = sqrt((sumsd/n)-pow(y[0],2));
    y[2] = pow(geo,1/n);
    y[3] = n/hm;
    y[4] = max;
    y[5] = min;

}