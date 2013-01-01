#include <iostream>
#include <vector>
#include <string>

using namespace std;

int count(string dithered,vector<string> screen){
	int i,j,length,retval = 0,size = screen.size();
	string str;

	for(i=0;i<size;i++){
		str = screen[i];
		length = str.length();
		for(j=0;j<length;j++){
			if(dithered.find_first_of(str[j])!=string::npos) retval++;
		}
	}

	return retval;
}

int main(){
	string dithered,curr;
	std::vector<string> v;
	cin>>dithered;
	
	while(cin>>curr) v.push_back(curr);

	cout<<count(dithered,v);

	return 0;
}
