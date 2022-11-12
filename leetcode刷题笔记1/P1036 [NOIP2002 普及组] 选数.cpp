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
//vector<int>v;
//bool prime(int n) {
//	if (n <= 1)return false;
//	if (n == 2)return true;
//	for (int i = 2; i * i <= n; i++)
//	{
//		if (n % i == 0)return false;
//	}
//	return true;
//}
//int sum = 0, ans = 0;
//void dfs(int i, int k) {
//	if (k == 0) {
//		if (prime(sum)) {
//			ans++;
//		}
//		return;
//	}
//	sum += v[i];
//	if (v.size() - i >= k)dfs(i + 1, k - 1);
//	sum -= v[i];
//	if (v.size() - i - 1 >= k)dfs(i + 1, k);
//}
//int main() {
//	int n, k;
//	cin >> n >> k;
//	v.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//	}
//	dfs(0, k);
//	cout << ans << endl;
//	return 0;
//}