#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<stack>
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
int search(vector<int>& nums, int target) {
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
ListNode* deleteDuplicates(ListNode* head) {
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
int minSubArrayLen(int target, vector<int>& nums) {
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
int maxPoints(vector<vector<int>>& points) {
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

int main() {
	ListNode* root = nullptr, * temp = nullptr;
	vector<int>nums1 = { 9,9,9 };
	vector<int>nums2 = { 1,7,4,6,8 };
	vector<vector<int>>a = {
  {1,   4,  7, 11, 15},
  {2,   5,  8, 12, 19},
  {3,   6,  9, 16, 22},
  {10, 13, 14, 17, 24},
  {18, 21, 23, 26, 30}
	};
	vector<int>preorder = { 3, 9, 20, 15, 7 }, inorder = { 9, 3, 15, 20, 7 };
	for (int x : nums1) {
		if (root == nullptr) {
			root = new ListNode(x);
			temp = root;
		}
		else {
			temp->next = new ListNode(x);
			temp = temp->next;
		}
	}
	addBinary("11", "1");
	return 0;
}