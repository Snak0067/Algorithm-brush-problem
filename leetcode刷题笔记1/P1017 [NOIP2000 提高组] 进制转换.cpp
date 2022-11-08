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
//vector<char>mapping = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K' };
//string conversionOfNumberSystem(int num, int hex) {
//	string ans;
//	while (num != 0 && num != 1) {
//		int remainder = num % hex;
//		int quotient = num / hex;
//		if (remainder < 0) {
//			quotient += 1;
//			remainder = num - quotient * hex;
//		}
//		ans.push_back(mapping[remainder]);
//		num = quotient;
//	}
//	if (num != 0)ans.push_back(mapping[num]);
//	reverse(ans.begin(), ans.end());
//	return ans;
//}
//int main() {
//	int n, cardinalNumber;
//	cin >> n >> cardinalNumber;
//	printf("%d=%s(base%d)", n, conversionOfNumberSystem(n, cardinalNumber).c_str(), cardinalNumber);
//	return 0;
//}