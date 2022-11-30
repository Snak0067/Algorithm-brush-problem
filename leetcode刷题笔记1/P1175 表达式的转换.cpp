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
//unordered_map<char, int>priority = { {'+',1},{'-',1},{'*',2},{'/',2},{'^',3} };
//stack<char>stk;
//vector<char>v;
//int main() {
//	string s;
//	cin >> s;
//	for (char c : s)
//	{
//		if (isdigit(c)) {
//			v.push_back(c);
//		}
//		else if (c == '(') {
//			stk.push(c);
//		}
//		else if (c == ')') {
//			while (stk.top() != '(') {
//				v.push_back(stk.top());
//				stk.pop();
//			}
//			stk.pop();
//		}
//		else {
//			if (!stk.empty() && stk.top() == '^' && c == '^') {
//				stk.push(c);
//				continue;
//			}
//			while (!stk.empty() && priority[stk.top()] >= priority[c]) {
//				v.push_back(stk.top());
//				stk.pop();
//			}
//			stk.push(c);
//		}
//	}
//	while (!stk.empty()) {
//		v.push_back(stk.top());
//		stk.pop();
//	}
//	vector<int>temp;
//	while (v.size() >= 1) {
//		bool pre = false;
//		for (int i = 0; i < temp.size(); i++)
//		{
//			if (i != 0)printf(" ");
//			printf("%d", temp[i]);
//			pre = true;
//		}
//		for (int i = 0; i < v.size(); i++)
//		{
//			if (i != 0 || pre)printf(" ");
//			printf("%c", v[i]);
//		}
//		printf("\n");
//		for (int i = 0; i < v.size(); i++)
//		{
//			if (isdigit(v[i])) {
//				temp.push_back(v[i] - '0');
//			}
//			else {
//				int num1 = temp.back();
//				temp.pop_back();
//				int num2 = temp.back();
//				temp.pop_back();
//				int re = 0;
//				switch (v[i]) {
//				case '+':
//					re = num1 + num2;
//					break;
//				case '-':
//					re = num2 - num1;
//					break;
//				case '*':
//					re = num1 * num2;
//					break;
//				case '/':
//					re = num2 / num1;
//					break;
//				case '^':
//					re = int(pow(num2, num1));
//					break;
//				}
//				temp.push_back(re);
//				v.assign(v.begin() + i + 1, v.end());
//				break;
//			}
//		}
//
//	}
//	printf("%d\n", temp[0]);
//	return 0;
//}