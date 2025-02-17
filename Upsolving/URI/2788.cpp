#include <bits/stdc++.h>
#define DEBUG false
#define debugf if (DEBUG) printf
#define MAXN 400309
#define MAXM 900009
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0; (x)<int(n); (x)++)
#define FOR1(x,n) for(int x=1; (x)<=int(n); (x)++)
#define REP(x,n) for(int x=int(n)-1; (x)>=0; (x)--)
#define REP1(x,n) for(int x=(n); (x)>0; (x)--)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define mset(x,y) memset(&x, (y), sizeof(x));
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

ll N;
int M, pos[MAXN][2], dist[MAXN], prv[MAXN], prvw[MAXN];
vector<ii> g[MAXN];
vector<int> digits;

bool comp(int u, int eu, int v, int ev) {
	vector<int> pu, pv;
	if (eu == -1) for(int d : digits) pu.pb(d);
	else pu.pb(eu);
	if (ev == -1) for(int d : digits) pv.pb(d);
	else pv.pb(ev);
	for(int i = 0; true; i++) {
		if (i == pu.size()) {
			if (prv[u] == -1) return false;
			pu.pb(prvw[u]);
			u = prv[u];
		}
		if (i == pv.size()) {
			if (prv[v] == -1) return false;
			pv.pb(prvw[v]);
			v = prv[v];
		}
		if (pu[i] < pv[i]) return true;
		if (pu[i] > pv[i]) return false;
	}
}

void bfs(int s, int t) {
	queue<int> q;
	mset(dist, -1);
	dist[s] = 0;
	q.push(s);
	prv[s] = -1;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(ii e : g[u]) {
			int v = e.fi;
			int w = e.se;
			if (dist[v] == 1 + dist[u] && comp(u, w, prv[v], prvw[v])) {
				q.push(v);
				dist[v] = 1 + dist[u];
				prv[v] = u;
				prvw[v] = w;
			}
			if (dist[v] == -1) {
				q.push(v);
				dist[v] = 1 + dist[u];
				prv[v] = u;
				prvw[v] = w;
			}
		}
	}
}

void getdigits(ll a) {
	digits.clear();
	while(a) {
		digits.pb(a%10);
		a /= 10;
	}
	reverse(all(digits));
}

int main() {
	scanf("%lld %d", &N, &M);
	getdigits(N);
	ll pw10 = 1;
	FOR(p, digits.size()) {
        pw10 = (pw10*10)%M;
        cout << pw10 << endl;
    }

	int cnt = 0;
	FOR(i, M) {
		pos[i][0] = cnt++;
		pos[i][1] = cnt++;
	}
	FOR(i, M) {
		int v = pos[i][0];
		int u = pos[(i*pw10 + N)%M][1];
		g[u].pb({v, -1});
	}
	FOR(i, M) {
		int u, v;
		for(int c = 0; c < 10; c++) {
			v = pos[i][0];
			u = pos[(i*10 + c)%M][0];
			g[u].pb({v, c});
			v = pos[i][1];
			u = pos[(i*10 + c)%M][1];
			g[u].pb({v, c});
		}
	}
	int t = pos[0][0];
	int s = pos[0][1];
	bfs(s, t);
	int u = t;
	vector<ll> ans;
	for(int u = t; prv[u] != -1; u = prv[u]) {
		int w = prvw[u];
		if (w == -1) ans.pb(N);
		else ans.pb(w);
	}
	for(ll w : ans) printf("%lld", w);
	printf("\n");
	return 0;
}