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

map<char, string> conv;

ll parse(const string &s, ll from, ll to) {
	ll ans = 0;
	for (ll i = from; i < to; ++i) {
		ans = 2 * ans + (s[i] - '0');
	}
	return ans;
}

pair<ll, ll> parseSinglePacket(const string &s, ll from) {
	ll version = parse(s, from, from + 3);
	ll type = parse(s, from + 3, from + 6);

	ll cur = from + 6;
	if (type == 4) {
		ll payload = 0;
		while (true) {
			payload = 16 * payload + parse(s, cur + 1, cur + 5);
			if (s[cur] == '0') break;
			cur += 5;
		}
		cur += 5;
		return mp(cur, payload);
	} else {
		ll otype = parse(s, cur, cur + 1);
		++cur;
		vector<ll> values;
		if (otype == 0) {
			ll length = parse(s, cur, cur + 15);
			cur += 15;
			ll to = cur + length;
			while (cur < to) {
				auto x = parseSinglePacket(s, cur);
				cur = x.first;
				values.pb(x.second);
			}
		} else if (otype == 1) {
			ll cnt = parse(s, cur, cur + 11);
			cur += 11;
			fora(_, cnt) {
				auto x = parseSinglePacket(s, cur);
				cur = x.first;
				values.pb(x.second);
			}
		}

		ll ans;
		if (type == 0) {
			ans = 0;
			forc(v, values) ans += v;
		} else if (type == 1) {
			ans = 1;
			forc(v, values) ans *= v;
		} else if (type == 2) {
			ans = maxval(ll);
			forc(v, values) imin(ans, v);
		} else if (type == 3) {
			ans = minval(ll);
			forc(v, values) imax(ans, v);
		} else if (type == 5) {
			ans = values[0] > values[1] ? 1 : 0;
		} else if (type == 6) {
			ans = values[0] < values[1] ? 1 : 0;
		} else if (type == 7) {
			ans = values[0] == values[1] ? 1 : 0;
		}

		return mp(cur, ans);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	conv['0'] = "0000";
	conv['1'] = "0001";
	conv['2'] = "0010";
	conv['3'] = "0011";
	conv['4'] = "0100";
	conv['5'] = "0101";
	conv['6'] = "0110";
	conv['7'] = "0111";
	conv['8'] = "1000";
	conv['9'] = "1001";
	conv['A'] = "1010";
	conv['B'] = "1011";
	conv['C'] = "1100";
	conv['D'] = "1101";
	conv['E'] = "1110";
	conv['F'] = "1111";

	string S;
	cin >> S;

	string s;
	forc(c, S) s += conv[c];

	auto x = parseSinglePacket(s, 0);
	cout << x.second << endl;

}
