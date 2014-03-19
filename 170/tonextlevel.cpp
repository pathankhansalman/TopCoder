#include <iostream>
#include <vector>

using namespace std;

class LevelUp{
	public:
		int toNextLevel(vector<int> expNeeded, int received){
			if(received < expNeeded[0]) return expNeeded[0] - received;
			for(int i = 1;i<expNeeded.size() - 1;i++) if(expNeeded[i - 1] <= received && received < expNeeded[i]) return expNeeded[i] - received;
			return 0;
		}
};