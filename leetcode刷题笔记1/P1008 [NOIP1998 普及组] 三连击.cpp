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
//	for (int i = 1; i < 4; i++)
//	{
//		vector<int>count(10, 0);
//		count[i] = 1;
//		for (int j = 1; j < 10; j++)
//		{
//			if (j == i)continue;
//			count[j] = 1;
//			for (int u = 1; u < 10; u++) {
//				if (u == j || u == i)continue;
//				count[u] = 1;
//				vector<int>cnt = count;
//				int cur = u + j * 10 + i * 100;
//				int cur2 = 2 * cur;
//				int cur3 = 3 * cur;
//				if (cur3 > 987)return 0;
//				bool match = true;
//				for (int k = 0; k < 3 && match; k++) {
//					int a = cur2 % 10, b = cur3 % 10;
//					if (cnt[a] == 0 && cnt[b] == 0 && a != 0 && b != 0) {
//						cnt[a] = 1;
//						cnt[b] = 1;
//					}
//					else {
//						match = false;
//						break;
//					}
//					cur2 /= 10;
//					cur3 /= 10;
//				}
//				if (match) {
//					cout << cur << " " << cur * 2 << " " << cur * 3 << endl;
//				}
//				count[u] = 0;
//			}
//			count[j] = 0;
//		}
//		count[i] = 0;
//	}
//	return 0;
//}