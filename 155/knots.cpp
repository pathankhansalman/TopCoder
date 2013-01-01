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
		string retval = "";
		for(int i = 0;i<str.length();i++) retval.push_back(str[str.length() - i - 1]);
		return retval;
	}
	int readKnots(string knots){
		string retval = "";
		int i,countm = 0,countx = 0;
		for(i = knots.length() - 1;i>=0;i--){
			if(knots[i] == '-'){
				if(countx) retval.push_back(countx + '0');
				countm++;
				countx = 0;
			}
			if(knots[i] == 'X'){
				countm--;
				if(countm>0) while(countm--) retval.push_back('0');
				countx++;
				countm = 0;
			}
		}
		int ans = atoi(myreverse(retval).c_str());
		return ans;
	}

start{
	string inp;
	cin>>inp;
	cout<<readKnots(inp)<<endl;
	return 0;
}
