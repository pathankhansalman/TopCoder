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

vector<int> coins(int pence){
		vector<int> retval;
		int pound = pence/240;
		retval.push_back(pound);
		pence = pence - (pound*240);
		int shilling = pence/12;
		retval.push_back(shilling);
		pence = pence - (shilling*12);
		retval.push_back(pence);
		return retval;
	}

start{
	return 0;
}