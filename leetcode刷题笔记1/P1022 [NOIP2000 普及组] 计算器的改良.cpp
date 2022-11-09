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
//	int coeffient = 0, value = 0;
//	string input;
//	cin >> input;
//	int equal = input.find('=');
//	string pre = input.substr(0, equal + 1);
//	string post = input.substr(equal + 1);
//	int symbol = 0, num = 0;
//	bool hasCoeffient = false;
//	char x = 'x';
//	for (int i = 0; i < pre.size(); i++)
//	{
//		if (pre[i] == '-' || pre[i] == '+' || pre[i] == '=') {
//			if (num != 0) {
//				if (symbol != -1) {
//					num = -num;
//				}
//				value += num;
//			}
//			num = 0;
//			hasCoeffient = false;
//			symbol = (pre[i] == '-' ? -1 : 1);
//		}
//		else if (pre[i] >= '0' && pre[i] <= '9') {
//			num = num * 10 + pre[i] - '0';
//			hasCoeffient = true;
//		}
//		else if (pre[i] >= 'a' && pre[i] <= 'z') {
//			x = pre[i];
//			if (num == 0 && !hasCoeffient)num = 1;
//			if (symbol == -1) {
//				num = -num;
//			}
//			coeffient += num;
//			num = 0;
//			symbol = 0;
//			hasCoeffient = false;
//		}
//	}
//	for (int i = 0; i < post.size(); i++)
//	{
//		if (post[i] == '-' || post[i] == '+' || post[i] == '=') {
//			if (num != 0) {
//				if (symbol == -1) {
//					num = -num;
//				}
//				value += num;
//			}
//			num = 0;
//			hasCoeffient = false;
//			symbol = (post[i] == '-' ? -1 : 1);
//		}
//		else if (post[i] >= '0' && post[i] <= '9') {
//			num = num * 10 + post[i] - '0';
//			hasCoeffient = true;
//		}
//		else if (post[i] >= 'a' && post[i] <= 'z') {
//			if (num != 0 && !hasCoeffient) {
//				if (symbol != -1) {
//					num = -num;
//				}
//			}
//			coeffient += num;
//			num = 0;
//			hasCoeffient = false;
//			symbol = 0;
//		}
//	}
//	if (num != 0) {
//		if (symbol == -1) {
//			num = -num;
//		}
//		value += num;
//	}
//	double ans = value * 1.0 / coeffient;
//	if (ans == -0.0) ans = 0;//特判，将-0.0改为0
//	cout << x << "=";
//	printf("%.3f", ans);
//	return 0;
//}