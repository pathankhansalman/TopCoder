#include <iostream>
#include <string>

using namespace std;

string decode(string cipherText,int shift){
		char c = 'A';
		int curr,index = (int)c;
		int i,length = cipherText.length();	
		string retval = "";
		
		for(i=0;i<length;i++){
			curr = (int)cipherText[i] - shift;
			if(curr < index) curr = (26 - (index - curr)) + index;
			retval.push_back((char)curr);
		}
		
		return retval;
}

int main(){
	string str;
	int n;
	cin>>str>>n;
	cout<<decode(str,n)<<endl;
	return 0;
}
