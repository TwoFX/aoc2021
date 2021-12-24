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
	string c, arg1, arg2s;
	ll arg2n;
	bool num;
};

vector<com> coms;

set<tuple<ll, ll, int>> seen;

pair<bool, string> get(ll w, ll x, ll y, ll z, int ci) {
	if (z > 10000000) return mp(false, "");
	if (has(seen, make_tuple(w, z, ci))) {
		return mp(false, "");
	}
	seen.emplace(w, z, ci);

	for (int i = ci; i < sz(coms); ++i) {
		const com &c = coms[i];

		if (c.c == "inp") {
			for (int d = 1; d <= 9; ++d) {
				auto res = get(d, x, y, z, i + 1);
				if (res.first) {
					stringstream ss;
					ss << (char)(d + '0') << res.second;
					return mp(true, ss.str());
				}
			}
			return mp(false, "");
		}

		ll rval;
		if (c.num) {
			rval = c.arg2n;
		} else if (c.arg2s == "w") {
			rval = w;
		} else if (c.arg2s == "x") {
			rval = x;
		} else if (c.arg2s == "y") {
			rval = y;
		} else if (c.arg2s == "z") {
			rval = z;
		}
		ll *lval;
		if (c.arg1 == "w") {
			lval = &w;
		} else if (c.arg1 == "x") {
			lval = &x;
		} else if (c.arg1 == "y") {
			lval = &y;
		} else if (c.arg1 == "z") {
			lval = &z;
		}

		if (c.c == "add") {
			*lval = *lval + rval;
		} else if (c.c == "mul") {
			*lval = *lval * rval;
		} else if (c.c == "div") {
			*lval = *lval / rval;
		} else if (c.c == "mod") {
			*lval = *lval % rval;
		} else if (c.c == "eql") {
			*lval = (*lval == rval) ? 1 : 0;
		}
	}
	return mp(z == 0, "");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string c;
	while (cin >> c) {
		string a1, a2;
		cin >> a1;
		if (c != "inp") {
			cin >> a2;
		} else {
			a2 = "x";
		}
		ll arg2n = 0;
		bool num = false;
		if (!(a2 == "w" || a2 == "x" || a2 == "y" || a2 == "z")) {
			arg2n = atoi(a2.c_str());
			num = true;
		}
		coms.pb(com { c, a1, a2, arg2n, num });
	}

	auto ans = get(0, 0, 0, 0, 0);
	cout << dbgs2(ans.first, ans.second) << endl;

}
