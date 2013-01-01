#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm> // binsearch
#include <math.h> 
#include <vector>
#include <set>
#include <map> 
#include <cstdlib> // abs(int),labs(int),llabs(int),min,max
#include <limits.h> // int_max,int_min,long_long_max,long_long_min

using namespace std;

#define read(x) cin>>x 
#define EPS 0.0000001
#define print(x) cout<<x<<endl
#define DEBUG 0
#define VI vector<long long> 
#define VS vector<string>
#define w(i) while(i--)
#define start int main()

bool sum(vector<int> val1,vector<int> val2,vector<int> val3,int start,int carry,int base){
		if(start >= 5) return 1;
		if(val1[start] == 0 && val2[start] == 0){
			if(carry == val3[start]) return 1;
			return 0;
		}
		if(val1[start] == 0){
			if((val2[start]+carry)%base != val3[start]) return 0;
			carry = (val2[start] + carry)/base;
			return sum(val1,val2,val3,start+1,carry,base);
		}
		if(val2[start] == 0){
			if((val1[start]+carry)%base != val3[start]) return 0;
			carry = (val1[start] + carry)/base;
			return sum(val1,val2,val3,start+1,carry,base);
		}
		int curr = (val1[start] + val2[start] + carry)%base;
		carry = (val1[start] + val2[start] + carry)/base;
		if(curr!=val3[start]) return 0;
		return sum(val1,val2,val3,start+1,carry,base);
	}
	
	bool check(int base, string arg1,string arg2,string arg3){
		vector<int> val1(5),val2(5),val3(5);
		for(int i = 0;i<5;i++){
			val1[i] = 0;
			val2[i] = 0;
			val3[i] = 0;
		}
		for(int i = 0;i<arg1.length();i++){
			if((int)arg1[arg1.length() - i - 1] < 65){
				val1[i] = arg1[arg1.length() - i - 1] - '0';
			}
			else{
				val1[i] = 10 + (int)arg1[arg1.length() - i - 1] - 65;
			}
		}	
		for(int i = 0;i<arg2.length();i++){
			if((int)arg2[arg2.length() - i - 1] < 65){
				val2[i] = arg2[arg2.length() - i - 1] - '0';
			}
			else{
				val2[i] = 10 + (int)arg2[arg2.length() - i - 1] - 65;
			}
		}
		for(int i = 0;i<arg3.length();i++){
			if((int)arg3[arg3.length() - i - 1] < 65){
				val3[i] = arg3[arg3.length() - i - 1] - '0';
			}
			else{
				val3[i] = 10 + (int)arg3[arg3.length() - i - 1] - 65;
			}
		}
		for(int i=0;i<arg1.length();i++) cout<<val1[i]<<" ";		
		cout<<endl;
		for(int i=0;i<arg2.length();i++) cout<<val2[i]<<" ";		
		cout<<endl;
		for(int i=0;i<arg3.length();i++) cout<<val3[i]<<" ";
				cout<<endl;
		
		for(int i=0;i<arg1.length();i++) if(val1[i] >= base) return 0;		
		for(int i=0;i<arg2.length();i++) if(val2[i] >= base) return 0;		
		for(int i=0;i<arg3.length();i++) if(val3[i] >= base) return 0;		
		
		if(sum(val1,val2,val3,0,0,base)) return 1;
		return 0;
	}
	
	vector<int> getBase(string equation){
		vector<int> retval;
		int i,plus = 0,eq = 0;
		string str1,str2,str3;
		for(i=0;i<equation.length();i++){
			if(equation[i] == '+'){
				str1 = equation.substr(0,i);
				plus = i;
			}
			if(equation[i] == '='){
				str2 = equation.substr(plus+1,i - plus - 1);
				eq = i;
			}
		}
		str3 = equation.substr(eq+1);
		cout<<str1<<" "<<str2<<" "<<str3<<endl;
		for(i=2;i<=20;i++) if(check(i,str1,str2,str3)) retval.push_back(i);
		return retval;
	}

	start{
	return 0;
}
