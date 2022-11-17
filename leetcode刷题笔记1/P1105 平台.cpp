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
//struct platform {
//	int id, height, left, right, leftDropId = 0, rightDropId = 0;
//};
//vector<platform>v;
//bool cmp(platform p1, platform p2) {
//	if (p1.height != p2.height) return p1.height > p2.height;
//	return p1.id < p2.id;
//}
//bool cmp1(platform p1, platform p2) {
//	return p1.id < p2.id;
//}
//int main() {
//	int n;
//	cin >> n;
//	v.resize(n);
//	for (size_t i = 0; i < n; i++)
//	{
//		v[i].id = i + 1;
//		cin >> v[i].height >> v[i].left >> v[i].right;
//	}
//	sort(v.begin(), v.end(), cmp);
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		int cnt = 2;
//		for (size_t j = i + 1; j < v.size() && cnt>0; j++)
//		{
//			if (v[j].height == v[i].height)continue;
//			if (v[i].leftDropId == 0 && v[j].left<v[i].left && v[j].right > v[i].left) {
//				v[i].leftDropId = v[j].id;
//				cnt--;
//			}
//			if (v[i].rightDropId == 0 && v[j].left<v[i].right && v[j].right > v[i].right) {
//				v[i].rightDropId = v[j].id;
//				cnt--;
//			}
//		}
//	}
//	sort(v.begin(), v.end(), cmp1);
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		printf("%d %d\n", v[i].leftDropId, v[i].rightDropId);
//	}
//	return 0;
//}