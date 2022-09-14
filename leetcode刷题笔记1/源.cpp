#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

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
int findMin(vector<int>& nums) {
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
	int num = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		int curr = 1;
		for (int j = i; j < nums.size(); j++)
		{
			curr *= nums[j];
			if (curr >= k)break;
			num++;
		}
	}
	return num;
}
int main() {
	ListNode* root = nullptr, * temp = nullptr;
	vector<int>nums = { 10,5,2,6 };
	vector<vector<int>>a = { {3,5},{9,20} };
	vector<vector<int>>b = { {4, 5}, { 7,10 }, { 11,12 }, { 14,15 }, { 16,20 } };
	for (int x : nums) {
		if (root == nullptr) {
			root = new ListNode(x);
			temp = root;
		}
		else {
			temp->next = new ListNode(x);
			temp = temp->next;
		}
	}
	numSubarrayProductLessThanK(nums, 100);

	return 0;
}