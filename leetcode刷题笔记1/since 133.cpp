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

int main() {
	ListNode* root = nullptr, * temp = nullptr;
	vector<int>nums1 = { 3,3,5,0,0,3,1,4 };
	vector<int>nums2 = { 9,15,7,20,3 };
	vector<int>nums3 = { 20,20,100,70,60 };
	for (int x : nums1) {
		if (root == nullptr) { root = new ListNode(x); temp = root; }
		else { temp->next = new ListNode(x); temp = temp->next; }
	}

	return 0;
}