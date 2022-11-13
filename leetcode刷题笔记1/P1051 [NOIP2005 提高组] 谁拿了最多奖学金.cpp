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
//string ansname;
//int maxPrize = 0, totalPrize = 0;
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		string name, isleader, isWest;
//		int	finalGrade, classGrade, leader, West, paper, prize = 0;
//		cin >> name >> finalGrade >> classGrade;
//		cin >> isleader >> isWest >> paper;
//		leader = (isleader == "Y" ? 1 : 0);
//		West = (isWest == "Y" ? 1 : 0);
//		if (finalGrade > 80 && paper >= 1) {
//			prize += 8000;
//		}
//		if (finalGrade > 85 && classGrade > 80) {
//			prize += 4000;
//		}
//		if (finalGrade > 90)prize += 2000;
//		if (finalGrade > 85 && West == 1)prize += 1000;
//		if (classGrade > 80 && leader == 1)prize += 850;
//		if (prize > maxPrize) {
//			maxPrize = prize;
//			ansname = name;
//		}
//		totalPrize += prize;
//	}
//	printf("%s\n%d\n%d\n", ansname.c_str(), maxPrize, totalPrize);
//
//	return 0;
//}