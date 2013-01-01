#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

string decipher(string typed,vector<string> switches){
		string retval="";
		vector<pair<char,char> > V;
		int j,i,length = typed.length(),size = switches.size();
		
		for(i=0;i<size;i++){
			string curr = switches[i];
			V.push_back(make_pair(curr[0],curr[2]));
		}
		
		for(i=0;i<size;i++){
			for(j=0;j<length;j++){
				if(typed[j] == V[i].first) typed[j] = V[i].second;
				else if(typed[j] == V[i].second) typed[j] = V[i].first;
			}
		}
		retval = typed;
		return retval;
}

int main(){
	string str,curr;
	std::vector<string> v;
	cin>>str;
	while(cin>>curr) v.push_back(curr);	
	cout<<decipher(str,v)<<endl;

	return 0;
}
