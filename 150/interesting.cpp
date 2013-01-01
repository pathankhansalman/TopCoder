#include <iostream>
#include <vector>

using namespace std;

vector<int> digits(int base){
		vector<int> retval;
		if(base == 2) return retval;
		int i,curr = base - 1;
		for(i=2;i<base;i++){
			if(curr%i == 0) retval.push_back(i);
		}
		return retval;
	}

int main(){
	int base;
	cin>>base;
	vector<int> v = digits(base);
	int i,length = v.size();
	for(i=0;i<length;i++) cout<<v[i]<<endl;
	return 0;
}
