#include <iostream>
#include <vector>

using namespace std;

#define ll long long
const ll MAX = 1000002;
const ll NMAX = 50000;

ll primeNum[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

ll n, q;
ll a[NMAX];
ll prime[MAX] = { 0 };

vector<ll> segT[200000];
vector<ll> zero(101, 0);

vector<ll> operator+(const vector<ll>& a, const vector<ll>& b) {
    vector<ll> tmp(101, 0);
    for(ll i = 0; i < a.size(); i++) {
        tmp[i] = a[i] + b[i];
    }
    return tmp;
}

void fac_prime() {
    for(ll i = 2; i < MAX; i += 2) prime[i] = 2;
    for(ll i = 3; i < MAX; i += 2) {
        if(!prime[i]) {
            prime[i] = i;
            for(ll j = i; i * j < MAX; j += 2) {
                if(!prime[i * j]) prime[i * j] = i;
            }
        }
        
    }
}

vector<ll> primeFactorOfNum(ll n) {
    vector <ll> v(101, 0);
    while(n != 1) {
        ll k = prime[n];
        while(!(n % k)) {
            n /= k;
            v[k]++;
        }
    }
    return v;
}

void build(ll id, ll l, ll r) {
    if(l == r) {
        segT[id] = primeFactorOfNum(a[l]);
        return;
    }

    ll mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    segT[id] = segT[id * 2] + segT[id * 2 + 1];
}

void update(ll id, ll l, ll r, ll index, vector<ll> val) {
    if(index < l || index > r || r < l) return;

    if(l == r) {
        segT[id] = segT[id] + val;
        return;
    }

    ll mid = (l + r) / 2;
    update(id * 2, l , mid, index, val);
    update(id * 2 + 1, mid + 1, r, index, val);
    segT[id] = segT[id * 2] + segT[id * 2 + 1];
}

vector<ll> get(ll id, ll l, ll r, ll u, ll v) {
    if(v < l || u > r || r < l) return zero;

    if(u <= l && r <= v) {
        return segT[id];
    }

    ll mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

int main() {
    fac_prime();
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("sodep.inp","r",stdin);
    freopen("sodep.out","w",stdout);
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    cin >> q;
    while(q--) {
        int type;
        cin >> type;
        if (type == 1) {
            ll L, R;
            bool flag = true;
            cin >> L >> R;
            vector<ll> ans = get(1, 1, n, L, R);
            for(ll i = 0; i < 25; i++) {
                if(ans[primeNum[i]] & 1){
                    flag = false;
                    break;
                }
            }
            cout << (flag ? "YES\n" : "NO\n");
        }
        else {
            ll index, val;
            cin >> index >> val;
            vector<ll> valPrime = primeFactorOfNum(val);
            update(1, 1, n, index, valPrime);
        }
    }
    return 0;
}
