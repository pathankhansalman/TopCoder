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

int howMuch(vector<string> arrival,vector<string> departure,int wage){
		int retval;
		double ah,am,as,dh,dm,ds;
		double sal = 0.0;
		for(int i = 0;i<arrival.size();i++){
			ah = atoi(arrival[i].substr(0,2).c_str());
			am = atoi(arrival[i].substr(3,2).c_str());
			as = atoi(arrival[i].substr(6,2).c_str());
			dh = atoi(departure[i].substr(0,2).c_str());
			dm = atoi(departure[i].substr(3,2).c_str());
			ds = atoi(departure[i].substr(6,2).c_str());
			if(ah >= 18){
				if(dh <= 24){
					sal+=((dh - ah) + ((dm - am)/60.0) + ((ds - as)/3600.0))*wage*1.5;
				}
				else if(dh <6){
					sal+=((23 - ah) + ((59 - am)/60.0) + ((59 - as)/3600.0))*wage*1.5;
					sal+=(dh + (dm/60.0) + (ds/3600.0))*wage*1.5;
				}
				else if(dh >= 18){
					sal+=((23 - ah) + ((59 - am)/60.0) + ((59 - as)/3600.0))*wage*1.5;
					sal+=(5 + (59/60.0) + (59/3600.0))*wage*1.5;
					sal+=12*wage;
					sal+=((dh - 18) + (dm/60.0) + (ds/3600.0))*wage*1.5;
				}
				else{
					sal+=((23 - ah) + ((59 - am)/60.0) + ((59 - as)/3600.0))*wage*1.5;
					sal+=(5 + (59/60.0) + (59/3600.0))*wage*1.5;
					sal+=((dh - 5) + ((dm - 59)/60.0) + ((ds - 59)/3600.0))*wage;
				}
			}
			else if(ah<6){
				if(dh<6){
					sal+=((dh - ah) + ((dm - am)/60.0) + ((ds - as)/3600.0))*wage*1.5;
				}
				else if(dh<18){
					sal+=((6 - ah) + ((0 - am)/60.0) + ((0 - as)/3600.0))*wage*1.5;
					sal+=((dh - 5) + ((dm - 59)/60.0) + ((ds - 59)/3600.0))*wage;
				}
				else if(dh <= 23){
					sal+=((6 - ah) + ((0 - am)/60.0) + ((0 - as)/3600.0))*wage*1.5;
					sal+=12*wage;
					sal+=((dh - 18) + (dm/60.0) + (ds/3600.0))*wage*1.5;
				}
				else{
					sal+=((6 - ah) + ((0 - am)/60.0) + ((0 - as)/3600.0))*wage*1.5;
					sal+=12*wage;
					sal+=(5 + (59/60.0) + (59/3600.0))*wage*1.5;
					sal+=(dh + (dm/60.0) + (ds/3600.0))*wage*1.5;
				}
			}
			else{
				if(dh<18 || (dh == 18 && dm == 0 && ds == 0)){
					sal+=((dh - ah) + ((dm - am)/60.0) + ((ds - as)/3600.0))*wage;
				}
				else if(dh <= 23){
					sal+=((18 - ah) + ((0 - am)/60.0) + ((0 - as)/3600.0))*wage;
					sal+=((dh - 18) + (dm/60.0) + (ds/3600.0))*wage*1.5;
				}
				else if(dh < 6){
					sal+=((17 - ah) + ((59 - am)/60.0) + ((ds - as)/3600.0))*wage;
					sal+=(5 + (59/60.0) + (59/3600.0))*wage*1.5;
					sal+=(dh + (dm/60.0) + (ds/3600.0))*wage*1.5;
				}
				else{
					sal+=((17 - ah) + ((59 - am)/60.0) + ((ds - as)/3600.0))*wage;
					sal+=12*wage*1.5;
					sal+=((dh - 5) + ((dm - 59)/60.0) + ((ds - 59)/3600.0))*wage;
				}
			}
		}
		cout<<sal<<endl;
		retval = (int)sal;
		return retval;
	}

start{
	return 0;
}
