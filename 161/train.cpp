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
	string s="";
	int i,length = str.length();
	for(i=0;i<length;i++){
		s.push_back(str[length - i - 1]);
	}

	return s;
}

string myitoa(int a){
	if(a == 0) return "0";
	string str = "";
	int curr = a,temp;char c;
	while(curr>=1){
		temp = curr%10;
		curr = curr/10;
		c = temp+'0';
		str.push_back(c);
	}
	return myreverse(str);
}
	string filter(string arg){
		char c = 'A';
		int ind = (int)c;
		int A[26];
		string str = arg;
		for(int i = 0;i<26;i++) A[i] = 0;
		for(int i = 0;i<arg.length();i++){
			A[(int)arg[i] - ind] = A[(int)arg[i] - ind] + 1;
		}
		for(int i=0;i<arg.length();i++){
			if(A[(int)arg[i] - ind] > 1){
				str = str.substr(0,i) + str.substr(i+1);
				return filter(str);
			}
		}
		return str;
	}
	
	string buildTrain(vector<string> cars){
		string retval = "";
		retval+=cars[0];
		
		for(int i = 1;i<cars.size();i++){
			int index = 0;
			for(int j = 1;j<cars[i].length();j++){
				if(cars[i].substr(0,j) == retval.substr(retval.length() - j)) index = j;
			}	
			if(index && index < retval.length()) retval = retval + cars[i].substr(index);
			cout<<retval<<endl;
		}
		cout<<retval<<endl;
		string s = myitoa(retval.length());
		retval = filter(retval);
		return s+ " " + retval;
	}

start{
	return 0;
}