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

	int power_of(int a,int b){
		if(b>a) return 0;
		if(a==b) return 1;
		int curr = a,retval = 0;
		while(curr%b == 0){
			curr/=b;
			retval++;
		}
		return retval;
	}
	int lcm(int first,int last){
		int retval = 1,curr;
		int i,j,primes[5],powers[5];
		primes[0] = 2;primes[1] = 3;primes[2] = 5;primes[3] = 7;primes[4] = 11;
		for(i=0;i<5;i++){
			powers[i] = 0;
			for(j=first;j<=last;j++){
				curr = power_of(j,primes[i]);
				if(curr > powers[i]) powers[i] = curr;
			}
		}
		for(i=0;i<5;i++) retval*=(int)pow(primes[i],powers[i]);
		return retval;
	}

start{
	return 0;
}