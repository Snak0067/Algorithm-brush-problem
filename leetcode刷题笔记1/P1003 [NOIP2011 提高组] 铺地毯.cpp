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
//using namespace std;
//struct blanket {
//	int a, b, g, k;
//};
//vector<blanket>v;
//int main() {
//	int n, x, y;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		blanket bk;
//		scanf_s("%d %d %d %d", &bk.a, &bk.b, &bk.g, &bk.k);
//		v.push_back(bk);
//	}
//	cin >> x >> y;
//	for (int i = n - 1; i >= 0; i--) {
//		if (v[i].a <= x && v[i].b <= y && v[i].a + v[i].g >= x && v[i].b + v[i].k >= y) {
//			cout << i + 1 << endl;
//			return 0;
//		}
//	}
//	cout << -1 << endl;
//
//	return 0;
//}