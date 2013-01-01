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

vector<string> dealHands(int numPlayers, string deck){
		vector<string> retval;
		if(deck.length() < numPlayers){
			for(int i = 0;i<numPlayers;i++) retval.push_back("");
			return retval;
		}
		int div = deck.length()/numPlayers;
		div = div * numPlayers;
		deck = deck.substr(0,div);
		div = div / numPlayers;
		for(int i=0;i<numPlayers;i++){
			string curr = "";
			for(int j=0;i+j<deck.length();j+=numPlayers) curr.push_back(deck[i+j]);
			retval.push_back(curr);
		}
		return retval;
	}

start{
	return 0;
}