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

	bool leap_year(int a){
		if(a%400 == 0) return 1;
		if(a%4 == 0 && a%100 !=0) return 1;
		return 0;
	}
	int useAgain(int year){
		int day_1 = 0,curr_day = 0,curr_year = year;
		
		while(curr_day!=day_1 || ((leap_year(curr_year) != leap_year(year)) || curr_year == year)){
			if(leap_year(curr_year+1)) curr_day = (curr_day + 366)%7;
			else curr_day = (curr_day + 365)%7;
			curr_year++;
			cout<<curr_year<<endl;
		}
		return curr_year;
	}

start{
	return 0;
}