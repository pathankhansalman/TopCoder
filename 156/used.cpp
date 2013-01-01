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

int minDrives(vector<int> used, vector<int> total){
		int retval = 0;
		long long sum = 0;
		for(int i = 0;i<used.size();i++) sum+=used[i];
		sort(total.begin(),total.end()); 
		for(int i = total.size() - 1;i>=0;i--){
			sum -= total[i];
			retval++;
			if(sum <= 0) break;
		}
		return retval;
	}

start{
	int a,b,N;
	vector<int> u,v;
	cin>>N;
	while(N--){
		cin>>a>>b;
		u.push_back(a);
		v.push_back(b);
	}
	cout<<minDrives(u,v)<<endl;
	return 0;
}

