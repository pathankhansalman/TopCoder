#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int monthlyOrder(vector<int> sales, vector<int> daysAvailable){
		int retval;
		int corr,i,length = sales.size(),diff = 0;
		double avg,curr,sum = 0.0;
		for(i=0;i<length;i++){
			if(sales[i] == 0) diff++;
			else{
				curr = (30.0*sales[i])/(1.0*daysAvailable[i]);
				sum+=curr;
			}
		}
		avg = sum/(length - diff);
		corr = (int)(sum/(length - diff));
		double d;
		d = avg - (1.0)*corr;
		if(d == 0) retval = corr;
		else retval = corr+1; 
		return retval;
	}

int main(){
	vector<int> s,d;
	cout<<monthlyOrder(s,d)<<endl;
	return 0;
}
