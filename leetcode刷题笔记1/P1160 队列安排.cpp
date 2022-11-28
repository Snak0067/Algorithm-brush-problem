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
//int num[100005];
//int v[100005][2];
//struct node {
//	int v;
//	node(int val) {
//		v = val;
//	}
//	node* next = nullptr;
//};
///*第一种方法是链表的顺序查询的方法 结果是超时三个点 只有40分*/
//void likedList() {
//	int n;
//	cin >> n;
//	node* root = new node(0);
//	root->next = new node(1);
//	for (int i = 2; i <= n; i++)
//	{
//		int val, dir;
//		cin >> val >> dir;
//		node* left = root, * right = root->next;
//		if (dir == 0) {
//			while (right->v != val) {
//				left = right;
//				right = right->next;
//			}
//			node* temp = new node(i);
//			temp->next = right;
//			left->next = temp;
//		}
//		else {
//			while (left->v != val) {
//				left = right;
//				right = right->next;
//			}
//			node* temp = new node(i);
//			temp->next = right;
//			left->next = temp;
//		}
//	}
//	int m, val;
//	cin >> m;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> val;
//		if (num[val])continue;
//		num[val] = 1;
//		node* temp = root;
//		while (temp->next != nullptr) {
//			if (temp->next->v == val) {
//				temp->next = temp->next->next;
//				break;
//			}
//			else {
//				temp = temp->next;
//			}
//
//		}
//	}
//	root = root->next;
//	while (root != nullptr) {
//		printf("%d", root->v);
//		if (root->next != nullptr)printf(" ");
//		root = root->next;
//	}
//}
//int main() {
//	int n;
//	cin >> n;
//	int start = 1;
//	for (int i = 2; i <= n; i++)
//	{
//		int val, dir;
//		cin >> val >> dir;
//		if (val == start && dir == 0) {
//			start = i;
//			v[val][0] = i;
//			v[i][1] = val;
//			v[i][0] = 0;
//		}
//		else {
//			int left = v[val][0];
//			int right = v[val][1];
//			if (dir == 0) {
//				v[left][1] = i;
//				v[val][0] = i;
//				v[i][1] = val;
//				v[i][0] = left;
//			}
//			else {
//				v[right][0] = i;
//				v[val][1] = i;
//				v[i][1] = right;
//				v[i][0] = val;
//			}
//		}
//	}
//	int m;
//	cin >> m;
//	for (int i = 0; i < m; i++)
//	{
//		int x;
//		cin >> x;
//		if (num[x])continue;
//		num[x] = 1;
//		int left = v[x][0];
//		int right = v[x][1];
//		v[left][1] = right;
//		v[right][0] = left;
//	}
//	int cur = start;
//	while (cur != 0) {
//		printf("%d", cur);
//		cur = v[cur][1];
//		if (cur != 0)printf(" ");
//	}
//	printf("\n");
//	return 0;
//}