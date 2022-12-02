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
//int a, b, minn = 0;
//struct nod {
//	int x, y, w;
//};
//vector<nod>v;
//int f[1005];
//int getf(int x) {
//	if (f[x] == x)return x;
//	f[x] = getf(f[x]);
//	return f[x];
//}
//bool cmp(nod n1, nod n2) {
//	return n1.w < n2.w;
//}
//int main() {
//	cin >> a >> b;
//	int w;
//	for (int i = 0; i < b; i++)
//	{
//		for (int j = 0; j < b; j++) {
//			scanf_s("%d", &w);
//			if (i >= j || w == 0)continue;
//			if (w >= a)minn++;
//			v.push_back({ i,j,w });
//		}
//	}
//	for (int i = 0; i < b; i++)
//	{
//		f[i] = i;
//	}
//	sort(v.begin(), v.end(), cmp);
//	int ans = 0, num = 0;
//	for (int i = 0; i < v.size() - minn; i++)
//	{
//		int x = getf(v[i].x);
//		int y = getf(v[i].y);
//		if (x != y) {
//			f[x] = y;
//			ans += v[i].w;
//			num++;
//		}
//	}
//	if (num == b - 1) {
//		ans += a;
//	}
//	else {
//		ans += (b - num) * a;
//	}
//	printf("%d", ans);
//	return 0;
//}