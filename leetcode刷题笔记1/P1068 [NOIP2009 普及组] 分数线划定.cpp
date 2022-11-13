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
//struct p
//{
//	int k, s;
//	p() {}
//};
//vector<p>v;
//bool cmp(p p1, p p2) {
//	if (p1.s != p2.s)	return p1.s > p2.s;
//	return p1.k < p2.k;
//}
//int main() {
//	int n, m;
//	cin >> n >> m;
//	m = int(m * 1.0 * 1.5);
//	v.assign(n, p());
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i].k >> v[i].s;
//	}
//	sort(v.begin(), v.end(), cmp);
//	int minimumPassingScore = v[m - 1].s;
//	while (m <= n && v[m].s == minimumPassingScore) {
//		m++;
//	}
//	cout << minimumPassingScore << " " << m << endl;
//	for (int i = 0; i < m; i++)
//	{
//		printf("%d %d\n", v[i].k, v[i].s);
//	}
//
//	return 0;
//}