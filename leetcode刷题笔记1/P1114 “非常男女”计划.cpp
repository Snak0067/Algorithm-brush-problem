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
//int v[100005];
//int main() {
//	int n;
//	cin >> n;
//	int man = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//		if (v[i] == 1)man++;
//	}
//	int len = n;
//	//预处理 总数必为偶数
//	if (len % 2 == 1) {
//		len--;
//		if (v[n - 1] == 1)man--;
//	}
//	if (man * 2 == len) {
//		cout << len << endl;
//		return 0;
//	}
//	while (man * 2 != len && len > 0) {
//		int temp = man;
//		for (int i = 0; i < n - len; i++)
//		{
//			if (v[i] == 1)temp--;
//			if (v[len + i] == 1)temp++;
//			if (temp * 2 == len) {
//				cout << len << endl;
//				return 0;
//			}
//		}
//		if (v[len - 1] == 1)man--;
//		if (v[len - 2] == 1)man--;
//		len -= 2;
//	}
//	if (man * 2 == len) {
//		cout << len << endl;
//	}
//	else {
//		cout << 0 << endl;
//	}
//	return 0;
//}