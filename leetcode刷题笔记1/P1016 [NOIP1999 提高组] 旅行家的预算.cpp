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
//vector<pair<double, double>>station;//��;��վ<����ʼ����룬��ǰվ�����ͼ۸�>
//double totalDistance;//��������֮��ľ��� 
//double capacity;//�������������
//double dis_pergas;//ÿ����������ʻ�ľ���
//double price_start;// ������ÿ�����ͼ۸�
//double numberOfGasStation;//��;��վ��
//double dis_fullGas;//���������ʻ����
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
//		//����ѡ��1����������͹�����һվ��������
//		if (disToEmpty > disFromCurrent) {
//			double nextOil = (disToEmpty - disFromCurrent) / dis_pergas;
//			dfs(i, nextOil, cost);
//		}
//		//����ѡ��2�����͵�ֻ��ֻ�ӵ���һվ
//		else {
//			dfs(i, 0, cost + (disFromCurrent - disToEmpty) / dis_pergas * station[cur].second);
//		}
//		//����ѡ��3����������ӦĳЩ��վ�����ر���˵������
//		if (station[cur].second < station[i].second) {
//			double nextOil = capacity - disFromCurrent / dis_pergas;
//			double costAdded = (capacity - curOil) * station[cur].second;
//			dfs(i, nextOil, cost + costAdded);
//		}
//	}
//}
//int main() {
//	cin >> totalDistance >> capacity >> dis_pergas >> price_start >> numberOfGasStation;
//	//�����������Լ�ÿ�����͵ļ۸�
//	station.assign(numberOfGasStation + 2, pair<double, double>(0.0, 0.0));
//	dis_fullGas = dis_pergas * capacity;
//	station[0].second = price_start;
//	station[numberOfGasStation + 1].first = totalDistance;
//	for (int i = 1; i <= numberOfGasStation; i++)
//	{
//		cin >> station[i].first >> station[i].second;
//		//�ж��ܷ񵽴�Ŀ�ĵ�
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