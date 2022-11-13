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
//int v[20005], w[35];
//int main() {
//	int volume, n;
//	cin >> volume >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> w[i];
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = volume; j >= w[i]; j--)
//		{
//			v[j] = max(v[j], v[j - w[i]] + w[i]);
//		}
//	}
//	cout << volume - v[volume] << endl;
//	return 0;
//}