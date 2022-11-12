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

int dp[105][1005];
int main() {
	int time, number;
	cin >> time >> number;
	vector<int>v(number + 1), t(number + 1);
	for (int i = 1; i <= number; i++)
	{
		cin >> t[i] >> v[i];
	}
	for (int i = 1; i <= number; i++)
	{
		for (int j = time; j >= 0; j--)
		{
			if (j >= t[i]) {
				dp[i][j] = max(dp[i - 1][j - t[i]] + v[i], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[number][time] << endl;

	return 0;
}