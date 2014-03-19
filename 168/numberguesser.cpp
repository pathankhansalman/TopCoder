#include <iostream>
#include <string>

using namespace std;

class NumberGuesser{
	public:
		int guess(string leftOver){
			int sum = 0;
			for(int i = 0;i<leftOver.length();i++){
				sum+=(leftOver[i] - '0');
			}
			return (9 - (sum%9));
		}
};