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
//unordered_map<char, int>letterToNumber = { {'A',10}, {'B',11}, {'C',12}, {'D',13}, {'E',14}, {'F',15} };
//unordered_map<int, char>numberToLetter = { {15,'F'}, {14,'E'}, {13,'D'}, {12,'C'}, {11,'B'}, {10,'A'} };
//bool palindrome(string s) {
//	int l = 0, r = s.size() - 1;
//	while (l < r) {
//		if (s[l] != s[r])return false;
//		l++;
//		r--;
//	}
//	return true;
//}
//string restr(string s) {
//	reverse(s.begin(), s.end());
//	return s;
//}
//string plus_decimal(string a, string b, int hex) {
//	string ans;
//	int idx1 = 0, idx2 = 0, flag = 0;
//	while (idx1 < a.length() || idx2 < b.length()) {
//		char ca = '0', cb = '0';
//		if (idx1 < a.length()) {
//			ca = a[idx1];
//			idx1++;
//		}
//		if (idx2 < b.length()) {
//			cb = b[idx2];
//			idx2++;
//		}
//		char temp;
//		if (hex != 16) {
//			temp = ca + cb - '0' + flag;
//			if (temp - '0' >= hex) {
//				temp -= hex;
//				flag = 1;
//			}
//			else {
//				flag = 0;
//			}
//		}
//		else {
//			int add1, add2;
//			if (ca >= 'A' && ca <= 'F') {
//				add1 = letterToNumber[ca];
//			}
//			else {
//				add1 = ca - '0';
//			}
//			if (cb >= 'A' && cb <= 'F') {
//				add2 = letterToNumber[cb];
//			}
//			else {
//				add2 = cb - '0';
//			}
//			int ch = add1 + add2 + flag;
//			if (ch >= 16) {
//				flag = 1;
//				ch -= 16;
//			}
//			else {
//				flag = 0;
//			}
//			if (ch > 10) {
//				temp = numberToLetter[ch];
//			}
//			else {
//				temp = ch + '0';
//			}
//		}
//		ans.push_back(temp);
//	}
//	if (flag > 0) {
//		ans.push_back('0' + flag);
//	}
//	reverse(ans.begin(), ans.end());
//	return ans;
//}
//int main() {
//	int decimal;
//	string n;
//	cin >> decimal >> n;
//	int cnt = 0;
//	while (!palindrome(n) && cnt < 30) {
//		n = plus_decimal(n, restr(n), decimal);
//		cnt++;
//	}
//	if (cnt < 30) {
//		printf("STEP=%d", cnt);
//	}
//	else {
//		printf("Impossible!");
//	}
//	return 0;
//}