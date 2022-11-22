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
//vector<vector<int>> book;
//struct irregularity {
//	int id, x;
//};
//bool cmp(irregularity i1, irregularity i2) {
//	return i1.x > i2.x;
//}
//vector<irregularity> irr;
//int main() {
//	int n, k;
//	cin >> n >> k;
//	book.assign(n, vector<int>(2));
//	for (int i = 0; i < n; i++)
//	{
//		cin >> book[i][0] >> book[i][1];
//	}
//	sort(book.begin(), book.end());
//	int total = 0;
//	for (int i = 0; i < n - 1; i++)
//	{
//		if (i != n - 1) {
//			total += abs(book[i][1] - book[i + 1][1]);
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		irregularity temp;
//		if (i == 0)temp.x = abs(book[0][1] - book[1][1]);
//		else if (i == n - 1)temp.x = abs(book[n - 1][1] - book[n - 2][1]);
//		else {
//			temp.x = abs(book[i][1] - book[i + 1][1]) + abs(book[i][1] - book[i - 1][1]) - abs(book[i - 1][1] - book[i + 1][1]);
//		}
//		temp.id = i;
//		irr.push_back(temp);
//	}
//
//	for (int i = 0; i < k; i++)
//	{
//		sort(irr.begin(), irr.end(), cmp);
//		irregularity cur = irr[0];
//		irr.erase(irr.begin());
//		total -= cur.x;
//		book[cur.id][0] = 0;
//		if (cur.id != 0 && cur.id != n - 1) {
//			int nxt = cur.id + 1;
//			int pre = cur.id - 1;
//			while (nxt < n && book[nxt][0] == 0)nxt++;
//			while (pre >= 0 && book[pre][0] == 0)pre--;
//			int ppre = pre - 1;
//			int nnxt = nxt + 1;
//			while (ppre > 0 && book[ppre][0] == 0)ppre--;
//			while (nnxt < n && book[nnxt][0] == 0)nnxt++;
//			if (nxt < n && pre >= 0) {
//				int cnt = 0;
//				for (int i = 0; i < n && cnt < 2; i++)
//				{
//					if (irr[i].id == pre) {
//						if (ppre > 0) {
//							irr[i].x = abs(book[pre][1] - book[nxt][1]) + abs(book[pre][1] - book[ppre][1]) - abs(book[ppre][1] - book[nxt][1]);
//						}
//						else {
//							irr[i].x = abs(book[nxt][1] - book[pre][1]);
//						}
//						cnt++;
//					}
//					if (irr[i].id == nxt) {
//						if (nnxt < n) {
//							irr[i].x = abs(book[pre][1] - book[nxt][1]) + abs(book[nnxt][1] - book[nxt][1]) - abs(book[pre][1] - book[nnxt][1]);
//						}
//						else {
//							irr[i].x = abs(book[nxt][1] - book[pre][1]);
//						}
//						cnt++;
//					}
//				}
//			}
//		}
//
//	}
//	cout << total << endl;
//	return 0;
//}