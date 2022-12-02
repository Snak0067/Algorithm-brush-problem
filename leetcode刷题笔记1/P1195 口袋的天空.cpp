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
//int n, m, k;
//int f[1005];
//struct nod {
//	int x, y, w;
//}v[10005];
//bool cmp(nod n1, nod n2) {
//	return n1.w < n2.w;
//}
//int getf(int x) {
//	if (f[x] == x)return x;
//	f[x] = getf(f[x]);
//	return f[x];
//}
//int main() {
//	int ans = 0;
//	cin >> n >> m >> k;
//	for (int i = 0; i < m; i++)
//	{
//		scanf_s("%d%d%d", &v[i].x, &v[i].y, &v[i].w);
//	}
//	sort(v, v + m, cmp);
//	for (int i = 0; i < n; i++)f[i] = i;
//	for (int i = 0; i < m && n > k; i++)
//	{
//		int x = getf(v[i].x);
//		int y = getf(v[i].y);
//		if (x != y) {
//			f[x] = y;
//			n--;
//			ans += v[i].w;
//		}
//	}
//	if (n > k) {
//		printf("No Answer");
//	}else{
//		printf("%d", ans);
//	}
//	return 0;
//}