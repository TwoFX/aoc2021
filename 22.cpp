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

struct com {
	string c;
	ll start[3], end[3];
};

vector<com> coms;

int getin(int i, int j, int k) {
	int ans = 0;
	forc(c, coms) {
		if (i < c.start[0] || i > c.end[0] || j < c.start[1] || j > c.end[1]
				|| k < c.start[2] || k > c.end[2]) continue;
		if (c.c == "on") ans = 1;
		else ans = 0;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	set<tuple<ll, ll, ll>> cur;
	string c;
	vector<vector<ll>> coords(3);
	while (cin >> c) {
		ll x1, x2, y1, y2, z1, z2;
		cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
			coords[0].pb(x1);
			coords[0].pb(x2 + 1);
			coords[1].pb(y1);
			coords[1].pb(y2 + 1);
			coords[2].pb(z1);
			coords[2].pb(z2 + 1);
		coms.pb(com { c, { x1, y1, z1 }, { x2, y2, z2 } });
	}

	fora(i, 3) {
		sort(all(coords[i]));
		coords[i].erase(unique(all(coords[i])), coords[i].end());
	}

	ll ans = 0;

	fora(i, sz(coords[0]) - 1) {
		cout << dbgs2(i, sz(coords[0])) << endl;
		fora(j, sz(coords[1]) - 1) {
			fora(k, sz(coords[2]) - 1) {
				ll siz = (coords[0][i + 1] - coords[0][i])
					* (coords[1][j + 1] - coords[1][j])
					* (coords[2][k + 1] - coords[2][k]);
				ans += siz * getin(coords[0][i], coords[1][j], coords[2][k]);
			}
		}
	}
	cout << ans << endl;
}
