#include <iostream>
#include <vector>

using namespace std;

int max(int a,int b){
		if(a>b) return a;
		return b;
	}
	
	int days(vector<int> arrivals,int numPerDay){
		int count = 0,curr,i,length = arrivals.size();
		for(i=0;i<length;i++){
			if(i==length - 1){
				curr = arrivals[i]/numPerDay;
				count+=curr;
				if(arrivals[i] > curr*numPerDay) count++;
				break;
			}
			if(arrivals[i]!=0){
				count++;
				arrivals[i] = max(arrivals[i] - numPerDay,0);
			}
			if(i!=length - 1){
				arrivals[i+1] = arrivals[i] + arrivals[i+1];
			}
		}
		return count;
	}

	int main(){
		int n,curr;
		vector<int> arr;
		cin>>n;
		while(cin>>curr) arr.push_back(curr);
		cout<<days(arr,n)<<endl;
		return 0;
	}


