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

vector<string> justify(vector<string> textIn){
		vector<string> retval;
		int max = 0;
		for(int i = 0;i<textIn.size();i++){
			if(textIn[i].length() > max) max = textIn[i].length();
		}
		for(int i = 0;i<textIn.size();i++){
			string curr = "";
			for(int j=0;j<max - textIn[i].length();j++) curr.push_back(' ');
			retval.push_back(curr + textIn[i]);
		}
		return retval;
	}

start{
	return 0;
}