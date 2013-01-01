#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm> // binsearch
#include <math.h> 
#include <vector>
#include <set>
#include <map> 
#include <cstdlib> // abs(int),labs(int),llabs(int),min,max
#include <limits.h> // int_max,int_min,long_long_max,long_long_min

using namespace std;

#define read(x) cin>>x 
#define EPS 0.0000001
#define print(x) cout<<x<<endl
#define DEBUG 0
#define VI vector<long long> 
#define VS vector<string>
#define w(i) while(i--)
#define start int main()

int area(vector<int> x,vector<int> y){
		int maxx = -1000000,maxy = -1000000,minx = 1000000,miny = 1000000;
		//start
		int temp;
		for(int i = 0;i<x.size();i+=2){
			if(x[i] > x[i+1] && y[i] > y[i+1]){
				temp = x[i];
				x[i] = x[i+1];
				x[i+1] = temp;
				temp = y[i];
				y[i] = y[i+1];
				y[i+1] = temp;
			}
			else if(x[i] > x[i+1]){
				temp = x[i];
				x[i] = x[i+1];
				x[i+1] = temp;
			}
			else if(y[i] > y[i+1]){
				temp = y[i];
				y[i] = y[i+1];
				y[i+1] = temp;
			}
		}
		//end
		for(int i = 0;i<x.size();i++) cout<<x[i]<<" "<<y[i]<<endl;
		for(int i = 0;i<x.size();i+=2) if(x[i] > maxx) maxx = x[i];
		for(int i = 1;i<x.size();i+=2) if(x[i] < minx) minx = x[i];
		for(int i = 0;i<y.size();i+=2) if(y[i] > maxy) maxy = y[i];
		for(int i = 1;i<y.size();i+=2) if(y[i] < miny) miny = y[i];
		if(maxx >= minx || maxy >= miny) return 0;
		return (minx - maxx)*(miny - maxy);
	}

start{
	return 0;
}