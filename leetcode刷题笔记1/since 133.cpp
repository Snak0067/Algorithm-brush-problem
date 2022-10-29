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
//133. ¿ËÂ¡Í¼
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

int main() {
	ListNode* root = nullptr, * temp = nullptr;
	vector<int>nums1 = { 3,3,5,0,0,3,1,4 };
	vector<int>nums2 = { 9,15,7,20,3 };
	vector<int>nums3 = { 20,20,100,70,60 };
	for (int x : nums1) {
		if (root == nullptr) { root = new ListNode(x); temp = root; }
		else { temp->next = new ListNode(x); temp = temp->next; }
	}
	Node* nod1 = new Node(1);
	Node* nod2 = new Node(2);
	Node* nod3 = new Node(3);
	Node* nod4 = new Node(4);
	nod1->neighbors.push_back(nod2);
	nod1->neighbors.push_back(nod4);
	nod2->neighbors.push_back(nod1);
	nod2->neighbors.push_back(nod3);
	nod3->neighbors.push_back(nod2);
	nod3->neighbors.push_back(nod4);
	nod4->neighbors.push_back(nod1);
	nod4->neighbors.push_back(nod3);
	cloneGraphSolution cs;
	cs.cloneGraph(nod1);
	return 0;
}