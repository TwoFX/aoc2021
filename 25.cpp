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

	vector<string> F;
	string s;
	while (cin >> s) F.pb(s);
	vector<vector<char>> f(sz(F), vector<char>(sz(F[0]), '.'));
	int n = sz(F);
	int m = sz(F[0]);
	fora(i, n) fora(j, m) f[i][j] = F[i][j];

	int k = 0;
	while (true) {
		auto oldf = f;
		vector<vector<char>> g(n, vector<char>(m, '.'));

		fora(i, n) fora(j, m) {
			if (f[i][j] != '>') continue;
			if (f[i][(j + 1) % m] == '.') {
				g[i][(j + 1) % m] = '>';
			} else g[i][j] = '>';
		}
		fora(i, n) fora(j, m) {
			if (f[i][j] == 'v') g[i][j] = 'v';
		}

		f = g;

		g = vector<vector<char>>(n, vector<char>(m, '.'));
		fora(i, n) fora(j, m) {
			if (f[i][j] == '>') g[i][j] = '>';
		}
		fora(i, n) fora(j, m) {
			if (f[i][j] != 'v') continue;
			if (f[(i + 1) % n][j] == '.') {
				g[(i + 1) % n][j] = 'v';
			} else g[i][j] = 'v';
		}

		f = g;
		++k;
		if (oldf == f) {
			break;
		}
	}
	cout << k << endl;
}
