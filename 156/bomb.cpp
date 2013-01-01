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

bool valid(int a,int b,vector<string> board){
		if(a<0 || b<0) return 0;
		else if(a >= board[0].length() || b>= board.size()) return 0;
		return 1;
	}
	double winPercentage(vector<string> board){
		double retval;
		int i,j,k,l,flag,cl = 0,ct = 0;
		char A[board[0].length()][board.size()];
		for(i=0;i<board[0].length();i++){
			for(j=0;j<board.size();j++) A[i][j] = board[j][i];
		}
		for(i=0;i<board[0].length();i++){
			for(j=0;j<board.size();j++){
				flag = 0;
				for(k = -1;k<=1;k++) for(l = -1;l<=1;l++) if(valid(i+k,j+l,board)) if(A[i+k][j+l] == 'B') flag++;
				if(flag){
					if(A[i][j] == 'B'){
						cl++;
						ct++;
					}
				}
				else ct++;
			}
		}
		cout<<cl<<" "<<ct<<endl;
		retval = 100*(ct - cl)*1.0/ct;
		return retval;
	}

start{
	return 0;
}