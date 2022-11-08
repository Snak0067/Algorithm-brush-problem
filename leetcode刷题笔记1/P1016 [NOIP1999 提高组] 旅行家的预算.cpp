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
//vector<pair<double, double>>station;//沿途油站<距起始点距离，当前站点汽油价格>
//double totalDistance;//两个城市之间的距离 
//double capacity;//汽车油箱的容量
//double dis_pergas;//每升汽油能行驶的距离
//double price_start;// 出发点每升汽油价格
//double numberOfGasStation;//沿途油站数
//double dis_fullGas;//满油箱可行驶距离
//double ans = 999999999;
//void dfs(int cur, double curOil, double cost) {
//	if (cost > ans) {
//		return;
//	}
//	if (cur == numberOfGasStation + 1) {
//		if (cost < ans) {
//			ans = cost;
//			return;
//		}
//	}
//	for (int i = cur + 1; i < station.size(); i++) {
//		double disFromCurrent = station[i].first - station[cur].first;
//		double disToEmpty = curOil * dis_pergas;
//		if (disFromCurrent > dis_fullGas) {
//			return;
//		}
//		//基本选择1：油箱里的油够到下一站，不加油
//		if (disToEmpty > disFromCurrent) {
//			double nextOil = (disToEmpty - disFromCurrent) / dis_pergas;
//			dfs(i, nextOil, cost);
//		}
//		//基本选择2：加油但只够只加到下一站
//		else {
//			dfs(i, 0, cost + (disFromCurrent - disToEmpty) / dis_pergas * station[cur].second);
//		}
//		//基本选择3：加满（对应某些油站的油特别便宜的情况）
//		if (station[cur].second < station[i].second) {
//			double nextOil = capacity - disFromCurrent / dis_pergas;
//			double costAdded = (capacity - curOil) * station[cur].second;
//			dfs(i, nextOil, cost + costAdded);
//		}
//	}
//}
//int main() {
//	cin >> totalDistance >> capacity >> dis_pergas >> price_start >> numberOfGasStation;
//	//离出发点距离以及每升汽油的价格
//	station.assign(numberOfGasStation + 2, pair<double, double>(0.0, 0.0));
//	dis_fullGas = dis_pergas * capacity;
//	station[0].second = price_start;
//	station[numberOfGasStation + 1].first = totalDistance;
//	for (int i = 1; i <= numberOfGasStation; i++)
//	{
//		cin >> station[i].first >> station[i].second;
//		//判断能否到达目的地
//		double disBetweenTwoPoint = station[i].first - station[i - 1].first;
//		if (disBetweenTwoPoint > dis_fullGas) {
//			cout << "No Solution" << endl;
//			return 0;
//		}
//	}
//	dfs(0, 0, 0);
//	printf("%.2f", ans);
//	return 0;
//}