#include <iostream>
#include <vector>

using namespace std;

class RecurrenceRelation{
	public:
		vector<int> X;
		vector<int> co;
		
		int find_x(int N,int K){
			if(N<K){
				if(X[N] > 10) return X[N]%10;
				else return 10 + (X[N]%10);
			}
			int retval = 0;
			while(X.size() < N) X.push_back(find_x(X.size(),K));
			
			for(int i = 0;i<K;i++){
				retval+=(X[N - K + i]*co[i]);
				retval%=10;
			}
			cout<<retval<<endl;
			if(retval < 0) retval+=10;
			cout<<retval<<endl;
			return retval;	
		}
		
		int moduloTen(vector<int> coefficients,vector<int> initial,int N){
			
			for(int i = 0;i<coefficients.size();i++){
				co.push_back(coefficients[i]%10);
				X.push_back(initial[i]%10);
			}
			
			return find_x(N,coefficients.size());
		}
};