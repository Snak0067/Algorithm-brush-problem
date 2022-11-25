//#include<bits/stdc++.h>
//#define MAX (1000001)
//using namespace std;
//int n, a[MAX], d[MAX];
//int main()
//{
//	int i, j, k, x;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	for (i = 1; i < n; i++)
//	{
//		for (j = i + 1; j <= n; j++)
//		{
//			x = abs(a[i] - a[j]);
//			for (k = 1; k * k <= x; k++)
//			{
//				if (!(x % k))
//				{
//					d[k] = d[x / k] = 1;
//				}
//			}
//		}
//	}
//	for (i = 1; d[i]; i++);
//	printf("%d\n", i);
//	return 0;
//}