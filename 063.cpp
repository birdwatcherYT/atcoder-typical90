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
// io系
#define OUT(x) cout << (x) << endl;
#define IN(x) cin >> x;
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

using namespace std;

template<class T> vector<size_t> argsort(const vector<T> &vec, bool asc=true){
	vector<size_t> index(vec.size());
	iota(index.begin(), index.end(), 0);
	sort(index.begin(), index.end(), [&vec, &asc](size_t i, size_t j){return asc ? (vec[i] < vec[j]):(vec[i] > vec[j]);});
	return index;
}
// 表示系
template <class Head> void print(Head&& head) {
	cout << head << endl;
}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {
	cout << head << " ";
	print(forward<Tail>(tail)...);
}
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) {
	os << "[ ";
	for ( const T& item : vec ) os << item << ", ";
	os << "]";
	return os;
}
template<class T> ostream& operator<<(ostream& os, const set<T>& s) {
	os << "{ ";
	for ( const T& item : s ) os << item << ", ";
	os << "}";
	return os;
}
template<class T1, class T2> ostream& operator<<(ostream& os, const map<T1, T2>& m) {
	os << "{ ";
	for ( const auto &[key, value] : m ) os << key << ":"<< value << ", ";
	os << "}";
	return os;
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
// 集合演算
template<class T> set<T> operator&(const set<T>& a, const set<T>& b) {// 共通集合
	set<T> ans;
	set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::inserter(ans, ans.end()));
	return ans;
}
template<class T> set<T> operator|(const set<T>& a, const set<T>& b) {// 和集合
	set<T> ans;
	std::set_union(a.begin(), a.end(), b.begin(), b.end(), std::inserter(ans, ans.end()));
	return ans;
}
template<class T> set<T> operator-(const set<T>& a, const set<T>& b) {// 差集合
	set<T> ans;
	std::set_difference(a.begin(), a.end(), b.begin(), b.end(), std::inserter(ans, ans.end()));
	return ans;
}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef set<int> SI;
typedef long long LL;

istringstream debug_iss(R"(
4 6
1 1 1 1 1 2
1 2 2 2 2 2
1 2 2 3 2 3
1 2 3 2 2 3
)");
// #define cin debug_iss

int select_best_cols(const VVI &mat, int select_rows){
	vector<map<int, int>> cnt(mat[0].size());
	int selected_rows=0;
	REP(i, SZ(mat)){
		if((1<<i)&select_rows){
			selected_rows++;
			REP(j, SZ(mat[0]))
				cnt[j][mat[i][j]]++;
		}
	}
	map<int,int> ans;
	REP(j, SZ(mat[0])){
		if(cnt[j].size()==1)
			ans[cnt[j].begin()->first]++;
	}
	int ans_max=0;
	for(auto [k,v]:ans)
		ans_max=max(ans_max, v);
	return ans_max*selected_rows;
}

// int -> str: to_string(i)
// str -> int: stoi(s)
// vec -> set: set<int> s(ALL(v));
int main() {
	int h,w;
	IN(h)IN(w)
	VVI P(h, VI(w));
	IN(P)

	int ans=0;
	REP(select_rows, 1<<h)
		ans=max(ans, select_best_cols(P, select_rows));

	OUT(ans)
	return 0;
}
