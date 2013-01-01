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

string decoder(string message){
		string retval = "";
		char c;
		int i,length = message.length();
		for(i=0;i<length;i++){
			c = message[i];
			if(c == ' ') retval.push_back(c);
			else if((int)message[i] >=78 && (int)message[i] <= 90) retval.push_back((char)((int)message[i] - 13));
			else if((int)message[i] >= 65 && (int)message[i] <= 77) retval.push_back((char)((int)message[i] + 13));
			else if((int)message[i] < 53) retval.push_back((char)((int)message[i] + 5));
			else if((int)message[i] < 58) retval.push_back((char)((int)message[i] - 5));
			else if((int)message[i] < 110) retval.push_back((char)((int)message[i] + 13));
			else retval.push_back((char)((int)message[i] - 13));
		}
		
		return retval;
}

start{
	string msg;
	cin>>msg;
	cout<<decoder(msg)<<endl;
	return 0;
}
