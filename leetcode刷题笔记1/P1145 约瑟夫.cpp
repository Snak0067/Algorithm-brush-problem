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
//int k;
//bool judge(int m) {
//	int start = 0, n = 2 * k;
//	int rest = k;
//	int idx = (start + m - 1) % n;
//	while (rest > 0) {
//		if (idx >= k) {
//			rest--;
//			if (idx == n - 1)idx = 0;
//			n--;
//			idx = (idx + m - 1) % n;
//		}
//		else {
//			return false;
//		}
//	}
//	return true;
//}
//
//int main() {
//	//for (int i = 1; i < 14; i++)
//	//{
//	//	k = i;
//	//	int m = 1;
//	//	while (!judge(m)) {
//	//		m++;
//	//	}
//	//	cout << i << " " << m << endl;
//	//}
//	cin >> k;
//	int m = 1;
//	while (!judge(m)) {
//		m++;
//	}
//	cout << m << endl;
//	return 0;
//}