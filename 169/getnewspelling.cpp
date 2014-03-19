#include <iostream>
#include <string>

using namespace std;

class Twain{
	public:

	string trim(string arg){
		string retval = arg;
		
		while(retval[0] == ' ') retval = retval.substr(1);
		
		while(retval[retval.length() - 1] == ' ') retval = retval.substr(0,retval.length() - 1);
		
		return retval;
	}

	int bef(string arg){
		int retval = 0,i = 0;
		
		while(arg[i] == ' '){
			retval++;
			i++;
		}
		
		return retval;
	}

	int af(string arg){
		int retval = 0,i = arg.length() - 1;
		
		while(arg[i] == ' '){
			retval++;
			i--;
			if(!i) break;
		}
		
		return retval;
	}

	string add_spaces(string arg,int bef,int af){
		string retval = "";
		
		int a = bef,b = af;
		
		while(a--) retval.push_back(' ');
		
		for(int i = 0;i<arg.length();i++) retval.push_back(arg[i]);
		
		while(b--) retval.push_back(' ');
		
		return retval;
	}

	string getNewSpelling(int year, string phrase){
		if(!year || phrase == "") return phrase;
		
		string retval = trim(phrase),curr = "";
		int before = bef(phrase),after = af(phrase);
		
		if(retval == "") return add_spaces(retval,before,after);
		
		int years = year;
		
		for(int i = 0;i<retval.length();i++){
		
			if(retval[i] == 'x' && (i == 0 || retval[i-1] == ' ')) curr.push_back('z');
		
			else if(retval[i] == 'x') curr = curr + "ks";
		
			else curr.push_back(retval[i]);
		}
		
		years--;
		
		if(!years) return add_spaces(curr,before,after);
		
		retval = curr;curr = "";
		
		for(int i = 0;i<retval.length();i++){
		
			if(retval[i] == 'y') curr.push_back('i');
		
			else curr.push_back(retval[i]);
		}
		
		years--;
		
		if(!years) return add_spaces(curr,before,after);
		
		retval = curr;curr = "";
		
		for(int i = 0;i<retval.length();i++){
		
			if(retval[i] == 'c' && (i!=retval.length() - 1 && (retval[i+1] == 'e' || retval[i+1] == 'i'))) curr.push_back('s');
		
			else curr.push_back(retval[i]);
		}
		
		years--;
		
		if(!years) return add_spaces(curr,before,after);
		
		retval = curr;curr = "";
		int flag = 1;
		
		while(flag){
		
			flag = 0;
		
			for(int i = 0;i<retval.length();i++){
		
				if(!(retval[i] == 'c' && (i!=retval.length() - 1 && retval[i+1] == 'k'))) curr.push_back(retval[i]);
			}
		
			cout<<curr<<endl;
			retval = curr;curr = "";
			cout<<retval<<endl;
		
			for(int i = 0;i<retval.length();i++){
		
				if(retval[i] == 'c' && (i!=retval.length() - 1 && retval[i+1] == 'k')){
					flag++;
					break;
				}
			}
		}
		cout<<retval<<endl;
		years--;
		
		if(!years) return add_spaces(retval,before,after);
		
		for(int i = 0;i<retval.length();i++){
		
			if(i<retval.length() - 2 && retval.substr(i,3) == "sch" && (i == 0 || retval[i - 1] == ' ')){
				curr = curr + "sk";
				i+=2;
			}
		
			else curr.push_back(retval[i]);
		}
		
		cout<<curr<<endl;
		retval = curr;curr = "";
		
		for(int i = 0;i<retval.length();i++){
		
			if(i<retval.length() - 2 && retval.substr(i,3) == "chr"){
				cout<<"here"<<endl;
				curr.push_back('k');
				i++;
			}
		
			else curr.push_back(retval[i]);
		}
		
		cout<<curr<<endl;
		retval = curr;curr = "";
		
		for(int i = 0;i<retval.length();i++){
		
			if(retval[i] == 'c' && (i == retval.length() - 1 || retval[i+1] != 'h')) curr.push_back('k');
		
			else curr.push_back(retval[i]);
		}
		
		cout<<curr<<endl;
		years--;
		
		if(!years) return add_spaces(curr,before,after);
		
		retval = curr;curr = "";
		
		for(int i = 0;i<retval.length();i++){
		
			if(i<retval.length() - 1 && retval.substr(i,2) == "kn" && (i == 0 || retval[i-1] == ' ')){
				curr.push_back('n');
				i++;
			}
		
			else curr.push_back(retval[i]);
		}
		
		cout<<curr<<endl;
		years--;
		
		if(!years) return add_spaces(curr,before,after);
		
		retval = curr;curr = "";
		
		for(int i = 0;i<retval.length();i++){
		
			if(i == retval.length() - 1 || !(retval[i] == retval[i+1] && (retval[i] != ' ' && retval[i] != 'a' && retval[i] != 'e' && retval[i] != 'i' && retval[i] != 'o' && retval[i] != 'u'))){ 
				curr.push_back(retval[i]);
			}
		}
		
		return add_spaces(curr,before,after);
	}
};