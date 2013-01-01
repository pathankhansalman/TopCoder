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

int leading_digit(int arg){
		int retval = 0,curr = arg;
		while(curr > 0){
			retval = curr%10;
			curr/=10;
		}
		return retval;
	}
	
	int questionableDigit(vector<int> transactions,int threshold){
		double expected[9],actuals[9];
		int i,retval = -1;
		for(i=0;i<9;i++){
			expected[i] = transactions.size() * log10(1 + 1.0/(i+1));
			actuals[i] = 0;
		}
		for(i=0;i<transactions.size();i++) actuals[leading_digit(transactions[i]) - 1]++;
		
		for(i=0;i<9;i++){
			if(actuals[i] < expected[i]/threshold || actuals[i] > expected[i]*threshold){
				retval = i+1;
				break;
			}
		}
		
		if(DEBUG){
			for(i=0;i<9;i++){
				cout<<expected[i]<<" "<<actuals[i]<<endl;
			}
		}
		
		return retval;
	}

start{
	return 0;
}
