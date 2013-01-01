#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <cstdlib>

using namespace std;

int getPercentages(string times){
	vector<int> v;
	int i,j,curr,h,m,s;
	h = atoi(times.substr(0,2).c_str());
	m = atoi(times.substr(3,2).c_str());
	s = atoi(times.substr(6,2).c_str());

	int seconds = h*3600 + m*60 + s;

	for(i=0;i<7;i++){
		for(j=0;j<3;j++){
			curr = (int)pow(2,i)*(int)pow(5,j);
			if(curr == 1 || 100%curr == 0) v.push_back(curr);
		}
	}

	sort(v.begin(),v.end());

	for(i=0;i<v.size();i++) if(seconds%(100/v[i]) == 0) return (100/v[i] - 1);

	return 0;
}

int main(){
	string str;
	cin>>str;
	cout<<getPercentages(str)<<endl;

	return 0;
}
