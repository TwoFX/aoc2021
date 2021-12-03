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

ll conv(string s) {
	ll ans = 0;
	forc(c, s) {
		ans = 2 * ans + (c - '0');
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<string> a;
	string s;
	while (cin >> s) a.pb(s);

	vector<vector<string>> aa = { a, a };

	int n = sz(a[0]);
	ll g = 0, e = 0;
	fora(i, n) {
		fora(j, 2) {

			ll zs = 0, os = 0;
			forc(s, aa[j]) if (s[i] == '0') ++zs; else ++os;

			vector<string> q;
			char keep;
			if (j == 1) {
				keep = os >= zs ? '1' : '0';
			} else {
				keep = zs <= os ? '0' : '1';
			}
			forc(s, aa[j]) {
				if (s[i] == keep) q.pb(s);
			}
			aa[j] = q;
		}
	}
	cout << conv(aa[0][0]) * conv(aa[1][0]) << endl;
}
