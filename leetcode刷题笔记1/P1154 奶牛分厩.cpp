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
//vector<int>f;
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int num;
//		cin >> num;
//		v.push_back(num);
//	}
//	int k = n;
//	bool match = false;
//	while (!match) {
//		match = true;
//		f.clear();
//		f.resize(k);
//		for (int i = 0; i < n; i++)
//		{
//			if (f[v[i] % k]) {
//				match = false;
//				break;
//			}
//			f[v[i] % k] = 1;
//		}
//		k += 1;
//	}
//	printf("%d", k - 1);
//	return 0;
//}