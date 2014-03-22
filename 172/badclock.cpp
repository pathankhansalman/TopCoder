#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
using namespace std;

class BadClock{
	public:
		double secdiff(string trueTime, string skewTime){
			double retval = 0.0;
			retval+=((atoi(trueTime.substr(0,2).c_str())-atoi(skewTime.substr(0,2).c_str()))*3600);
			retval+=((atoi(trueTime.substr(3,2).c_str())-atoi(skewTime.substr(3,2).c_str()))*60);
			retval+=(atoi(trueTime.substr(6,2).c_str())-atoi(skewTime.substr(6,2).c_str()));
			return retval;
		}
		
		double nextAgreement(string trueTime, string skewTime,int hourlyGain){
			double retval = 0.0;
			if(trueTime == skewTime) return retval;
			double diff = secdiff(trueTime,skewTime);
			cout<<diff<<endl;
			if(diff*hourlyGain>0) retval = diff*1.0/hourlyGain;
			else retval = (43200-fabs(diff))/(fabs(hourlyGain));
			return retval;
		}
};