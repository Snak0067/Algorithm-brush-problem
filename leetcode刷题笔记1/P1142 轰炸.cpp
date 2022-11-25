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
//int gcd(int x, int y) {
//	return y ? gcd(y, x % y) : x;
//}
//struct p {
//	int x, y;
//};
//vector<p>v;
//unordered_map<string, int>mmap;
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int x, y;
//		cin >> x >> y;
//		v.push_back({ x,y });
//	}
//	for (int i = 0; i < v.size() - 1; i++)
//	{
//		for (int j = i + 1; j < v.size(); j++)
//		{
//			int a = v[i].x - v[j].x, b = v[i].y - v[j].y;
//			//对分子分母取绝对值
//			if (a * b < 0) {
//				a = abs(a);
//				b = -abs(b);
//			}
//			else {
//				a = abs(a);
//				b = abs(b);
//			}
//			int gcd_ = gcd(abs(a), abs(b));
//			a = a / gcd_;
//			b = b / gcd_;
//			string id1 = to_string(v[i].x) + "_" + to_string(v[i].y) + "_" + to_string(a) + "_" + to_string(b);
//			string id2 = to_string(v[j].x) + "_" + to_string(v[j].y) + "_" + to_string(a) + "_" + to_string(b);
//			mmap[id1]++;
//			mmap[id2]++;
//		}
//	}
//	int maxn = INT_MIN;
//	for (auto i = mmap.begin(); i != mmap.end(); i++)
//	{
//		maxn = max(i->second, maxn);
//	}
//	cout << maxn + 1 << endl;
//	return 0;
//}