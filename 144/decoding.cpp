#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

vector<string> decode(string message){
		vector<string> V;
		int fault = 0,i,length = message.length();
		int Q[length];
		for(i=0;i<length;i++) Q[i] = message[i] - '0';
		int P[length];
		P[0] = 0;
		P[1] = Q[0] - P[0];
		if(P[1]>1) fault = 1;
		for(i=1;i<length;i++){
			if(fault) break;
			P[i+1] = Q[i] - P[i] - P[i-1];
			if(P[i+1]>1){
				fault++;
			}
		}
		if(Q[length-1]!= P[length-2]+P[length-1]) fault = 1;
		if(fault) V.push_back("NONE");
		else{
			string str = "";
			for(i=0;i<length;i++) str.push_back(P[i]+'0');
			V.push_back(str);
		}
		fault = 0;
		P[0] = 1;
		P[1] = Q[0] - P[0];
		if(P[1]>1) fault = 1;
		for(i=1;i<length;i++){
			if(fault) break;
			P[i+1] = Q[i] - P[i] - P[i-1];
			if(P[i+1]>1){
				fault++;
			}
		}
		if(Q[length-1]!= P[length-2]+P[length-1]) fault = 1;
		if(fault) V.push_back("NONE");
		else{
			string str = "";
			for(i=0;i<length;i++) str.push_back(P[i]+'0');
			V.push_back(str);
		}
		return V;
	}

int main(){
	string str;
	cin>>str;
	std::vector<string> v = decode(str);
	int i,length = v.size();
	for(i = 0;i<length;i++) cout<<v[i]<<endl;
	return 0;
}
