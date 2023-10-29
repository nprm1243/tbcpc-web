#include <bits/stdc++.h>
using namespace std;

int n, m, a[1001], b[1001], nt[100010];

void sang()
{
	nt[0] = 1;
	nt[1] = 1;
	for (int i=2; i<=sqrt(1000); i++) if (!nt[i])
	{
		for (int j=i*i; j<=1000; j+=i) nt[j] = i;
	}
	for (int i=2; i<=1000; i++) if (!nt[i]) nt[i] = i;
}

int main()
{
    freopen("chiahet.inp", "r", stdin);
    freopen("chiahet.out", "w", stdout);
	cin >> n >> m;
	sang();
	for (int i=1; i<=n; i++)
	{
		int x;
		cin >> x;
		if (x > 1)
			for (x; x != 1; x /= nt[x]) a[nt[x]]++;
	}
	for (int i=1; i<=m; i++)
	{
		int x;
		cin >> x;
		if (x > 1)
			for (x; x != 1; x /= nt[x]) b[nt[x]]++;
	}
	for (int i=1; i<=1000; i++) if (b[i] > a[i]) 
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
}
