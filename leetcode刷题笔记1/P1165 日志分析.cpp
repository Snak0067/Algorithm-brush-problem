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
//stack<int>maxs, s;
//int main() {
//	int n, number, weight;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> number;
//		if (number == 0) {
//			cin >> weight;
//			if (maxs.empty() || maxs.top() < weight) {
//				maxs.push(weight);
//				s.push(weight);
//			}
//			else {
//				s.push(weight);
//				maxs.push(maxs.top());
//			}
//		}
//		else if (number == 1) {
//			if (!s.empty()) {
//				maxs.pop();
//				s.pop();
//			}			
//		}
//		else {
//			if (!s.empty()) {
//				printf("%d\n", maxs.top());
//			}
//			else {
//				printf("0\n");
//			}
//		}
//	}
//	return 0;
//}