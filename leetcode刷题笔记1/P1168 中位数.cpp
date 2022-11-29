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
///*
//	利用upper_bound的二分查找到大于目标值的第一个位置然后插入，保证了插入的数组随时是排好序的
//	用时614ms
//*/
//void stlMethod() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		int num;
//		scanf_s("%d", &num);
//		v.insert(upper_bound(v.begin(), v.end(), num), num);
//		if (i % 2 == 1) {
//			printf("%d\n", v[i / 2]);
//		}
//	}
//}
///*
//  建立大小堆  两边一边小于mid  一边大于mid  mid就是中位数 
//  用时191ms
//*/
//int mid;
//priority_queue<int, vector<int>, less<int>>q1;//大根堆
//priority_queue<int, vector<int>, greater<int>>q2;//小根堆
//void heap() {
//	int n, x;
//	cin >> n;
//	scanf_s("%d", &x);
//	mid = x;
//	printf("%d\n", x);
//	for (int i = 0; i < n - 1; i++)
//	{
//		scanf_s("%d", &x);
//		if (x <= mid) {
//			q1.push(x);
//		}
//		else {
//			q2.push(x);
//		}
//		if (i % 2 == 1) {
//
//			while (q1.size() > q2.size()) {
//				q2.push(mid);
//				mid = q1.top();
//				q1.pop();
//			}
//			while (q2.size() > q1.size()) {
//				q1.push(mid);
//				mid = q2.top();
//				q2.pop();
//			}
//			printf("%d\n", mid);
//		}
//	}
//}
//int main() {
//	heap();
//	return 0;
//}