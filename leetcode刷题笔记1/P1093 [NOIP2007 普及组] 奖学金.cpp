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
//	int id, chinese, math, english;
//	int totalScore;
//	stu() {}
//};
//vector<stu>v;
//bool cmp(stu s1, stu s2) {
//	if (s1.totalScore != s2.totalScore)return s1.totalScore > s2.totalScore;
//	if (s1.chinese != s2.chinese)return s1.chinese > s2.chinese;
//	return s1.id < s2.id;
//}
//int main() {
//	int n;
//	cin >> n;
//	v.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i].chinese >> v[i].math >> v[i].english;
//		v[i].totalScore = v[i].chinese + v[i].math + v[i].english;
//		v[i].id = i + 1;
//	}
//	sort(v.begin(), v.end(), cmp);
//	for (int i = 0; i < 5 && i < v.size(); i++)
//	{
//		printf("%d %d\n", v[i].id, v[i].totalScore);
//	}
//	return 0;
//}