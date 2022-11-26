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
int v[105];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v, v + n);
	int left = 0, right = 0;
	m -= v[0];
	int cnt = 0;
	while (right < n && left < n) {
		if (m > 0) {

		}
	}
	return 0;
}