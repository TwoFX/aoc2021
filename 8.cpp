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

vector<int> pairs;

vector<vector<ll>> poss = {
	{},
	{},
	{ 2, 5 },
	{ 0, 2, 5 },
	{ 1, 2, 3, 5 },
	{ 0, 1, 2, 3, 4, 5, 6 },
	{ 0, 1, 2, 3, 4, 5, 6 },
	{ 0, 1, 2, 3, 4, 5, 6 } };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	map<vector<ll>, ll> num;
	num[{0, 1, 2, 4, 5, 6}] = 0;
	num[{2, 5}] = 1;
	num[{0, 2, 3, 4, 6}] = 2;
	num[{0, 2, 3, 5, 6}] = 3;
	num[{1, 2, 3, 5}] = 4;
	num[{0, 1, 3, 5, 6}] = 5;
	num[{0, 1, 3, 4, 5, 6}] = 6;
	num[{0, 2, 5}] = 7;
	num[{0, 1, 2, 3, 4, 5, 6 }] = 8;
	num[{0, 1, 2, 3, 5, 6}] = 9;

	ll ans = 0;
	string s;
	while (cin >> s) {
		vector<string> l, r;
		while (s != "|") {
			l.pb(s);
			cin >> s;
		}
		cin >> s;
		while (s != "NEXT") {
			r.pb(s);
			cin >> s;
		}
		vector<string> b(all(l));
		forc(x, r) b.pb(x);
		string as = "abcdefg";
		pairs = vector<int>(14);
		bool ok = true;
		do {
			ok = true;
			fora(i, 7) {
				pairs[as[i] - 'a'] = i + 7;
			}
			forc(t, b) {
				vector<ll> chrs;
				forc(c, t) {
					chrs.pb(pairs[c - 'a'] - 7);
				}
				sort(all(chrs));
				if (num.find(chrs) == num.end()) {
					ok = false;
					break;
				}
			}
			if (ok) break;
		} while (next_permutation(all(as)));

		ll innerans = 0;

		forc(t, r) {
			vector<ll> chrs;
			forc(c, t) {
				chrs.pb(pairs[c - 'a'] - 7);
			}
			sort(all(chrs));
			if (num.find(chrs) == num.end()) {
				cout << "Cannot find ";
				forc(n, chrs) {
					cout << n << " ";
				}
				cout << endl;
			}
			innerans = 10 * innerans + num[chrs];
		}
		ans += innerans;
	}
	cout << ans << endl;

}
