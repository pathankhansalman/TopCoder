#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class SkipRope{
	public:
		vector<int> partners(vector<int> candidates2,int height){
			vector<int> retval;
			vector<int> candidates = candidates2;
			sort(candidates.begin(),candidates.end());
			int min = 1000000,minind = 0;
			for(int i = 0;i<candidates.size();i++){
				if(fabs(height - candidates[i]) <= min){
					min = fabs(height - candidates[i]);
					minind = i;
				}
			}
			cout<<min<<endl;
			int secmin = 1000000,secminind = 0;
			for(int i = 0;i<candidates.size();i++){
				if(i!=minind && fabs(height - candidates[i]) <= secmin){
					secmin = fabs(height - candidates[i]);
					secminind = i;
				}
			}
			retval.push_back(candidates[minind]);
			retval.push_back(candidates[secminind]);
			sort(retval.begin(),retval.end());
			return retval;
		}
};