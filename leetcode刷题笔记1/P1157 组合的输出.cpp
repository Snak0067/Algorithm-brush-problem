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
//#include<iomanip>
//#include<limits.h>
//using namespace std;
////从 nn 个元素中抽出 rr 个元素
//int n, r;
//vector<int>v;
//void dfs(int x) {
//	if (v.size() + n - x + 1 < r) {
//		return;
//	}
//	if (v.size() == r) {
//		for (int i = 0; i < v.size(); i++)
//		{
//			cout << setw(3) << v[i];
//		}
//		cout << endl;
//		return;
//	}
//	if (x > n)return;
//	v.push_back(x);
//	dfs(x + 1);
//	v.pop_back();
//	dfs(x + 1);
//}
//int main() {
//	cin >> n >> r;
//	dfs(1);
//	return 0;
//}