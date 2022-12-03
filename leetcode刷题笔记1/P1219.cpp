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
int n;
vector<vector<int>>ans;
vector<int>temp;
int column[15], line[15];
void dfs(int i, int j, vector<vector<int>>vis) {
	temp.push_back(j + 1);
	column[j] = 1;
	line[i] = 1;
	for (int x = 0; x < n - i; x++)
	{
		if (j + x >= n && j - x < 0)break;
		if (j + x < n) {
			vis[i + x][j + x] = 1;
		}
		if (j - x >= 0) {
			vis[i + x][j - x] = 1;
		}
	}
	if (i == n - 1) {
		ans.push_back(temp);
		column[j] = 0;
		line[i] = 0;
		temp.pop_back();
		return;
	}
	for (int x = 0; x < n; x++)
	{
		if (vis[i + 1][x] || column[x])continue;
		dfs(i + 1, x, vis);
	}
	temp.pop_back();
	column[j] = 0;
	line[i] = 0;
}
int main() {
	cin >> n;
	vector<vector<int>>vis(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		dfs(0, i, vis);
	}
	for (int i = 0; i < min(3, int(ans.size())); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
		{
			if (j != 0)printf(" ");
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}
	printf("%d", ans.size());
	return 0;
}