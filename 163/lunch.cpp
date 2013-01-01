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

int gcd(int a,int b){
		if(b == 0) return a;
		return gcd(b,a%b);
	}
	
	int lunchtime(int branch,int rest,int leaf){
		int lcm;
		if(rest<=leaf) lcm = rest*leaf/gcd(leaf,rest);
		else lcm = rest*leaf/gcd(rest,leaf);
		int t = branch/lcm;
		return t+1; 
	}

start{
	return 0;
}