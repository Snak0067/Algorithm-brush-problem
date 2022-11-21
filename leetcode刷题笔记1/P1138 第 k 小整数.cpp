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
//int main() {
//	int n, rank;
//	cin >> n >> rank;
//	v.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//	}
//	sort(v.begin(), v.end());
//	int cur = v[0], cnt = rank - 1;
//	for (int i = 0; i < n; i++)
//	{
//		if (v[i] == cur)continue;
//		cur = v[i];
//		cnt--;
//		if (cnt == 0) {
//			cout << cur << endl;
//			return 0;
//		}
//	}	
//	printf("NO RESULT");
//	return 0;
//}