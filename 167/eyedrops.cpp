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

double closest(int sleepTime,int k){
		double retval = 0.0;
		int time = 24 - sleepTime;
		if(k!=1) retval = time/(1.0*(k-1));
		if(sleepTime < 24/k) return 24*60/k;
		return retval*60;
	}

start{
	return 0;
}