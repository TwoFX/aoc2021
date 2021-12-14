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

map<pair<char, char>, char> p;
map<tuple<char, char, int>, vector<ll>> d;

vector<ll> get(char fi, char se, int steps) {
	auto x = mp(fi, se);
	auto t = make_tuple(fi, se, steps);
	if (has(d, t)) return d[t];

	vector<ll> res(26);
	if (has(p, x)) {
		char mi = p[x];
		++res[mi - 'A'];

		if (steps > 0) {
			vector<ll> u = get(fi, mi, steps - 1);
			vector<ll> v = get(mi, se, steps - 1);
			fora(i, 26) {
				res[i] += u[i];
				res[i] += v[i];
			}
		}
	}
	d[t] = res;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string t;
	cin >> t;

	string u, v;
	while (cin >> u >> v) {
		p[mp(u[0], u[1])] = v[0];
	}

	vector<ll> res(26);
	forc(c, t) {
		++res[c - 'A'];
	}

	fora(i, sz(t) - 1) {
		vector<ll> q = get(t[i], t[i + 1], 39);
		fora(i, 26) res[i] += q[i];
	}

	ll mi = maxval(ll), ma = minval(ll);
	fora(i, 26) {
		if (res[i] == 0) continue;
		imin(mi, res[i]);
		imax(ma, res[i]);
	}

	cout << dbgs3(ma, mi, ma - mi) << endl;
}
