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

	ll x1, x2, y1, y2;
	cin >> x1 >> x2 >> y1 >> y2;

	ll best = 0;
	ll ans = 0;

	for (int ix = 1; ix < 200; ++ix) {
		for (int iy = -120; iy <= 100000; ++iy) {
			ll dx = ix, dy = iy;
			ll x = 0, y = 0;
			ll my = 0;
			bool ok = false;
			while (x <= x2 && y >= y1 && (x >= x1 || dx > 0)) {
				x += dx;
				y += dy;
				imax(my, y);
				dx = max(0ll, dx - 1);
				dy -= 1;
				if (y > 6786) break;
				if (x1 <= x && x <= x2 && y1 <= y && y <= y2) ok = true;
			}
			if (ok) ++ans;
		}
	}
	cout << ans << endl;
}
