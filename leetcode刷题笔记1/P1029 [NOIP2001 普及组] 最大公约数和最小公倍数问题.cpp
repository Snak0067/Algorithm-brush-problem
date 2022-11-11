#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<stack>
#include<unordered_set>
#include<queue>
#include<limits.h>
using namespace std;
//最大公约数
long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}
int main() {
	long long x, y, ans = 0;
	cin >> x >> y;
	y *= x;
	for (int i = 1; i <= sqrt(y); i++)
	{
		if (y % i != 0)continue;
		if (gcd(i, y / i) == x) {
			ans += 2;
		}
	}
	if (x == y / x)ans--;
	cout << ans << endl;
	return 0;
}