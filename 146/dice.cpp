#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int maxPoints(vector<int> toss){
		int j,i,max = 0,values[6],score[6];
		
		for(i=0;i<6;i++){
			values[i] = i+1;
			score[i] = 0;
		}
		
		for(i=0;i<5;i++){
			for(j=0;j<6;j++){
				if(toss[i] == values[j]) score[j]+=values[j];
			}
		}
		
		for(i=0;i<6;i++){
			if(score[i] > max) max = score[i];
		}
		
		return max;
}

int main(){
	std::vector<int> v;
	int temp;
	while(cin>>temp) v.push_back(temp);
	cout<<maxPoints(v)<<endl;
	return 0;
}
