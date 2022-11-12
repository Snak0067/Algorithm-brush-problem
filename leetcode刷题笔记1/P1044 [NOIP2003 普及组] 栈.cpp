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
//vector<int>v;
//long memory[25][25];
//int ans = 0;
//long dfs(int x, int y) {
//	if (memory[x][y] != 0)return memory[x][y];
//	if (y == 0)return 1;
//	if (x > 0) {
//		memory[x][y] += dfs(x - 1, y);
//	}
//	memory[x][y] += dfs(x + 1, y - 1);
//	return memory[x][y];
//}
//int main() {
//	int n;
//	cin >> n;
//	cout << dfs(0, n) << endl;
//	return 0;
//}