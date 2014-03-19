#include <iostream>
#include <vector>

using namespace std;

class Swimmers{
	public:
	vector<int> getSwimTimes(vector<int> distances,vector<int> speeds,int current){
		vector<int> retval;
		for(int i = 0;i<speeds.size();i++){
			if(current >= speeds[i]) retval.push_back(-1);
			else retval.push_back((2*distances[i]*speeds[i])/((speeds[i] - current)*(speeds[i] + current)));
		}
		return retval;
	}
};