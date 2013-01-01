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

int percent(vector<string> items){
		int retval;
		double cost = 0.0, sale = 0.0;
		int length = items.size();
		for(int i = 0;i<length;i++){
			cost+=atof(items[i].substr(7,6).c_str());
			sale+=atof(items[i].substr(0,6).c_str());
		}
		retval = (int)((sale - cost)*100/sale);
		return retval;
}

start{
	string cost,sale;
	vector<string> v;
	int T;
	cin>>T;
	
	while(T--){
		cin>>cost>>sale;
		v.push_back(sale + " " + cost);
	}

	cout<<percent(v)<<endl;
	return 0;
}
