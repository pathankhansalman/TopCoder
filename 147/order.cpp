#include <iostream>
#include <string>

using namespace std;

string order(int numMales,int numFemales,int K){
	string retval = "";
	char m = 'M';
	int init = 0,a = numMales,b = numFemales, c = K,tot = a+b;
	int removed[tot];
	int i = 0;

	while(tot--){
		retval.push_back(m);
		removed[i] = 0;
		i++;
	}

	tot = a+b;
	
	while(b--){
		c = K;
		c--;
		
		while(c--){
			
			if(init>=tot) init = 0;
			
			init++;
			
			if(init>=tot) init = 0;
			
			while(removed[init]) init++;
		}

		if(init>=tot) init = init - tot;
		
		removed[init]++;
		
		while(removed[init]) init++;
	}
	
	for (i = 0; i < tot; ++i)
	{
		if(removed[i]) retval[i] = 'F';
	}
	
	return retval;
}

int main(){
	int m,f,k;
	cin>>m>>f>>k;
	cout<<order(m,f,k)<<endl;
	return 0;
}
