#include <iostream>
#include <set>

using namespace std;

int howMany(int number){
		int curr = number;
		multiset<int> s;
		while(curr>=1){
			s.insert(curr%10);
			curr/=10;
		}
		int count = 0;
		set<int>::iterator it;
		for(it = s.begin();it!=s.end();it++){
			if(*it != 0 && number%(*it) == 0) count++;
		}
		return count;
}

int main(){
	int input;
	cin>>input;
	cout<<howMany(input)<<endl;
	return 0;
}
