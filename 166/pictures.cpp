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

int pictureFrames(vector<int> pieces){
		long long i,j,k;
		set<vector<int> > s;
		vector<int> curr;
		for(i=0;i<pieces.size();i++){
			for(j=0;j<pieces.size();j++){
				for(k = 0;k<pieces.size();k++){
					curr.clear();
					if(((pieces[i] + pieces[j] > pieces[k]) && ((pieces[i] + pieces[k] > pieces[j]) && (pieces[k] + pieces[j] > pieces[i]))) && (i!=j && (j!=k && k!=i))){
						curr.push_back(pieces[i]);
						curr.push_back(pieces[j]);
						curr.push_back(pieces[k]);
						sort(curr.begin(),curr.end());
						s.insert(curr);
					}
				}
			}
		}
		return s.size();
	}


start{
	return 0;
}