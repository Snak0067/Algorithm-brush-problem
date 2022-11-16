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
//struct cross {
//	int id, num;
//};
//vector<cross>column(1005);
//vector<cross>line(1005);
//bool cmp(cross c1, cross c2) {
//	return c1.num > c2.num;
//}
//bool cmp1(cross c1, cross c2) {
//	return c1.id < c2.id;
//}
//int main() {
//	int m, n, k, l, d;
//	cin >> m >> n >> k >> l >> d;
//	int x1, y1, x2, y2;
//	for (int i = 0; i < d; i++)
//	{
//		cin >> x1 >> y1 >> x2 >> y2;
//		//行相等，分割列
//		if (x1 == x2) {
//			column[min(y1, y2)].id = min(y1, y2);
//			column[min(y1, y2)].num++;
//		}
//		//列相等，分割行
//		else {
//			line[min(x1, x2)].id = min(x1, x2);
//			line[min(x1, x2)].num++;
//		}
//	}
//	sort(line.begin(), line.begin() + m, cmp);
//	sort(column.begin(), column.begin() + n, cmp);
//	vector<cross>ansx, ansy;
//	ansx.insert(ansx.begin(), line.begin(), line.begin() + k);
//	ansy.insert(ansy.begin(), column.begin(), column.begin() + l);
//	sort(ansx.begin(), ansx.end(), cmp1);
//	sort(ansy.begin(), ansy.end(), cmp1);
//	for (int i = 0; i < k; i++)
//	{
//		if (i != 0)printf(" ");
//		printf("%d", ansx[i].id);
//	}
//	printf("\n");
//	for (int i = 0; i < l; i++)
//	{
//		if (i != 0)printf(" ");
//		printf("%d", ansy[i].id);
//	}
//	return 0;
//}