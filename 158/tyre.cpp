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

	string myreverse(string str){
		string s = "";
		for(int i = 0;i<str.length();i++){
			s.push_back(str[str.length() - 1 - i]);
		}
		return s;
	}
	int getCycle(string initial, string current){
		string changes[4];
		changes[0] = initial;
		for(int i = 1;i<4;i++){
				changes[i] = myreverse(changes[i-1].substr(2,2)) + changes[i-1].substr(0,2);
		}
		for(int i=0;i<4;i++){
			if(changes[i] == current) return i+1;
		}
		return -1;
	}

start{
	return 0;
}