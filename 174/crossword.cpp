#include <iostream>
#include <string>
#include <vector>

using namespace std;

//class CrossWord{
	//public:
	int countSubstring(const std::string& str, const std::string& sub)
{
    if (sub.length() == 0) return 0;
    int count = 0;
    for (size_t offset = str.find(sub); offset != std::string::npos;
	 offset = str.find(sub, offset + sub.length()))
    {
        ++count;
    }
    return count;
}
	int countWords(vector<string> board,int size){
		int size2 = size;
		string required = "";
		int count = 0;

		while(size2--) required.push_back('.');
		int found = 0,length = 0;
		for(int i = 0;i<board.size();i++){
			count+=countSubstring(board[i],required);
		}
		return count;
	}
//};

int main(){
	int length;
	cin>>length;
	vector<string> board;
	string curr;
	while(cin>>curr){
		if(curr == "-1") break;
		board.push_back(curr);
	}
	cout<<countWords(board,length)<<endl;
	return 0;
}