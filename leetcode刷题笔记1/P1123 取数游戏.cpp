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
//struct p {
//	int val, x, y;
//};
//bool cmp(p p1, p p2) {
//	return p1.val > p2.val;
//}
//int vis[25][10][10];
//vector<p>v;
//void paint(int t, int n, int m, int x, int y) {
//	for (int i = max(0, x - 1); i < min(n, x + 2); i++)
//	{
//		for (int j = max(0, y - 1); j < min(m, y + 2); j++)
//		{
//			vis[t][i][j] = 1;
//		}
//	}
//}
///*
//  ���ʹ��̰�ķ���ÿ��ȥ���ֵ����ô���Է��������⡣
//  ��Ϊÿȡһ���������ڵ����Ͳ�����ȡ����ôÿ�ξ��߾ͻ�Ӱ���´ν����
//  �Ӷ�����̰�ľ��߲������Ż���
//*/
//void Non_optimal_solution() {
//	int t, n, m;
//	cin >> t;
//	for (int u = 0; u < t; u++)
//	{
//		cin >> n >> m;
//		v.clear();
//		v.resize(n * m);
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++)
//			{
//				cin >> v[i * m + j].val;
//				v[i * m + j].x = i;
//				v[i * m + j].y = j;
//			}
//		}
//		sort(v.begin(), v.end(), cmp);
//		int cnt = 0;
//		for (int i = 0; i < n * m; i++)
//		{
//			if (vis[u][v[i].x][v[i].y])continue;
//			cnt += v[i].val;
//			paint(u, n, m, v[i].x, v[i].y);
//		}
//		printf("%d\n", cnt);
//	}
//}
//
//int nn, mm, tt, maxn = 0;
//int temp = 0;
//int num[25][25];
//int dir[8][2] = { {0,1},{0,-1},{1,1},{1,-1},{1,0},{-1,0},{-1,1},{-1,-1} };
//void dfs(int u, int x, int y) {
//	//��y���߽�ʱ��������һ�� 
//	if (y == mm) {
//		dfs(u, x + 1, 0);
//		return;
//	}
//	//��x���߽�ʱ������������ˢ�����ֵ 
//	if (x == nn) {
//		maxn = max(maxn, temp);
//		return;
//	}
//	//��ȡ����
//	dfs(u, x, y + 1);
//	//ȡ���������
//	//1�������ж��Ƿ����
//	if (vis[u][x][y] == 0) {
//		temp += num[x][y];
//		for (int i = 0; i < 8; i++)
//		{
//			int newx = x + dir[i][0];
//			int newy = y + dir[i][1];
//			vis[u][newx][newy]++;
//		}
//		dfs(u, x, y + 1);
//		temp -= num[x][y];
//		for (int i = 0; i < 8; i++)
//		{
//			int newx = x + dir[i][0];
//			int newy = y + dir[i][1];
//			vis[u][newx][newy]--;
//		}
//	}
//}
//void optimal_solution() {
//	cin >> tt;
//	for (int u = 0; u < tt; u++)
//	{
//		cin >> nn >> mm;
//		maxn = 0;
//		temp = 0;
//		v.clear();
//		v.resize(nn * mm);
//		for (int i = 0; i < nn; i++) {
//			for (int j = 0; j < mm; j++)
//			{
//				cin >> num[i][j];
//			}
//		}
//		dfs(u, 0, 0);
//		printf("%d\n", maxn);
//	}
//}
//int main() {
//	optimal_solution();
//	return 0;
//}