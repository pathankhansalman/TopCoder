#include <string>
#include <iostream>
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

string whatTime(int seconds){
	string str="";
	int h,m,s;
	h = seconds/3600;
	seconds = seconds - (h*3600);
	m = seconds/60;
	seconds = seconds - (m*60);
	s = seconds;
	str = str + myitoa(h) + ":";
	str = str + myitoa(m) + ":";
	str = str + myitoa(s);
	return str;
}

int main(){
	int a = 3661;
	cout<<whatTime(a)<<endl;
	return 0;
}
