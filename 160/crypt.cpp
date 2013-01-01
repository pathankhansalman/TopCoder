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

string refine(string code,string key){
		string retval = "";
		for(int i = 0;i<code.length();i++){
			if(key.find(code[i])!=string::npos) retval.push_back(code[i]);
		}
		return retval;
	}
	int getValue(string key,string code){
		string arg = refine(code,key);
		string retval = "";
		for(int i = 0;i<arg.length();i++){
			retval.push_back((key.find(arg[i])+1)%10 +'0');
		}
		return atoi(retval.c_str());
	}

start{
	return 0;
}