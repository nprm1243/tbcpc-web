#include <bits/stdc++.h>
using namespace std;

int n, a[100010][101], f[100010][101], q, l, r, nt[1001];

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

void xuly(int v, int idx)
{
	for (v; v != 1; v /= nt[v]) a[idx][nt[v]]++;
}

bool check(int l, int r)
{
	for (int j=2; j<=100; j++)
	{
		int t = f[r][j] - f[l-1][j];
		if (t % 2 != 0) return false;
	}
	return true;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
    freopen("chinhphuong.inp", "r", stdin);
    freopen("chinhphuong.out", "w", stdout);
	cin >> n >> q;
	sang();
	for (int i=1; i<=n; i++) cin >> a[i][0];
	for (int i=1; i<=n; i++) xuly(a[i][0], i);
	for (int i=1; i<=n; i++) for (int j=1; j<=100; j++) f[i][j] = f[i-1][j] + a[i][j];
	while (q--)
	{
		cin >> l >> r;
		cout << (check(l, r) ? "YES" : "NO") << endl;
	}
}
