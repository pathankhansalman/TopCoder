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

int p2(int a){
		double curr = a*1.0;
		int retval = 0;
		while(curr>1){
			curr/=2.0;
			retval++;
		}
		return retval;
	}
	int numFolds(vector<int> paper,vector<int> box){
		int retval;
		int pwidth = paper[0],plength = paper[1],bwidth = box[0],blength = box[1];
		int rat1,rat2,rat3,rat4;
		double rats1,rats2,rats3,rats4;
		rat1 = pwidth/bwidth;
		rat2 = plength/blength;
		rats1 = pwidth/(bwidth*1.0);
		rats2 = plength/(blength*1.0);
		if(rats1-rat1*1.0) rat1++;
		if(rats2-rat2*1.0) rat2++;
		
		rat3 = pwidth/blength;
		rat4 = plength/bwidth;
		rats3 = pwidth/(blength*1.0);
		rats4 = plength/(bwidth*1.0);
		if(rats3 - rat3*1.0) rat3++;
		if(rats4 - rat4*1.0) rat4++;
		
		cout<<rat1<<" "<<rat2<<" "<<rat3<<" "<<rat4<<endl;
		cout<<rats1<<" "<<rats2<<" "<<rats3<<" "<<rats4<<endl;
		
		int fold1,fold2;
		fold1 = p2(rat1)+p2(rat2);
		fold2 = p2(rat3)+p2(rat4);
		if(fold1<fold2 && fold1<=8) return fold1;
		retval = fold2;
		if(retval<=8) return retval;
		return -1;
	}

start{
	return 0;
}