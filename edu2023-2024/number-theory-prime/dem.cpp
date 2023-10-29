#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M = 1e9 + 7;
ll n, a[1000100], ret = 1, nt[1000100];

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
	freopen("dem.inp", "r", stdin);
    freopen("dem.out", "w", stdout);
	cin >> n;
	sang();
	for (int i=1; i<=n; i++)
	{
		ll tmp;
		cin >> tmp;
		add(tmp);
	}
	for (int i=2; i<=1000000; i++) if (a[i]) ret = (ret * (a[i] + 1)) % M;
	cout << ret << endl;
}
