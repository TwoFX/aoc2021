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

int n;

constexpr ll inf = 100000000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<ll>> F;
	string s;
	while (cin >> s) {
		F.eb();
		forc(c, s) {
			ll r = c - '0';
			F.back().pb(r);
		}
	}

	int m = sz(F);
	n = 5 * sz(F);


	vector<vector<ll>> f(n, vector<ll>(n));
	fora(i, n) fora(j, n) {
		int ir = i % m;
		int jr = j % m;
		int d = i / m + j / m;
		int q = F[ir][jr] + d;
		while (q > 9) q -= 9;
		f[i][j] = q;
	}

	vector<vector<ll>> best(n, vector<ll>(n, inf));
	priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;

	best[0][0] = 0;
	pq.emplace(mp(0, mp(0, 0)));
	while (!pq.empty()) {
		auto t = pq.top();
		pq.pop();
		int i = t.second.first;
		int j = t.second.second;
		ll d = t.first;
		if (d < best[i][j]) continue;
		for (int di = -1; di <= 1; ++di) {
			for (int dj = -1; dj <= 1; ++dj) {
				if ((di == 0) == (dj == 0)) continue;
				int ii = i + di;
				int jj = j + dj;
				if (ii < 0 || ii >= n || jj < 0 || jj >= n) continue;
				ll pd = d + f[ii][jj];
				if (pd < best[ii][jj]) {
					best[ii][jj] = pd;
					pq.emplace(mp(pd, mp(ii, jj)));
				}
			}
		}
	}

	cout << best[n - 1][n - 1] << endl;
}
