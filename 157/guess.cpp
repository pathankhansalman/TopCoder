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

class GuessTheNumber{
	public:
	int noGuesses(int upper,int answer){
		int lower = 1,retval = 0,guess = 0;
		while(guess != answer){
			guess = (upper+lower)/2;
			if(guess>answer) upper = guess - 1;
			else lower = guess + 1;
			retval++;
		}
		return retval;
	}

start{
	return 0;
}