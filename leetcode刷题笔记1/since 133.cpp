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
	unordered_map<string, int>mmap;
	vector<string>res;
	string ans;
public:
	void dfs(string s, vector<int>dp, int begin) {
		int len = ans.length(), cnt = 0;
		for (int i = begin + 1; i < s.size(); i++) {
			if (dp[i] == -1)continue;
			if (mmap.find(s.substr(begin, i - begin)) != mmap.end()) {
				ans = ans + s.substr(begin, i - begin) + " ";
				dfs(s, dp, i);
				ans = ans.substr(0, len);
				cnt++;
			}
			else if (cnt >= 1) {
				return;
			}
		}
		string cur = s.substr(begin);
		if (mmap.find(cur) != mmap.end())res.push_back(ans + cur);
		return;
	}
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		int n = s.length(), minl = INT_MAX;
		for (int j = 0; j < wordDict.size(); j++) {
			mmap[wordDict[j]] = 1;
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
		dfs(s, dp, 0);
		return res;
	}
};
//141. 环形链表
class hasCycleSolution {
public:
	bool hasCycle(ListNode* head) {
		unordered_map<ListNode*, int>mmap;
		while (head != nullptr) {
			if (mmap.find(head) == mmap.end()) {
				mmap[head] = 1;
			}
			else return true;
			head = head->next;
		}
		return false;
	}
};
class detectCycleSolution {
public:
	ListNode* detectCycle(ListNode* head) {
		unordered_map<ListNode*, int>mmap;
		while (head != nullptr) {
			if (mmap.find(head) == mmap.end()) {
				mmap[head] = 1;
			}
			else return head;
			head = head->next;
		}
		return nullptr;
	}
};

//143. 重排链表
class reorderListSolution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* pre = nullptr, * cur = head;
		while (cur != nullptr) {
			ListNode* temp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = temp;
		}
		return pre;
	}
	ListNode* middleNode(ListNode* head) {
		ListNode* slow = head, * fast = head;
		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next;
			fast = fast->next;
		}
		return slow;
	}
	void mergeList(ListNode* l1, ListNode* l2) {
		ListNode* left, * right;
		while (l1 != nullptr && l2 != nullptr) {
			left = l1->next;
			right = l2->next;

			l1->next = l2;
			l1 = left;

			l2->next = l1;
			l2 = right;
		}
	}
	void reorderList(ListNode* head) {
		if (head == nullptr)return;
		ListNode* mid = middleNode(head);
		ListNode* l1 = head;
		ListNode* l2 = mid->next;
		mid->next = nullptr;
		l2 = reverseList(l2);
		mergeList(l1, l2);
	}
};
//784. 字母大小写全排列
class letterCasePermutation_Solution {
private:
	vector<string>ans;
public:
	vector<string> letterCasePermutation(string s) {
		int len = s.length();
		if (len == 0)return ans;
		ans.push_back(s.substr(0, 1));
		if (!(s[0] <= '9' && s[0] >= '0')) {
			string temp = "";
			char ch = s[0];
			if (islower(ch)) {
				ch = toupper(ch);
			}
			else {
				ch = tolower(ch);
			}
			temp.push_back(ch);
			ans.push_back(temp);
		}
		for (int i = 1; i < len; i++) {
			vector<string>temp = ans;
			if (s[i] <= '9' && s[i] >= '0') {
				for (int u = 0; u < ans.size(); u++) {
					ans[u].push_back(s[i]);
				}
			}
			else {
				int n = ans.size();
				ans.insert(ans.end(), temp.begin(), temp.end());
				char other = (islower(s[i]) ? toupper(s[i]) : tolower(s[i]));
				for (int u = 0; u < n; u++) {
					ans[u].push_back(s[i]);
				}
				for (int u = n; u < 2 * n; u++) {
					ans[u].push_back(other);
				}
			}
		}
		return ans;
	}
};
//144. 二叉树的前序遍历
class preorderTraversalSolution {
private:
	vector<int>ans;
public:
	void dfs(TreeNode* root) {
		if (root == nullptr)return;
		ans.push_back(root->val);
		dfs(root->left);
		dfs(root->right);
	}
	vector<int> preorderTraversal(TreeNode* root) {
		dfs(root);
		return ans;
	}
};
//145. 二叉树的后序遍历
class postorderTraversalSolution {
private:
	vector<int>ans;
public:
	void dfs(TreeNode* root) {
		if (root == nullptr)return;
		dfs(root->left);
		dfs(root->right);
		ans.push_back(root->val);
	}
	vector<int> postorderTraversal(TreeNode* root) {
		dfs(root);
		return ans;
	}
};
//146. LRU 缓存
class LRUCache {
private:
	int index = 0;
	int cap;
	unordered_map<int, int>keys;
	unordered_map<int, int>idx;
	vector<int>v;
public:
	LRUCache(int capacity) {
		this->cap = capacity;
	}

	int get(int key) {
		if (keys.find(key) == keys.end()) {
			return -1;
		}
		else {
			v[idx[key]] = -1;
			v.push_back(key);
			idx[key] = v.size() - 1;
			return keys[key];
		}
	}
	void put(int key, int value) {
		if (keys.find(key) != keys.end()) {
			v[idx[key]] = -1;
		}
		else {
			if (cap > 0) {
				cap--;
			}
			else {
				while (v[index] == -1)index++;
				int cur_key = v[index];
				v[index] = -1;
				keys.erase(cur_key);
				idx.erase(cur_key);
			}
		}
		v.push_back(key);
		keys[key] = value;
		idx[key] = v.size() - 1;
	}
};
//147. 对链表进行插入排序
class insertionSortListSolution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == nullptr)return head;
		ListNode* dummyhead = new ListNode(0);
		dummyhead->next = head;
		ListNode* lastSorted = head, * cur = head->next;
		while (cur != nullptr) {
			if (cur->val > lastSorted->val) {
				lastSorted->next = cur;
				lastSorted = lastSorted->next;
			}
			else {
				ListNode* pre = dummyhead;
				while (pre->next->val < cur->val)pre = pre->next;
				lastSorted->next = cur->next;
				cur->next = pre->next;
				pre->next = cur;
			}
			cur = lastSorted->next;
		}
		return dummyhead->next;
	}
};
//481. 神奇字符串
class magicalStringSolution {
public:
	int magicalString(int n) {
		if (n == 1)return 1;
		else if (n <= 4)return 2;
		else if (n <= 6)return 3;
		int num_index = 0, str_index = 0, insert_num = 2;
		string str = "122112";
		while (str.length() < n) {
			int num = str[num_index++] - '0';
			insert_num = 3 - insert_num;
			while (num > 0) {
				num--;
				if (str_index == str.length()) {
					str.push_back('0' + insert_num);
				}
				str_index++;
			}
		}
		vector<int>v(2);
		for (int i = 0; i < n; i++)
		{
			v[str[i] - '1']++;
		}
		return v[0];
	}
};
//150. 逆波兰表达式求值
int evalRPN(vector<string>& tokens) {
	stack<string>stk;
	for (string s : tokens) {
		if (s == "+" || s == "-" || s == "*" || s == "/") {
			long num1 = stoi(stk.top());
			stk.pop();
			long num2 = stoi(stk.top());
			stk.pop();
			long re;
			if (s == "+") {
				re = num1 + num2;
			}
			else if (s == "-") {
				re = num2 - num1;
			}
			else if (s == "*") {
				re = num1 * num2;
			}
			else if (s == "/") {
				re = num2 / num1;
			}
			stk.push(to_string(re));
		}
		else {
			stk.push(s);
		}
	}
	return stoi(stk.top());
}
//151. 反转字符串中的单词
string reverseWords(string s) {
	vector<string>ans;
	string temp = "";
	for (char ch : s) {
		if (ch == ' ') {
			if (temp.size() > 0) {
				ans.push_back(temp);
				temp = "";
			}
		}
		else {
			temp.push_back(ch);
		}
	}
	if (temp.size() > 0) {
		ans.push_back(temp);
	}
	reverse(ans.begin(), ans.end());
	string res;
	for (int i = 0; i < ans.size(); i++) {
		if (i != 0)res.push_back(' ');
		res += ans[i];
	}
	return res;
}
//155. 最小栈
class MinStack {
private:
	stack<int>stk, minstk;
public:
	MinStack() {

	}

	void push(int val) {
		stk.push(val);
		minstk.push(min(minstk.top(), val));
	}

	void pop() {
		minstk.pop();
		stk.pop();
	}

	int top() {
		return stk.top();
	}

	int getMin() {
		return minstk.top();
	}
};
//160. 相交链表
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
	unordered_set<ListNode*>visit;
	ListNode* ptr = headA;
	while (ptr != nullptr) {
		visit.insert(ptr);
		ptr = ptr->next;
	}
	ptr = headB;
	while (ptr != nullptr) {
		if (visit.count(ptr)) {
			return ptr;
		}
		ptr = ptr->next;
	}
	return nullptr;
}
//Maximum Gap
int maximumGap(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int maxGap = 0;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] - nums[i - 1] > maxGap)maxGap = nums[i] - nums[i - 1];
	}
	return maxGap;
}
//1662. 检查两个字符串数组是否相等
bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
	int n = word1.size(), m = word2.size();
	int elementId1 = 0, elementId2 = 0, charId1 = 0, charId2 = 0;
	while (elementId1 < word1.size() && elementId2 < word2.size()) {
		while (charId1 < word1[elementId1].size() && charId2 < word2[elementId2].size()) {
			if (word1[elementId1][charId1] != word2[elementId2][charId2]) {
				return false;
			}
			charId1++;
			charId2++;
		}
		if (charId1 >= word1[elementId1].size()) {
			charId1 = 0;
			elementId1++;
		}
		if (charId2 >= word2[elementId2].size()) {
			charId2 = 0;
			elementId2++;
		}
	}
	if (elementId1 != n || elementId2 != m || charId1 != 0 || charId2 != 0)return false;
	return true;
}
class maxPointsSolution {
public:
	int gcd(int a, int b) {
		return b ? gcd(b, a % b) : a;
	}
	int maxPoints(vector<vector<int>>& points) {

	}
};
//1668. 最大重复子字符串
class maxRepeatingSolution {
public:
	int maxRepeating(string sequence, string word) {
		string cur = word;
		int key = 1;
		while (sequence.find(cur) != string::npos) {
			key++;
			cur += word;
		}
		return key - 1;
	}
};

//1620. 网络信号最好的坐标
class bestCoordinateSolution {
public:
	vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
		int xMax = INT_MIN, yMax = INT_MIN;
		for (auto&& tower : towers) {
			int x = tower[0], y = tower[1];
			xMax = max(xMax, x);
			yMax = max(yMax, y);
		}
		int cx = 0, cy = 0;
		int maxQuality = 0;
		for (int x = 0; x <= xMax; x++) {
			for (int y = 0; y <= yMax; y++) {
				vector<int> coordinate = { x, y };
				int quality = 0;
				for (auto&& tower : towers) {
					int squaredDistance = getSquaredDistance(coordinate, tower);
					if (squaredDistance <= radius * radius) {
						double distance = sqrt((double)squaredDistance);
						quality += floor((double)tower[2] / (1 + distance));
					}
				}
				if (quality > maxQuality) {
					cx = x;
					cy = y;
					maxQuality = quality;
				}
			}
		}
		return { cx, cy };
	}

	int getSquaredDistance(const vector<int>& coordinate, const vector<int>& tower) {
		return (tower[0] - coordinate[0]) * (tower[0] - coordinate[0]) + (tower[1] - coordinate[1]) * (tower[1] - coordinate[1]);
	}
};
//165. 比较版本号
class compareVersionSolution {
public:
	int compareVersion(string version1, string version2) {
		string temp1 = "", temp2 = "";
		int index1 = 0, index2 = 0;
		while (index1 < version1.size() && index2 < version2.size()) {
			while (index1 < version1.size() && version1[index1] != '.') {
				temp1.push_back(version1[index1]);
				index1++;
			}
			while (index2 < version2.size() && version2[index2] != '.') {
				temp2.push_back(version2[index2]);
				index2++;
			}
			int num1 = stoi(temp1);
			int num2 = stoi(temp2);
			if (num1 < num2) {
				return -1;
			}
			else if (num1 > num2) {
				return 1;
			}
			temp1.clear();
			temp2.clear();
			index1++;
			index2++;
		}
		while (index1 < version1.size()) {
			while (index1 < version1.size() && version1[index1] != '.') {
				temp1.push_back(version1[index1]);
				index1++;
			}
			if (stoi(temp1) != 0) {
				return 1;
			}
			temp1.clear();
			index1++;
		}
		while (index2 < version2.size()) {
			while (index2 < version2.size() && version2[index2] != '.') {
				temp2.push_back(version2[index2]);
				index2++;
			}
			if (stoi(temp2) != 0) {
				return -1;
			}
			temp2.clear();
			index2++;
		}
		return 0;
	}
};
//166. 分数到小数
class fractionToDecimalSolution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		string ans;
		unordered_set<long>numerators;
		unordered_map<long, int>mmap;
		long numeratorLong = numerator;
		long denominatorLong = denominator;
		if (numeratorLong % denominatorLong == 0) {
			return to_string(numeratorLong / denominatorLong);
		}

		if (numeratorLong < 0 ^ denominatorLong < 0) {
			ans.push_back('-');
		}
		//整数部分
		numeratorLong = abs(numeratorLong);
		denominatorLong = abs(denominatorLong);
		long  integralPart = numeratorLong / denominatorLong;
		numeratorLong -= integralPart * denominatorLong;
		ans = ans + to_string(integralPart) + ".";
		while (numeratorLong != 0 && numeratorLong % denominatorLong != 0) {
			numeratorLong *= 10;
			if (numerators.count(numeratorLong)) {
				string circle = ans.substr(mmap[numeratorLong]);
				string pre = ans.substr(0, mmap[numeratorLong]);
				string re = pre + "(" + circle + ")";
				return re;
			}
			numerators.insert(numeratorLong);
			ans += to_string(numeratorLong / denominatorLong);
			mmap[numeratorLong] = ans.length() - 1;
			numeratorLong %= denominatorLong;
		}
		return ans;
	}
};
int main() {
	ListNode* root = nullptr, * temp = nullptr;
	vector<int>nums1 = { 1,2,3,4,5 };
	vector<int>nums2 = { 3,4,5,1,2 };
	vector<string>str1 = { "abc", "d", "defg" };
	vector<string>str2 = { "abcddefg" };
	for (int x : nums1) {
		if (root == nullptr) { root = new ListNode(x); temp = root; }
		else { temp->next = new ListNode(x); temp = temp->next; }
	}
	vector<vector<int>>v = { {46,48,17},{12,38,14} };
	fractionToDecimalSolution bs;
	bs.fractionToDecimal(1, 90);
	return 0;
}
