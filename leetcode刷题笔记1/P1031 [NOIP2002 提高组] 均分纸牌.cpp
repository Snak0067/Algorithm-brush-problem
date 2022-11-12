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
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int>v(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//		if (i == 0)continue;
//		v[i] = v[i - 1] + v[i];
//	}
//	int p = v[n - 1] / n, ans = 0;
//	for (int i = 1; i < n; i++)
//	{
//		if (v[i - 1] != p * i)ans++;
//	}
//	cout << ans << endl;
//	return 0;
//}