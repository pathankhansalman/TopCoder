#include <iostream>
#include <vector>

using namespace std;

vector<int> returnPicks(int position, int friends, int picks){
		vector<int> retval;
		int i = 0,curr = position;
		while(curr<=picks){
			retval.push_back(curr);
			curr++;
			if(i%2 == 0) curr+=2*(friends-position);
			else curr+=2*(position - 1);
			i++;
		}
		return retval;
	}

int main(){
	int pos,fr,pi;
	cin>>pos>>fr>>pi;
	vector<int> v = returnPicks(pos,fr,pi);
	int i,length = v.size();
	for(i=0;i<length;i++) cout<<v[i]<<endl;
	return 0;
}
