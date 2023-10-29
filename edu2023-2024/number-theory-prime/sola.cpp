#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

const ll M = 1e9+7;
ll n, a[10010][301], f[10010][301], q, l, r, nt[1001], val[100010], ff[100010];
int mp[1001], m, pm[1001];

inline ll get_bit(ll state, int j)
{
    return state >> (j-1) & 1;
}
inline ll set_bit(int c, ll state, int j)
{
    if (c == 1) return state | (1 << (j-1));
    else return state & (~(1 << (j-1)));
}

void sang()
{
	nt[0] = 1;
	nt[1] = 1;
	for (int i=2; i<=sqrt(1000); i++) if (!nt[i])
	{
		for (int j=i*i; j<=1000; j+=i) nt[j] = i;
	}
	for (int i=2; i<=1000; i++) if (!nt[i]) nt[i] = i, mp[++m] = i, pm[i] = m;
}

void add(int v, int idx)
{
	ll tmp = 0;
	for (v; v != 1; v /= nt[v])
	{
		a[idx][nt[v]]++;
		if (!get_bit(tmp, pm[nt[v]])) tmp = set_bit(1, tmp, pm[nt[v]]);
	}
	val[idx] = tmp;
}

void solve(int l, int r)
{
	ll ret = 1;
	ll state = ff[r] ^ ff[l-1];
	// for (int i=1; i<=63; i++) cout << get_bit(state, i); cout << endl;
	for (int i=1; i<=63; i++) if (get_bit(state, i))
	{
		ll tmp = f[r][mp[i]];
		while (tmp)
		{
			ret = (ret * mp[i]) % M;
			tmp--;
		}
	}
	cout << ret << endl;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("la.inp", "r", stdin);
    freopen("la.out", "w", stdout);
	cin >> n >> q;
	sang();
	for (int i=1; i<=n; i++) cin >> a[i][0];
	for (int i=1; i<=n; i++) add(a[i][0], i);
	for (int i=1; i<=n; i++) for (int j=1; j<=100; j++)
	{
		if (!a[i][j]) f[i][j] = f[i-1][j];
		else f[i][j] = a[i][j];
	}
	// for (int i=1; i<=n; i++) 
	// {
	// 	for (int j=1; j<=63; j++) cout << f[i][j]; cout << endl;
	// }
	for (int i=1; i<=n; i++) ff[i] = ff[i-1] ^ val[i];
	while (q--)
	{
		cin >> l >> r;
		solve(l, r);
	}
}
