#include <iostream>
#include <vector>
#include <string>

using namespace std;

string bestItem(vector<int> costs, vector<int> prices, vector<int> sales, vector<string> items){
		int i,length = costs.size();
		string retval = "";
		int profits[length];
		for(i =0 ;i<length;i++) profits[i] = sales[i]*(prices[i] - costs[i]);
		int max = 0,maxin = -1;
		for(i=0;i<length;i++){
			if(profits[i] > max){
				max = profits[i];
				maxin = i;
			}
		}
		if(maxin != -1) retval = items[maxin];
		return retval;
	}

int main(){
	vector<int> a,b,c;
	vector<string> d;
	cout<<bestItem(a,b,c,d)<<endl;
	return 0;
}
