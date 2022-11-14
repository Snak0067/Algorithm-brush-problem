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
//vector<vector<char>>fbi;
//string divide(int i, int j) {
//	string res = "";
//	if (i == j) {
//		res.push_back(fbi[i][j]);
//		return res;
//	}
//	int mid = (i + j) >> 1;
//	res += divide(i, mid);
//	res += divide(mid + 1, j);
//	res.push_back(fbi[i][j]);
//	return res;
//}
//int main() {
//	int n;
//	string s;
//	cin >> n >> s;
//	n = pow(2, n);
//	fbi.assign(n, vector<char>(n));
//	for (int i = 0; i < n; i++)
//	{
//		if (s[i] == '0') {
//			fbi[i][i] = 'B';
//		}
//		else {
//			fbi[i][i] = 'I';
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			if (fbi[i][j - 1] == 'F') {
//				fbi[i][j] = fbi[i][j - 1];
//				continue;
//			}
//			else if (fbi[i][j - 1] == 'I' && s[j] == '0' || fbi[i][j - 1] == 'B' && s[j] == '1') {
//				fbi[i][j] = 'F';
//			}
//			else {
//				fbi[i][j] = fbi[i][j - 1];
//			}
//		}
//	}
//	cout << divide(0, s.length() - 1) << endl;
//	return 0;
//}