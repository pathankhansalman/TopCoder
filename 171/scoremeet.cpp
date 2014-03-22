#include <iostream>
#include <string>

using namespace std;

class CrossCountry{
	public:
		string scoreMeet(int numTeams, string finishOrder){
			string retval;
			int score[26],score2[26],score3[26],ranks[numTeams];
			for(int i = 0;i<26;i++){
				score[i] = 0;
				score3[i] = 0;
			}
			
			for(int i = 0;i<finishOrder.length();i++){
				score[(int)finishOrder[i] - (int)('A')]++;
				if(score[(int)finishOrder[i] - (int)('A')] <= 5) score3[(int)finishOrder[i] - (int)('A')]+=(i+1);
			}
			
			for(int i = 0;i<26;i++) score2[i] = score3[i];
			for(int i = 0;i<numTeams;i++) ranks[i] = -1;
			int nt = numTeams;
			while(nt--){
				int min = 100000,minind = 0,flag = 0;
				for(int i = 0;i<26;i++){
					if(score3[i]<min && score3[i]>0){
						min = score3[i];
						minind = i;
						flag = 1;
					}
				}
				if(flag){score3[minind] = 1000000;ranks[numTeams - nt - 1] = minind;}
				//cout<<ranks[numTeams - nt - 1]<<endl;
			}
			for(int i = 0;i<numTeams-1;i++){
				cout<<score2[ranks[i]]<<" "<<score2[ranks[i+1]]<<endl;
				if(score2[ranks[i]] == score2[ranks[i+1]]){
					if(score[ranks[i]] >= 6 && score[ranks[i+1]] >= 6){
						if(finishOrder.find((char)(ranks[i] - (int)('A'))) > finishOrder.find((char)(ranks[i+1] - (int)('A')))){
							int temp = ranks[i];
							ranks[i] = ranks[i+1];
							ranks[i+1] = temp;
						}
					}
					else if(score[ranks[i+1]] >= 6){
						int temp = ranks[i];
						ranks[i] = ranks[i+1];
						ranks[i+1] = temp;
					}
				}
			}
			
			for(int i = 0;i<numTeams;i++){
				if(ranks[i]>=0 && score[ranks[i]]>=5){
					retval.push_back((char)(ranks[i] + (int)('A')));
				}
			}
			
			return retval;
		}
};