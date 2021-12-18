#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define all(a) begin(a), end(a)
#define has(a, b) (a.find(b) != a.end())
#define fora(i, n) for(ll i = 0; i < n; i++)
#define forb(i, n) for(ll i = 1; i <= n; i++)
#define forc(a, b) for(const auto &a : b)
#define ford(i, n) for(ll i = n; i >= 0; i--)
#define maxval(t) numeric_limits<t>::max()
#define minval(t) numeric_limits<t>::min()
#define imin(a, b) a = min(a, b)
#define imax(a, b) a = max(a, b)
#define sz(x) (ll)(x).size()
#define pvec(v) copy(all(v), ostream_iterator<decltype(v)::value_type>(cout, " "))

#define dbgs(x) #x << " = " << x
#define dbgs2(x, y) dbgs(x) << ", " << dbgs(y)
#define dbgs3(x, y, z) dbgs2(x, y) << ", " << dbgs(z)
#define dbgs4(w, x, y, z) dbgs3(w, x, y) << ", " << dbgs(z)

using ll = long long;
using ld = long double;

vector<ll> val, dleft, dright, up;

void print_mem() {
	fora(i, sz(val)) {
		cout << dbgs(i) << " " << dbgs4(val[i], dleft[i], dright[i], up[i]) << endl;
	}
}

void check_valid(int root) {
	if (val[root] == -1 && dleft[root] == -1 && dright[root] == -1) {
		cout << "invalid" << endl;
		print_mem();
	}
}

pair<ll, ll> parse(const string&s, ll i) {
	ll nval, ndleft, ndright;
	if (s[i] == '[') {
		pair<ll, ll> l = parse(s, i + 1);
		i = l.first;
		ndleft = l.second;
		pair<ll, ll> r = parse(s, i + 1);
		i = r.first + 1;
		ndright = r.second;
		nval = -1;
	} else {
		nval = s[i] - '0';
		ndright = -1;
		ndleft = -1;
		i++;
	}
	ll idx = sz(val);
	val.pb(nval);
	dleft.pb(ndleft);
	dright.pb(ndright);
	up.pb(-1);
	if (ndleft != -1) up[ndleft] = idx;
	if (ndright != -1) up[ndright] = idx;
	return mp(i, idx);
}

ll drightmost(ll root) {
	//cout << "drightmost " << root << endl;
	if (root == -1) print_mem();
	if (val[root] != -1) return root;
	return drightmost(dright[root]);
}

ll dleftmost(ll root) {
	//cout << "dleftmost " << root << endl;
	if (val[root] != -1) return root;
	return dleftmost(dleft[root]);
}

ll next_dleft(ll root, ll avoid) {
	//cout << "next_dleft " << root << " " << avoid << endl;
	if (dleft[root] != avoid) return drightmost(dleft[root]);
	if (up[root] == -1) return -1;
	return next_dleft(up[root], root);
}

ll next_dright(ll root, ll avoid) {
	//cout << "next_dright " << root << " " << avoid << endl;
	if (dright[root] != avoid) return dleftmost(dright[root]);
	if (up[root] == -1) return -1;
	return next_dright(up[root], root);
}

void replace_with(ll dest, ll src) {
	val[dest] = val[src];
	dleft[dest] = dleft[src];
	dright[dest] = dright[src];
	if (dleft[src] != -1) up[dleft[src]] = dest;
	if (dright[src] != -1) up[dright[src]] = dest;
	// up stays the same
}

bool expl(ll root, ll depth) {
	check_valid(13);
	//cout << "expl " << root << " " << depth << endl;
	if (root == -1) print_mem();
	if (val[root] != -1) return false;
	if (depth == 4) {
		ll nl = next_dleft(up[root], root);
		if (nl != -1) val[nl] += val[dleft[root]];
		ll nr = next_dright(up[root], root);
		if (nr != -1) val[nr] += val[dright[root]];
		val[root] = 0;
		dleft[root] = -1;
		dright[root] = -1;
		return true;
	} else {
		bool ok = expl(dleft[root], depth + 1);
		if (!ok) {
			ok = expl(dright[root], depth + 1);
		}
		return ok;
	}
}

bool try_explode(ll root) {
	return expl(root, 0);
}

ll mk_node(ll par, ll v) {
	ll idx = sz(val);
	val.pb(v);
	dleft.pb(-1);
	dright.pb(-1);
	up.pb(par);
	return idx;
}

bool try_split(ll root) {
	//cout << "try_split " << root << endl;
	if (val[root] != -1) {
		if (val[root] < 10) return false;
		//cout << dbgs3(root, sz(dleft), sz(dright)) << endl;
		ll nl = mk_node(root, val[root] / 2);
		dleft[root] = nl;

		ll nr = mk_node(root, (val[root] + 1) / 2);
		dright[root] = nr;
		val[root] = -1;
		return true;
	} else {
		bool ok = try_split(dleft[root]);
		if (!ok) {
			ok = try_split(dright[root]);
		}
		return ok;
	}
}

ll combine(ll par, ll le, ll ri) {
	ll idx = sz(val);
	val.pb(-1);
	dleft.pb(le);
	dright.pb(ri);
	up[le] = idx;
	up[ri] = idx;
	up.pb(par);
	return idx;
}

ll add(ll le, ll ri) {
	ll root = combine(-1, le, ri);

	while (try_explode(root) || try_split(root)) { }

	return root;
}

ll magnitude(ll root) {
	if (val[root] != -1) return val[root];
	return 3 * magnitude(dleft[root]) + 2 * magnitude(dright[root]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	ll cur = -1;
	ll best = 0;
	vector<string> S;
	while (cin >> s) S.pb(s);
	ll n = sz(S);
	fora(i, n) fora(j, n) {
		if (i == j) continue;

		auto c1 = parse(S[i], 0);
		auto c2 = parse(S[j], 0);
		ll x = add(c1.second, c2.second);
		imax(best, magnitude(x));
	}
	cout << best << endl;
}
