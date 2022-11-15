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
//vector<int>price;
//vector<int>send;
//int main() {
//	int w, n;
//	cin >> w >> n;
//	price.resize(n);
//	send.assign(n, false);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> price[i];
//	}
//	sort(price.begin(), price.end(), greater<int>());
//	int ans = 0, lastIndex = n - 1;
//	for (int i = 0; i < n; i++)
//	{
//		if (send[i] == true)break;
//		if (price[i] + price[lastIndex] > w) {
//			ans++;
//		}
//		else {
//			send[lastIndex] = true;
//			lastIndex--;
//			ans++;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}