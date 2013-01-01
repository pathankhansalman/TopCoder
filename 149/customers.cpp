#include <iostream>
#include <vector>

using namespace std;

int max(int a,int b){
		if(a>b) return a;
		else return b;
	}

	int maxWait(vector<int> arrival, vector<int> service){
		int j,i,ncust = arrival.size(),waiting[ncust];
		for(i=0;i<ncust;i++) waiting[i] = 0;
		// waiting time [i] = (arrival time [j] + service time [j] - arrival time [i]) for all j where arrival time [j] < arrival time [i] or 
		// arrival time [j] = arrival time [i] && index[j] < index [i]
		for(i=0;i<ncust;i++){
			for(j=0;j<=i;j++){
				if(arrival[j] < arrival[i]) waiting[i]=max((arrival[j] + waiting[j] + service[j] - arrival[i]),0);
				if((arrival[j] == arrival[i]) && (j<i)) waiting[i]+=service[j];
			}
		}
		int max = 0;
		for(i=0;i<ncust;i++){
			if(waiting[i] > max) max = waiting[i];
		}
		return max; 
	}

	int main(){
		vector<int> arr,ser;
		int arrival,service;
		
		while(cin>>arrival>>service){
			arr.push_back(arrival);
			ser.push_back(service);
		}

		return 0;
	}
	
