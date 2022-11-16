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
//struct stu {
//	string name;
//	int id, y, m, d;
//};
//vector<stu>v;
//bool cmp(stu s1, stu s2) {
//	if (s1.y != s2.y)return s1.y < s2.y;
//	if (s1.m != s2.m)return s1.m < s2.m;
//	if (s1.d != s2.d)return s1.d < s2.d;
//	return s1.id > s2.id;
//}
//int main() {
//	int n;
//	cin >> n;
//	v.resize(n);
//	for (size_t i = 0; i < n; i++)
//	{
//		v[i].id = i;
//		cin >> v[i].name >> v[i].y >> v[i].m >> v[i].d;
//	}
//	sort(v.begin(), v.end(), cmp);
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		printf("%s\n", v[i].name.c_str());
//	}
//	return 0;
//}