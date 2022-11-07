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
//	int line, sum = 0;
//	for (line = 1; sum + line < n; line++) {
//		sum += line;
//	}
//	int dir = line % 2 == 0 ? 1 : 0;
//	if (dir == 1) {
//		int l = 1, r = line;
//		int cnt = n - sum - 1;
//		while (cnt > 0) {
//			l++;
//			r--;
//			cnt--;
//		}
//		cout << l << "/" << r << endl;
//	}
//	else {
//		int l = line, r = 1;
//		int cnt = n - sum - 1;
//		while (cnt > 0) {
//			l--;
//			r++;
//			cnt--;
//		}
//		cout << l << "/" << r << endl;
//	}
//	return 0;
//}