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
//string input;
//int n;
//int v[500];
//int ans[500];
//int main() {
//	cin >> input >> n;
//	int len = input.length();
//	for (int i = 0; i < input.length(); i++)
//	{
//		v[i] = input[i] - '0';
//	}
//	int idx = 0, pre = 0;
//	for (int i = 1; i <= len - n; i++)
//	{
//		int minn = INT_MAX;
//		for (int j = pre; j < n + i && j < len; j++)
//		{
//			if (v[j] < minn) {
//				minn = v[j];
//				pre = j + 1;
//			}
//		}
//		ans[idx++] = minn;
//	}
//	bool flag = false;
//	for (int i = 0; i < len - n; i++)
//	{
//		if (ans[i] != 0) {
//			printf("%d", ans[i]);
//			flag = true;
//		}
//	}
//	if (!flag) {
//		cout << 0 << endl;
//	}
//	return 0;
//}