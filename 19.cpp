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

	vector<vector<vector<ll>>> p;

	ll x;
	while (cin >> x) {
		if (x == 100000) {
			p.eb();
			continue;
		}
		ll y, z;
		cin >> y >> z;
		p.back().pb({ x, y, z });
	}

	int n = sz(p);

	vector<bool> know(n);
	vector<vector<vector<ll>>> fi(n);
	vector<vector<ll>> pos(n);

	fi[0] = p[0];
	pos[0] = { 0, 0, 0 };
	sort(all(fi[0]));
	know[0] = true;

	fora(_, n) {
		fora(i, n) {
			if (!know[i]) continue;
			fora(j, n) {
				if (know[j]) continue;

				fora(nfx, 2) fora(nfy, 2) fora(nfz, 2) {
					if (know[j]) break;
					bool fx = nfx == 1;
					bool fy = nfy == 1;
					bool fz = nfz == 1;;
					if (fx) fora(k, sz(p[j])) p[j][k][0] *= -1;
					if (fy) fora(k, sz(p[j])) p[j][k][1] *= -1;
					if (fz) fora(k, sz(p[j])) p[j][k][2] *= -1;

					vector<ll> ind = { 0, 1, 2 };
					do {
						fora(from, sz(fi[i])) fora(to, sz(p[j])) {
							if (know[j]) break;
							vector<vector<ll>> cand;
							forc(v, p[j]) {
								cand.pb({ v[ind[0]] - p[j][to][ind[0]] + fi[i][from][0],
										v[ind[1]] - p[j][to][ind[1]] + fi[i][from][1],
										v[ind[2]] - p[j][to][ind[2]] + fi[i][from][2] });
							}
							sort(all(cand));
							vector<vector<ll>> inter;
							set_intersection(all(fi[i]), all(cand), back_inserter(inter));
							if (sz(inter) >= 12) {
								pos[j] = {
									- p[j][to][ind[0]] + fi[i][from][0],
									- p[j][to][ind[1]] + fi[i][from][1],
									- p[j][to][ind[2]] + fi[i][from][2]
								};
								fi[j] = cand;
								know[j] = true;
								break;
							}
						}
					} while (next_permutation(all(ind)));

					if (fx) fora(k, sz(p[j])) p[j][k][0] *= -1;
					if (fy) fora(k, sz(p[j])) p[j][k][1] *= -1;
					if (fz) fora(k, sz(p[j])) p[j][k][2] *= -1;
				}

			}
		}
	}

	bool allok = true;
	fora(i, n) allok &= know[i];
	if (!allok) {
		cout << "KO!" << endl;
	}

	ll best = 0;
	fora(i, n) fora(j, n) {
		ll cand = 0;
		fora(k, 3) cand += abs(pos[i][k] - pos[j][k]);
		imax(best, cand);
	}

	set<vector<ll>> al;
	fora(i, n) al.insert(all(fi[i]));
	cout << best << endl;

}
