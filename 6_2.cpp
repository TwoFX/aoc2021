#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define all(a) begin(a), end(a)
#define has(a, b) (a.find(b) != a.end())
#define fora(i, n) for(int i = 0; i < n; i++)
#define forb(i, n) for(int i = 1; i <= n; i++)
#define forc(a, b) for(const auto &a : b)
#define ford(i, n) for(int i = n; i >= 0; i--)
#define maxval(t) numeric_limits<t>::max()
#define minval(t) numeric_limits<t>::min()
#define imin(a, b) a = min(a, b)
#define imax(a, b) a = max(a, b)
#define sz(x) (int)(x).size()
#define pvec(v) copy(all(v), ostream_iterator<decltype(v)::value_type>(cout, " "))

#define dbgs(x) #x << " = " << x
#define dbgs2(x, y) dbgs(x) << ", " << dbgs(y)
#define dbgs3(x, y, z) dbgs2(x, y) << ", " << dbgs(z)
#define dbgs4(w, x, y, z) dbgs3(w, x, y) << ", " << dbgs(z)

using ll = long long;
using ld = long double;

constexpr ll mod = 1000000000;
constexpr ll n = 9;
constexpr ll days = 1000000000000000000;

using mat = vector<vector<ll>>;

mat mul(const mat &a, const mat &b) {
	mat res = mat(n, vector<ll>(n));
	fora(i, n) fora(j, n) fora(k, n) {
		res[i][k] = (res[i][k] + ((a[i][j] * b[j][k]) % mod)) % mod;
	}
	return res;
}

mat powMod(const mat &a, ll b) {
	mat res = a;
	mat aa = a;
	--b;
	while (b > 0) {
		if (b & 1) res = mul(aa, res);
		aa = mul(aa, aa);
		b /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	mat a = mat(n, vector<ll>(n));
	fora(i, n) {
		a[i][(i + 1) % n] = 1;
	}
	a[6][0] = 1;

	mat e = powMod(a, days);

	vector<ll> cnt(n);
	ll x;
	while (cin >> x) ++cnt[x];

	ll ans = 0;
	fora(i, n) fora(j, n) {
		ans = (ans + ((e[i][j] * cnt[j]) % mod)) % mod;
	}
	cout << ans << endl;
}
