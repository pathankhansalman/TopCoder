#include <iostream>
#include <string>

using namespace std;

//class WordForm{
	bool isvowel(char c){
		if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return 1;
		else return 0;
	}

	string filter(string arg){
		
		if(arg.find("CC") == string::npos && arg.find("VV") == string::npos) return arg;
		int ind = arg.find("CC");
		if(ind == string::npos) ind = arg.find("VV");
		string retval = arg.substr(0,ind) + arg.substr(ind+1);

		return filter(retval);
	}

	string getSequence(string word2){
		string retval = "";
		int flag = 0;
		string word = word2;

		for(int i = 0;i<word.length();i++){
			word[i] = toupper(word[i]);
		}

		for(int i = 0;i<word.length();i++){
			if(isvowel(word[i])) retval.push_back('V');
			else if(i == 0 && word[i] == 'Y') retval.push_back('C');
			else if(i!=0 && word[i] == 'Y' && word[i-1] == ' ') retval.push_back('C');
			else if(i!=0 && word[i] == 'Y' && isvowel(word[i-1])) retval.push_back('C');
			else if(word[i] == 'Y'){
				if(retval[retval.length() - 1] == 'V') retval.push_back('C');
				else retval.push_back('V');
			}
			else retval.push_back('C');
			}

		retval = filter(retval);

		return retval;
	}
//};

int main(){
	string str;
	cin>>str;
	cout<<getSequence(str)<<endl;

	return 0;
}