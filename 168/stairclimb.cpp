#include <vector>
#include <iostream>

using namespace std;

class StairClimb{
	public:
		int stridesTaken(vector<int> flights,int stairsPerStride){
			int length = flights.size();
			int retval = 0;
			for(int i = 0;i<length;i++){
				if(retval) retval+=2;
				if(flights[i]%stairsPerStride != 0) retval++;
				retval+=(flights[i]/stairsPerStride);
			}
			return retval;
		}
};