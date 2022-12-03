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
//int m, s, c;//木板最大的数目、牛棚的总数、牛的总数
//int v[250];
//int space[250];
//int main() {
//	cin >> m >> s >> c;
//	for (int i = 0; i < c; i++) {
//		scanf_s("%d", &v[i]);
//	}
//	if (m >= c) {
//		printf("%d", c);
//		return 0;
//	}
//	sort(v, v + c);
//	int ans = v[c - 1] - v[0] + 1;
//	for (int i = 1; i < c; i++) {
//		space[i - 1] = v[i] - v[i - 1] - 1;
//	}
//	sort(space, space + c, greater<int>());
//	for (int i = 0; i < m - 1; i++)
//	{
//		ans -= space[i];
//	}
//	printf("%d", ans);
//	return 0;
//}