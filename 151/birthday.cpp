#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#define DEBUG 0

using namespace std;

string getNext(string date,vector<string> birthdays){
		int i,j,length = birthdays.size();
		int difference[length];
		int days[12];
		for(i=0;i<12;i++){
			if(i == 2) days[i] = 28;
			else if(i<=7){
				if(i%2 == 1) days[i] = 31;
				else days[i] = 30;
			}
			else{
				if(i%2 == 0) days[i] = 31;
				else days[i] = 30;
			}
		}
		if(DEBUG) cout<<"lno 24"<<endl;
		int curr_date,curr_mnth,frien_date,frien_mnth;
		for(i=0;i<length;i++){
			curr_mnth = atoi(date.substr(0,2).c_str());
			curr_date = atoi(date.substr(3,2).c_str());
			frien_mnth = atoi(birthdays[i].substr(0,2).c_str());
			frien_date = atoi(birthdays[i].substr(3,2).c_str());
			if(DEBUG) cout<<"lno 31"<<endl;
			if(frien_mnth < curr_mnth){
				difference[i] = 0;
				for(j=0;j<frien_mnth - 1;j++) difference[i]+=days[j];
				for(j=curr_mnth;j<12;j++) difference[i]+=days[j];
				difference[i]+=frien_date;
				difference[i]+=(days[curr_mnth - 1] - curr_date);
			}
			else if(curr_mnth < frien_mnth){
				difference[i] = 0;
				for(j = curr_mnth;j<frien_mnth-1;j++) difference[i]+=days[j];
				difference[i]+=frien_date;
				difference[i]+=(days[curr_mnth - 1] - curr_date);
			}
			else{
				if(frien_date>=curr_date){
					difference[i] = 0;
					difference[i] += (frien_date - curr_date);
				}
				else{
					difference[i] = 0;
					difference[i]+=(365 - days[curr_mnth - 1]);
					difference[i]+= frien_date;
					difference[i]+=(days[curr_mnth - 1] - curr_date);
				}
			}
		}
		int min = 800,minindex = 0;
		for(i=0;i<length;i++){
			if(difference[i]<min){
				minindex = i;
				min = difference[i];
			}
		}
		if(DEBUG) cout<<"lno 65"<<endl;

		return birthdays[minindex].substr(0,5);
	}

int main(){
	string str;
	cin>>str;
	string bd;
	vector<string> v;
	while(cin>>bd) v.push_back(bd);
	cout<<getNext(str,v)<<endl;
	return 0;
}
