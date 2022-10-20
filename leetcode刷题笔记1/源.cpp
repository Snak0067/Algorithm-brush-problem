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





int main() {
	ListNode* root = nullptr, * temp = nullptr;
	vector<int>nums1 = { 2,0,2,1,1,0 };
	vector<int>nums2 = { 0,1,0,1 };
	for (int x : nums1) {
		if (root == nullptr) { root = new ListNode(x); temp = root; }
		else { temp->next = new ListNode(x); temp = temp->next; }
	}
	vector<vector<int>>v = { {1,5} };
	vector<string>s = { "This", "is", "an", "example", "of", "text", "justification." };
	sortColors(nums1);
	return 0;
}