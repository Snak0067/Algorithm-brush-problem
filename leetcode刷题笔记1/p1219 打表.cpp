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
//struct nod {
//	string l1, l2, l3;
//	int maxn;
//};
//int main() {
//	vector<nod>v(8);
//	v[0].l1 = "2 4 6 1 3 5";
//	v[0].l2 = "3 6 2 5 1 4";
//	v[0].l3 = "4 1 5 2 6 3";
//	v[0].maxn = 4;
//
//	v[1].l1 = "1 3 5 7 2 4 6";
//	v[1].l2 = "1 4 7 3 6 2 5";
//	v[1].l3 = "1 5 2 6 3 7 4";
//	v[1].maxn = 40;
//
//	v[2].l1 = "1 5 8 6 3 7 2 4";
//	v[2].l2 = "1 6 8 3 7 4 2 5";
//	v[2].l3 = "1 7 4 6 8 2 5 3";
//	v[2].maxn = 92;
//
//	v[3].l1 = "1 3 6 8 2 4 9 7 5";
//	v[3].l2 = "1 3 7 2 8 5 9 4 6";
//	v[3].l3 = "1 3 8 6 9 2 5 7 4";
//	v[3].maxn = 352;
//
//	v[4].l1 = "1 3 6 8 10 5 9 2 4 7";
//	v[4].l2 = "1 3 6 9 7 10 4 2 5 8";
//	v[4].l3 = "1 3 6 9 7 10 4 2 8 5";
//	v[4].maxn = 724;
//
//	v[5].l1 = "1 3 5 7 9 11 2 4 6 8 10";
//	v[5].l2 = "1 3 6 9 2 8 11 4 7 5 10";
//	v[5].l3 = "1 3 7 9 4 2 10 6 11 5 8";
//	v[5].maxn = 2680;
//
//	v[6].l1 = "1 3 5 8 10 12 6 11 2 7 9 4";
//	v[6].l2 = "1 3 5 10 8 11 2 12 6 9 7 4";
//	v[6].l3 = "1 3 5 10 8 11 2 12 7 9 4 6";
//	v[6].maxn = 14200;
//
//	v[7].l1 = "1 3 5 2 9 12 10 13 4 6 8 11 7";
//	v[7].l2 = "1 3 5 7 9 11 13 2 4 6 8 10 12";
//	v[7].l3 = "1 3 5 7 12 10 13 6 4 2 8 11 9";
//	v[7].maxn = 73712;
//
//	int n;
//	cin >> n;
//	printf("%s\n%s\n%s\n%d\n", v[n - 6].l1.c_str(), v[n - 6].l2.c_str(), v[n - 6].l3.c_str(), v[n - 6].maxn);
//	return 0;
//}