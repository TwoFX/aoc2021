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

using state = array<uint8_t, 27>;

state fs(const string &s) {
	state ans;
	fora(i, 11) ans[i] = 0;
	fora(i, 16) {
		ans[i + 11] = (uint8_t)(s[i] - 'A' + 1);
	}
	return ans;
}

vector<vector<int>> adj(27);
vector<ll> mult = { 0, 1, 10, 100, 1000 };

void dfs(int cur, int dist, int from, int type, const state &st, int start,
		vector<pair<int, ll>> &outp) {
	if (cur != start && st[cur] != 0) return;

	bool startedInHallway = start < 11;
	bool canStopHere = true;
	if (startedInHallway && cur < 11) canStopHere = false;
	if (cur == 2 || cur == 4 || cur == 6 || cur == 8) canStopHere = false;
	if (canStopHere && cur >= 11) {
		bool anyOk = false;
		fora(i, 4) {
			if (anyOk && st[10 + (4 * i) + type] != type) {
				anyOk = false;
			}
			if (cur == 10 + (4 * i) + type) anyOk = true;
		}
		if (!anyOk) canStopHere = false;
	}
	if (canStopHere) {
		outp.eb(cur, mult[type] * dist);
	}

	forc(ne, adj[cur]) {
		if (ne == from) continue;
		dfs(ne, dist + 1, cur, type, st, start, outp);
	}
}

string ps(const state &s) {
	ostringstream ss;
	fora(i, 19) ss << (char)(s[i] + '0');
	return ss.str();
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	fora(i, 10) {
		adj[i].pb(i + 1);
		adj[i + 1].pb(i);
	}

	fora(u, 4) {
		vector<int> is = { 2 * (u + 1), 11 + u, 15 + u, 19 + u, 23 + u };
		fora(i, 4) {
			adj[is[i]].pb(is[i + 1]);
			adj[is[i + 1]].pb(is[i]);
		}
	}

	string s;
	cin >> s;

	state start = fs(s);
	state dest = fs("ABCDABCDABCDABCD");

	map<state, ll> dist;
	priority_queue<pair<ll, state>, vector<pair<ll, state>>, greater<pair<ll, state>>> pq;
	dist[start] = 0;
	pq.emplace(0ll, start);

	ll last = -1;

	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (p.first > last) {
			cout << p.first << endl;
			last = p.first;
		}
		state cur = p.second;
		if (cur == dest) break;
		if (p.first > dist[cur]) continue;

		fora(tomove, 27) {
			if (cur[tomove] == 0) continue;

			bool athome = false;
			int type = cur[tomove];
			fora(i, 4) {
				int c = 10 + (4 * i) + type;
				if (athome && cur[c] != type) athome = false;
				if (c == tomove) {
					athome = true;
				}
			}
			if (athome) continue;

			vector<pair<int, ll>> poss;
			dfs(tomove, 0, -1, cur[tomove], cur, tomove, poss);

			forc(po, poss) {
				state newstate = cur;
				newstate[po.first] = newstate[tomove];
				newstate[tomove] = 0;
				ll newdist = p.first + po.second;
				if (!(has(dist, newstate)) || newdist < dist[newstate]) {
					dist[newstate] = newdist;
					pq.emplace(newdist, newstate);
				}
			}
		}
	}

	cout << dist[dest] << endl;

}
