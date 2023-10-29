#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M = 1e9+7;
ll n, a[100010][101], f[100010][101], q, l, r, nt[1001], u, v;

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

inline void add(int v, int idx)
{
	for (v; v != 1; v /= nt[v]) a[idx][nt[v]]++;
}

void xuly(int l, int r, int u, int v)
{
	vector<int>x(101, 0);
	vector<int>y(101, 0);
	for (int j=2; j<=100; j++) x[j] = f[r][j] - f[l-1][j];
	for (int j=2; j<=100; j++) y[j] = f[v][j] - f[u-1][j];
	vector<int>gcd(101, 0);
	vector<int>lcm(101, 0);
	for (int i=2; i<=100; i++) gcd[i] = min(x[i], y[i]), lcm[i] = max(x[i], y[i]);
	ll gcd_ = 1, lcm_ = 1;
	for (int i=1; i<=100; i++) while (gcd[i])
	{
		gcd_ = (gcd_ * i) % M;
		gcd[i]--;
	}
	for (int i=1; i<=100; i++) while (lcm[i])
	{
		lcm_ = (lcm_ * i) % M;
		lcm[i]--;
	}
	cout << gcd_ << " " << lcm_ << endl;
}

bool check(int l, int r)
{
	for (int j=1; j<=100; j++)
	{
		int t = f[r][j] - f[l-1][j];
		if (t % 2 != 0) return false;
	}
	return true;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("gcd.inp", "r", stdin);
    freopen("gcd.out", "w", stdout);
	cin >> n >> q;
	sang();
	for (int i=1; i<=n; i++) cin >> a[i][0];
	for (int i=1; i<=n; i++) add(a[i][0], i);
	for (int i=1; i<=n; i++) for (int j=1; j<=100; j++) f[i][j] = f[i-1][j] + a[i][j];
	while (q--)
	{
		cin >> l >> r >> u >> v;
		xuly(l, r, u, v);
	}
}
