#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int ADJ[55][55],val[55][55],visited[55],parent[55],distance[55];

void init(){
	int i,j;
	
	for(i=0;i<55;i++){
		for(j=0;j<55;j++){
			ADJ[i][j] = 0;
			val[i][j] = 0;
		}
			parent[i] = 0;
			visited[i] = 0;
			distance[i] = 0;
	}
}

void findVal(int N){
	for(i=N;i<55;i++){
		if(Adj[N][i]){
			distance[i] = val[N][i] + distance[N];
			findVal(i);
		}
	}
}

int estimateTimeOut(vector<int> fromJunction,vector<int> toJunction,vector<int> ductLength){
	int sum = 0,i,retval,length = fromJunction.size();
	init();
	
	for(i=0;i<length;i++){
		ADJ[fromJunction[i]][toJunction[i]] = 1;
		parent[toJunction[i]] = fromJunction[i];
		val[fromJunction[i]][toJunction[i]] = ductLength[i];
		sum+=ductLength[i];
	}
	findVal(0);
	int max = 0;
	for(i=0;i<55;i++) if(distance[i]>max) max = distance[i];
	return (2*sum) - max;
}

int main(){
	return 0;
}

