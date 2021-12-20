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

	string s;
	cin >> s;

	vector<string> f;
	string q;
	while (cin >> q) f.pb(q);

	set<pair<int, int>> im;
	fora(i, sz(f)) fora(j, sz(f[i])) if (f[i][j] == '#') im.emplace(i, j);

	int pjma = -1, pjmi, pima, pimi;
	fora(_, 50) {
		set<pair<int, int>> rel;
		forc(p, im) for (int di = -2; di <= 2; ++di) for (int dj = -2; dj <= 2; ++dj) {
			rel.emplace(p.first + di, p.second + dj);
		}

		int ima = minval(int);
		int imi = maxval(int);
		int jma = minval(int);
		int jmi = maxval(int);
		forc(p, rel) {
			imax(ima, p.first);
			imin(imi, p.first);
			imax(jma, p.second);
			imin(jmi, p.second);
		}

		set<pair<int, int>> ni;
		for (int i = imi; i <= ima; ++i) {
		for (int j = jmi; j <= jma; ++j) {
			int idx = 0;
			for (int di = -1; di <= 1; ++di)
			for (int dj = -1; dj <= 1; ++dj) {
				int ii = i + di;
				int jj = j + dj;
				int add = 0;
				if (has(im, mp(ii, jj))) {
					add = 1;
				}
				if (_ % 2 == 1 && (ii < pimi || ii > pima || jj < pjmi || jj > pjma)
						&& s[0] == '#') {
					add = 1;
				}
				idx = 2 * idx + add;
			}
			//cout << dbgs3(i, j, idx) << endl;
			if (s[idx] == '#') ni.insert(mp(i, j));
		}
		}
		pima = ima;
		pimi = imi;
		pjma = jma;
		pjmi = jmi;
		im = ni;
	}

	cout << sz(im) << endl;
}
