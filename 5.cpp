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

	vector<vector<int>> f(1500, vector<int>(1500));
	ll x1;
	while (cin >> x1) {
		ll y1, x2, y2;
		cin >> y1 >> x2 >> y2;
		if (x1 == x2) {
		if (y1 > y2) swap(y1, y2);
			for (ll y = y1; y <= y2; ++y) {
				++f[x1][y];
			}
		} else if (y1 == y2) {
		if (x1 > x2) swap(x1, x2);
			for (ll x = x1; x <= x2; ++x) {
				++f[x][y1];
			}
		} else {
			if (x1 > x2) { swap(x1, x2); swap(y1, y2); }
			ll d = y2 > y1 ? 1 : -1;
			ll y = y1;
			for (ll x = x1; x <= x2; ++x) {
				++f[x][y];
				y += d;
			}
		}
	}
	ll ans = 0;
	fora(i, 1500) fora(j, 1500) {
		if (f[i][j] >= 2) {
			cout << dbgs2(i, j) << endl;
			++ans;
		}
	}
	cout << ans << endl;
}
