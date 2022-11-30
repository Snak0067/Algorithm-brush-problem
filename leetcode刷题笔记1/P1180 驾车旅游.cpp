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
//double totalDis;//从出发地到目的地的距离
//double capacityOfCarGas;//汽车油箱的最大容量
//double disPerGas;//汽车每升油能行驶的公里数
//double costOfStart;//汽车在出发地加满油箱时的费用
//int n;//从出发地到目的地线路上加油站的数目
//vector<pair<double, double>>v;
//double minn = 999999999;
//void dfs(int i, double cost, double gas) {
//	if (cost > minn)return;
//	gas -= (v[i].first - v[i - 1].first) / disPerGas;
//	if (gas < 0)return;
//	if (i == v.size() - 1) {
//		minn = min(cost, minn);
//		return;
//	}
//	dfs(i + 1, cost, gas);
//	if (gas * 2 < capacityOfCarGas) {
//		dfs(i + 1, cost + 20 + (capacityOfCarGas - gas) * v[i].second, capacityOfCarGas);
//	}
//}
//int main() {
//	cin >> totalDis >> capacityOfCarGas >> disPerGas >> costOfStart;
//	cin >> n;
//	v.emplace_back(0, 0);
//	for (int i = 0; i < n; i++)
//	{
//		double d, c;
//		cin >> d >> c;
//		v.emplace_back(d, c);
//	}
//	v.emplace_back(totalDis, 0);
//	double cost = costOfStart, curGas = capacityOfCarGas;
//	dfs(1, cost, curGas);
//	printf("%.1lf", minn);
//	return 0;
//}