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
//vector<char>num;
//map<int, int>cnt;
//bool waveNum() {
//	for (int i = 0; i < num.size() - 1; i += 2)
//	{
//		if (num[i] != num[0])return false;
//		if (num[i + 1] != num[1])return false;
//	}
//	return true;
//}
//void transform(int x, int hex) {
//	num.clear();
//	while (x > 0) {
//		int remainder = x % hex;
//		if (remainder >= 10) {
//			num.push_back('A' + remainder - 10);
//		}
//		else {
//			num.push_back('0' + remainder);
//		}
//		x /= hex;
//	}
//}
//void test() {
//	transform(191919, 11);
//	for (int i = 0; i < num.size(); i++)printf("%c", num[i]);
//	printf("\n");
//	transform(300, 32);
//	for (int i = 0; i < num.size(); i++)printf("%c", num[i]);
//	printf("\n");
//	transform(300, 8);
//	for (int i = 0; i < num.size(); i++)printf("%c", num[i]);
//	printf("\n");
//}
///*换个思路，先找出波浪数*/
//int hexBegin, hexEnd;
//int start, endNum;
//int n;
//void make() {
//	for (int hex = hexBegin; hex <= hexEnd; hex++)
//	{
//		for (int i = 1; i < hex; i++)
//		{
//			for (int j = 0; j < hex; j++)
//			{
//				if (i == j)continue;
//				int x = 0;
//				int t = 0;
//				while (x <= endNum) {
//					if (t % 2 == 0) {
//						x = x * hex + i;
//						t++;
//					}
//					else {
//						x = x * hex + j;
//						t++;
//					}
//					if (x >= start && x <= endNum) {
//						cnt[x]++;
//					}
//				}
//
//			}
//		}
//	}
//}
//int main() {
//	cin >> hexBegin >> hexEnd >> start >> endNum >> n;
//	make();
//	for (auto i = cnt.begin(); i != cnt.end(); i++)
//	{
//		if (i->second == n) {
//			printf("%d\n", i->first);
//		}
//	}
//	return 0;
//}