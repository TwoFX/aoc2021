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

	int n;
	cin >> n;
	vector<int> a(n);
	fora(i, n) cin >> a[i];

	int bestt = 0;
	ll bests = 0;
	vector<vector<ll>> board(5, vector<ll>(5));
	while (cin >> board[0][0]) {
		fora(i, 5) fora(j, 5) {
			if (i != 0 || j != 0) cin >> board[i][j];
		}

		fora(i, n) {
			int cur = a[i];
			fora(i, 5) fora(j, 5) {
				if (board[i][j] == cur) board[i][j] = 0;
			}

			bool done = false;
			fora(i, 5) {
				bool ok = true;
				fora(j, 5) ok &= board[i][j] == 0;
				done |= ok;
			}
			fora(i, 5) {
				bool ok = true;
				fora(j, 5) ok &= board[j][i] == 0;
				done |= ok;
			}

			if (done) {
				ll sum = 0;
				fora(i, 5) fora(j, 5) sum += board[i][j];
				if (i > bestt) {
					bests = sum * cur;
					bestt = i;
				}
				break;
			}
		}
	}
	cout << bests << endl;
}
