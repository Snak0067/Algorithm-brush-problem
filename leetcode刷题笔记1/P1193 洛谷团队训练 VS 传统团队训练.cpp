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
//int n, m;
//int p[1010], s[1010];
//int ta, tb, tc, td, A, H, E, R;
//unordered_map<int, int>mmap;
//struct nod {
//	int num = 0;
//	unordered_map<int, vector<int>>record;
//};
//vector<nod>v(1010);
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		scanf_s("%d", &p[i]);
//	}
//	for (int i = 0; i < m; i++)
//	{
//		scanf_s("%d", &s[i]);
//	}
//	scanf_s("%d%d%d%d%d%d%d%d", &ta, &tb, &tc, &td, &A, &H, &E, &R);
//	int luogu = (ta * 1.0 * n + R * tc) / A * 100 + H;
//	int id = 0;
//	for (int i = 0; i < R; i++)
//	{
//		int pr, sr, sc;
//		scanf_s("%d%d%d", &pr, &sr, &sc);
//		if (!mmap.count(sr)) {
//			mmap[sr] = id++;
//		}
//		v[mmap[sr]].record[pr].push_back(sc);
//		v[mmap[sr]].num += 1;
//	}
//	int bound = 1;
//	//计算出采用学生机更快的题目量
//	while (tb * bound < ta + tc * bound) {
//		bound++;
//	}
//	int traditional = n * ta;
//	for (int i = 0; i < m; i++)
//	{
//		unordered_map<int, vector<int>>temp = v[mmap[s[i]]].record;
//		//如果题目量大于等于边界，则效率更快是在本机上
//		for (auto it = temp.begin(); it != temp.end(); it++)
//		{
//			vector<int>vc = it->second;
//			int cur = 0, maxn = 0, num = vc.size();
//			if (num >= bound) {
//				traditional = traditional + ta + tc * num;
//			}
//			else {//否则跑到教师那儿去
//				traditional = traditional + tb * num;
//			}
//
//			for (int j = 0; E == 1 && j < vc.size(); j++)
//			{
//				if (vc[j] > maxn) {
//					maxn = vc[j];
//					cur += td;
//				}
//			}
//			traditional += cur;
//		}
//	}
//	printf("%d\n%d\n", traditional, luogu);
//	printf(luogu < traditional ? "Use Luogu!" : "Forget it...");
//	return 0;
//}