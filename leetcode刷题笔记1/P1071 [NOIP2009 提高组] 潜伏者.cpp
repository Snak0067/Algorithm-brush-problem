//#include<iostream>
//#include<unordered_map>
//#include<set>
//#include<vector>
//#include<string>
//#include<cmath>
//#include<algorithm>
//#include<map>
//#include<stack>
//#include<unordered_set>
//#include<queue>
//#include<limits.h>
//using namespace std;
//int main() {
//	vector<char>mapping(27, -1), origin(27, -1);
//	string encriperedMsg, primeInfo, askMsg;
//	cin >> encriperedMsg >> primeInfo >> askMsg;
//	for (int i = 0; i < primeInfo.size(); i++)
//	{
//		origin[primeInfo[i] - 'A'] = primeInfo[i];
//		if (mapping[encriperedMsg[i] - 'A'] == -1) {
//			mapping[encriperedMsg[i] - 'A'] = primeInfo[i];
//		}
//		else {
//			if (mapping[encriperedMsg[i] - 'A'] != primeInfo[i]) {
//				printf("Failed");
//				return 0;
//			}
//		}
//	}
//	for (int i = 0; i < 26; i++)
//	{
//		if (origin[i] == -1) {
//			printf("Failed");
//			return 0;
//		}
//	}
//	for (int i = 0; i < askMsg.size(); i++)
//	{
//		cout << mapping[askMsg[i] - 'A'];
//	}
//	return 0;
//}