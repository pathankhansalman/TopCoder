#include <iostream>
#include <math.h>

using namespace std;

double cycleRange(double R){
		double retval;
		double X = 0.25;
		int i = 0;
		while(i!=200000){
			X = R * X * (1-X);
			i++;
		}
		double V[1000];
		i = 0;
		while(i!=1000){
			V[i] = X;
			X = R * X * (1-X);
			i++;
		}
		double max = 0,min = 1;
		for(i=0;i<1000;i++){
			if(V[i] > max) max = V[i];
			if(V[i] < min) min = V[i];
		}
		retval = max - min;
		return retval;
	}

int main(){
	double arg;
	cin>>arg;
	cout<<cycleRange(arg)<<endl;
	return 0;
}
