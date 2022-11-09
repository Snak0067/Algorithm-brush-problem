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
//int expect, basicCost, sale_basicCost, extraSaleVolumeDeclined;
//int sale[10000][2];
//int main() {
//	cin >> expect;
//	int price, volume, index = -1;
//	do {
//		index++;
//		cin >> sale[index][0] >> sale[index][1];
//		if (sale[index][0] != -1) {
//			if (index > 0 && sale[index][0] - sale[index - 1][0] > 1) {
//				int differ = (sale[index - 1][1] - sale[index][1]) / (sale[index][0] - sale[index - 1][0]);
//				int tempSellingPrice = sale[index][0];
//				int beginPrice = sale[index - 1][0];
//				int beginSaleNum = sale[index - 1][1];
//				for (int i = 1; i + beginPrice <= tempSellingPrice; i++)
//				{
//					sale[index][0] = i + beginPrice;
//					sale[index][1] = beginSaleNum - i * differ;
//					index++;
//				}
//				index--;
//			}
//		}
//	} while (sale[index][0] != -1);
//	cin >> extraSaleVolumeDeclined;
//	while (sale[index - 1][1] >= 0) {
//		sale[index][0] = sale[index - 1][0] + 1;
//		sale[index][1] = sale[index - 1][1] - extraSaleVolumeDeclined;
//		index++;
//	}
//	double Min = 0, Max = 1000.0;
//	int expectSaleNum = 0;
//	for (int i = 0; i < index; i++)
//	{
//		if (sale[i][0] == expect) {
//			expectSaleNum = sale[i][1];
//			break;
//		}
//	}
//	for (int i = 1; i < index; i++)
//	{
//		int expectProfit = expect - sale[0][0];
//		int basicProfit = (sale[i][0] - sale[0][0]);
//		double ans = (expectProfit * 1.0 * expectSaleNum - basicProfit * sale[i][1]) / (sale[i][1] - expectSaleNum);
//		double g = sale[i][1] - expectSaleNum;
//		if (g > 0) {
//			Max = min(Max, ans);
//		}
//		else {
//			Min = max(Min, ans);
//		}
//	}
//	//此时[Min,Max]就是答案的范围，取绝对值最小的输出。
//	if (Min > 0) printf("%d", (int)ceil(Min));//Max>Min>0，答案为Min上取整
//	else if (Max < 0) printf("%d", (int)floor(Max));//Min<Max<0，答案为Max下取整
//	else puts("0");//Min<0<Max，显然是0绝对值最小
//	return 0;
//}