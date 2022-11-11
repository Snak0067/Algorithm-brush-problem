//#include<iostream>
//#include<unordered_map>
//#include <cstring>
//#include<limits.h>
//using namespace std;
//int ans = 0;
//int memory[1010];
//int count(int n) {
//	int res = 1;
//	for (int i = 1; i <= n / 2; i++)
//	{
//		if (memory[i] == -1) {
//			memory[i] = count(i);
//		}
//		res += memory[i];
//	}
//	memory[n] = res;
//	return res;
//}
//int main() {
//	int n, ans = 0;
//	memset(memory, -1, sizeof(memory));
//	cin >> n;
//	cout << count(n) << endl;
//	return 0;
//}