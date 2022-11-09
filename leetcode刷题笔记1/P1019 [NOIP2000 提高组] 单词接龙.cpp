#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<stack>
#include<unordered_set>
#include<queue>
#include<limits.h>
using namespace std;
unordered_map<string, vector<string>>mmap;
string ans;
int repeatLength(string a, string b) {
	int len = 1, alen = a.length();
	string asub, bsub;
	while (len < a.size() && len < b.size()) {
		asub = a.substr(alen - len, len);
		bsub = b.substr(0, len);
		if (asub == bsub)return len;
		len++;
	}
	return 0;
}
bool connect(string a, string b) {
	if (repeatLength(a, b) != 0) {
		return true;
	}
	return false;
}
void dfs(string curWord, string curDragon, unordered_map<string, int>count) {
	bool hasSuffix = false;
	for (int i = 0; i < mmap[curWord].size(); i++) {
		string temp = mmap[curWord][i];
		if (count[temp] < 2) {
			count[temp]++;
			int repeatLen = repeatLength(curWord, temp);
			string nextDragon = curDragon.substr(0, curDragon.size() - repeatLen);
			nextDragon += temp;
			dfs(temp, nextDragon, count);
			hasSuffix = true;
			count[temp]--;
		}
	}
	if (!hasSuffix) {
		if (curDragon.length() > ans.length()) {
			ans = curDragon;
		}
		return;
	}
}
int main() {
	int n;
	string word;
	vector<string>words;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> word;
		vector<string>v;
		mmap[word] = v;
		if (connect(word, word)) {
			mmap[word].push_back(word);
		}
		for (auto it = mmap.begin(); it != mmap.end(); it++)
		{
			string a = it->first;
			if (a.find(word) == string::npos && word.find(a) == string::npos) {
				if (connect(a, word)) {
					mmap[a].push_back(word);
				}
				if (connect(word, a)) {
					mmap[word].push_back(a);
				}
			}
		}
		words.push_back(word);
	}
	char begin;
	cin >> begin;
	unordered_map<string, int>count;
	for (int i = 0; i < words.size(); i++)
	{
		if (words[i][0] == begin) {
			count[words[i]]++;
			dfs(words[i], words[i], count);
			count[words[i]]--;
		}
	}
	cout << ans.length() << endl;
	return 0;
}