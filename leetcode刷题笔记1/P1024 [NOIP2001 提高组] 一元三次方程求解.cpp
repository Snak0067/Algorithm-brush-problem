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
//#include<math.h>
//using namespace std;
//vector<double>ans;
//unordered_map<double, int>cnt;
//double a, b, c, d;
//double calc(double x) {
//	return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
//}
//int judge(double x) {
//	double result = calc(x);
//	if (fabs(result) < 1e-9) {
//		return 0;
//	}
//	else if (result > 0) {
//		return 1;
//	}
//	else {
//		return -1;
//	}
//}
//double extract(double left, double right) {
//	while (true) {
//		double mid = (left + right) / 2.0;
//		double la = calc(left), lb = calc(right), lm = calc(mid);
//		if (fabs(la) < 1e-6) {
//			return left;
//		}
//		else if (fabs(lb) < 1e-6) {
//			return right;
//		}
//		else if (fabs(lb - la) < 0.01) {
//			return mid;
//		}
//		else if (fabs(lm) < 1e-6) {
//			return mid;
//		}
//		else if (la * lm < 0) {
//			right = mid;
//		}
//		else {
//			left = mid;
//		}
//	}
//	return -1;
//}
//int main() {
//	cin >> a >> b >> c >> d;
//	double rangeA = -100.0, rangeB = -99.0;
//	while (rangeA >= -100.0 && rangeB <= 100.0 && ans.size() < 3) {
//		int judgeA = judge(rangeA);
//		int judgeB = judge(rangeB);
//		if (judgeA + judgeB == 0 || judgeA == 0 || judgeB == 0) {
//			double temp = extract(rangeA, rangeB);
//			if (cnt.find(temp) == cnt.end()) {
//				ans.push_back(temp);
//				cnt[temp] = 1;
//			}
//		}
//		rangeA += 1.0;
//		rangeB += 1.0;
//	}
//	printf("%.2f %.2f %.2f", ans[0], ans[1], ans[2]);
//	return 0;
//}