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
//unordered_map<int, vector<int>>memory;
//vector<int>power;
//vector<int>mul(vector<int>a, vector<int>b) {
//	int alen = a.size(), blen = b.size();
//	vector<int>res(alen + blen);
//	for (int i = alen - 1; i >= 0 && i >= alen - 510; i--)
//	{
//		int flag = 0, cur = 0, resIndex = res.size() - (alen - i);
//		for (int j = blen - 1; j >= 0 && j >= blen - 510; j--)
//		{
//			int temp = a[i] * b[j] + flag + res[resIndex];
//			res[resIndex] = temp % 10;
//			flag = temp / 10;
//			if (res.size() - resIndex >= 510) {
//				break;
//			}
//			resIndex--;
//		}
//		if (flag != 0) {
//			res[resIndex] = flag;
//		}
//	}
//	int nonzeroIndex = 0;
//	while (res[nonzeroIndex] == 0)nonzeroIndex++;
//	vector<int>ans;
//	ans.insert(ans.begin(), res.begin() + nonzeroIndex, res.end());
//	return ans;
//}
//int main() {
//	/*测试高精度乘法 高精*高精
//	string biga="1718371853578517354", bigb="48967893788975";
//	vector<int>a, b, res;
//	for (char ch : biga) {
//		a.push_back(ch - '0');
//	}
//	for (char ch : bigb) {
//		b.push_back(ch - '0');
//	}
//	res = mul(a, b);
//	for (int x : res) {
//		cout << x;
//	}*/
//	int p;
//	cin >> p;
//	while (p != 0) {
//		int time = 0;
//		while (p - pow(2, time) >= 0) {
//			time++;
//		}
//		p -= int(pow(2, time - 1));
//		power.push_back(time - 1);
//	}
//
//	int topPower = power[0], num = 0;
//	vector<int>initail = { 2 };
//	memory[0] = initail;
//	while (num < topPower) {
//		vector<int>cur = mul(memory[num], memory[num]);
//		num++;
//		memory[num] = cur;
//	}
//	reverse(power.begin(), power.end());
//	vector<int>ans = memory[power[0]];
//	for (size_t i = 1; i < power.size(); i++)
//	{
//		ans = mul(ans, memory[power[i]]);
//	}
//	ans[ans.size() - 1]--;
//	if (ans.size() < 500) {
//		cout << ans.size() << endl;
//		int numOfZero = 500 - ans.size();
//		int space = 0;
//		for (size_t i = 0; i < 500 - ans.size(); i++)
//		{
//			space++;
//			printf("0");
//			if (space % 50 == 0) {
//				printf("\n");
//			}
//		}
//		for (size_t i = 0; i < ans.size(); i++)
//		{
//			printf("%d", ans[i]);
//			space++;
//			if (space % 50 == 0) {
//				printf("\n");
//			}
//		}
//	}
//	else {
//		int space = 0;
//		unordered_map<int, int>weishu = { {0,1} };
//		vector<int>toptwo;
//		for (int i = 0; i <= power.back(); i++)
//		{
//			int nn = 0;
//			for (int j = 0; j < memory[i].size() && j < 3; j++)
//			{
//				nn = nn * 10 + memory[i][j];
//			}
//			toptwo.emplace_back(nn);
//		}
//		for (size_t i = 1; i <= power.back(); i++)
//		{
//			int curlen = weishu[i - 1];
//			int toplen = to_string(toptwo[i - 1]).length();
//			string st = to_string(toptwo[i - 1] * toptwo[i - 1]);
//			if (st.length() < toplen * 2) {
//				weishu[i] = curlen * 2 - 1;
//			}
//			else {
//				weishu[i] = curlen * 2;
//			}
//		}
//		int digitNum = 1, cur = 1;
//		for (size_t i = 0; i < power.size(); i++)
//		{
//			int curlen = to_string(cur).length();
//			int flen = to_string(toptwo[power[i]]).length();
//			string st = to_string(cur * toptwo[power[i]]);
//			if (st.length() < curlen + flen) {
//				digitNum = digitNum + weishu[power[i]] - 1;
//			}
//			else {
//				digitNum = digitNum + weishu[power[i]];
//			}
//			cur = stoi(st.substr(0, 4));
//		}
//		cout << digitNum << endl;
//		for (size_t i = 0; i < 500; i++)
//		{
//			printf("%d", ans[i]);
//			space++;
//			if (space % 50 == 0) {
//				printf("\n");
//			}
//		}
//	}
//	return 0;
//}