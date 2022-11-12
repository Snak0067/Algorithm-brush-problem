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
//string in, post;
//void traverse(int ini, int inj, int posti, int postj) {
//	cout << post[postj];
//	int index = ini;
//	while (in[index] != post[postj])index++;
//	int left = index - ini;
//	int right = inj - index;
//	if (left > 0) {
//		traverse(ini, index - 1, posti, posti + left - 1);
//	}
//	if (right > 0) {
//		traverse(index + 1, inj, posti + left, postj - 1);
//	}
//}
//int main() {
//	cin >> in >> post;
//	traverse(0, post.size() - 1, 0, post.size() - 1);
//	return 0;
//}