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
#define CASE break; case
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
10 10
1 3
3 5
5 7
7 9
2 4
4 6
6 8
3 5
5 7
4 6
)");
// #define cin debug_iss

template <class Head> void IN(Head&& head) {cin >> head;}
template <class Head, class... Tail> void IN(Head&& head, Tail&&... tail) {cin >> head;IN(forward<Tail>(tail)...);}

// 最大値に関するセグメント木
template <class T>
class SegmentTree {
private:
	T init_val; // 初期値
	int num_leaves; // 2のべき
	vector<T> data, lazy;
	VB upd;

	T op(T a, T b){
		return max(a, b); // ここを書き換えれば最小値, 合計値に対する木も作れる
	}
	void __update(int a, int b, T val, int i, int l, int r) {
		eval(i);
		if (a <= l && r <= b) { // 範囲内のとき
			lazy[i] = val;
			upd[i] = true;
			eval(i);
		} else if (a < r && l < b) {
			__update(a, b, val, i * 2 + 1, l, (l + r) / 2);
			__update(a, b, val, i * 2 + 2, (l + r) / 2, r);
			data[i] = op(data[i * 2 + 1], data[i * 2 + 2]);
		}
	}
	T __query(int a, int b, int i, int l, int r) {
		eval(i);
		if (r <= a || b <= l) // 範囲外のとき
			return init_val;
		if (a <= l && r <= b)// 範囲内のとき
			return data[i];
		T vl = __query(a, b, i * 2 + 1, l, (l + r) / 2);
		T vr = __query(a, b, i * 2 + 2, (l + r) / 2, r);
		return op(vl, vr);
	}
	void eval(int i) {
		if (!upd[i]) return; // 更新が無ければスルー
		if (i < num_leaves - 1) { // 葉でなければ子に伝搬
			lazy[i * 2 + 1] = lazy[i];
			lazy[i * 2 + 2] = lazy[i];
			upd[i * 2 + 1] = true;
			upd[i * 2 + 2] = true;
		}
		// 自身を更新
		data[i] = lazy[i];
		lazy[i] = init_val;
		upd[i] = false;
	}
public:
	SegmentTree(int n, T init) {// [0,n)の範囲を持つセグメント木
		int x = 1;
		while(n > x)
			x *= 2;
		num_leaves = x;
		init_val = init;
		data.resize(num_leaves*2-1, init_val);
		lazy.resize(num_leaves*2-1, init_val);
		upd.resize(num_leaves*2-1, false);
	}
	void update(int a, int b, T val) {// [a,b)区間の値をvalに更新
		__update(a, b, val, 0, 0, num_leaves);
	}
	void update(int i, T val) {// 値を更新
		__update(i, i+1, val, 0, 0, num_leaves);
	}
	T query(int a, int b) {// [a,b)の最大値を取得
		return __query(a, b, 0, 0, num_leaves);
	}
	T query(int i) {// iの最大値を取得
		return __query(i, i+1, 0, 0, num_leaves);
	}
	// 表示用
	friend ostream& operator<<(ostream& os, SegmentTree& st){
		st.query(0, st.num_leaves);
		int br=1;
		for (int i = 0; i < 2*st.num_leaves-1; ++i) {
			os << st.data[i] << ", ";
			if (br==i+1){
				os << endl;
				br = 2*br+1;
			}
		}
		return os;
	}
};

// int -> str: to_string(i)
// str -> int: stoi(s)
// vec -> set: set<int> s(ALL(v));
int main() {
	int w,n;
	IN(w,n);

	SegmentTree<int> st(w+2, 0);
	REP(_, n){
		int l,r;
		IN(l,r);
		int val=st.query(l,r+1);
		st.update(l,r+1,val+1);
		OUT(val+1);
	}
	return 0;
}
