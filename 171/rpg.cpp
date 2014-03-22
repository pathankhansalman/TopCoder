#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class RPG{
	public:
		vector<int> dieRolls(vector<string> dice){
			vector<int> retval;
			int min = 0,max = 0;
			float avg = 0.0;
			for(int i = 0;i<dice.size();i++){
				string str = dice[i];
				int pos = 0;
				for(int j = 0;j<str.length();j++){
					if(str[j] == 'd'){
						pos = j;
						break;
					}
				}
				int a = atoi(str.substr(0,pos).c_str());
				int b = atoi(str.substr(pos+1).c_str());
				min+=a;
				max+=(a*b);
				avg+=(a*(b+1)/2.);
			}
			retval.push_back(min);
			retval.push_back(max);
			retval.push_back(avg);
			return retval;
		}
};