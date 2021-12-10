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

	map<char, ll> p;
	p[')'] = 3;
	p[']'] = 57;
	p['}'] = 1197;
	p['>'] = 25137;

	map<char, ll> q;
	q[')'] = 1;
	q[']'] = 2;
	q['}'] = 3;
	q['>'] = 4;

	string s;
	ll score = 0;
	vector<ll> scores;
	while (cin >> s) {
		vector<char> t;
		bool ok = true;
		forc(c, s) {
			if (c == '(') {
				t.pb(')');
			} else if (c == '[') {
				t.pb(']');
			} else if (c == '<') {
				t.pb('>');
			} else if (c == '{') {
				t.pb('}');
			} else {
				char ex = t.back();
				t.pop_back();
				if (c != ex) {
					ok = false; break;
				}
			}
		}
		if (ok) {
			ll sc = 0;
			while (sz(t) != 0) {
				sc = 5 * sc + q[t.back()];
				t.pop_back();
			}
			scores.pb(sc);
		}
	}
	sort(all(scores));
	cout << scores[sz(scores) / 2] << endl;
}
