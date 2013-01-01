#include <iostream>
#include <math.h>

using namespace std;

long long mini(long long a,long long b){
	if(a<b) return a;
	return b;
}
	
long long countRectangles(long long width,long long height){
	long long retval,temp,curr,retval2;
		
	retval = (width+1)*width*(height+1)*height/4;
	temp = mini(width,height);
	curr = (long long)fabs(width - height);
	retval2 = curr*temp*(temp+1)/2;
	retval2 += temp*(temp + 1)*(2*temp + 1)/6;
		
	return (retval - retval2);
}

int main(){
	long long w,h;
	cin>>w>>h;
	cout<<countRectangles(w,h)<<endl;

	return 0;
}
