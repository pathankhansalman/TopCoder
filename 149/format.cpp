#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string myreverse(string str){
	string s="";
	int i,length = str.length();
	for(i=0;i<length;i++){
		s.push_back(str[length - i - 1]);
	}

	return s;
}

string myitoa(int a){
	if(a == 0) return "0";
	string str = "";
	int curr = a,temp;char c;
	while(curr>=1){
		temp = curr%10;
		curr = curr/10;
		c = temp+'0';
		str.push_back(c);
	}
	return myreverse(str);
}
	
	string convert_dollars(int i){
		string retval;
		int j;
		if(i<1000){
			retval = myitoa(i);
			for(j=0;j<3-retval.length();j++) retval = "0" + retval;
			return retval;
		}
		retval = myitoa(i%1000);
		int len = retval.length();
		for(j=0;j<3-len;j++) retval = "0" + retval;
		retval = convert_dollars(i/1000) + ","+ retval;
		
		return retval;
	}
	string refine(string str){
		if(str[0] == '0') return refine(str.substr(1));
		else return str;
	}
	string amount(int dollars,int cents){
		string retval = "";
		string dollar,cent;
		if(cents < 10) cent = "0" + myitoa(cents);
		else cent = myitoa(cents);
		dollar = convert_dollars(dollars);
		dollar = refine(dollar);
		if(dollar == "") dollar = "0";
		retval = "$" + dollar + "." + cent;
		
		return retval;
	}

	int main(){
		int dollars,cents;
		cin>>dollars>>cents;
		cout<<amount(dollars,cents)<<endl;
		return 0;
	}
	