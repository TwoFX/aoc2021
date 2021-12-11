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

int tfc = 0;
int fc = 0;
int n, m;
vector<vector<int>> f;
vector<vector<bool>> seen;

void dfs(int i, int j) {
	if (seen[i][j]) return;
	if (f[i][j] <= 9) return;
	seen[i][j] = true;
	++fc;
	for (int dx = -1; dx <= 1; ++dx)
	for (int dy = -1; dy <= 1; ++dy) {
		int ii = i + dx;
		int jj = j + dy;
		if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
		++f[ii][jj];
		dfs(ii, jj);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<string> F;
	string s;
	while (cin >> s) F.pb(s);
	n = sz(F);
	m = sz(F[0]);
	f = vector<vector<int>>(n, vector<int>(m));
	seen = vector<vector<bool>>(n, vector<bool>(m));
	fora(i, n) fora(j, m) f[i][j] = F[i][j] - '0';

	int steps = 100000000;
	fora(_, steps) {
		tfc = 0;
		fora(i, n) fora(j, m) ++f[i][j];
		fora(i, n) fora(j, m) seen[i][j] = false;
		fora(i, n) fora(j, m) dfs(i, j);
		fora(i, n) fora(j, m) if (f[i][j] > 9) { f[i][j] = 0; ++tfc; }
		if (tfc == n * m) {
			cout << _ + 1 << endl;
			return 0;
		}
	}
	cout << fc << endl;
}
