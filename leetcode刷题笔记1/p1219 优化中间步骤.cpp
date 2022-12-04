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
//int n;
//vector<vector<int>>ans;
//vector<int>temp;
//int column[100], line[100], c[100], d[100];
//void dfs(int i, int j) {
//	temp.push_back(j + 1);
//	column[j] = 1;
//	line[i] = 1;
//	c[i + j] = 1;
//	d[i - j + n] = 1;
//	if (i == n - 1) {
//		ans.push_back(temp);
//		column[j] = 0;
//		line[i] = 0;
//		c[i + j] = 0;
//		d[i - j + n] = 0;
//		temp.pop_back();
//		return;
//	}
//	for (int x = 0; x < n; x++)
//	{
//		if (c[i + 1 + x] || d[i + 1 - x + n] || column[x])continue;
//		dfs(i + 1, x);
//	}
//	temp.pop_back();
//	column[j] = 0;
//	line[i] = 0;
//	c[i + j] = 0;
//	d[i - j + n] = 0;
//}
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		dfs(0, i);
//	}
//	for (int i = 0; i < min(3, int(ans.size())); i++)
//	{
//		for (int j = 0; j < ans[i].size(); j++)
//		{
//			if (j != 0)printf(" ");
//			printf("%d", ans[i][j]);
//		}
//		printf("\n");
//	}
//	printf("%d\n", ans.size());
//
//	return 0;
//}