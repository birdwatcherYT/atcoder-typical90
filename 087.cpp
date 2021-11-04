// #pragma GCC optimize("O3")
// #include <atcoder/all>
// #include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <numeric>
#include <cassert> // assert();
#include <iomanip> // cout << setprecision(15);
#define _PI     3.14159265358979323846
#define _E      2.7182818284590452354
#define INF     (INT_MAX / 2)
#define LINF    (LLONG_MAX / 2)
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n)  FOR(i, 0, n)
#define RREP(i, n)  for(int i = (n) - 1; i >= 0; --i)
#define EACH(e, v) for(auto &e : v)
#define ITR(it, v) for(auto it = (v).begin(); it != (v).end(); ++it)
#define RITR(it, v) for(auto it = (v).rbegin(); it != (v).rend(); ++it)
#define CASE(x) break; case x:
#define ALL(v)  (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SZ(v) int((v).size())
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define SUM(v, type) accumulate((v).begin(), (v).end(), (type) 0)
#define MIN(v) (*min_element((v).begin(), (v).end()))
#define MAX(v) (*max_element((v).begin(), (v).end()))
#define ARGMIN(v) (min_element((v).begin(), (v).end()) - (v).begin())
#define ARGMAX(v) (max_element((v).begin(), (v).end()) - (v).begin())
#define REVERSE(v) reverse((v).begin(), (v).end())
#define ARANGE(v) iota((v).begin(), (v).end(), 0)
#define FILTER(src, tgt, func) copy_if(begin(src), end(src), back_inserter(tgt), func); // func = [](type x){return 条件;}
#define CTOI(c) (c - '0')
#define HEADSTR(str, n) str.substr(0, (n))
#define TAILSTR(str, n) str.substr((str).length() - (n))
#define CONTAINS(str, c) ((str).find(c) != string::npos)
#define INSPOS(v, a) (lower_bound((v).begin(), (v).end(), a) - (v).begin())
// デバッグ用
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

using namespace std;

template<class T> vector<size_t> argsort(const vector<T> &vec, bool asc=true){
	vector<size_t> index(vec.size()); iota(index.begin(), index.end(), 0);
	sort(index.begin(), index.end(), [&vec, &asc](size_t i, size_t j){return asc ? (vec[i] < vec[j]):(vec[i] > vec[j]);});
	return index;
}
// 表示系
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}
template<class... T> ostream& operator<<(ostream& os, const tuple<T...>& t) {
	os << "("; apply([&os](auto&&... args) {((os << args << ", "), ...);}, t);
	os << ")"; return os;
}
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) {
	os << "[ "; for ( const T& item : vec ) os << item << ", ";
	os << "]"; return os;
}
template<class T> ostream& operator<<(ostream& os, const set<T>& s) {
	os << "{ "; for ( const T& item : s ) os << item << ", ";
	os << "}"; return os;
}
template<class T1, class T2> ostream& operator<<(ostream& os, const map<T1, T2>& m) {
	os << "{ "; for ( const auto &[key, value] : m ) os << key << ":"<< value << ", ";
	os << "}"; return os;
}
template <class Head> void OUT(Head&& head) {cout << head << endl;}
template <class Head, class... Tail> void OUT(Head&& head, Tail&&... tail) {cout << head << " ";OUT(forward<Tail>(tail)...);}
// 入力系
template<class T1, class T2> istream& operator>>(istream& is, pair<T1, T2>& p) {
	is >> p.first >> p.second;
	return is;
}
template<class... T> istream& operator>>(istream& is, tuple<T...>& t) {
	apply([&is](auto&&... args) {((is >> args), ...);}, t);
	return is;
}
template<class T> istream& operator>>(istream& is, vector<T>& vec) {
	for ( T& item : vec ) is >> item;
	return is;
}
// 集合演算
template<class T> set<T> operator&(const set<T>& a, const set<T>& b) {// 共通集合
	set<T> ans; set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(ans, ans.end()));
	return ans;
}
template<class T> set<T> operator|(const set<T>& a, const set<T>& b) {// 和集合
	set<T> ans; set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(ans, ans.end()));
	return ans;
}
template<class T> set<T> operator-(const set<T>& a, const set<T>& b) {// 差集合
	set<T> ans; set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(ans, ans.end()));
	return ans;
}

typedef long long LL; typedef unsigned long long ULL;
typedef vector<int> VI; typedef vector<VI> VVI;
typedef vector<LL> VL; typedef vector<VL> VVL;
typedef vector<bool> VB; typedef vector<VB> VVB;
typedef vector<char> VC; typedef vector<string> VS;
typedef pair<int, int> PII; typedef pair<LL, LL> PLL;
typedef map<int, int> MII; typedef map<LL, LL> MLL;
typedef set<int> SI; typedef set<LL> SL;

istringstream debug_iss(R"(
3 4 2
0 3 -1
3 0 5
-1 5 0
)");
// #define cin debug_iss

template <class Head> void IN(Head&& head) {cin >> head;}
template <class Head, class... Tail> void IN(Head&& head, Tail&&... tail) {cin >> head;IN(forward<Tail>(tail)...);}

VL dijkstra(const VVL &A, LL x, int n, int s){
	VL dist(n, INF);
	priority_queue< pair<LL, int>, vector< pair<LL, int> >, greater< pair<LL, int> > > pq;
	pq.push({0, s}); // (コスト, ノード)
	dist[s] = 0;
	VB seen(n, false);
	while (!pq.empty()){
		int v = pq.top().second;
		pq.pop();
		seen[v] = true;
		REP(to, n){
			LL cost= A[v][to]<0 ? x : A[v][to];
			if (!seen[to] && dist[v] + cost < dist[to]){
				dist[to] = dist[v] + cost;
				pq.push({dist[to], to});
			}
		}
	}
	return dist;
}

// Floyd–Warshall: 全ペアの最短経路
template<class T>
vector< vector<T> > floyd_warshall(const vector< vector<T> > &cost, T x, int n) {// (移動コスト行列, 頂点数)
	vector< vector<T> > cost_min = cost;
	REP(i, n)REP(j, n)
		if(cost_min[i][j]<0) cost_min[i][j]=x;
	REP(i, n)
		cost_min[i][i]=0;
	REP(k, n)REP(i, n)REP(j, n)
		cost_min[i][j]=min(cost_min[i][j], cost_min[i][k]+cost_min[k][j]);
	return cost_min;
}

int get_pairs(const VVL &A, int n, LL p, LL x){
	int cnt=0;
	// REP(i, n){
	// 	auto dist=dijkstra(A, x, n, i);
	// 	FOR(j, i+1, n)
	// 		cnt+=(dist[j]<=p);
	// }
	auto dist=floyd_warshall(A, x, n);
	REP(i, n)FOR(j, i+1, n)
		cnt+=(dist[i][j]<=p);
	return cnt;
}

LL bsearch(const VVL &A, int n, LL p, int k, bool lower_bound=true){
	LL left=1, right=p;
	while(left<=right){
		LL mid=(left+right)/2;
		int cnt = get_pairs(A, n, p, mid); 
		if (cnt>k // 降順なので不等号逆
			|| (!lower_bound && cnt==k))
			left=mid+1;
		else
			right=mid-1;
	}
	return left;
}

// int -> str: to_string(i)
// str -> int: stoi(s)
// vec -> set: set<int> s(ALL(v));
int main() {
	// in
	int n,k;
	LL p;
	IN(n,p,k);
	VVL A(n, VL(n));
	IN(A);

	// コストP以下で到達可能な組がちょうどK個
	// 負をつながってないとみなした場合に解が存在 → 無限個
	// Xを決めたときに組数を数える関数
	// 二分探索で解を求める

	int cnt=get_pairs(A, n, p, INF);
	if (cnt==k){
		OUT("Infinity");
		return 0;
	}
	LL lower=bsearch(A, n, p, k);
	LL upper=bsearch(A, n, p, k, false);
	OUT(upper-lower);

	return 0;
}
