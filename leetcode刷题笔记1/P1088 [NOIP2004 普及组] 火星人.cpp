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
//int n, m;
//vector<int>v;
//vector<bool>flag;
//int findFlexible(int begin) {
//	int minNum = INT_MAX, minIndex = -1;
//	for (int i = begin + 1; i < n; i++)
//	{
//		if (flag[i] == false && v[i] > v[begin]) {
//			if (v[i] < minNum) {
//				minNum = v[i];
//				minIndex = i;
//			}
//		}
//	}
//	if (minNum == INT_MAX) {
//		return -1;
//	}
//	return minIndex;
//}
//int main() {
//	cin >> n >> m;
//	v.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//	}
//	while (m > 0) {
//		flag.assign(n, true);
//		for (int i = n - 1; i >= 0; i--)
//		{
//			int notMarked = findFlexible(i);
//			if (notMarked == -1) {
//				flag[i] = false;
//				continue;
//			}
//			swap(v[i], v[notMarked]);
//			sort(v.begin() + i + 1, v.end());
//			break;
//		}
//		m--;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", v[i]);
//	}
//	printf("\n");
//
//	return 0;
//}