#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

const ll M = 1e9 + 7;
ll n, a[1000100], ret = 1, nt[1000100], f[1000100], k;

void sang()
{
	nt[0] = 1;
	nt[1] = 1;
	for (int i=2; i<=1000; i++) if (!nt[i])
	{
		for (int j=i*i; j<=1000000; j+=i) nt[j] = i;
	}
	for (int i=2; i<=1000000; i++) if (!nt[i]) nt[i] = i;
}

inline void add(ll v)
{
	for (v; v != 1; v /= nt[v]) a[nt[v]]++;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("mu.inp", "r", stdin);
    freopen("mu.out", "w", stdout);
	cin >> n >> k;
	sang();
	for (int i=1; i<=n; i++)
	{
		ll tmp;
		cin >> tmp;
		add(tmp);
	}
	ll mn = 0;
	vector<pair<int, int> > val;
	for (int i=2; i<=1000; i++) if (a[i])
	{
		mn = max(mn, a[i]);
		f[a[i]]++;
	}
	for (int i=1; i<=1000000; i++) if (f[i])
	{
		val.push_back({i, f[i]});
	}
	ll tmp = 0;
	for (auto v : val) tmp += (v.fi % k) * v.se;
	cout << tmp << endl;
}
