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

int freeParks(string street){
		int retval = 0;
		for(int i = 0;i<street.length();i++){
			if(street[i] != 'D' && street[i] != 'B' && street[i] != 'S'){
				if(i==0){
					if(street[i+1] != 'B' && street[i+1] != 'S' && street[i+2] != 'B') retval++;
				}
				else if(i == street.length() - 1){
					if(street[i-1] != 'S') retval++;
				}
				else if(i == street.length() - 2){
					if(street[i+1] != 'B' && street[i+1] != 'S' && street[i-1] != 'S') retval++;
				}
				else{
					if(street[i+1] != 'B' && street[i+1] != 'S' && street[i+2] != 'B' && street[i-1] != 'S') retval++;
				}
			}
		}
		return retval;
	}

start{
	return 0;
}