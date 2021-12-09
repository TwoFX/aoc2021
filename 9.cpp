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

vector<vector<int>> f;
vector<vector<int>> comp;
int n, m;

void dfs(int i, int j, int c) {
	if (f[i][j] == 9) {
		return;
	}
	if (comp[i][j] != 0) return;
	comp[i][j] = c;
	for (int di = -1; di <= 1; di++) {
		for (int dj = -1; dj <= 1; dj++) {
			if ((di == 0) == (dj == 0)) continue;
			int ii = i + di;
			int jj = j + dj;
			if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
			dfs(ii, jj, c);
		}
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
	comp = vector<vector<int>>(n, vector<int>(m));
	fora(i, n) fora(j, m) f[i][j] = F[i][j] - '0';


	int co = 1;
	fora(i, n) fora(j, m) {
		if (i >= 1 && f[i][j] >= f[i - 1][j]) continue;
		if (j >= 1 && f[i][j] >= f[i][j - 1]) continue;
		if (i < n - 1 && f[i][j] >= f[i + 1][j]) continue;
		if (j < m - 1 && f[i][j] >= f[i][j + 1]) continue;
		dfs(i, j, co);
		++co;
	}
	vector<ll> hist(co);
	fora(i, n) fora(j, m) ++hist[comp[i][j]];
	hist[0] = 0;
	sort(all(hist));
	cout << hist[co - 1] * hist[co - 2] * hist[co - 3] << endl;
}
