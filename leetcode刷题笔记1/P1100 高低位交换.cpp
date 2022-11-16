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
//
//int main() {
//	long long num;
//	cin >> num;
//	vector<int>v;
//	while (num > 0) {
//		v.push_back(num % 2);
//		num /= 2;
//	}
//	while (v.size() < 32) {
//		v.push_back(0);
//	}
//	reverse(v.begin(), v.end());
//	vector<int>newv;
//	newv.insert(newv.begin(), v.begin() + 16, v.end());
//	newv.insert(newv.end(), v.begin(), v.begin() + 16);
//	long long n = 0;
//	for (int i = 31; i >= 0; i--)
//	{
//		n += ((long long)pow(2, 31 - i)) * newv[i];
//	}
//	cout << n << endl;
//	return 0;
//}