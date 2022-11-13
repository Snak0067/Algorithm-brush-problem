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
//
//int main() {
//	string cipertext, secretkey, ans;
//	cin >> secretkey >> cipertext;
//	while (secretkey.length() < cipertext.length()) {
//		secretkey += secretkey;
//	}
//	string cipertext_copy = cipertext, secretkey_copy = secretkey;
//	transform(cipertext_copy.begin(), cipertext_copy.end(), cipertext_copy.begin(), ::tolower);
//	transform(secretkey_copy.begin(), secretkey_copy.end(), secretkey_copy.begin(), ::tolower);
//	for (int i = 0; i < cipertext.size(); i++)
//	{
//		if (cipertext_copy[i] < secretkey_copy[i]) {
//			cipertext_copy[i] += 26;
//		}
//		if (cipertext[i] >= 'A' && cipertext[i] <= 'Z') {
//			ans.push_back(cipertext_copy[i] - secretkey_copy[i] + 'A');
//		}
//		else {
//			ans.push_back(cipertext_copy[i] - secretkey_copy[i] + 'a');
//		}
//
//	}
//	cout << ans << endl;
//	return 0;
//}