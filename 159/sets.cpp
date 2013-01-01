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

vector<int> operate(vector<int> A,vector<int> B,string operation){
		/*set<int> arg1,arg2;
		for(int i = 0;i<A.size();i++) arg1.insert(A[i]);
		for(int i = 0;i<B.size();i++) arg2.insert(B[i]);*/
		set<int> retval;
		for(int i = 0;i<A.size();i++) retval.insert(A[i]);
		for(int i = 0;i<B.size();i++) retval.insert(B[i]);
		vector<int> result;
		set<int>::iterator it;
		multiset<int> inter;
			
		for(int i = 0;i<A.size();i++) inter.insert(A[i]);
		for(int i = 0;i<B.size();i++) inter.insert(B[i]);
			
		multiset<int>::iterator it2;
			
		for(it = retval.begin();it!=retval.end();it++){
			it2 = inter.find(*it);
			inter.erase(it2);
		}
			
		if(operation == "UNION"){
			for(it = retval.begin();it!=retval.end();it++) result.push_back(*it);
			return result;
		}
		
		if(operation == "INTERSECTION"){
			for(it2 = inter.begin();it2!=inter.end();it2++) result.push_back(*it2);
			return result;
		}
		
		for(it2 = inter.begin();it2!=inter.end();it2++){
			it = retval.find(*it2);
			retval.erase(it);
		}
		
		if(operation == "SYMMETRIC DIFFERENCE"){
			for(it = retval.begin();it!=retval.end();it++) result.push_back(*it);
			return result;
		}
		
		return result;
	}

start{
	return 0;
}