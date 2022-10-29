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
using namespace std;
const int INF = 999999999;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;
	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}
	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};
//133. 克隆图
class cloneGraphSolution {
public:
	Node* cloneGraph(Node* node) {
		unordered_map<int, Node*>mmap;
		if (node == nullptr)return node;
		Node* cur = new Node(node->val);
		mmap[1] = cur;
		queue<Node*>q;
		q.push(node);
		while (!q.empty()) {
			Node* top = q.front();
			q.pop();
			for (Node* nod : top->neighbors) {
				if (mmap.find(nod->val) == mmap.end()) {
					mmap[nod->val] = new Node(nod->val);
					q.push(nod);
				}
			}
		}
		vector<int>vis(mmap.size() + 1, -1);
		q.push(node);
		vis[node->val] = 1;
		while (!q.empty()) {
			Node* top = q.front();
			q.pop();
			for (Node* x : top->neighbors) {
				mmap[top->val]->neighbors.push_back(mmap[x->val]);
				if (vis[x->val] == -1) {
					q.push(x);
					vis[x->val] = 1;
				}
			}
		}
		return mmap[1];
	}
};
//1773. 统计匹配检索规则的物品数量
int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
	int cnt = 0, idx;
	if (ruleKey == "type")idx = 0;
	else if (ruleKey == "color")idx = 1;
	else if (ruleKey == "name")idx = 2;
	for (vector<string>v : items) {
		if (v[idx] == ruleValue)cnt++;
	}
	return cnt;
}
//134. 加油站
class canCompleteCircuitSolution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		int i = 0;
		while (i < n) {
			int sumOfGas = 0, sumOfCost = 0;
			int cnt = 0;
			while (cnt < n) {
				int j = (i + cnt) % n;
				sumOfGas += gas[j];
				sumOfCost += cost[j];
				if (sumOfGas < sumOfCost) {
					i += (cnt + 1);
					break;
				}
				cnt++;
			}
			if (cnt == n)return i;
		}
		return -1;
	}
};
//135. 分发糖果
class candySolution {
public:
	int candy(vector<int>& ratings) {
		int  n = ratings.size(), cnt = 0;
		vector<int>candy_up(n, 1);
		vector<int>candy_down(n, 1);
		for (int i = 0; i < n - 1; i++) {
			if (ratings[i + 1] > ratings[i]) {
				candy_up[i + 1] = candy_up[i] + 1;
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			if (i > 0 && ratings[i] < ratings[i - 1]) {
				candy_down[i - 1] = candy_down[i] + 1;
			}
			cnt += max(candy_down[i], candy_up[i]);
		}
		return cnt;
	}
};
//139. 单词拆分
class wordBreakSolution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int n = s.length(), minl = INT_MAX;
		for (int j = 0; j < wordDict.size(); j++) {
			if (minl > wordDict[j].length())minl = wordDict[j].length();
		}
		vector<int>dp(n + 1, -1);
		dp[n] = 1;
		for (int i = n - minl; i >= 0; i--) {
			int len = n - i;
			for (int j = 0; j < wordDict.size(); j++) {
				int wordlen = wordDict[j].length();
				if (wordlen > len)continue;
				if (s.substr(i, wordlen) == wordDict[j]) {
					dp[i] &= dp[i + wordlen];
					if (dp[i] == 1)break;
				}
			}
		}
		return dp[0] == 1;
	}
};
//140. 单词拆分 II
class wordBreak_Solution {
private:
	vector<string>res;
	string ans;
public:
	void dfs(string s, vector<string>& wordDict, vector<int>dp, int begin) {

	}
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		int n = s.length(), minl = INT_MAX;
		for (int j = 0; j < wordDict.size(); j++) {
			if (minl > wordDict[j].length())minl = wordDict[j].length();
		}
		vector<int>dp(n + 1, -1);
		dp[n] = 1;
		for (int i = n - minl; i >= 0; i--) {
			int len = n - i;
			for (int j = 0; j < wordDict.size(); j++) {
				int wordlen = wordDict[j].length();
				if (wordlen > len)continue;
				if (s.substr(i, wordlen) == wordDict[j]) {
					dp[i] &= dp[i + wordlen];
					if (dp[i] == 1)break;
				}
			}
		}
		if (dp[0] != 1)return res;
		dfs(s, wordDict, dp, 0);
		return res;
	}
};

int main() {
	ListNode* root = nullptr, * temp = nullptr;
	vector<int>nums1 = { 1,2,3,4,5 };
	vector<int>nums2 = { 3,4,5,1,2 };
	vector<string>str = { "apple","pen","applepen","pine","pineapple" };
	for (int x : nums1) {
		if (root == nullptr) { root = new ListNode(x); temp = root; }
		else { temp->next = new ListNode(x); temp = temp->next; }
	}
	wordBreakSolution ws;
	ws.wordBreak("pineapplepenapple", str);
	return 0;
}
