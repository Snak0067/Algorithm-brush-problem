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
//vector<string>v, ans, downv;
//string status, song;
//int main() {
//	cin >> n;
//	v.resize(n);
//	ans.resize(n);
//	int left = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> song >> status;
//		if (status[0] == 'U') {
//			downv.push_back(song);
//		}
//		else if (status[0] == 'S') {
//			ans[i] = song;
//		}
//		else {
//			if (!ans[left].empty()) {
//				while (!ans[left].empty())left++;
//			}
//			ans[left++] = song;
//		}
//	}
//	int idx = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (ans[i].empty()) {
//			ans[i] = downv[idx++];
//		}
//	}
//	//printf("---------------\n");
//	for (int i = 0; i < ans.size(); i++)
//	{
//		cout << ans[i] << endl;
//	}
//	return 0;
//}