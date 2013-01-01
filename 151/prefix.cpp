#include <iostream>
#include <vector>
#include <string>

using namespace std;

	bool prefix(string str1,string str2){
		if(str2.length()<str1.length()) return 0;
		int i,length = str1.length();
		for(i=0;i<length;i++){
			if(str1[i] != str2[i]) return 0;
		}
		return 1;
	}
	
	string isOne(vector<string> words){
		string retval = "Yes";
		int i,j,length = words.size();
		for(i=0;i<length;i++){
			for(j=0;j<length;j++){
				if(j!=i){
					if(prefix(words[i],words[j])){
						retval = "No, ";
						retval.push_back(i+'0');
						return retval;
					}
				}
			}
		}
		return retval;
	}

int main(){
	string curr;
	vector<string> v;
	while(cin>>curr) v.push_back(curr);
	cout<<isOne(v)<<endl;
	return 0;
}
