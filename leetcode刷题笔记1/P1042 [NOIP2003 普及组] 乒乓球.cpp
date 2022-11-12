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
//int hua11 = 0, ding11 = 0;
//int hua21 = 0, ding21 = 0;
//vector<string>out21;
//int main() {
//	string s;
//	while (true) {
//		cin >> s;
//		for (char ch : s)
//		{
//			if (ch == 'E') {
//				printf("%d:%d\n\n", hua11, ding11);
//				for (int i = 0; i < out21.size(); i++)
//				{
//					printf("%s\n", out21[i].c_str());
//				}
//				printf("%d:%d\n", hua21, ding21);
//				return 0;
//			}
//			if (ch == 'W') {
//				hua11++;
//				hua21++;
//				if (hua11 >= 11 && hua11 - ding11 >= 2) {
//					printf("%d:%d\n", hua11, ding11);
//					hua11 = 0;
//					ding11 = 0;
//				}
//				if (hua21 >= 21 && hua21 - ding21 >= 2) {
//					string temp = to_string(hua21) + ":" + to_string(ding21);
//					out21.push_back(temp);
//					hua21 = 0;
//					ding21 = 0;
//				}
//			}
//			else {
//				ding11++;
//				ding21++;
//				if (ding11 >= 11 && ding11 - hua11 >= 2) {
//					printf("%d:%d\n", hua11, ding11);
//					ding11 = 0;
//					hua11 = 0;
//				}
//				if (ding21 >= 21 && ding21 - hua21 >= 2) {
//					string temp = to_string(hua21) + ":" + to_string(ding21);
//					out21.push_back(temp);
//					hua21 = 0;
//					ding21 = 0;
//				}
//			}
//		}
//	}
//	return 0;
//}