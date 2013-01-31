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

int power_two(int n){
		int retval = 1,curr = n;
		while(curr>2){
			curr/=2;
			retval++;
		}
		return retval;
	}
	
	vector<int> arrange(vector<int> numbers){
		vector<int> retval;
		int max = 0;
		for(int i = 0;i<numbers.size();i++) if(numbers[i] >max) max = numbers[i];
		int size = power_two(max),curr;
		cout<<size<<endl;
		map<int,set<int> > M;
		set<int> S;
		for(int i = 0;i<=size;i++) M.insert(pair<int,set<int> >(i,S));
		for(int i = 0;i<numbers.size();i++){
			int count = 0;
			curr = numbers[i];
			while(curr>=1){
				if(curr%2==1) count++;
				curr/=2;
			}
			M[count].insert(numbers[i]);
		}
		
		for(int i = 0;i<=size;i++){
			set<int>::iterator it;
			if(M[i].size() == 0) continue;
			for(it = M[i].begin();it!=M[i].end();it++){
				retval.push_back(*it);
			}
		}
		return retval;
	}

start{
	return 0;
}