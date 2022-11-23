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
//	int target = n * 2;
//	for (long i = 1; i < n; i++)
//	{
//		long long temp = (long long)i * i;
//		double x = sqrt(double(target) + 0.25 + temp - i) - 0.5;
//		if (x < i)break;
//		if (x - int(x) < 1e-6) {
//			int b = (int)x;
//			if ((i + b) * (b - i + 1) / 2 == n) {
//				printf("%d %d\n", i, int(x));
//			}			
//		}
//	}
//	return 0;
//}