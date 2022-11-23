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
//int match[10] = { 6,2,5,5,4,5,6,3,7,6 };
//int vis[25][25];
//int main() {
//	int n;
//	cin >> n;
//	n -= 4;
//	int cnt = 0;
//	for (int i = 0; i < 1000; i++)
//	{
//		for (int j = 0; j < 1000; j++)
//		{
//			int a = i, b = j, c = i + j;
//			int match_a = 0, match_b = 0, match_c = 0;
//			do {
//				match_a += match[a % 10];
//				a /= 10;
//			} while (a > 0);
//			do {
//				match_b += match[b % 10];
//				b /= 10;
//			} while (b > 0);
//			do {
//				match_c += match[c % 10];
//				c /= 10;
//			} while (c > 0);
//			if (match_a + match_b + match_c == n) {
//				
//				cnt++;
//				//printf("%d + %d = %d\n", i, j, i + j);
//			}
//		}
//	}
//	cout << cnt << endl;
//	return 0;
//}