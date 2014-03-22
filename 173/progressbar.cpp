#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ProgressBar{
	public:
		string showProgress(vector<int> taskTimes,int tasksCompleted){
			int time = 0,fulltime = 0;
			double percent = 0.0;
			for(int i = 0;i<tasksCompleted;i++) time+=taskTimes[i];
			for(int i = 0;i<taskTimes.size();i++) fulltime+=taskTimes[i];
			percent = time*100.0/fulltime;
			int num1 = percent/5,num2 = 20 - num1;
			string retval = "";
			for(int i = 0;i<num1;i++) retval.push_back('#');
			for(int i = 0;i<num2;i++) retval.push_back('.');
			return retval;
		}
};