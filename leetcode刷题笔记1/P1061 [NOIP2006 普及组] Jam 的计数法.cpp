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
//vector<char>word;
//int main() {
//	int s, t, w;
//	cin >> s >> t >> w;
//	string wrd;
//	cin >> wrd;
//	word.resize(w);
//
//	for (int i = 0; i < wrd.size(); i++)
//	{
//		word[i] = wrd[i];
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		bool hasSuffix = false;
//		for (int j = w - 1; j >= 0; j--)
//		{
//			char last = 'a' + t - w + j;
//			if (word[j] != last) {
//				char cur = word[j] + 1;
//				for (int u = j; u < w; u++)
//				{
//					word[u] = cur + (u - j);
//				}
//				hasSuffix = true;
//				break;
//			}
//		}
//		if (hasSuffix) {
//			for (int j = 0; j < w; j++)
//			{
//				cout << word[j];
//			}
//			cout << endl;
//		}
//		else {
//			break;
//		}
//	}
//	return 0;
//}