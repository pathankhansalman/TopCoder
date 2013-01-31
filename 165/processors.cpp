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

int numProcessors(int k,int overhead){
		long long curr,min = 1000000000,minind = 0;
		int retval;
		for(long long i = 1;i<=k;i++){
			curr = (k/i) + ((i/2) * overhead * (i-1));
			if(curr< min){
				min = curr;
				minind = i;
			}
		}
		return retval = minind;
	}

start{
	return 0;
}