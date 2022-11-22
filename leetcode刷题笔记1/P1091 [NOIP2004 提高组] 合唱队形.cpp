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
//int leftToRight[105], rightToLeft[105];
//int height[105];
//int main() {
//	int n;
//	cin >> n;
//	fill(leftToRight, leftToRight + 105, 1);
//	fill(rightToLeft, rightToLeft + 105, 1);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> height[i];
//	}
//	for (int i = 1; i < n; i++)
//	{
//		for (int j = 0; j < i; j++) {
//			if (height[i] > height[j]) {
//				leftToRight[i] = max(leftToRight[i], leftToRight[j] + 1);
//			}
//		}
//	}
//	for (int i = n - 2; i >= 0; i--)
//	{
//		for (int j = n - 1; j > i; j--) {
//			if (height[i] > height[j]) {
//				rightToLeft[i] = max(rightToLeft[i], rightToLeft[j] + 1);
//			}
//		}
//	}
//	int maxn = INT_MIN;
//	for (int i = 0; i < n; i++)
//	{
//		maxn = max(maxn, leftToRight[i] + rightToLeft[i]);
//	}
//	cout << n - (maxn - 1) << endl;
//	return 0;
//}