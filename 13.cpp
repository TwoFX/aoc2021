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

	int n;
	cin >> n;
	vector<pair<ll, ll>> ps(n);
	fora(i, n) cin >> ps[i].first >> ps[i].second;

	char dir;
	ll q;
	set<pair<ll, ll>> curdots(all(ps));
	while (cin >> dir >> q) {
		set<pair<ll, ll>> newdots;
		forc(d, curdots) {
			ll newx = d.first, newy = d.second;
			if (dir == 'x') {
				if (newx >= q) {
					newx = 2 * q - newx;
				}
			} else{
				if (newy >= q) {
					newy = 2 * q - newy;
				}
			}
			newdots.emplace(newx, newy);
		}
		curdots = newdots;
	}

	ll xmin = maxval(int), xmax = minval(int), ymin = maxval(int), ymax = minval(int);
	forc(d, curdots) {
		imin(xmin, d.first);
		imax(xmax, d.first);
		imin(ymin, d.second);
		imax(ymax, d.second);
	}
	cout << dbgs4(xmin, xmax, ymin, ymax) << endl;
	vector<vector<char>> a(10, vector<char>(40, '.'));
	forc(d, curdots) a[d.second][d.first] = '#';
	fora(i, 10) {
		forc(c, a[i]) cout << c;
		cout << endl;
	}
}
