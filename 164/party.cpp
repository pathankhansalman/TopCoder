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

vector<string> seating(vector<string> attendees){
		vector<string>retval;
		if(attendees.size()%2!=0) return retval;
		string gender[attendees.size()];
		for(int i = 0;i<attendees.size();i++){
			if(attendees[i][attendees[i].length() - 1] == 'y'){
				gender[i] = attendees[i].substr(attendees[i].length() - 3);
				attendees[i] = attendees[i].substr(0,attendees[i].length() - 4);
			}
			else{
				gender[i] = attendees[i].substr(attendees[i].length() - 4);
				attendees[i] = attendees[i].substr(0,attendees[i].length() - 5);
			}
		}
		int male = 0,female = 0;
		for(int i = 0;i<attendees.size();i++){
			if(gender[i] == "boy") male++;
			else female++;
		}
		if((male!= female) || (female<2)) return retval;
		vector<string> boys,girls;
		for(int i = 0;i<attendees.size();i++){
			if(gender[i] == "boy") boys.push_back(attendees[i]);
			else girls.push_back(attendees[i]);
		}
		sort(boys.begin(),boys.end());
		sort(girls.begin(),girls.end());
		retval.push_back("HOST");
		int j = 0;
		for(int i = 0;i<attendees.size()/2;i++){
			if(i%2 == 0) retval.push_back(girls[j]);
			else{
				retval.push_back(boys[j]);
				j++;
			}
		}
		retval.push_back("HOSTESS");
		for(int i = attendees.size()/2;i<attendees.size();i++){
			if((i-attendees.size()/2)%2 == 0) retval.push_back(boys[j]);
			else{
				retval.push_back(girls[j]);
				j++;
			}
		}
		return retval;
	}

start{
	return 0;
}