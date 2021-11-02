#pragma GCC optimize("O3")
// #include <atcoder/all>
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
// #include <bits/stdc++.h>
#ifndef M_PI
	#define M_PI		3.14159265358979323846
#endif
#ifndef M_E
	#define M_E		2.7182818284590452354
#endif
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
template <class Head> void OUT(Head&& head) {cout << head << endl;}
template <class Head, class... Tail> void OUT(Head&& head, Tail&&... tail) {cout << head << " ";OUT(forward<Tail>(tail)...);}
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
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
template<class... T> ostream& operator<<(ostream& os, const tuple<T...>& t) {
	os << "("; apply([&os](auto&&... args) {((os << args << ", "), ...);}, t);
	os << ")"; return os;
}
// 入力系
template<class T1, class T2> istream& operator>>(istream& is, pair<T1, T2>& p) {
	is >> p.first >> p.second;
	return is;
}
template<class T> istream& operator>>(istream& is, vector<T>& vec) {
	for ( T& item : vec ) is >> item;
	return is;
}
template<class... T> istream& operator>>(istream& is, tuple<T...>& t) {
	apply([&is](auto&&... args) {((is >> args), ...);}, t);
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

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef set<int> SI;
typedef long long LL;

istringstream debug_iss(R"(
7
b a b a b b a
2 1
3 7
3 2
3 4
5 4
4 6
)");
// #define cin debug_iss

template <class Head> void IN(Head&& head) {cin >> head;}
template <class Head, class... Tail> void IN(Head&& head, Tail&&... tail) {cin >> head;IN(forward<Tail>(tail)...);}

const LL MOD  = 1000000007;

// dp[now][連結成分のラベル集合]=部分木で条件を満たすものが何通りか
// 集合の対応付け = {a}:0, {b}:1, {a,b}:2
//
// nowのラベルがaのとき {a} を生成するのは
// 辺(now, child)を削除する場合, 部分木が条件を満たすために dp[child][{a,b}]
// 辺(now, child)を削除しない場合, {a}だけにならないといけないため dp[child][{a}]
// すべての子でこれらのパターンがあるため, dp[now][{a}] = prod(dp[child][{a}] + dp[child][{a,b}])
//
// nowのラベルがaのとき {a,b} を生成するのは
// dp[now][{a,b}] = すべての場合 - dp[now][{a}]
// すべての場合 = prod(dp[child][{a}]+dp[child][{b}]+2*dp[child][{a,b}])
// ※ dp[child][{a,b}]は辺(now, child)を削除する場合も含むため係数2がつく
void dfs(const VVI &adj, const VI &label, int now, vector<bool> &seen, vector< vector<LL> > &dp){
	seen[now] = true;
	LL all=1;
	dp[now][label[now]]=1;
	for (auto to : adj[now]){
		if (!seen[to]){
			dfs(adj, label, to, seen, dp);
			dp[now][label[now]]*=(dp[to][label[now]]+dp[to][2])%MOD;
			dp[now][label[now]]%=MOD;
			all*=(dp[to][0]+dp[to][1]+2*dp[to][2])%MOD;
			all%=MOD;
		}
	}
	dp[now][2]=(all-dp[now][label[now]])%MOD+MOD;
	dp[now][2]%=MOD;
}

// int -> str: to_string(i)
// str -> int: stoi(s)
// vec -> set: set<int> s(ALL(v));
int main() {
	// in
	int n;
	IN(n);
	VI label(n);
	REP(i,n){
		char tmp; IN(tmp);
		label[i]=(tmp-'a');
	}
	VVI adj(n);
	REP(i,n-1){
		int a,b;
		IN(a,b);
		a--,b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<bool> seen(n, false);
	vector< vector<LL> > dp(n, vector<LL>(3,0));
	dfs(adj, label, 0, seen, dp);
	OUT(dp[0][2]);

	return 0;
}