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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<ll> a;
	ll b;
	while (cin >> b) a.pb(b);

	//sort(all(a));
	int n = sz(a);
	ll ma = 0;
	fora(i, n) imax(ma, a[i]);
	ll best = maxval(ll);
	fora(p, ma + 1) {
		ll v = 0;
		fora(i, n) {
			ll dist = abs(p - a[i]);
			v += (dist * (dist + 1)) / 2;
		}
		imin(best, v);
		if (best == 168) {
			cout << p << endl;
		fora(i, n) {
			ll dist = abs(p - a[i]);
			cout << dbgs2(dist, (dist * (dist + 1)) / 2) << endl;
		}
		}
	}
	cout << best << endl;
}
