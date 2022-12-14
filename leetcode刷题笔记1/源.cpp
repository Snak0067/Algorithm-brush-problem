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
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;
	Node() : val(0), left(NULL), right(NULL), next(NULL) {}
	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};
//1780. 判断一个数字是否可以表示成三的幂的和
bool checkPowersOfThree(int n) {
	int bound = 2;
	while (pow(3, bound) <= n) {
		bound++;
	}
	while (n != 0 && bound >= 0) {
		bound = bound - 1;
		while (bound >= 0 && pow(3, bound) > n) {
			bound--;
		}
		if (bound >= 0) {
			n -= pow(3, bound);
		}
		else {
			return false;
		}
	}
	return true;
}
//33. 搜索旋转排序数组
int searchI(vector<int>& nums, int target) {
	int len = nums.size();
	if (len == 0)return -1;
	if (len == 1 && nums[0] != target) return -1;
	int l = 0, r = len - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		//左侧有序
		if (nums[mid] == target)return mid;
		if (nums[0] <= target) {
			if (nums[mid] < nums[0]) {
				r = mid - 1;
			}
			else {
				if (nums[mid] > target) {
					r = mid - 1;
				}
				else {
					l = mid + 1;
				}
			}
		}
		else {
			if (nums[len - 1] < nums[mid]) {
				l = mid + 1;
			}
			else {
				if (nums[mid] > target) {
					r = mid - 1;
				}
				else {
					l = mid + 1;
				}
			}
		}
	}
	return -1;
}
//153. 寻找旋转排序数组中的最小值
int findMin1(vector<int>& nums) {
	int len = nums.size(), i = 0, j = len - 1;
	if (nums[i] < nums[len - 1])return nums[i];
	while (i < j) {
		int mid = (i + j) / 2;
		if (nums[mid] > nums[j]) {
			i = mid + 1;
		}
		else {
			j = mid;
		}
	}
	return nums[i];
}
//162. 寻找峰值 爬坡法，根据mid的左右两端值进行比较
int findPeakElement(vector<int>& nums) {
	int len = nums.size(), i = 0, j = len - 1;
	if (len == 1)return 0;
	if (nums[0] > nums[1])return 0;
	if (nums[len - 1] > nums[len - 2])return len - 1;
	while (i < j) {
		int mid = (i + j) / 2;
		if (nums[mid] < nums[mid + 1]) {
			i = mid + 1;
		}
		else {
			j = mid;
		}
	}
	return i;
}
//82. 删除排序链表中的重复元素 II
ListNode* deleteDuplicatesII(ListNode* head) {
	ListNode* ptr = head;
	ListNode* ans = nullptr, * temp = nullptr, * second = nullptr;
	bool same = false;
	while (ptr != nullptr) {
		if (ptr->next != nullptr) {
			if (ptr->val == ptr->next->val) {
				if (same == false) {
					same = true;
				}
			}
			else {
				if (same == false) {
					if (ans == nullptr) {
						ans = new ListNode(ptr->val);
						temp = ans;
					}
					else {
						temp->next = new ListNode(ptr->val);
						temp = temp->next;
					}
				}
				else {
					same = false;
				}
			}
		}
		else {
			if (same == false) {
				if (ans == nullptr)ans = new ListNode(ptr->val);
				else {
					temp->next = new ListNode(ptr->val);
				}
			}
		}
		ptr = ptr->next;
	}
	return ans;
}
//15. 三数之和
vector<vector<int>> threeSum(vector<int>& nums) {
	int i, j, k, len = nums.size();
	sort(nums.begin(), nums.end());
	vector<vector<int>> temp;
	for (i = 0; i < len - 2; i++)
	{
		j = i + 1, k = len - 1;
		while (j < k) {
			if (nums[i] + nums[j] + nums[k] == 0) {
				temp.push_back(vector<int>{nums[i], nums[j], nums[k]});
				while (j < k && nums[j] == nums[j + 1])j++;
				while (j < k && nums[k] == nums[k - 1])k--;
				j++;
				k--;
			}
			else if (nums[i] + nums[j] + nums[k] < 0) {
				j++;
			}
			else {
				k--;
			}
		}
		while (nums[i] == nums[i + 1])i++;
	}
	return temp;
}
//844. 比较含退格的字符串
bool backspaceCompare(string s, string t) {
	string a, b;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '#' && i != 0) {
			a.pop_back();
		}
		else {
			a.push_back(s[i]);
		}
	}
	for (int i = 0; i < t.length(); i++) {
		if (t[i] == '#' && i != 0) {
			b.pop_back();
		}
		else {
			b.push_back(t[i]);
		}
	}
	return a == b;
}
//986. 区间列表的交集
vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
	int i = 0, j = 0;
	vector<vector<int>>ans;
	while (i < firstList.size() && j < secondList.size()) {
		int a1 = firstList[i][0], a2 = firstList[i][1], b1 = secondList[j][0], b2 = secondList[j][1];
		int start = max(a1, b1);
		int end = min(a2, b2);
		if (start <= end) {
			ans.push_back(vector<int>{start, end});
		}
		if (a2 > b2) {
			j++;
		}
		else {
			i++;
		}
	}
	return ans;
}
//438. 找到字符串中所有字母异位词
vector<int> findAnagrams(string s, string p) {
	vector<int>v, sv(26), pv(26);
	int slen = s.length(), plen = p.length();
	bool same = false;
	if (slen < plen)return v;
	for (int i = 0; i < plen; i++) {
		sv[s[i] - 'a']++;
		pv[p[i] - 'a']++;
	}
	if (sv == pv)v.push_back(0);
	for (int i = 1; i <= slen - plen; i++)
	{
		sv[s[i - 1] - 'a']--;
		sv[s[i + plen - 1] - 'a']++;
		if (sv == pv)v.push_back(i);
	}
	return v;
}
//713. 乘积小于 K 的子数组
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
	int i = 0, j = 0, mul = 1, cnt = 0;
	for (; j < nums.size(); j++) {
		mul *= nums[j];
		while (i <= j && mul >= k) {
			mul /= nums[i];
			i++;
		}
		cnt += j - i + 1;
	}
	return cnt;
}
//209. 长度最小的子数组
int minSubArrayLen1(int target, vector<int>& nums) {
	int i = 0, j = 0, sum = 0, cnt = 999;
	for (; j < nums.size(); j++)
	{
		sum += nums[j];
		while (i <= j && sum >= target) {
			if (j - i + 1 < cnt)cnt = j - i + 1;
			sum -= nums[i];
			i++;
		}
	}
	return cnt == 999 ? 0 : cnt;
}
//149. 直线上最多的点数
bool pointSort(vector<int>v1, vector<int>v2) {
	if (v1[0] != v2[0])return v1[0] < v2[0];
	return v1[1] < v2[1];
}
int maxPoints_line(vector<vector<int>>& points) {
	vector<vector<int>>v;
	unordered_map<string, int>k;
	unordered_map<string, vector<int>>same;
	int len = points.size();
	for (int i = 0; i < points.size(); i++)
	{
		string s = to_string(points[i][1]) + "_" + to_string(points[i][0]);
		if (same.find(s) != same.end())continue;
		same[s] = points[i];
		v.push_back(points[i]);
	}
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			double rate = (v[j][1] * 1.0 - v[i][1]) / (v[j][0] * 1.0 - v[i][0]);
			double b = v[j][1] - rate * v[j][0];
			string id = to_string(rate) + "_" + to_string(b);
			k[id]++;
		}
	}
	int max = -1;
	auto iter = k.begin();
	while (iter != k.end()) {
		if (iter->second > max)max = iter->second;
		iter++;
	}
	int cnt = 1;
	while (cnt < len && (cnt - 1) * cnt != max * 2) {
		cnt++;
	}
	return cnt;
}
//2427. 公因子的数目
int commonFactors(int a, int b) {
	int count = 0;
	for (int i = 0; i <= a; i++)
	{
		if (a % i == 0 && b % i == 0) {
			count++;
		}
	}
	return count;
}
//2428. 沙漏的最大总和
int findMaxSumOfSand(vector<vector<int>>& grid, int width, int height, int i, int j) {
	int numa = i, numb = height + i - 1, tempw = width, max = 0, temp = j;
	while (numa != numb) {
		for (int i = temp; i < tempw + temp; i++)
		{
			max += grid[numa][i];
			max += grid[numb][i];
		}
		numa++;
		numb--;
		tempw -= 2;
		temp++;
	}
	max += grid[numa][temp];
	return max;
}
int maxSumOfSand(vector<vector<int>>& grid) {
	int max = 0;
	for (int i = 0; i <= grid.size() - 3; i++) {
		for (int j = 0; j <= grid[i].size() - 3; j++)
		{
			int temp = findMaxSumOfSand(grid, 3, 3, i, j);
			if (max < temp) {
				max = temp;
			}
		}
	}
	return max;
}
//2429. 最小 XOR
//int minimizeXor(int num1, int num2) {
//	int c1 = __builtin_popcount(num1);
//	int c2 = __builtin_popcount(num2);
//	for (; c2 < c1; ++c2) num1 &= num1 - 1; // 最低的 1 变成 0
//	for (; c2 > c1; --c2) num1 |= num1 + 1; // 最低的 0 变成 1
//	return num1;
//}
//剑指 Offer II 001. 整数除法
//int divide(int a, int b) {
//
//}
int findRepeatNumber(vector<int>& nums) {
	map<int, int>mmap;
	for (int num : nums) {
		if (mmap.find(num) != mmap.end())return num;
		mmap[num]++;
	}
}
//剑指 Offer 04. 二维数组中的查找
bool findNumberIn2DArray1(vector<vector<int>>& matrix, int target) {
	int height = matrix.size(), width = matrix[0].size();
	int ha = 0, hb = height - 1, wa = 0, wb = width - 1;
	while (ha < height && matrix[ha][width - 1] < target)ha++;
	while (hb >= 0 && matrix[hb][0] > target)hb--;
	while (wa < width && matrix[height - 1][wa] < target)wa++;
	while (wb >= 0 && matrix[0][wb] > target)wb--;
	if (wb < 0 || hb < 0 || wa >= width || ha >= height)return false;
	for (int i = ha; i <= hb; i++)
	{
		for (int j = wa; j <= wb; j++)
		{
			if (matrix[i][j] == target)return true;
		}
	}
	return false;
}
//类似查找二叉搜索树
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0 || matrix[0].size() == 0)return false;
	int i = matrix[0].size() - 1, j = 0;
	while (i >= 0 && j < matrix.size()) {
		if (matrix[j][i] < target)j++;
		else if (matrix[j][i] > target)i--;
		else return true;
	}
	return false;
}
//剑指 Offer 05. 替换空格
string replaceSpace(string s) {
	string ans;
	for (char ch : s) {
		if (ch == ' ')ans += "%20";
		else ans.push_back(ch);
	}
	return ans;
}
//剑指 Offer 06. 从尾到头打印链表
vector<int> reversePrint(ListNode* head) {
	vector<int>ans;
	while (head != nullptr) {
		ans.push_back(head->val);
		head = head->next;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
//剑指 Offer 07. 前序后序求树
TreeNode* buildTreeHelp(vector<int>& pre, vector<int>& in, int ini, int inj, int prei, int prej) {
	TreeNode* head = new TreeNode(pre[prei]);
	int root = pre[prei], index = ini;
	while (index <= inj && in[index] != root)index++;
	int left = index - ini, right = inj - index;
	if (left > 0)head->left = buildTreeHelp(pre, in, ini, index - 1, prei + 1, prei + left);
	if (right > 0)head->right = buildTreeHelp(pre, in, index + 1, inj, prei + 1 + left, prej);
	return head;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.size() == 0 || inorder.size() == 0)return nullptr;
	return buildTreeHelp(preorder, inorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
}
//剑指 Offer 09. 用两个栈实现队列
class CQueue {
public:
	stack<int>a, b;
	CQueue() {

	}

	void appendTail(int value) {
		a.push(value);
	}

	int deleteHead() {
		if (b.empty()) {
			if (a.empty()) {
				return -1;
			}
			while (!a.empty()) {
				b.push(a.top());
				a.pop();
			}
		}
		int ans = b.top();
		b.pop();
		return ans;
	}
};
//剑指 Offer 10- I. 斐波那契数列
int fib(int n) {
	vector<long long>fibtemp;
	fibtemp.push_back(0);
	fibtemp.push_back(1);
	int cnt = 2;
	while (cnt <= n) {
		fibtemp.push_back((fibtemp[cnt - 2] + fibtemp[cnt - 1]) % 1000000007);
		cnt++;
	}
	return fibtemp[n];
}
//剑指 Offer 10- II. 青蛙跳台阶问题
int numWays(int n) {
	vector<int>way;
	way.push_back(1);
	way.push_back(1);
	int cnt = 2;
	while (n >= cnt) {
		way.push_back((way[cnt - 1] + way[cnt - 2]) % 1000000007);
		cnt++;
	}
	return way[n];
}
//剑指 Offer 11. 旋转数组的最小数字
int minArray(vector<int>& numbers) {
	int i = 0, j = numbers.size() - 1;
	while (i < j) {
		int mid = (i + j) / 2;
		if (numbers[mid] < numbers[j])j = mid;
		else if (numbers[mid] > numbers[j])i = mid + 1;
		else j--;
	}
	return numbers[i];
}
//154. 寻找旋转排序数组中的最小值 II
int findMin2(vector<int>& nums) {
	int i = 0, j = nums.size() - 1;
	while (i < j) {
		int mid = (i + j) / 2;
		if (nums[mid] < nums[j])j = mid;
		else if (nums[mid] > nums[j])i = mid + 1;
		else j--;
	}
	return nums[i];
}
//18. 四数之和
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	int len = nums.size();
	vector<vector<int>>ans;
	if (nums.size() < 4)return ans;
	map<string, vector<int>>mmap;
	sort(nums.begin(), nums.end());
	long  targetNum = (long)target;
	for (int i = 0; i < nums.size() - 3; i++)
	{
		for (int j = i + 1; j < nums.size() - 2; j++) {
			int newt = targetNum - nums[i] - nums[j];
			int left = j + 1, right = nums.size() - 1;
			if ((nums[len - 1] + nums[len - 2]) < newt) continue;
			if ((nums[j + 1] + nums[j + 2]) > newt) continue;
			while (left < right) {
				if ((long)nums[left] + (long)nums[right] < newt)left++;
				else if ((long)nums[left] + (long)nums[right] > newt)right--;
				else {
					string tab = to_string(nums[i]) + "_" + to_string(nums[j])
						+ "_" + to_string(nums[left]) + "_" + to_string(nums[right]);
					if (mmap.find(tab) == mmap.end()) {
						mmap[tab] = { nums[i],nums[j] ,nums[left] ,nums[right] };
						ans.push_back({ nums[i],nums[j] ,nums[left] ,nums[right] });
					}
					left++;
					right--;
				}
			}
		}
	}
	return ans;
}
//20. 有效的括号
bool isValid(string s) {
	int n = s.size();
	if (n % 2 == 1) {
		return false;
	}
	map<char, char>mmap = { {')','('},{']','['},{'}','{'} };
	stack<char>sta;
	for (char ch : s) {
		if (mmap.find(ch) != mmap.end()) {
			if (sta.empty() || sta.top() != mmap[ch]) {
				return false;
			}
			sta.pop();
		}
		else sta.push(ch);
	}
	return sta.empty();
}
//21. 合并两个有序链表  
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	if (list1 == nullptr || list2 == nullptr)return list1 == nullptr ? list2 : list1;
	ListNode head, * tail = &head, * aptr = list1, * bptr = list2;
	while (aptr && bptr) {
		if (aptr->val < bptr->val) {
			tail->next = aptr;
			aptr = aptr->next;
		}
		else {
			tail->next = bptr;
			bptr = bptr->next;
		}
		tail = tail->next;
	}
	tail->next = (aptr == nullptr ? bptr : aptr);
	return head.next;
}
//23. 合并K个升序链表 分而治之 分治排序
ListNode* merge(vector<ListNode*>& lists, int l, int r) {
	if (l == r)return lists[l];
	if (l > r)return nullptr;
	int mid = (l + r) >> 1;
	return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
	return merge(lists, 0, lists.size() - 1);
}
//24. 两两交换链表中的节点
ListNode* swapPairs(ListNode* head) {
	if (head == nullptr || head->next == nullptr)return head;
	ListNode* newhead = head->next;
	head->next = swapPairs(newhead->next);
	newhead->next = head;
	return newhead;
}
//25. K 个一组翻转链表
ListNode* reverseKGroup(ListNode* head, int k) {
	vector<int>v;
	stack<int> s;
	int cnt = 0;
	while (head) {
		if (cnt != 0 && cnt % k == 0) {
			while (!s.empty()) {
				v.push_back(s.top());
				s.pop();
			}
		}
		s.push(head->val);
		head = head->next;
		cnt++;
	}
	if (!s.empty()) {
		if (s.size() % k == 0) {
			while (!s.empty()) {
				v.push_back(s.top());
				s.pop();
			}
		}
		else {
			stack<int>news;
			while (!s.empty()) {
				news.push(s.top());
				s.pop();
			}
			while (!news.empty()) {
				v.push_back(news.top());
				news.pop();
			}
		}

	}
	ListNode root, * tail = &root;
	for (int val : v) {
		tail->next = new ListNode(val);
		tail = tail->next;
	}
	return root.next;
}
//26. 删除有序数组中的重复项
int removeDuplicates(vector<int>& nums) {
	int n = nums.size();
	if (n == 0) {
		return 0;
	}
	int l = 1, r = 1;
	while (r < nums.size()) {
		if (nums[r] != nums[r - 1]) {
			nums[l] = nums[r];
			l++;
		}
		r++;
	}
	return l;
}
//27. 移除元素
int removeElement(vector<int>& nums, int val) {
	int l = 0, r = 0;
	while (r < nums.size()) {
		if (nums[r] != val) {
			swap(nums[l], nums[r]);
			l++;
		}
		r++;
	}
	return l;
}
//28. 找出字符串中第一个匹配项的下标
int strStr(string haystack, string needle) {
	return haystack.find(needle);
}
//29. 两数相除
int divide(int dividend, int divisor) {
	if (dividend == INT_MIN) {
		if (divisor == 1)return INT_MIN;
		if (divisor == -1)return INT_MAX;
	}
	if (divisor == INT_MIN) {
		return (dividend == INT_MIN ? 1 : 0);
	}
	if (dividend == 0)return 0;
	int sigh = -1, result = 0;
	if (dividend > 0 && divisor > 0 || dividend < 0 && divisor < 0)sigh = 1;
	long dividend_long = (long)abs(dividend);
	long divisor_long = (long)abs(divisor);
	while (dividend_long >= divisor_long) {
		long i = 1;
		long temp = divisor_long;
		while (dividend_long >= temp) {
			dividend_long -= temp;
			result += i;
			i = i << 1;
			temp = temp << 1;
		}
	}
	result *= sigh;
	if (result > INT_MAX || result < INT_MIN) {
		return INT_MAX;
	}
	return (int)result;
}
//30. 串联所有单词的子串
bool matchSubstring(string s, map<string, int>mmap, int len) {
	map<string, int>mp;
	for (int i = 0; i < s.length(); i += len)mp[s.substr(i, len)]++;
	if (mp == mmap)return true;
	return false;
}
vector<int> findSubstring(string s, vector<string>& words) {
	vector<int>ans;
	map<string, int>mmap;
	if (words.size() == 0 || s.length() < words[0].size())return ans;
	int len = words[0].length(), lens = len * words.size();
	for (string word : words) {
		mmap[word]++;
	}
	if (s.length() < lens)return ans;
	for (int i = 0; i < s.length(); i++)
	{
		if (i + lens > s.length())break;
		if (mmap.find(s.substr(i, len)) == mmap.end())continue;
		if (matchSubstring(s.substr(i, lens), mmap, len))ans.push_back(i);
	}
	return ans;
}
//856. 括号的分数
int scoreOfParentheses(string s) {
	if (s.size() == 2)return 1;
	int cnt = 0, len = 0;
	for (int i = 0; i < s.size(); i++)
	{
		cnt += (s[i] == ')' ? -1 : 1);
		if (cnt == 0) {
			len = i + 1;
			break;
		}
	}
	if (len == s.size()) {
		return 2 * scoreOfParentheses(s.substr(1, len - 2));
	}
	else return scoreOfParentheses(s.substr(0, len)) + scoreOfParentheses(s.substr(len));
}
//801. 使序列递增的最小交换次数
int minSwap(vector<int>& nums1, vector<int>& nums2) {
	int len = nums1.size();
	int a = 0, b = 1;
	for (int i = 1; i < len; i++)
	{
		int at = a, bt = b;
		a = b = len;
		if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
			a = min(at, a);
			b = min(bt + 1, b);
		}
		if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
			a = min(a, bt);
			b = min(b, at + 1);
		}
	}
	return min(a, b);
}
//31. 下一个排列
void nextPermutation(vector<int>& nums) {
	bool match = false;
	for (int i = nums.size() - 1; i > 0; i--)
	{
		if (nums[i] > nums[i - 1]) {
			int min = 999, index = 0;
			for (int j = nums.size() - 1; j >= i; j--)
			{
				if (nums[j]<min && nums[j]>nums[i - 1]) {
					min = nums[j];
					index = j;
				}
			}
			swap(nums[i - 1], nums[index]);
			sort(nums.begin() + i, nums.end());
			match = true;
			break;
		}
	}
	if (!match) {
		reverse(nums.begin(), nums.end());
	}
}
//32. 最长有效括号
int longestValidParentheses(string s) {
	int max = 0;
	stack<int>sta;
	sta.push(-1);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(')sta.push(i);
		else {
			sta.pop();
			if (sta.empty())sta.push(i);
			else {
				if (i - sta.top() > max)max = i - sta.top();
			}
		}
	}
	return max;
}
//35. 搜索插入位置
int searchInsert(vector<int>& nums, int target) {
	int i = 0, j = nums.size() - 1;
	while (i < j) {
		int mid = (i + j) >> 1;
		if (nums[mid] > target)j = mid;
		else if (nums[mid] < target)i = mid + 1;
		else return mid;
	}
	if (i == nums.size() - 1)return nums.size();
	return i;
}
//36. 有效的数独
bool isValidSudoku(vector<vector<char>>& board) {
	if (board.size() != 9)return false;
	for (int i = 0; i < board.size(); i++)
	{
		unordered_map<char, int>mmap;
		for (char ch : board[i]) {
			if (ch > '0' && ch <= '9') {
				if (mmap.find(ch) != mmap.end())return false;
				mmap[ch] = 1;
			}
		}
	}
	for (int i = 0; i < board[0].size(); i++)
	{
		unordered_map<char, int>mmap;
		for (int j = 0; j < board.size(); j++) {
			if (board[j][i] > '0' && board[j][i] <= '9') {
				if (mmap.find(board[j][i]) != mmap.end())return false;
				mmap[board[j][i]] = 1;
			}

		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			unordered_map<char, int>mmap;
			for (int v = 0; v < 3; v++) {
				for (int n = 0; n < 3; n++) {
					if (board[i * 3 + v][j * 3 + n] > '0' && board[i * 3 + v][j * 3 + n] <= '9') {
						if (mmap.find(board[i * 3 + v][j * 3 + n]) != mmap.end())return false;
						mmap[board[i * 3 + v][j * 3 + n]] = 1;
					}
				}
			}
		}
	}
	return true;
}
//1472. 设计浏览器历史记录
class BrowserHistory {
public:
	string current;
	stack<string>bac, fro;
	BrowserHistory(string homepage) {
		current = homepage;
	}

	void visit(string url) {
		bac.push(current);
		current = url;
		while (!fro.empty())fro.pop();
	}

	string back(int steps) {
		while (steps > 0 && !bac.empty()) {
			fro.push(current);
			current = bac.top();
			steps--;
			bac.pop();
		}
		return current;
	}

	string forward(int steps) {
		while (steps > 0 && !fro.empty()) {
			bac.push(current);
			current = fro.top();
			steps--;
			fro.pop();
		}
		return current;
	}
};
//58. 最后一个单词的长度
int lengthOfLastWord(string s) {
	int right = s.length() - 1;
	while (right > 0 && s[right] == ' ')right--;
	int left = right;
	while (left > 0 && s[left] != ' ')left--;
	if (s[left] == ' ')return right - left;
	return right - left + 1;
}
//66. 加一
vector<int> plusOne(vector<int>& digits) {
	int flag = 0, len = digits.size();
	digits[len - 1] = digits[len - 1] + 1;
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		digits[i] = digits[i] + flag;
		if (digits[i] > 9) {
			digits[i] = 0;
			flag = 1;
		}
		else {
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		digits.push_back(1);
		reverse(digits.begin(), digits.end());
	}
	return digits;
}
//67. 二进制求和
string addBinary(string a, string b) {
	string ans;
	if (a == "0" || b == "0")return a == "0" ? b : a;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int flag = 0;
	for (int i = 0; i < min(a.length(), b.length()) + 1; i++)
	{
		if (i < a.length() && i < b.length()) {
			char temp = a[i] + b[i] - '0' + flag;
			if (temp > '1') {
				ans.push_back(temp - 2);
				flag = 1;
			}
			else {
				ans.push_back(temp);
				flag = 0;
			}
		}
		else if (i < a.length()) {
			while (i < a.length()) {
				char temp = a[i] + flag;
				if (temp > '1') {
					ans.push_back(temp - 2);
					flag = 1;
				}
				else {
					ans.push_back(temp);
					flag = 0;
				}
				i++;
			}
		}
		else if (i < b.length()) {
			while (i < b.length()) {
				char temp = b[i] + flag;
				if (temp > '1') {
					ans.push_back(temp - 2);
					flag = 1;
				}
				else {
					ans.push_back(temp);
					flag = 0;
				}
				i++;
			}
		}
	}
	if (flag == 1)ans.push_back('1');
	reverse(ans.begin(), ans.end());
	return ans;
}
//1790. 仅执行一次字符串交换能否使两个字符串相等
bool areAlmostEqual(string s1, string s2) {
	int differ = 0;
	map<char, int>map1, map2;
	if (s1 == s2)return true;
	if (s1.size() != s2.size())return false;
	for (int i = 0; i < s1.size(); i++)
	{
		map1[s1[i]]++;
		map2[s2[i]]++;
		if (s1[i] != s2[i])differ++;
	}
	if (differ != 2 || map1 != map2)return false;
	return true;
}
//870. 优势洗牌
vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
	int len = nums1.size();
	unordered_map<int, vector<int>>mmap;
	vector<int>ans(len, -1);
	for (int i = 0; i < nums2.size(); i++)mmap[nums2[i]].push_back(i);
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	int left = 0, right = 0;
	while (left < len && right < len) {
		if (nums1[left] > nums2[right]) {
			ans[mmap[nums2[right]][0]] = nums1[left];
			mmap[nums2[right]].erase(mmap[nums2[right]].begin());
			nums1[left] = -1;
			right++;
		}
		left++;
	}
	left = 0, right = 0;
	while (left < len && right < len) {
		if (nums1[left] == -1) {
			left++; continue;
		}
		if (ans[right] != -1) {
			right++; continue;
		}
		ans[right] = nums1[left];
		right++;
		left++;
	}
	return ans;
}
//1190. 反转每对括号间的子串
string reverseParentheses(string s) {
	stack<char>stk, back;
	string ans;
	for (char ch : s) {
		if (ch == ')') {
			string temp;
			while (stk.top() != '(') {
				temp.push_back(stk.top());
				stk.pop();
			}
			stk.pop();
			for (char c : temp)stk.push(c);
		}
		else stk.push(ch);
	}
	while (!stk.empty()) {
		ans.push_back(stk.top());
		stk.pop();
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
//1191. K 次串联后最大子数组之和
int kConcatenationMaxSum(vector<int>& arr, int k) {
	int len = arr.size();
	long sum = 0;
	vector<int>v = arr;
	bool allpositive = true;
	for (int x : arr) {
		if (x < 0)allpositive = false;
		sum += x;
		v.push_back(x);
	}
	if (allpositive)return (sum * k) % 1000000007;
	if (sum > 0 && k >= 3) {
		long mid = (sum * (k - 2)) % 1000000007;
		int max1 = 0, max2 = 0, temp1 = 0, temp2 = 0;
		for (int i = len - 1; i >= 0; i--) {
			temp1 += arr[i];
			temp2 += arr[len - i - 1];
			if (temp1 > max1)max1 = temp1;
			if (temp2 > max2)max2 = temp2;
		}
		return (max1 + max2 + mid) % 1000000007;
	}
	if (k >= 2) {
		vector<vector<int>>dp(arr.size() * 2, vector<int>(2, 0));
		if (arr.size() > 0 && arr[0] > 0)dp[0][0] = dp[0][1] = arr[0];
		for (int i = 1; i < v.size(); i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] = max(v[i], dp[i - 1][1] + v[i]);
		}
		return max(dp[len * 2 - 1][0], dp[len * 2 - 1][1]);
	}
	vector<vector<int>>dp(arr.size(), vector<int>(2, 0));
	if (arr.size() > 0 && arr[0] > 0)dp[0][0] = dp[0][1] = arr[0];
	for (int i = 1; i < dp.size(); i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = max(v[i], dp[i - 1][1] + v[i]);
	}
	return max(dp[len - 1][0], dp[len - 1][1]);
}
//1192. 查找集群内的「关键连接」未完成
void dfs_critical(int current, int n, vector<vector<int>>road, vector<bool>& vis) {
	vis[current] = true;
	queue<int>q;
	q.push(current);
	while (!q.empty()) {
		int top = q.front();
		vis[top] = true;
		q.pop();
		for (int x : road[top]) {
			if (vis[x])continue;
			q.push(x);
		}
	}
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
	vector<vector<int>>road(n), ans;
	vector<bool>visit(n, false);
	for (vector<int>v : connections) {
		road[v[0]].push_back(v[1]);
		road[v[1]].push_back(v[0]);
	}
	int circle = 0;
	for (int i = 0; i < n; i++) {
		if (visit[i])continue;
		circle++;
		dfs_critical(i, n, road, visit);
	}
	for (int i = 0; i < connections.size(); i++) {
		vector<int>v = connections[i], a, b;
		for (int x : road[v[0]]) { if (x != v[1])a.push_back(x); }
		for (int x : road[v[1]]) { if (x != v[0])b.push_back(x); }
		road[v[0]] = a;
		road[v[1]] = b;
		vector<bool>vis(n, false);
		int temp = 0;
		for (int i = 0; i < n; i++) {
			if (vis[i])continue;
			temp++;
			dfs_critical(i, n, road, vis);
		}
		if (temp > circle)ans.push_back({ v[0],v[1] });
		road[v[0]].push_back(v[1]);
		road[v[1]].push_back(v[0]);
	}
	return ans;
}
//1937. 扣分后的最大得分
//long long maxPoints(vector<vector<int>>& points) {
//	vector<int>index(points.size());
//	for (int i = 0; i < points.size(); i++) {
//		int max = 0;
//		for (int j = 0; j < points[i].size(); j++) {
//			
//		}
//	}
//}
//817. 链表组件
int numComponents(ListNode* head, vector<int>& nums) {
	int index[10005];//应该放在外面
	ListNode* ptr = head;
	for (int x : nums)index[x] = 1;
	int ans = 0, cnt = 0;
	while (ptr != nullptr) {
		if (index[ptr->val] != 1) {
			if (cnt > 0) {
				ans++;
				cnt = 0;
			}
		}
		else {
			cnt++;
		}
		ptr = ptr->next;
	}
	if (cnt > 0)ans++;
	return ans;
}
//73. 矩阵置零
void setZeroes(vector<vector<int>>& matrix) {
	vector<int>zerov[2];
	zerov[0].resize(matrix.size());
	zerov[1].resize(matrix[0].size());
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			if (matrix[i][j] == 0) {
				zerov[0][i] = 1;
				zerov[1][j] = 1;
			}
		}
	}
	vector<vector<int>>temp(matrix.size(), vector<int>(matrix[0].size(), 0));
	for (int i = 0; i < matrix.size(); i++) {
		if (zerov[0][i] == 1)continue;
		for (int j = 0; j < matrix[i].size(); j++) {
			if (zerov[1][j] == 1)continue;
			temp[i][j] = matrix[i][j];
		}
	}
	matrix = temp;
}
//剑指 Offer II 008. 和大于等于 target 的最短子数组
int minSubArrayLen(int target, vector<int>& nums) {
	int minl = 999999, left = 0, right = 1, sum = nums[0];
	while (right < nums.size() || sum >= target) {
		if (sum < target) {
			sum += nums[right++];
			continue;
		}
		while (sum >= target) {
			if (right - left < minl) {
				minl = right - left;
			}
			sum -= nums[left++];
		}
	}
	return minl == 999999 ? 0 : minl;
}
//349. 两个数组的交集
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	int index[1005];
	fill(index, index + 1005, -1);
	for (int x : nums1) {
		if (index[x] == -1)index[x] = 0;
	}
	for (int x : nums2) {
		if (index[x] == 0)index[x] = 1;
	}
	vector<int>ans;
	for (int i = 0; i < 1005; i++)if (index[i] == 1)ans.push_back(i);
	return ans;
}
class solveSudoku_Solution {
private:
	bool line[9][9];
	bool column[9][9];
	bool block[3][3][9];
	bool valid;
	vector<pair<int, int>>spaces;

public:
	void dfs(vector<vector<char>>& board, int pos) {
		if (pos == spaces.size()) {
			valid = true;
			return;
		}
		pair<int, int>p = spaces[pos];
		int i = p.first, j = p.second;
		for (int digit = 0; digit < 9 && !valid; digit++) {
			if (!line[i][digit] && !column[j][digit] && !block[i / 3][j / 3][digit]) {
				line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
				board[i][j] = digit + '0' + 1;
				dfs(board, pos + 1);
				line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = false;
			}
		}
	}
	void solveSudoku(vector<vector<char>>& board) {
		memset(line, false, sizeof(line));
		memset(column, false, sizeof(column));
		memset(block, false, sizeof(block));
		valid = false;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') {
					spaces.emplace_back(i, j);
				}
				else {
					int digit = board[i][j] - '0' - 1;
					line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
				}
			}
		}
		dfs(board, 0);
	}
};
//38. 外观数列
string countAndSay(int n) {
	string s = "1", ans;
	while (--n > 0) {
		int cnt = 0;
		char temp = s[0];
		ans = "";
		for (char x : s) {
			if (x == temp) {
				cnt++;
				continue;
			}
			else {
				ans.push_back(cnt + '0');
				ans.push_back(temp);
				cnt = 1;
				temp = x;
			}
		}
		ans.push_back(cnt + '0');
		ans.push_back(temp);
		s = ans;
	}
	return s;
}
//39. 组合总和
class combinationSum_Solution {
private:
	vector<vector<int>>ans;
public:
	void dfs(vector<int>& candidates, vector<int>v, int target) {
		if (target == 0) {
			ans.push_back(v);
			return;
		}
		for (int x : candidates) {
			if (target >= x && x >= v[v.size() - 1]) {
				v.push_back(x);
				dfs(candidates, v, target - x);
				v.pop_back();
			}
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		for (int x : candidates) {
			vector<int>v;
			v.push_back(x);
			dfs(candidates, v, target - x);
		}
		return ans;
	}
};
//40. 组合总和 II
class combinationSum2_Solution {
private:
	vector<vector<int>>ans;
public:
	void dfs(vector<pair<int, int>>freq, int index, vector<pair<int, int>>v, int target) {
		if (target == 0) {
			vector<int>temp;
			for (pair<int, int>p : v) {
				for (int i = 0; i < p.second; i++)temp.push_back(p.first);
			}
			ans.push_back(temp);
			return;
		}
		if (index >= freq.size()) {
			return;
		}
		for (int i = 0; i <= freq[index].second; i++) {
			int mul = i * freq[index].first;
			if (target < mul || target < freq[index].first)return;
			if (i == 0) {
				dfs(freq, index + 1, v, target);
			}
			else {
				v.emplace_back(freq[index].first, i);
				dfs(freq, index + 1, v, target - mul);
				v.pop_back();
			}
		}
	}
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		map<int, int>mmap;
		vector<pair<int, int>>freq, v;
		for (int x : candidates)mmap[x]++;
		auto it = mmap.begin();
		while (it != mmap.end()) {
			freq.emplace_back(it->first, it->second);
			it++;
		}
		dfs(freq, 0, v, target);
		return ans;
	}
};
//769. 最多能完成排序的块
int maxChunksToSorted(vector<int>& arr) {
	int len = arr.size(), cnt = 0, right = len - 1, min = len + 1;
	vector<int>po(len, 0);
	for (int i = len - 1; i >= 0; i--) {
		if (arr[i] < min)min = arr[i];
		po[arr[i]] = 1;
		int temp = right;
		while (temp >= 0 && po[temp] != 0)temp--;
		if (temp + 1 == min) {
			right = temp;
			cnt++;
		}
	}
	return cnt;
}
//768. 最多能完成排序的块 II
int maxChunksToSortedII(vector<int>& arr) {
	int len = arr.size(), cnt = 0, right = len - 1, min = arr.size(), temp = right;
	vector<int>array = arr;
	vector<int>a(len, 0);
	sort(array.begin(), array.end());
	unordered_map<int, vector<int>>mmap;
	for (int i = 0; i < array.size(); i++)mmap[array[i]].push_back(i);
	for (int i = len - 1; i >= 0; i--) {
		if (mmap[arr[i]].back() < min)min = mmap[arr[i]].back();
		a[mmap[arr[i]].back()] = 1;
		mmap[arr[i]].pop_back();
		while (temp >= 0 && a[temp] == 1)temp--;
		if (temp + 1 == min) {
			right = temp;
			cnt++;
		}
	}
	return cnt;
}
//41. 缺失的第一个正数
int firstMissingPositive(vector<int>& nums) {
	int minn = 1;
	unordered_map<int, int>mmap;
	for (int x : nums) {
		if (x == minn) {
			do {
				minn++;
			} while (mmap.find(minn) != mmap.end());
		}
		else mmap[x] = 1;
	}
	return minn;
}
//42. 接雨水 
int trap(vector<int>& height) {
	int len = height.size(), ans = 0;
	vector<int>maxl(len), maxr(len);
	int maxleft = 0, maxright = 0;
	for (int i = 0; i < len; i++) {
		if (height[i] > maxleft)maxleft = height[i];
		if (height[len - 1 - i] > maxright)maxright = height[len - 1 - i];
		maxl[i] = maxleft;
		maxr[len - 1 - i] = maxright;
	}
	for (int i = 0; i < len; i++) {
		ans += max(min(maxl[i], maxr[i]) - height[i], 0);
	}
	return ans;
}
//43. 字符串相乘
//44. 通配符匹配
bool isMatch(string s, string p) {
	int m = s.size(), n = p.size();
	vector<vector<int>>dp(m + 1, vector<int>(n + 1));
	dp[0][0] = true;
	for (int i = 1; i <= n; i++) {
		if (p[i - 1] == '*')dp[0][i] = true;
		else break;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (p[j - 1] == '*') {
				dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
			}
			else if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
				dp[i][j] = dp[i - 1][j - 1];
			}
		}
	}
	return dp[m][n];
}
//45. 跳跃游戏 II
int jump(vector<int>& nums) {
	vector<int>dp(nums.size(), nums.size() + 1);
	dp[0] = 0;
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 1; j <= nums[i] && i + j < nums.size(); j++) {
			dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	return dp[nums.size() - 1];
}
//46. 全排列
class permute_Solution {
private:
	vector<vector<int>>ans;
public:
	void premute_dfs(vector<int>nums, vector<bool>vis, vector<int>temp, int index) {
		if (index >= nums.size()) {
			ans.push_back(temp);
			return;
		}
		for (int i = 0; i < vis.size(); i++) {
			if (vis[i])continue;
			vis[i] = true;
			temp.push_back(nums[i]);
			premute_dfs(nums, vis, temp, index + 1);
			temp.pop_back();
			vis[i] = false;
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		vector<bool>vis(nums.size(), false);
		vector<int>temp;
		premute_dfs(nums, vis, temp, 0);
		return ans;
	}
};
///940. 不同的子序列 II
int distinctSubseqII(string s) {
	vector<int> last(26, -1);
	int n = s.size();
	vector<int> f(n, 1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 26; ++j) {
			if (last[j] != -1) {
				f[i] = (f[i] + f[last[j]]) % 1000000007;
			}
		}
		last[s[i] - 'a'] = i;
	}

	int ans = 0;
	for (int i = 0; i < 26; ++i) {
		if (last[i] != -1) {
			ans = (ans + f[last[i]]) % 1000000007;
		}
	}
	return ans;
}

//1441. 用栈操作构建数组
vector<string> buildArray(vector<int>& target, int n) {
	int cnt = 1;
	vector<string>ans;
	for (int i = 0; i < target.size(); i++) {
		ans.push_back("Push");
		while (target[i] > cnt) {
			ans.push_back("Pop");
			ans.push_back("Push");
			cnt++;
		}
		cnt++;
	}
	return ans;
}
//47. 全排列 II
class permuteUnique_Solution {
private:
	vector<vector<int>>ans;
public:
	void premute_dfs(vector<int>nums, vector<bool>vis, vector<int>temp, int index) {
		if (index >= nums.size()) {
			ans.push_back(temp);
			return;
		}
		unordered_map<int, int>mmap;
		for (int i = 0; i < vis.size(); i++) {
			if (vis[i] || mmap.find(nums[i]) != mmap.end())continue;
			vis[i] = true;
			mmap[nums[i]] = 1;
			temp.push_back(nums[i]);
			premute_dfs(nums, vis, temp, index + 1);
			temp.pop_back();
			vis[i] = false;
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<bool>vis(nums.size(), false);
		vector<int>temp;
		premute_dfs(nums, vis, temp, 0);
		return ans;
	}
};
//48. 旋转图像
void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size(), cnt = n / 2 - 1;
	for (int i = 0; i <= cnt; i++) {
		for (int j = i; j < n - 2 * i - 1 + i; j++) {
			int old = matrix[i][j], current, temp, newi = j, newj = n - i - 1;
			for (int u = 0; u < 4; u++) {
				current = matrix[newi][newj];
				matrix[newi][newj] = old;
				old = current;
				temp = newj;
				newj = n - newi - 1;
				newi = temp;
			}
		}
	}
}
//49. 字母异位词分组
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>>ans;
	unordered_map<string, vector<string>>mmap;
	for (int i = 0; i < strs.size(); i++) {
		string s = strs[i];
		vector<int>ch(26, 0);
		for (int v = 0; v < s.length(); v++)ch[s[v] - 'a']++;
		string tab;
		for (int v = 0; v < 26; v++)tab.push_back('0' + ch[v]);
		mmap[tab].push_back(s);
	}
	auto it = mmap.begin();
	while (it != mmap.end()) {
		ans.push_back(it->second);
		it++;
	}
	return ans;
}
//50. Pow(x, n)
double quickMul(double x, long long n) {
	if (n == 0) return 1.0;
	double y = quickMul(x, n / 2);
	return n % 2 == 0 ? y * y : y * y * x;
}
double myPow(double x, int n) {
	long long N = n;
	return N >= 0 ? quickMul(x, n) : 1.0 / quickMul(x, -n);
}
//51. N 皇后
class NQueensSolution {
private:
	vector<vector<string>>ans;
	void allTrueOrFalse(int i, int j, vector<vector<int>>& vis, int flag) {
		int left = j - 1, right = j + 1, len = vis.size();
		vis[i][j] += flag;
		i++;
		while (i < len && (left >= 0 || right < len)) {
			if (left >= 0)vis[i][left] += flag;
			if (right < len)vis[i][right] += flag;
			i++;
			left--;
			right++;
		}
	}
public:
	void NQueens_dfs(int index, int n, vector<int>v, vector<bool>line, vector<bool>column, vector<vector<int>>vis) {
		if (index == n) {
			vector<string>an;
			for (int i = 0; i < n; i++) {
				string temp;
				for (int j = 0; j < n; j++) {
					if (v[i] != j)temp.push_back('.');
					else temp.push_back('Q');
				}
				an.push_back(temp);
			}
			ans.push_back(an);
			return;
		}
		for (int i = 0; i < n; i++) {
			if (column[i] || vis[index][i] >= 1)continue;
			v.push_back(i);
			column[i] = true;
			line[index] = true;
			allTrueOrFalse(index, i, vis, 1);
			NQueens_dfs(index + 1, n, v, line, column, vis);
			column[i] = false;
			line[index] = false;
			allTrueOrFalse(index, i, vis, -1);
			v.pop_back();
		}
	}
	vector<vector<string>> solveNQueens(int n) {
		vector<bool>line(n), column(n);
		vector<vector<int>>vis(n, vector<int>(n));
		vector<int>v;
		NQueens_dfs(0, n, v, line, column, vis);
		return ans;
	}
};
//902. 最大为 N 的数字组合
int atMostNGivenDigitSet(vector<string>& digits, int n) {
	int len = to_string(n).length(), dlen = digits.size();
	vector<char>digit;
	for (int i = 0; i < digits.size(); i++)digit.push_back(stoi(digits[i].c_str()) + '0');
	string bound = "";
	string target = to_string(n);
	for (int i = 0; i < len; i++)bound += digits[0];
	if (bound > target) {
		bound = "";
		int cnt = 0, local = 1;
		while (local < len) {
			cnt += pow(digits.size(), local);
			local++;
		}
		return cnt;
	}
	else {
		for (int i = 0; i < len; i++) {
			string temp = bound;
			for (int j = 1; j < digit.size(); j++) {
				temp[i] = digit[j];
				if (temp > target)break;
				bound = temp;
			}
		}
		int cnt = 0, local = 1;
		while (local < len) {
			cnt += pow(digits.size(), local);
			local++;
		}
		for (int i = 0; i < bound.length(); i++) {
			for (int j = 1; j < digit.size(); j++) {
				if (digit[j] == bound[i]) {
					cnt += pow(digit.size(), bound.length() - i - 1) * (j);
					break;
				}
			}
		}
		cnt++;
		return cnt;
	}
}
//53. 最大子数组和
int maxSubArray(vector<int>& nums) {
	int len = nums.size();
	vector<vector<int>>dp(2, vector<int>(len));
	dp[0][0] = dp[1][0] = nums[0];
	for (int i = 1; i < len; i++) {
		dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
		dp[1][i] = max(nums[i], dp[1][i - 1] + nums[i]);
	}
	return max(dp[0][len - 1], dp[1][len - 1]);
}
//56. 合并区间
bool mergeCmp(vector<int>a, vector<int>b) { return a[0] < b[0]; }
vector<vector<int>> merge(vector<vector<int>>& intervals) {
	sort(intervals.begin(), intervals.end());
	vector<vector<int>>ans;
	vector<int>curr = intervals[0];
	for (int i = 1; i < intervals.size(); i++) {
		if (curr[1] >= intervals[i][0] && curr[1] <= intervals[i][1]) {
			curr[1] = intervals[i][1];
		}
		else if (curr[1] < intervals[i][0]) {
			ans.push_back(curr);
			curr = intervals[i];
		}
	}
	ans.push_back(curr);
	return ans;
}
//57. 插入区间
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	vector<vector<int>>ans;
	if (intervals.size() == 0) {
		ans.push_back(newInterval);
		return ans;
	}
	else if (intervals[0][0] > newInterval[1]) {
		ans.push_back(newInterval);
		for (vector<int>x : intervals)ans.push_back(x);
		return ans;
	}
	int len = intervals.size();
	int left = 0, right = len - 1, mid = 0;
	while (left < right) {
		mid = (left + right) >> 1;
		if (intervals[mid][0] > newInterval[0])right = mid;
		else if (intervals[mid][0] < newInterval[0])left = mid + 1;
		else {
			left = mid; break;
		}
	}
	while (left >= 0 && intervals[left][1] >= newInterval[0])left--;
	for (int i = 0; i <= left; i++)ans.push_back(intervals[i]);
	vector<int>curr = newInterval;
	int idx = left + 1;
	bool change = false;
	for (; idx < intervals.size(); idx++) {
		if (curr[1] >= intervals[idx][0]) {
			curr[1] = max(intervals[idx][1], curr[1]);
			curr[0] = min(intervals[idx][0], curr[0]);
		}
		else {
			change = true;
			ans.push_back(curr);
			curr = intervals[idx];
			break;
		}
	}
	if (!change)ans.push_back(curr);
	for (; idx < intervals.size(); idx++)ans.push_back(intervals[idx]);
	return ans;
}
//59. 螺旋矩阵 II
vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>>v(n, vector<int>(n, -1));
	bool change = true;
	int i = 0, j = 0, num = 1;
	while (change) {
		change = false;
		while (j < n && v[i][j] == -1) {
			v[i][j] = num++; j++; change = true;
		}
		j--; i++;
		while (i < n && v[i][j] == -1) {
			v[i][j] = num++; i++; change = true;
		}
		i--; j--;
		while (j >= 0 && v[i][j] == -1) {
			v[i][j] = num++; j--; change = true;
		}
		j++; i--;
		while (i >= 0 && v[i][j] == -1) {
			v[i][j] = num++; i--; change = true;
		}
		i++; j++;
	}
	return v;
}
//1700. 无法吃午餐的学生数量
int countStudents(vector<int>& students, vector<int>& sandwiches) {
	queue<int>stu, sand;
	for (int i = 0; i < students.size(); i++)stu.push(students[i]);
	for (int i = 0; i < sandwiches.size(); i++)sand.push(sandwiches[i]);
	bool eat = true;
	while (eat) {
		eat = false;
		int cnt = 0;
		while (cnt < stu.size()) {
			if (stu.front() != sand.front()) {
				cnt++;
				stu.push(stu.front());
				stu.pop();
			}
			else {
				stu.pop();
				sand.pop();
				eat = true;
				break;
			}
		}
	}
	return stu.size();
}
//904. 水果成篮
int totalFruit(vector<int>& fruits) {
	if (fruits.size() <= 2)return fruits.size();
	int maxn = 0, k1, k2, sum = 0, idx;
	for (int i = 2; i < fruits.size(); i++) {
		if (fruits.size() - i + 2 < maxn)break;
		k1 = fruits[i - 2];
		k2 = fruits[i - 1];
		sum = 2;
		idx = i;
		while (idx < fruits.size() && (fruits[idx] == k1 || fruits[idx] == k2 || k1 == k2)) {
			if (k1 == k2 && fruits[idx] != k1)k2 = fruits[idx];
			sum++; idx++;
		}
		maxn = max(sum, maxn);
	}
	return maxn;
}
//60. 排列序列
string getPermutation(int n, int k) {
	string result;
	vector<int>fac(n + 1), vis(n + 1, -1);
	fac[1] = 1;
	for (int i = 2; i <= n; i++)fac[i] = fac[i - 1] * i;
	int total = 1;
	for (int i = 0; i < n; i++) {
		int  num = 0, j = 1;
		while (total <= k && (n - i - 1) >= 1) {
			if (total + fac[n - i - 1] <= k) {
				num++;
				total += fac[n - i - 1];
			}
			else {
				break;
			}
		}
		while (vis[j] != -1)j++;
		while (num > 0 || vis[j] != -1) {
			if (vis[j] != -1) {
				j++; continue;
			}
			num--;
			j++;
		}
		vis[j] = 1;
		result.push_back(j + '0');
	}
	return result;
}
//61. 旋转链表
ListNode* rotateRight(ListNode* head, int k) {
	if (k == 0 || head == nullptr || head->next == nullptr) {
		return head;
	}
	int n = 1;
	ListNode* root = head;
	while (head->next != nullptr) {
		head = head->next;
		n++;
	}
	if (k % n == 0)return root;
	k = k % n;
	head->next = root;
	int cnt = 1;
	while (cnt < n - k) {
		root = root->next;
		cnt++;
	}
	head = root->next;
	root->next = nullptr;
	return head;
}
//68. 文本左右对齐
vector<string> fullJustify(vector<string>& words, int maxWidth) {
	vector<string>ans;
	vector<string>temp;
	int wordWidth = 0, wordn = 0;
	for (int i = 0; i < words.size(); i++) {
		if (temp.size() + wordWidth + words[i].length() <= maxWidth) {
			wordWidth += words[i].length();
			temp.push_back(words[i]);
		}
		else {
			if (temp.size() == 1) {
				string last = "";
				for (int i = 0; i < temp.size(); i++) {
					if (i != 0)last.push_back(' ');
					last += temp[i];
				}
				while (last.size() < maxWidth)last.push_back(' ');
				ans.push_back(last);
			}
			else {
				int keng = (maxWidth - wordWidth) % (temp.size() - 1);
				int space = (maxWidth - wordWidth) / (temp.size() - 1);
				string spa = "";
				for (int j = 0; j < space; j++)spa.push_back(' ');
				string curr;
				for (int j = 0; j < temp.size(); j++) {
					if (j != 0) {
						curr += spa;
						if (keng > 0) {
							curr.push_back(' ');
							keng--;
						}
					}
					curr += temp[j];
				}
				ans.push_back(curr);
			}
			temp.clear();
			temp.push_back(words[i]);
			wordWidth = words[i].length();
			wordn = 1;
		}
	}
	string last = "";
	for (int i = 0; i < temp.size(); i++) {
		if (i != 0)last.push_back(' ');
		last += temp[i];
	}
	while (last.size() < maxWidth)last.push_back(' ');
	ans.push_back(last);
	return ans;
}
//779. 第K个语法符号
int kthGrammar(int n, int k) {
	if (n == 1)return 0;
	return kthGrammar(n - 1, (k + 1) >> 1) ^ 1 ^ (1 & k);
}
//71. 简化路径
string simplifyPath(string path) {
	vector<string> ans;
	stack<char>s;
	for (int i = 0; i < path.size() || !s.empty(); i++) {
		if (i >= path.size() && !s.empty() || i != 0 && path[i] == '/') {
			if (i >= path.size() && s.top() == '/')break;
			if (s.size() > 0 && s.top() == '/') continue;
			string temp;
			while (!s.empty() && s.top() != '/') {
				temp.push_back(s.top());
				s.pop();
			}
			if (temp == ".")continue;
			else if (temp == "..") {
				if (ans.size() > 0)ans.pop_back();
			}
			else {
				reverse(temp.begin(), temp.end());
				ans.push_back(temp);
			}
		}
		else {
			s.push(path[i]);
		}
	}
	string res;
	for (string x : ans) {
		res.push_back('/');
		res += x;
	}
	if (res.length() == 0)res.push_back('/');
	return res;
}
//72. 编辑距离
int minDistance(string word1, string word2) {
	int n = word1.size(), m = word2.size();
	if (n * m == 0)return n + m;
	vector<vector<int>>dp(n + 1, vector<int>(m + 1));
	for (int i = 0; i < n + 1; i++)dp[i][0] = i;
	for (int i = 0; i < m + 1; i++)dp[0][i] = i;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			int left = dp[i - 1][j] + 1;
			int down = dp[i][j - 1] + 1;
			int left_down = dp[i - 1][j - 1];
			if (word1[i - 1] != word2[j - 1])left_down += 1;
			dp[i][j] = min(left, min(down, left_down));
		}
	}
	return dp[n][m];
}
//75. 颜色分类
void sortColors(vector<int>& nums) {
	int p0 = 0, p1 = 0, idx = 0, len = nums.size();
	for (int i = 0; i < len; i++) {
		if (nums[i] == 0) {
			swap(nums[i], nums[p0]);
			if (p0 < p1) {
				swap(nums[i], nums[p1]);
			}
			p0++;
			p1++;
		}
		else if (nums[i] == 1) {
			swap(nums[i], nums[p1]);
			p1++;
		}
	}
}
//77. 组合
class combineSolution {
private:
	vector<int>temp;
	vector<vector<int>>ans;
public:
	void combine_dfs(int i, int n, int k) {
		if (temp.size() + (n - i + 1) < k)return;
		if (temp.size() == k) {
			ans.push_back(temp);
			return;
		}
		temp.push_back(i);
		combine_dfs(i + 1, n, k);
		temp.pop_back();
		combine_dfs(i + 1, n, k);
	}
	vector<vector<int>> combine(int n, int k) {
		combine_dfs(1, n, k);
		return ans;
	}
};
//78. 子集
class subsetsSolution {
private:
	vector<int>temp;
	vector<vector<int>>ans;
public:
	void dfs(vector<int>& nums, int i) {
		if (i == nums.size()) {
			ans.push_back(temp);
			return;
		}
		temp.push_back(nums[i]);
		dfs(nums, i + 1);
		temp.pop_back();
		dfs(nums, i + 1);
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		dfs(nums, 0);
		return ans;
	}
};
//78. 子集  1,0  10来查重有误
class subsetsSolution1 {
private:
	string s;
	vector<int>temp;
	vector<vector<int>>ans;
	unordered_map<string, int>mmap;
public:
	void dfs(vector<int>& nums, int i) {
		if (mmap.find(s) == mmap.end()) {
			ans.push_back(temp);
			mmap[s] = 1;
		}
		if (i == nums.size())return;
		string sn = to_string(nums[i]);
		temp.push_back(nums[i]);
		s += sn;
		dfs(nums, i + 1);
		temp.pop_back();
		for (int i = 0; i < sn.size(); i++)s.pop_back();
		dfs(nums, i + 1);
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		dfs(nums, 0);
		return ans;
	}
};
//80. 删除有序数组中的重复项 II
int removeDuplicates1(vector<int>& nums) {
	if (nums.size() <= 2)return nums.size();
	int slow = 2, fast = 2;
	while (fast < nums.size()) {
		if (nums[slow - 2] != nums[fast]) {
			nums[slow] = nums[fast];
			slow++;
		}
		fast++;
	}
	return slow;
}
//81. 搜索旋转排序数组 II

//83. 删除排序链表中的重复元素
ListNode* deleteDuplicates(ListNode* head) {
	ListNode* ptr = head;
	while (ptr != nullptr && ptr->next != nullptr) {
		if (ptr->next->val == ptr->val) {
			ptr->next = ptr->next->next;
		}
		else {
			ptr = ptr->next;
		}
	}
	return head;
}
//901. 股票价格跨度
class StockSpanner {
	vector<int>stocks;
	vector<int>dp;
	int len = -1;
public:
	StockSpanner() {

	}

	int next(int price) {
		stocks.push_back(price);
		int last = len, width = 1;
		while (last >= 0 && stocks[last] <= price) {
			width += dp[last];
			last -= dp[last];
		}
		dp.push_back(width);
		len++;
		return width;
	}
};
//81. 搜索旋转排序数组 II
bool search(vector<int>& nums, int target) {
	if (nums.size() == 0)return false;
	else if (nums.size() == 1)return nums[0] == target;
	int left = 0, right = nums.size() - 1;
	while (left < right) {
		while (right > 0 && nums[right] == nums[right - 1])right--;
		int mid = (left + right) >> 1;
		if (nums[mid] == target)return true;
		if (target <= nums[right]) {
			if (nums[mid] < nums[right]) {
				if (nums[mid] < target) {
					left = mid + 1;
				}
				else {
					right = mid;
				}
			}
			else {
				left = mid + 1;
			}
		}
		else {
			if (nums[mid] < nums[right]) {
				right = mid;
			}
			else {
				if (nums[mid] > target) {
					right = mid;
				}
				else {
					left = mid + 1;
				}
			}
		}
	}
	return nums[left] == target;
}
//84. 柱状图中最大的矩形
int largestRectangleArea(vector<int>& heights) {
	int len = heights.size();
	if (len == 0)return 0;
	if (len == 1)return heights[0];
	vector<int>left(len), right(len, len);
	stack<pair<int, int>>stk;
	for (int i = 0; i < len; i++) {
		while (!stk.empty() && stk.top().first >= heights[i]) {
			right[stk.top().second] = i;
			stk.pop();
		}
		left[i] = (stk.empty() ? -1 : stk.top().second);
		stk.emplace(heights[i], i);
	}
	int maxn = 0;
	for (int i = 0; i < len; i++) {
		maxn = max(maxn, (right[i] - left[i] - 1) * heights[i]);
	}
	return maxn;
}
//85. 最大矩形
int maximalRectangle(vector<vector<char>>& matrix) {
	if (matrix.size() == 0 || matrix[0].size() == 0)return 0;
	int n = matrix.size(), m = matrix[0].size();
	vector<vector<int>>right(n, vector<int>(m, m));
	vector<vector<int>>up(n, vector<int>(m, -1));
	vector<vector<int>>down(n, vector<int>(m, n));
	for (int i = 0; i < n; i++) {
		stack<pair<int, int>>stk, sta;
		for (int j = 0; j < m; j++) {
			while (!sta.empty() && sta.top().first >= matrix[i][m - j - 1]) {
				sta.pop();
			}
			right[i][m - j - 1] = (sta.empty() ? m : sta.top().second);
			sta.emplace(matrix[i][m - j - 1], m - j - 1);
		}
	}
	for (int j = 0; j < m; j++) {
		stack<pair<int, int>>stk, sta;
		for (int i = 0; i < n; i++) {
			while (!stk.empty() && stk.top().first >= matrix[i][j]) {
				stk.pop();
			}
			while (!sta.empty() && sta.top().first >= matrix[n - i - 1][j]) {
				sta.pop();
			}
			up[i][j] = (stk.empty() ? -1 : stk.top().second);
			down[n - i - 1][j] = (sta.empty() ? n : sta.top().second);
			stk.emplace(matrix[i][j], i);
			sta.emplace(matrix[n - i - 1][j], n - i - 1);
		}
	}
	int maxn = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == '0')continue;
			int width = right[i][j] - j;
			int maxu = -1, mind = n;
			for (int u = j; u < right[i][j]; u++) {
				maxu = max(maxu, up[i][u]);
				mind = min(mind, down[i][u]);
				if (mind - maxu - 1 == 1)break;
			}
			maxn = max(maxn, width * (mind - maxu - 1));
		}
	}
	return maxn;
}
//86. 分隔链表
ListNode* partition(ListNode* head, int x) {
	ListNode* small = new ListNode(0);
	ListNode* smallhead = small;
	ListNode* large = new ListNode(0);
	ListNode* largehead = large;
	while (head != nullptr) {
		if (head->val < x) {
			small->next = head;
			small = small->next;
		}
		else {
			large->next = head;
			large = large->next;
		}
		head = head->next;
	}
	large->next = nullptr;
	small->next = largehead->next;
	return smallhead->next;
}
//90. 子集 II
class subsetsWithDupSolution {
private:
	vector<vector<int>>ans;
	unordered_map<string, int>mmap;
	vector<int>v;
	string s;
public:
	void dfs(vector<int>nums, int i) {
		if (i == nums.size()) {
			if (mmap.find(s) == mmap.end()) {
				ans.push_back(v);
				mmap[s] = 1;
			}
			return;
		}
		string cur = to_string(nums[i]);
		v.push_back(nums[i]);
		s = s + cur + "_";
		dfs(nums, i + 1);
		v.pop_back();
		for (int i = 0; i <= cur.size(); i++)s.pop_back();
		dfs(nums, i + 1);
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		dfs(nums, 0);
		return ans;
	}
};
//91. 解码方法
int numDecodings(string s) {
	int len = s.length();
	vector<int>dp(len + 1);
	dp[0] = 1;
	for (int i = 1; i <= len; i++) {
		if (s[i - 1] != '0')dp[i] += dp[i - 1];
		if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + s[i - 1] - '0') <= 26) {
			dp[i] += dp[i - 2];
		}
	}
	return dp[len];
}
//92. 反转链表 II
ListNode* reverseBetween(ListNode* head, int left, int right) {
	int mid = right - left;
	ListNode* root = new ListNode(0), * tail1 = head;
	if (left == 1)tail1 = root;
	root->next = head;
	while (left > 1) {
		tail1 = head;
		head = head->next;
		left--;
	}
	ListNode* tail2 = head, * midhead = tail2, * cur = tail2;
	head = head->next;
	while (mid > 0) {
		midhead = new ListNode(head->val);
		midhead->next = cur;
		cur = midhead;
		head = head->next;
		mid--;
	}
	tail1->next = midhead;
	tail2->next = head;
	return root->next;
}
//104. 二叉树的最大深度
int maxDepth(TreeNode* root) {
	if (root == nullptr)return 0;
	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
//111. 二叉树的最小深度
int minDepth(TreeNode* root) {
	if (root == nullptr)return 0;
	if (root->left != nullptr && root->right != nullptr) {
		return 1 + min(minDepth(root->left), minDepth(root->right));
	}
	else if (root->left != nullptr) {
		return 1 + minDepth(root->left);
	}
	else {
		return 1 + minDepth(root->right);
	}
	return 1;
}
//87. 扰乱字符串
class ScrambleSolution {
private:
	// 记忆化搜索存储状态的数组
	// -1 表示 false，1 表示 true，0 表示未计算
	int memo[30][30][31];
	string s1, s2;

public:
	bool checkIfSimilar(int i1, int i2, int length) {
		unordered_map<int, int> freq;
		for (int i = i1; i < i1 + length; ++i) {
			++freq[s1[i]];
		}
		for (int i = i2; i < i2 + length; ++i) {
			--freq[s2[i]];
		}
		if (any_of(freq.begin(), freq.end(), [](const auto& entry) {return entry.second != 0; })) {
			return false;
		}
		return true;
	}

	// 第一个字符串从 i1 开始，第二个字符串从 i2 开始，子串的长度为 length，是否和谐
	bool dfs(int i1, int i2, int length) {
		if (memo[i1][i2][length]) {
			return memo[i1][i2][length] == 1;
		}

		// 判断两个子串是否相等
		if (s1.substr(i1, length) == s2.substr(i2, length)) {
			memo[i1][i2][length] = 1;
			return true;
		}

		// 判断是否存在字符 c 在两个子串中出现的次数不同
		if (!checkIfSimilar(i1, i2, length)) {
			memo[i1][i2][length] = -1;
			return false;
		}

		// 枚举分割位置
		for (int i = 1; i < length; ++i) {
			// 不交换的情况
			if (dfs(i1, i2, i) && dfs(i1 + i, i2 + i, length - i)) {
				memo[i1][i2][length] = 1;
				return true;
			}
			// 交换的情况
			if (dfs(i1, i2 + length - i, i) && dfs(i1 + i, i2, length - i)) {
				memo[i1][i2][length] = 1;
				return true;
			}
		}

		memo[i1][i2][length] = -1;
		return false;
	}

	bool isScramble(string s1, string s2) {
		memset(memo, 0, sizeof(memo));
		this->s1 = s1;
		this->s2 = s2;
		return dfs(0, 0, s1.size());
	}
};
class isScrambleSolution {
public:
	bool isScramble(string s1, string s2) {
		if (s1.size() != s2.size()) return false;
		if (s1 == s2) return true;
		int len = s1.size();
		int m[256] = { 0 };
		for (int i = 0; i < len; i++) {
			m[s1[i]]++;
			m[s2[i]]--;
		}
		for (int i = 0; i < 256; i++) {
			if (m[i] != 0)return false;
		}
		for (int i = 1; i < len; i++) {
			if (isScramble(s1.substr(0, i), s2.substr(0, i))
				&& isScramble(s1.substr(i, len - i), s2.substr(i, len - i))) {
				return true;
			}
			if (isScramble(s1.substr(0, i), s2.substr(len - i, i))
				&& isScramble(s1.substr(i, len - i), s2.substr(0, len - i))) {
				return true;
			}
		}
		return false;
	}
};
//1235. 规划兼职工作
struct job
{
	int start, end, profit;
};
bool jobcmp(job a, job b) {
	return a.end < b.end;
}
class jobSchedulingSolution {
private:
public:
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		int n = startTime.size();
		vector<job>jobs;
		for (int i = 0; i < n; i++) {
			jobs.push_back({ startTime[i], endTime[i], profit[i] });
		}
		sort(jobs.begin(), jobs.end(), jobcmp);
		sort(endTime.begin(), endTime.end());
		vector<int>dp(n + 1);
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			int target = jobs[i - 1].start;
			//查找大于x的第一个元素
			int k = upper_bound(endTime.begin(), endTime.end(), target) - endTime.begin();
			dp[i] = max(dp[i - 1], dp[k] + jobs[i - 1].profit);
		}
		return dp[n];
	}
};
//93. 复原 IP 地址
class restoreIpAddressesSolution {
private:
	vector<string>ans;
public:
	void dfs(string s, string cur, int i, int n) {
		if (n == 4 || i == s.size()) {
			if (i == s.size() && n == 4) {
				cur.pop_back();
				ans.push_back(cur);
			}
			return;
		}
		if (s[i] == '0') {
			cur.push_back(s[i]);
			cur.push_back('.');
			dfs(s, cur, i + 1, n + 1);
		}
		else {
			int num = s[i] - '0', idx = i + 1;
			cur.push_back(s[i]);
			while (num < 255 && idx <= s.size()) {
				dfs(s, cur + ".", idx, n + 1);
				if (idx >= s.size())break;
				num = num * 10 + s[idx] - '0';
				cur.push_back(s[idx]);
				idx++;
			}
		}

	}
	vector<string> restoreIpAddresses(string s) {
		dfs(s, "", 0, 0);
		return ans;
	}
};
//95. 不同的二叉搜索树 II
class generateTreesSolution {
public:
	vector<TreeNode*>generate(int start, int end) {
		if (start > end) {
			return { nullptr };
		}
		vector<TreeNode*>ans;
		for (int i = start; i <= end; i++) {
			vector<TreeNode*>left = generate(start, i - 1);
			vector<TreeNode*>right = generate(i + 1, end);
			for (TreeNode* ln : left) {
				for (TreeNode* rn : right) {
					TreeNode* root = new TreeNode(i);
					root->left = ln;
					root->right = rn;
					ans.push_back(root);
				}
			}
		}
		return ans;
	}
	vector<TreeNode*> generateTrees(int n) {
		return generate(1, n);
	}
};

//96. 不同的二叉搜索树
class numTreesSolution {
public:
	int numTrees(int n) {
		vector<int>g(n + 1);
		g[0] = 1;
		g[1] = 1;
		//G(n)表示不同的n个数能表示多少个不同的二叉树
		//F(i,n)表示以i为二叉树根，节点个数为n个的不同的二叉树的个数
		//G(n) = F(1 , n) + F(2,n) +.....+ F(n-1,n) + F(n,n);
		//F(i,n) = G(i - 1) * G(n - i - 1);
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				g[i] += g[j - 1] * g[i - j];
			}
		}
		return g[n];
	}
};
//97. 交错字符串
bool isInterleave(string s1, string s2, string s3) {
	int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
	if (n1 + n2 != n3)return false;
	if (s3 == s1 + s2 || s3 == s2 + s1)return true;
	int m[256] = { 0 };
	for (int i = 0; i < s1.size(); i++)m[s1[i]]++;
	for (int i = 0; i < s2.size(); i++)m[s2[i]]++;
	for (int i = 0; i < s3.size(); i++)m[s3[i]]--;
	for (int i = 0; i < 256; i++) {
		if (m[i] != 0)return false;
	}
	vector<vector<int>>dp(n1 + 1, vector<int>(n2 + 1));
	dp[0][0] = 1;
	for (int i = 0; i <= n1; i++) {
		for (int j = 0; j <= n2; j++) {
			if (i > 0) {
				dp[i][j] |= dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
			}
			if (j > 0) {
				dp[i][j] |= dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
			}

		}
	}
	return dp[n1][n2];

}
//1768. 交替合并字符串
string mergeAlternately(string word1, string word2) {
	int n1 = word1.length(), n2 = word2.length();
	string ans;
	for (int i = 0; i < n1 || i < n2; i++) {
		if (i < n1)ans.push_back(word1[i]);
		if (i < n2)ans.push_back(word2[i]);
	}
	return ans;
}
//98. 验证二叉搜索树
bool helper(TreeNode* root, long lowwer, long upper) {
	if (root == nullptr)return true;
	if (root->val <= lowwer || root->val >= upper)return false;
	return helper(root->left, lowwer, root->val) && helper(root->right, root->val, upper);
}
bool isValidBST(TreeNode* root) {
	return helper(root, LONG_MIN, LONG_MAX);
}
//99. 恢复二叉搜索树 
class recoverTreeSolution {
private:
	vector<TreeNode*>ans;
	unordered_map<int, TreeNode*>mmap;
public:
	bool checkVaildBST(TreeNode* root, long low, long up) {
		if (root == nullptr)return true;
		if (root->val > up || root->val < low) {
			return false;
		}
		return checkVaildBST(root->left, low, root->val) && checkVaildBST(root->right, root->val, up);
	}
	void dfs(TreeNode* root, long low, long up) {
		if (root == nullptr)return;
		mmap[root->val] = root;
		if (root->val > up || root->val < low) {
			ans.push_back(root);
			if (root->val > up)ans.push_back(mmap[up]);
			else ans.push_back(mmap[low]);
		}
		dfs(root->left, low, root->val);
		dfs(root->right, root->val, up);
	}
	void recoverTree(TreeNode* root) {
		dfs(root, LONG_MIN, LONG_MAX);
		for (int i = 0; i < ans.size(); i++) {
			for (int j = 1; j < ans.size(); j++) {
				if (ans[i]->val == ans[j]->val)continue;
				long temp = ans[i]->val;
				ans[i]->val = ans[j]->val;
				ans[j]->val = temp;
				if (checkVaildBST(root, LONG_MIN, LONG_MAX))return;
				ans[j]->val = ans[i]->val;
				ans[i]->val = temp;
			}
		}

	}
};
//102. 二叉树的层序遍历
vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>>ans;
	int remain = 1, child = 0;
	queue<TreeNode*>q;
	vector<int>cur;
	if (root != nullptr)q.push(root);
	while (!q.empty()) {
		TreeNode* top = q.front();
		cur.push_back(top->val);
		remain--;
		q.pop();
		if (top->left != nullptr) {
			q.push(top->left);
			child++;
		}
		if (top->right != nullptr) {
			q.push(top->right);
			child++;
		}
		if (remain == 0) {
			remain = child;
			child = 0;
			ans.push_back(cur);
			cur.clear();
		}
	}
	return ans;
}
//103. 二叉树的锯齿形层序遍历
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>>ans;
	int remain = 1, child = 0, cnt = 0;
	queue<TreeNode*>q;
	vector<int>cur;
	if (root != nullptr)q.push(root);
	while (!q.empty()) {
		TreeNode* top = q.front();
		cur.push_back(top->val);
		remain--;
		q.pop();
		if (top->left != nullptr) {
			q.push(top->left);
			child++;
		}
		if (top->right != nullptr) {
			q.push(top->right);
			child++;
		}
		if (remain == 0) {
			remain = child;
			child = 0;
			if (cnt % 2 == 1) {
				reverse(cur.begin(), cur.end());
			}
			cnt++;
			ans.push_back(cur);
			cur.clear();
		}
	}
	return ans;
}
//105. 从前序与中序遍历序列构造二叉树
class buildTreeSolution {
private:
	vector<int> pre, in;
public:
	TreeNode* build(int ini, int inj, int prei, int prej) {
		TreeNode* root = new TreeNode(pre[prei]);
		int idx = ini;
		while (idx <= inj && in[idx] != pre[prei])idx++;
		int left = idx - ini, right = inj - idx;
		if (left > 0)root->left = build(ini, idx - 1, prei + 1, prei + left);
		if (right > 0)root->right = build(idx + 1, inj, prei + left + 1, prej);
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		this->pre = preorder;
		this->in = inorder;
		return build(0, pre.size() - 1, 0, pre.size() - 1);
	}
};
//106. 从中序与后序遍历序列构造二叉树
class buildTreeSolution1 {
private:
	vector<int> in, post;
public:
	TreeNode* build(int ini, int inj, int pi, int pj) {
		TreeNode* root = new TreeNode(post[pj]);
		int idx = ini;
		while (idx <= inj && in[idx] != post[pj])idx++;
		int left = idx - ini, right = inj - idx;
		if (left > 0)root->left = build(ini, idx - 1, pi, pi + left - 1);
		if (right > 0)root->right = build(idx + 1, inj, pi + left, pj - 1);
		return root;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		this->post = postorder;
		this->in = inorder;
		return build(0, in.size() - 1, 0, in.size() - 1);
	}
};
//107. 二叉树的层序遍历 II
vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int>>ans;
	int remain = 1, child = 0;
	queue<TreeNode*>q;
	vector<int>cur;
	if (root != nullptr)q.push(root);
	while (!q.empty()) {
		TreeNode* top = q.front();
		cur.push_back(top->val);
		remain--;
		q.pop();
		if (top->left != nullptr) {
			q.push(top->left);
			child++;
		}
		if (top->right != nullptr) {
			q.push(top->right);
			child++;
		}
		if (remain == 0) {
			remain = child;
			child = 0;
			ans.push_back(cur);
			cur.clear();
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
//109. 有序链表转换二叉搜索树
class sortedListToBSTSolution {
public:
	TreeNode* insert(TreeNode* root, int val) {
		if (root == nullptr)return new TreeNode(val);
		if (root->val > val) {
			root->left = insert(root->left, val);
			int l = height(root->left), r = height(root->right);
			if (l - r >= 2) {
				if (val < root->left->val) {
					root = rightRotate(root);
				}
				else {
					root = leftRightRotate(root);
				}
			}
		}
		else {
			root->right = insert(root->right, val);
			int l = height(root->left), r = height(root->right);
			if (l - r <= -2) {
				if (val > root->right->val) {
					root = leftRotate(root);
				}
				else {
					root = rightLeftRotate(root);
				}
			}
		}
		return root;
	}
	int height(TreeNode* root) {
		if (root == nullptr)return 0;
		return max(height(root->left), height(root->right)) + 1;
	}
	TreeNode* leftRotate(TreeNode* root) {
		TreeNode* rnode = root->right;
		root->right = rnode->left;
		rnode->left = root;
		return rnode;
	}
	TreeNode* rightRotate(TreeNode* root) {
		TreeNode* lnode = root->left;
		root->left = lnode->right;
		lnode->right = root;
		return lnode;
	}
	TreeNode* rightLeftRotate(TreeNode* root) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	TreeNode* leftRightRotate(TreeNode* root) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	TreeNode* sortedListToBST(ListNode* head) {
		TreeNode* root = nullptr;
		while (head != nullptr) {
			root = insert(root, head->val);
			head = head->next;
		}
		return root;
	}
};
class sortedListToBST_Solution {
public:
	TreeNode* build(vector<int>v, int i, int j) {
		if (i > j)return nullptr;
		int mid = (i + j) >> 1;
		TreeNode* root = new TreeNode(v[mid]);
		root->left = build(v, i, mid - 1);
		root->right = build(v, mid + 1, j);
		return root;
	}
	TreeNode* sortedListToBST(ListNode* head) {
		vector<int>v;
		while (head != nullptr) {
			v.push_back(head->val);
			head = head->next;
		}
		return build(v, 0, v.size() - 1);
	}
};
class sortedListToBST__Solution {
public:
	ListNode* getMedium(ListNode* left, ListNode* right) {
		ListNode* fast = left, * slow = left;
		while (fast != right && fast->next != right) {
			fast = fast->next;
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
	TreeNode* build(ListNode* left, ListNode* right) {
		if (left == right)return nullptr;
		ListNode* mid = getMedium(left, right);
		TreeNode* root = new TreeNode(mid->val);
		root->left = build(left, mid);
		root->right = build(mid->next, right);
		return root;
	}
	TreeNode* sortedListToBST(ListNode* head) {
		return build(head, nullptr);
	}
};
//915. 分割数组
int partitionDisjoint(vector<int>& nums) {
	int n = nums.size();
	vector<int>minv(n, nums[n - 1]);
	vector<int>maxv(n, nums[0]);
	for (int i = 1; i < nums.size(); i++) {
		maxv[i] = max(maxv[i - 1], nums[i]);
	}
	for (int i = n - 2; i >= 0; i--) {
		minv[i] = min(minv[i + 1], nums[i]);
	}
	int idx;
	for (int i = 0; i < n - 1; i++) {
		if (maxv[i] <= minv[i + 1])return i + 1;
	}
	return 1;
}
//112. 路径总和
class hasPathSumSolution {
public:
	bool help(TreeNode* root, int targetSum, int cur) {
		if (root == nullptr)return false;
		cur += root->val;
		if (root->left == nullptr && root->right == nullptr) {
			if (cur == targetSum)return true;
			else return false;
		}
		else {
			return help(root->left, targetSum, cur) || help(root->right, targetSum, cur);
		}
	}
	bool hasPathSum(TreeNode* root, int targetSum) {
		return help(root, targetSum, 0);
	}
};
//113. 路径总和 II
class pathSumSolution {
private:
	vector<vector<int>>ans;
public:
	void dfs(TreeNode* root, vector<int>v, int targetSum, int cur) {
		if (root == nullptr)return;
		cur += root->val;
		v.push_back(root->val);
		if (root->left == nullptr && root->right == nullptr) {
			if (cur == targetSum) {
				ans.push_back(v);
			}
			return;
		}
		else {
			dfs(root->left, v, targetSum, cur);
			dfs(root->right, v, targetSum, cur);
		}
	}
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		dfs(root, {}, targetSum, 0);
		return ans;
	}
};
class flattenSolution {
public:
	void dfs(TreeNode* root, vector<TreeNode*>& v) {
		if (root != nullptr) {
			v.push_back(root);
			dfs(root->left, v);
			dfs(root->right, v);
		}
	}
	void flatten(TreeNode* root) {
		vector<TreeNode*>v;
		dfs(root, v);
		for (int i = 0; i < v.size() - 1; i++) {
			v[i]->left = nullptr;
			v[i]->right = v[i + 1];
		}
	}
};
TreeNode* buildTree(int i, vector<int>v) {
	if (i >= v.size() || v[i] == -1)return nullptr;
	TreeNode* root = new TreeNode(v[i]);
	root->left = buildTree(i * 2 + 1, v);
	root->right = buildTree(i * 2 + 2, v);
	return root;
}
//118. 杨辉三角
vector<vector<int>> generate(int numRows) {
	vector<vector<int>>ans(numRows);
	for (int i = 1; i <= numRows; i++)ans[i - 1].resize(i);
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			if (j == 0 || j == ans[i].size() - 1)ans[i][j] = 1;
			else ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
		}
	}
	return ans;
}
//934. 最短的桥
class shortestBridgeSolution {
private:
	int n, m;
	vector<vector<int>>dir = { {0,1},{0,-1},{1,0},{-1,0} };
	queue<pair<int, int>>q;
public:
	void dfs(vector<vector<int>>& v, vector<vector<int>>& vis, int i, int j) {
		v[i][j] = -1;
		vis[i][j] = 1;
		q.emplace(i, j);
		for (int u = 0; u < dir.size(); u++) {
			int x = dir[u][0] + i;
			int y = dir[u][1] + j;
			if (x < 0 || y < 0 || x >= n || y >= m || v[x][y] != 1 || vis[x][y] != -1)continue;
			dfs(v, vis, x, y);
		}
	}
	int shortestBridge(vector<vector<int>>& grid) {
		this->n = grid.size(), this->m = grid[0].size();
		vector<vector<int>>vis(n, vector<int>(m, -1));
		bool findIsland = false;
		for (int i = 0; i < n && !findIsland; i++) {
			for (int j = 0; j < m && !findIsland; j++) {
				if (grid[i][j] == 0)continue;
				dfs(grid, vis, i, j);
				findIsland = true;
			}
		}
		int cnt = 0, remain = q.size();
		while (!q.empty()) {
			pair<int, int>p = q.front();
			q.pop();
			remain--;
			for (int u = 0; u < dir.size(); u++) {
				int x = dir[u][0] + p.first;
				int y = dir[u][1] + p.second;
				if (x < 0 || y < 0 || x >= n || y >= m)continue;
				if (vis[x][y] == -1) {
					if (grid[x][y] == 1)return cnt;
					q.emplace(x, y);
					vis[x][y] = 1;
				};
			}
			if (remain == 0) {
				remain = q.size();
				cnt++;
			}
		}
		return 0;
	}
};
//116. 填充每个节点的下一个右侧节点指针
class connectSolution {
public:
	Node* connect(Node* root) {
		if (root == nullptr)return root;
		root->next = nullptr;
		int remain = 1, kid = 0;
		queue<Node*>q;
		q.push(root);
		vector<Node*>v;
		while (!q.empty()) {
			remain--;
			kid++;
			Node* top = q.front();
			q.pop();
			v.push_back(top);
			if (top->left != nullptr)q.push(top->left);
			if (top->right != nullptr)q.push(top->right);
			if (remain == 0) {
				remain = kid;
				kid = 0;
				for (int i = 0; i < v.size(); i++) {
					if (i == v.size() - 1)v[i]->next = nullptr;
					else v[i]->next = v[i + 1];
				}
				v.clear();
			}
		}
		return root;
	}
};
//862. 和至少为 K 的最短子数组
class shortestSubarraySolution {
public:
	int shortestSubarray(vector<int>& nums, int k) {
		int n = nums.size(), len = INT_MAX;
		if (n == 0)return -1;
		vector<int>sum(n + 1);
		sum[0] = 0;
		for (int i = 1; i <= n; i++) {
			sum[i] = sum[i - 1] + nums[i - 1];
		}
		deque<int>q;
		for (int i = 0; i <= n; i++) {
			long cur = sum[i];
			while (!q.empty() && cur - sum[q.front()] >= k) {
				len = min(len, i - q.front());
				q.pop_front();
			}
			while (!q.empty() && sum[q.back()] >= cur) {
				q.pop_back();
			}
			q.push_back(i);
		}
		return len == INT_MAX ? -1 : len;
	}
};
//115. 不同的子序列
int numDistinct(string s, string t) {
	int n = s.length(), m = t.length();
	if (n < m)return 0;
	vector<vector<long long>>dp(n + 1, vector<long long>(m + 1, 0));
	for (int i = 0; i < n + 1; i++)dp[i][m] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (n - i < m - j)break;
			if (s[i] == t[j]) {
				dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
			}
			else {
				dp[i][j] = dp[i + 1][j];
			}
		}
	}
	return dp[0][0];
}
//117. 填充每个节点的下一个右侧节点指针 II
class connect_Solution {
public:
	Node* connect(Node* root) {
		if (root == nullptr)return root;
		root->next = nullptr;
		int remain = 1, kid = 0;
		queue<Node*>q;
		q.push(root);
		vector<Node*>v;
		while (!q.empty()) {
			remain--;
			Node* top = q.front();
			q.pop();
			v.push_back(top);
			if (top->left != nullptr) {
				q.push(top->left); kid++;
			}
			if (top->right != nullptr) {
				q.push(top->right); kid++;
			}
			if (remain == 0) {
				remain = kid;
				kid = 0;
				for (int i = 0; i < v.size(); i++) {
					if (i == v.size() - 1)v[i]->next = nullptr;
					else v[i]->next = v[i + 1];
				}
				v.clear();
			}
		}
		return root;
	}
};
//121. 买卖股票的最佳时机
int maxProfit(vector<int>& prices) {
	int n = prices.size(), profit = 0;
	vector<int>maxp(n + 1, 0);
	for (int i = n - 1; i >= 0; i--) {
		maxp[i] = max(prices[i], maxp[i + 1]);
		profit = max(profit, maxp[i + 1] - prices[i]);
	}
	return profit;
}
//122. 买卖股票的最佳时机 II
class maxProfitSolution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<vector<int>>dp(n, vector<int>(2, 0));
		dp[0][0] = 0;
		dp[0][1] = 0 - prices[0];
		for (int i = 1; i < n; i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
		}
		return dp[n - 1][0];
	}
};
//123. 买卖股票的最佳时机 III
class maxProfit_Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int sell1 = 0, sell2 = 0;
		int buy1 = -prices[0], buy2 = -prices[0];
		for (int i = 1; i < n; i++) {
			buy1 = max(buy1, -prices[i]);
			sell1 = max(sell1, buy1 + prices[i]);
			buy2 = max(buy2, sell1 - prices[i]);
			sell2 = max(sell2, buy2 + prices[i]);
		}
		return sell2;
	}
};
//124. 二叉树中的最大路径和
class maxPathSumSolution {
private:
	int maxSum = INT_MIN;
public:
	int nodeGain(TreeNode* root) {
		if (root == nullptr)return 0;
		int leftGain = max(nodeGain(root->left), 0);
		int rightGain = max(nodeGain(root->right), 0);
		int gainNode = leftGain + rightGain + root->val;
		maxSum = max(maxSum, gainNode);
		return root->val + max(leftGain, rightGain);
	}
	int maxPathSum(TreeNode* root) {
		vector<vector<int>>dp(1, vector<int>(2, 0));
		nodeGain(root);
		return maxSum;
	}
};
bool isPalindrome(string s) {
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	string ans;
	for (char ch : s) {
		if (ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')ans.push_back(ch);
	}
	string copy = ans;
	reverse(copy.begin(), copy.end());
	return copy == ans;
}
//128. 最长连续序列
int longestConsecutive(vector<int>& nums) {
	if (nums.size() == 0)return 0;
	sort(nums.begin(), nums.end());
	int maxn = 1, n = nums[0], temp = 1;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] == n)continue;
		if (nums[i] == n + 1) {
			temp++;
			n++;
		}
		else {
			maxn = max(maxn, temp);
			temp = 1;
			n = nums[i];
		}
	}
	maxn = max(maxn, temp);
	return maxn;
}
//1822. 数组元素积的符号
int arraySign(vector<int>& nums) {
	int minus = 0;
	for (int x : nums) {
		if (x == 0)return 0;
		if (x < 0)minus++;
	}
	return minus % 2 == 0 ? 1 : -1;
}
//126. 单词接龙 II
class findLaddersSolution {
private:
	vector<vector<string>>ans;
public:
	void backtrack(unordered_map<string, set<string>> from, string cur, vector<string>v) {
		v.push_back(cur);
		if (from[cur].size() == 0) {
			reverse(v.begin(), v.end());
			ans.push_back(v);
			return;
		}
		for (string next : from[cur]) {
			backtrack(from, next, v);
		}
	}
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		//因为需要快速判断扩展出的单词是否在 wordList 里，因此需要将 wordList 存入哈希表，这里命名为「字典」
		unordered_set<string>dict = { wordList.begin(),wordList.end() };
		if (dict.find(endWord) == dict.end())return ans;
		dict.erase(beginWord);
		// 第 1 步：广度优先搜索建图
		// 记录扩展出的单词是在第几次扩展的时候得到的，key：单词，value：在广度优先搜索的第几层
		unordered_map<string, int>steps = { {beginWord,0} };
		// 记录了单词是从哪些单词扩展而来，key：单词，value：单词列表，这些单词可以变换到 key ，它们是一对多关系
		unordered_map<string, set<string>> from = { {beginWord, {}} };
		int step = 0;
		bool bound = false;
		queue<string>q;
		q.push(beginWord);
		bool find = false;
		int wordlen = beginWord.length();
		while (!q.empty()) {
			step++;
			int qn = q.size();
			for (int i = 0; i < qn; i++) {
				string cur = q.front();
				q.pop();
				string next = cur;
				for (int i = 0; i < wordlen; i++) {
					if (i != 0)next[i - 1] = cur[i - 1];
					for (char c = 'a'; c <= 'z'; c++) {
						next[i] = c;
						if (steps[next] == step) {
							from[next].insert(cur);
						}
						if (dict.find(next) == dict.end()) continue;
						dict.erase(next);
						q.push(next);
						steps[next] = step;
						from[next].insert(cur);
						if (next == endWord)find = true;
					}
				}
			}
			if (find)break;
		}
		if (find) {
			backtrack(from, endWord, {});
		}
		return ans;
	}
};
class ladderLengthSolution {
private:
	int minl = INT_MAX;
	vector<int>valid[505];
public:
	bool validWord(string a, string b) {
		int cnt = 0;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] != b[i]) {
				cnt++;
				if (cnt == 2)return false;
			}
		}
		return true;
	}
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		int n = wordList.size() + 1;
		wordList.push_back(beginWord);
		vector<int>vis(n, -1);
		bool find = false;
		for (int i = 0; i < n - 1; i++) {
			if (endWord == wordList[i])find = true;
			for (int j = i + 1; j < n; j++) {
				if (validWord(wordList[i], wordList[j])) {
					valid[i].push_back(j);
					valid[j].push_back(i);
				}
			}
		}
		if (!find)return 0;
		int cnt = 1, remain = 1, kid = 0;
		queue<int>q;
		q.push(n - 1);
		vis[n - 1] = 1;
		while (!q.empty()) {
			int top = q.front();
			q.pop();
			remain--;
			if (wordList[top] == endWord)return cnt;
			for (int i = 0; i < valid[top].size(); i++) {
				int next = valid[top][i];
				if (wordList[next] == endWord)return cnt + 1;
				if (vis[next] == -1) {
					vis[next] = 1;
					q.push(next);
					kid++;
				}
			}
			if (remain == 0) {
				remain = kid;
				kid = 0;
				cnt++;
			}
		}
	}
};
//129. 求根节点到叶节点数字之和
class sumNumbersSolution {
private:
	int sum = 0;
public:
	void dfs(TreeNode* root, string num) {
		if (root == nullptr) {
			return;
		}
		num.push_back(root->val + '0');
		if (root->left == nullptr && root->right == nullptr) {
			int start = 0;
			while (num[start] == '0')start++;
			string re = num.substr(start);
			if (re.length() > 0)sum += stoi(re);
			return;
		}
		else {
			dfs(root->left, num);
			dfs(root->right, num);
		}
	}
	int sumNumbers(TreeNode* root) {
		dfs(root, "");
		return sum;
	}
};
//130. 被围绕的区域
class solve_surround_Solution {
private:
	vector<vector<int>>dir = { {-1,0},{1,0},{0,1},{0,-1} };
public:
	void solve(vector<vector<char>>& board) {
		int n = board.size();
		if (n <= 1)return;
		int m = board[0].size();
		vector<vector<int>>vis(n, vector<int>(m, -1));
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				if (vis[i][j] == 1 || board[i][j] == 'X')continue;
				vis[i][j] = 1;
				vector<pair<int, int>>v;
				queue<pair<int, int>>q;
				q.emplace(i, j);
				bool edge = false;
				while (!q.empty()) {
					pair<int, int>p = q.front();
					v.emplace_back(p.first, p.second);
					vis[p.first][p.second] = 1;
					q.pop();
					for (int u = 0; u < 4; u++) {
						int x = p.first + dir[u][0];
						int y = p.second + dir[u][1];
						if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y] != -1 || board[x][y] != 'O')continue;
						if (x == 0 || x == n - 1 || y == 0 || y == m - 1)edge = true;
						q.emplace(x, y);
						vis[x][y] = 1;
					}
				}
				if (!edge) {
					for (int u = 0; u < v.size(); u++) {
						board[v[u].first][v[u].second] = 'X';
					}
				}
			}
		}
	}
};
//131. 分割回文串
class partitionSolution {
private:
	vector<string>ans;
	vector<vector<string>>res;
	vector<vector<int>>f;
	int n;
public:
	void dfs(string s, int i) {
		if (i == n) {
			res.push_back(ans);
			return;
		}
		for (int u = i; u < n; u++) {
			if (f[i][u]) {
				ans.push_back(s.substr(i, u - i + 1));
				dfs(s, i + 1);
				ans.pop_back();
			}
		}
	}
	vector<vector<string>> partition(string s) {
		n = s.length();
		f.assign(n, vector<int>(n, true));
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				f[i][j] = (s[i] == s[j] && f[i + 1][j - 1]);
			}
		}
		dfs(s, 0);
		return res;
	}
};
//132. 分割回文串 II
class minCutSolution {
private:
	vector<vector<int>>f;
	int n;
public:
	int minCut(string s) {
		n = s.length();
		f.assign(n, vector<int>(n, 1));
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				f[i][j] = (s[i] == s[j] && f[i + 1][j - 1]);
			}
		}
		vector<int>dp(n, INT_MAX);
		for (int i = 0; i < n; i++) {
			if (f[0][i])dp[i] = 0;
			else {
				for (int j = 0; j < i; j++) {
					if (f[j + 1][i]) {
						dp[i] = min(dp[i], dp[j] + 1);
					}
				}
			}
		}
		return dp[n - 1];
	}
};
////138. 复制带随机指针的链表
//Node* copyRandomList(Node* head) {
//	Node* ptr = head;
//	Node* root;
//	while (ptr != nullptr) {
//		root = new Node(ptr->val);
//		ptr = ptr->next;
//	}
//
//}
//int main() {
//	ListNode* root = nullptr, * temp = nullptr;
//	vector<int>nums1 = { 3,3,5,0,0,3,1,4 };
//	vector<int>nums2 = { 9,15,7,20,3 };
//	vector<int>nums3 = { 20,20,100,70,60 };
//	for (int x : nums1) {
//		if (root == nullptr) { root = new ListNode(x); temp = root; }
//		else { temp->next = new ListNode(x); temp = temp->next; }
//	}
//	vector<vector<char>>v = { {'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'} };
//	minCutSolution ss;
//	ss.minCut("aab");
//
//	return 0;
//}