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
//vector<unordered_map<string, int>>v(4);
//unordered_set<string>uset = { "S12","H1", "H2", "H3", "H4", "H5", "H6",
//"H7", "H8", "H9", "H10","H11","H12","H13","D11","C10" };
//unordered_map<string, int>mmap = { {"S12",-100},{"H1",-50}, {"H2",-2}, {"H3",-3},
//	{ "H4",-4},{"H5",-5}, {"H6",-6},{"H7",-7}, {"H8",-8}, {"H9",-9},{ "H10",-10},
//	{"H11",-20},{"H12",-30},{"H13",-40},{"D11",100 } ,{"D10",100}};
//int main() {
//	int a, b, c, d;
//	while (true) {
//		vector<int>h(14);
//		for (int i = 0; i < 4; i++)
//		{
//			cin >> a;
//			v[i].clear();
//			for (int j = 0; j < a; j++)
//			{
//				string input;
//				cin >> input;
//				if (uset.count(input)) {
//					v[i][input] = 1;
//					if (input[0] == 'H') {
//						h[stoi(input.substr(1))] = i;
//					}
//				}
//			}
//		}
//		if (v[0].empty() && v[1].empty() && v[2].empty() && v[3].empty())break;
//		bool samePlace = true;
//		for (int i = 1; i < 13; i++)
//		{
//			if (h[i] != h[0]) {
//				samePlace = false;
//				break;
//			}
//		}
//		//若有一玩家持有所有 16 张计分牌，则得 +1000 分。其余三家均得零分
//		if (v[h[0]].size() == 16) {
//			for (int i = 0; i < 4; i++)
//			{
//				if (i != 0)printf(" ");
//				if (i == h[0]) {
//					printf("1000");
//				}
//				else {
//					printf("0");
//				}
//			}
//			printf("\n");
//			continue;
//		}
//		else {
//			//若红心牌 H1 至H13 均在同一家
//			int redPlayer = h[0];
//			for (int i = 0; i < 4; i++)
//			{
//				int score = 0;
//				if (i != 0)printf(" ");
//				if (v[i].size() == 1 && v[i].begin()->first == "C10") {
//					score = 50;
//				}
//				else {
//					if (i == redPlayer && samePlace) {
//
//						if (v[redPlayer].count("S12") && v[redPlayer].count("D11")) {
//							score = 500;
//						}
//						else {
//							score = 200;
//							if (v[redPlayer].count("S12")) {
//								score += mmap["s12"];
//							}
//							if (v[redPlayer].count("D11")) {
//								score += mmap["D11"];
//							}
//							if (v[redPlayer].count("D10")) {
//								score += 100;
//							}
//							if (v[redPlayer].count("C10")) {
//								score *= 2;
//							}
//						}
//					}
//					else {
//						for (auto j = v[i].begin(); j != v[i].end(); j++)
//						{
//							if (mmap.count(j->first)) {
//								score += mmap[j->first];
//							}
//						}
//						if (v[i].count("C10")) {
//							score *= 2;
//						}
//					}
//				}
//				if (score > 0) {
//					printf("+%d", score);
//				}
//				else {
//					printf("%d", score);
//				}
//			}
//
//		}
//		printf("\n");
//	}
//	return 0;
//
//}