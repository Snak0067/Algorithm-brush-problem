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
//	int n, l;
//	cin >> l >> n;
//	vector<int>v(n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &v[i]);
//	}
//	int mint = 0, maxt = 0;
//	for (int i = 0; i < n; i++) {
//		//����ʿ���������ʱ������ֵ
//		mint = max(mint, min(l + 1 - v[i], v[i] - 0));
//		//����ʿ�������ʱ������ֵ
//		maxt = max(maxt, max(l + 1 - v[i], v[i] - 0));
//	}
//	cout << mint << " " << maxt << endl;
//
//	return 0;
//}