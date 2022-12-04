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
//int n, m;
//int v[55][55];
//int f[55][55][55][55];
//int main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++) {
//			scanf_s("%d", &v[i][j]);
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			for (int k = 1; k <= n; k++)
//			{
//				for (int u = j + 1; u <= m; u++)
//				{
//					f[i][j][k][u] = max(max(f[i][j - 1][k][u - 1], f[i - 1][j][k - 1][u]),
//						max(f[i][j - 1][k - 1][u], f[i - 1][j][k][u - 1])) + v[i][j] + v[k][u];
//				}
//			}
//		}
//	}
//	cout << f[n][m - 1][n - 1][m] << endl;
//	return 0;
//}