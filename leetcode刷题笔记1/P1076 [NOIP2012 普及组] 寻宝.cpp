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
//int hasStairway[10005][105];
//int x[10005][105];
//vector<int>stairwayNum;
//int main() {
//	int n, m, begin;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		int num = 0;
//		for (int j = 0; j < m; j++) {
//			scanf_s("%d %d", &hasStairway[i][j], &x[i][j]);
//			if (hasStairway[i][j])num++;
//		}
//		stairwayNum.push_back(num);
//	}
//	cin >> begin;
//	int key = 0;
//	for (int i = 0; i < n; i++)
//	{
//		key = (key + x[i][begin]) % 20123;
//		int cnt = (x[i][begin] - 1) % stairwayNum[i] + 1;
//		int nxt = begin;
//		if (hasStairway[i][nxt] == 1)cnt--;
//		while (cnt > 0) {
//			nxt = (nxt + 1) % m;
//			if (hasStairway[i][nxt] == 1) {
//				cnt--;
//			}
//		}
//		begin = nxt;
//	}
//	cout << key << endl;
//	return 0;
//}