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
//string s, input;
//vector<string>v;
//int n[20005];
//bool huiwen(int i, int j) {
//	while (i < j) {
//		if (!isalpha(s[i])) {
//			i++;
//		}
//		else if (!isalpha(s[j])) {
//			j--;
//		}
//		else {
//			if (s[i] != s[j]) {
//				return false;
//			}
//			i++; j--;
//		}
//	}
//	return true;
//}
//int main() {
//	while (getline(cin, input)) {
//		if (input == "")break;
//		v.push_back(input);
//	}
//	int num = 0;
//	for (int i = 0; i < v.size(); i++)
//	{
//		s = s + v[i];
//	}
//	for (int j = 0; j < s.size(); j++)
//	{
//		if (isalpha(s[j])) {
//			n[j] = ++num;
//		}
//	}
//	string origin = s;
//	transform(s.begin(), s.end(), s.begin(), ::tolower);
//	int maxn = 0, a, b;
//	for (int i = 0; i < s.length(); i++)
//	{
//		if (!isalpha(s[i]))continue;
//		int nxt = s.find(s[i], i + 1);
//		while (nxt != string::npos) {
//			int alnum = n[nxt] - n[i] + 1;
//			if (alnum > maxn && huiwen(i, nxt)) {
//				a = i;
//				b = nxt;
//				maxn = alnum;
//			}
//			nxt = s.find(s[i], nxt + 1);
//		}
//	}
//	printf("%d\n%s", maxn, origin.substr(a, b - a + 1).c_str());
//	return 0;
//}