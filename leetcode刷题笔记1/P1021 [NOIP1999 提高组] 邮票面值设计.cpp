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
//bool judge(int value, int limited, vector<int>stamp) {
//	int cur = stamp.size() - 1;
//	while (value > 0 && limited > 0) {
//		if (value >= stamp[cur]) {
//			value -= stamp[cur];
//			limited--;
//		}
//		else {
//			cur--;
//		}
//	}
//	if (value == 0) {
//		return true;
//	}
//	return false;
//}
//int maxCurrencyValue = INT_MIN;
//vector<int>maxCurrencyValueKind;
//void dfs(int curValue, vector<int>stamp, int limited, int remainKind, int curMaximumRange) {
//	while (true) {
//		curValue++;
//		stamp.push_back(curValue);
//		int nextMaximumRange = curMaximumRange + 1;
//		if (judge(nextMaximumRange, limited, stamp)) {
//			while (judge(nextMaximumRange, limited, stamp)) nextMaximumRange++;
//			if (nextMaximumRange - 1 >= maxCurrencyValue) {
//				maxCurrencyValue = nextMaximumRange - 1;
//				maxCurrencyValueKind = stamp;
//			}
//			if (remainKind - 1 > 0) {
//				dfs(curValue, stamp, limited, remainKind - 1, nextMaximumRange - 1);
//			}
//			stamp.pop_back();
//		}
//		else {
//			break;
//		}
//	}
//}
//int main() {
//	int n, k;//¿ÉÕ³ÌùNÕÅÓÊÆ±£¬KÖÖÓÊÆ±
//	cin >> n >> k;
//	vector<int>stamp(1, 1);
//	dfs(1, stamp, n, k - 1, n);
//	for (int i = 0; i < maxCurrencyValueKind.size(); i++)
//	{
//		if (i != 0) {
//			printf(" ");
//		}
//		printf("%d", maxCurrencyValueKind[i]);
//	}
//	printf("\nMAX=%d", maxCurrencyValue);
//	return 0;
//}