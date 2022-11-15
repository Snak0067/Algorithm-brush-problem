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
//
//int main() {
//	int p1, p2, p3;
//	cin >> p1 >> p2 >> p3;
//	string s, ans;
//	cin >> s;
//	bool match = false;
//	for (int i = 0; i < s.length(); i++)
//	{
//		if (match == false) {
//			if (s[i] == '-') {
//				match = true;
//			}
//			else {
//				ans.push_back(s[i]);
//			}
//			continue;
//		}
//		else {
//			if (s[i] == '-') {
//				ans.push_back('-');
//				ans.push_back('-');
//				match = false;
//				continue;
//			}
//			else {
//				char before = ans.back();
//				char next = s[i];
//				if (islower(before) && islower(next) || isdigit(before) && isdigit(next)) {
//					if (next <= before) {
//						ans.push_back('-');
//					}
//					else if (next - before == 1) {}
//					else {
//						if (p1 == 3) {
//							for (int j = 0; j < (next - before) * p2; j++)
//							{
//								ans.push_back('*');
//							}
//						}
//						else {
//							if (p3 == 2) {
//								for (char ch = next - 1; ch > before; ch--)
//								{
//									for (int j = 0; j < p2; j++)
//									{
//										if (p1 == 1) {
//											ans.push_back(tolower(ch));
//										}
//										else {
//											ans.push_back(toupper(ch));
//										}
//									}
//								}
//							}
//							else {
//								for (char ch = before + 1; ch < next; ch++)
//								{
//									for (int j = 0; j < p2; j++)
//									{
//										if (p1 == 1) {
//											ans.push_back(tolower(ch));
//										}
//										else {
//											ans.push_back(toupper(ch));
//										}
//									}
//								}
//							}
//						}
//					}
//					ans.push_back(next);
//					match = false;
//				}
//				else {
//					match = false;
//					ans.push_back('-');
//					ans.push_back(next);
//				}
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}