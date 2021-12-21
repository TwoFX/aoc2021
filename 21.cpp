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

ll poss[11][11][35][35][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<ll> p(2);
	cin >> p[0] >> p[1];

	poss[p[0]][p[1]][0][0][0] = 1;
	fora(s0, 21) fora(s1, 21) fora(t, 2) fora(p0, 11) fora(p1, 11) {
		if (poss[p0][p1][s0][s1][t] == 0) {
			continue;
		}
		fora(D0, 3) fora(D1, 3) fora(D2, 3) {
			ll ns0 = s0, ns1 = s1, np0 = p0, np1 = p1, nt = (t + 1) % 2;
			ll d = D0 + D1 + D2 + 3;
			if (t == 0) {
				np0 += d;
				if (np0 > 10) np0 -= 10;
				ns0 += np0;
			} else {
				np1 += d;
				if (np1 > 10) np1 -= 10;
				ns1 += np1;
			}
			poss[np0][np1][ns0][ns1][nt] += poss[p0][p1][s0][s1][t];
		}
	}

	ll w0 = 0, w1 = 0, total = 0;
	fora(s0, 35) fora(s1, 35) fora(t, 2) fora(p0, 11) fora(p1, 11) {
		total += poss[p0][p1][s0][s1][t];
		if (s0 >= 21) w0 += poss[p0][p1][s0][s1][t];
		if (s1 >= 21) w1 += poss[p0][p1][s0][s1][t];
	}
	cout << max(w0, w1) << endl;



}
