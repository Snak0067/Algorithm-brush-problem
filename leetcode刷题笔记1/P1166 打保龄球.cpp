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
//vector<char>v;
//vector<int>scorePerRound;
//vector<int>totalScore(1, 0);
//int main() {
//	int idx = 0;
//	v.resize(50);
//	string input;
//	getline(cin, input);
//	for (int i = 0; i < input.size(); i++)
//	{
//		if (input[i] != ' ') {
//			v[idx++] = input[i];
//		}
//	}
//	int  len = idx, turn = 1;
//	idx = 0;
//	while (idx < len - 1 && turn <= 10) {
//		int cur = 0;
//		if (v[idx] == '/') {
//			cur = 10;
//			if (v[idx + 1] == '/') {
//				cur += 10 + (v[idx + 2] == '/' ? 10 : v[idx + 2] - '0');
//			}
//			else {
//				if (v[idx + 2] == '/') {
//					cur += 10;
//				}
//				else {
//					cur += (v[idx + 1] == '/' ? 10 : v[idx + 1] - '0');
//					cur += (v[idx + 2] == '/' ? 10 : v[idx + 2] - '0');
//				}
//			}
//			idx = idx + 1;
//		}
//		else {
//			if (v[idx + 1] == '/') {
//				cur = 10 + (v[idx + 2] == '/' ? 10 : v[idx + 2] - '0');
//			}
//			else {
//				cur = v[idx] + v[idx + 1] - '0' - '0';
//			}
//			idx = idx + 2;
//		}
//		scorePerRound.push_back(cur);
//		totalScore.push_back(totalScore.back() + cur);
//		turn++;
//	}
//	for (int i = 0; i < scorePerRound.size(); i++)
//	{
//		if (i != 0)printf(" ");
//		printf("%d", scorePerRound[i]);
//	}
//	printf("\n");
//	for (int i = 1; i < totalScore.size(); i++)
//	{
//		if (i != 1)printf(" ");
//		printf("%d", totalScore[i]);
//	}
//	printf("\n");
//	return 0;
//}