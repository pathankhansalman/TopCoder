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

vector<string> animate(int speed,string init){
		vector<string> retval;
		string str = "";
		int i;
		for(i = 0;i<init.length();i++){
			if(init[i] != '.') str.push_back('X');
			else str.push_back('.');
		}
		retval.push_back(str);
		
		string curr1 = init,curr2 = init;
		string ind = "";
		for(i = 0;i<init.length();i++) ind.push_back('.');
		vector<int> Rt,Lt;
		int count = 1;
		while(count){
			count = 0;
			vector<int> Rt;
			vector<int> Lt;
			Rt.clear();Lt.clear();
			for(i = 0;i<init.length();i++){
				if(curr1[i] == 'R') Rt.push_back(i+speed);
				if(curr2[i] == 'L') Lt.push_back(i-speed); 
			}
			string curr = ind;curr1 = ind;curr2 = ind;
			for(i = 0;i<Rt.size();i++){
				if(Rt[i]>=0 && Rt[i]<curr.length()) curr1[Rt[i]] = 'R';
			}
			for(i = 0;i<Lt.size();i++){
				if(Lt[i]>=0 && Lt[i]<curr.length()) curr2[Lt[i]] = 'L';
			}
			for(i = 0;i<init.length();i++){
				if(curr1[i]=='R' || curr2[i]=='L') curr[i] = 'X';
			}
			retval.push_back(curr);
			for(i = 0;i<init.length();i++){
				if(curr[i] =='X'){
					count++;
					break;
				}
			}
			for(i = 0;i<Rt.size();i++) cout<<Rt[i]<<endl;
			Rt.clear();Lt.clear();
			cout<<curr1<<" "<<curr2<<" "<<endl;
		}
		if(retval[0]==retval[1] && retval.size() == 2){
			string curr = retval[0];
			retval.clear();
			retval.push_back(curr);
		} 
		return retval;
	}

start{
	return 0;
}