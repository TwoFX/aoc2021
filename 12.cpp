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

map<string, set<string>> adj;

bool lower(char c) {
	return 'a' <= c && c <= 'z';
}

bool bad(const map<string, int> & seen) {
	bool one = false;
	forc(p, seen) {
		if (p.second >= 3) return true;
		if (p.second >= 2 && one) return true;
		if (p.second >= 2) one = true;
	}
	return false;
}

ll dfs(const string &cur, map<string, int> &seen) {
	if (bad(seen)) return 0;
	if (cur == "end") {
		return 1;
	}

	if (cur == "start" && seen[cur] >= 1) return 0;

	ll ans = 0;
	if (lower(cur[0])) ++seen[cur];
	forc(ne, adj[cur]) {
		ans += dfs(ne, seen);
	}
	if (lower(cur[0])) --seen[cur];
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s, t;
	while (cin >> s >> t) {
		adj[s].insert(t);
		adj[t].insert(s);
	}
	map<string, int> S;
	cout << dfs("start", S)  << endl;


}
