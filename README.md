# atcoder-typical90
[atcoder典型90問](https://atcoder.jp/contests/typical90/tasks)を日々解いていく

その過程で, 必要があれば[テンプレート](https://github.com/birdwatcherYT/atcoder-template)を更新していく

## 問題の解法メモ
まずは★5以下のものを順番に解いていきます. 
その後, ★6, ★7にチャレンジします. 

### 001: スコアを最大にする最適な切れ目を選択
答えでないかどうかの判定が高速にできる場合は, 答えで二分探索する

### 002: 括弧のあり得る場合を生成
小さい規模のものは全探索する

### 003: グラフが木である場合の最長距離
最短距離計算を2回行う
- ある頂点から他の頂点への最短距離を求める
- 最も距離が長かった頂点を基準に, 他の頂点への最短距離を求める

### 004: 行列の各セルの縦横の和
何度も同じデータを参照する場合は, 事前計算しておく
- 事前計算で縦の和, 横の和を計算しておく

### 006: 最小部分文字列
貪欲に1文字ずつ決定していく
- 何度も同じデータを参照しないように, 各アルファベットがそれ以降でどのポジションにあるのか事前計算しておく

### 007: 最も近い要素の検索
ソートして挿入位置を二分探索で検索する

### 008: 部分文字列の場合の数
漸化式を立ててDPで解く
- 事前に関係ない文字は除外しておく
- 入力された文字列を後ろから参照していく
- 漸化式 (文字に対応する数字をa:0, t:1, c:2, o:3, d:4, e:5, r:6として, 後ろからi番目の文字がkに対応するとき)
    - k=6のとき dp[k][i+1] = dp[k][i]+1
    - k<6のとき dp[k][i+1] = dp[k+1][i]+dp[k][i];

### 010: 区間の和
累積和の差で解く

### 012: 塗られたマスの連結判定
UnionFindで解く

### 013: 経由地点のある最短経路
スタート地点からのダイクストラとゴール地点からのダイクストラで解く

### 014: 最も近くなるような人と学校の一対一対応
それぞれソートして差をとる

### 016: 最小のコイン枚数
無駄を省いた全探索をする
- 制約「合計9999枚以下の硬貨でちょうどN円を支払うことができる」も見逃さないようにする

### 018: 俯角を求める
逆三角関数を使って角度を求める
- atan2(y, x)

### 020: log同士の数値の比較
桁数に注意してlong longで受け取り, logの中身を整数で比較する

### 021: 相互に行き来できる頂点のペア数
強連結成分分解を使って, 頂点をお互いに行き来できるグループに分ける

強連結成分分解のアルゴリズム:
1. DFSで頂点をたどり, 帰りに訪問したことにする (すべてたどれなければ訪問できなかった頂点からDFSを再開する)
2. 辺の向きをすべて反転させ, 1.の訪問と逆順にDFSを行う (それぞれのDFSでたどれた分が強連結成分となる)

### 022: 直方体を立方体に分割するのに必要なカット数
3辺の最大公約数を求める
- g = gcd(a, b, c) = gcd(gcd(a, b), c)
- 切る回数は (a/g - 1) + (b/g - 1) + (c/g - 1)

### 024: 2つの数列を一致させるための手数
ステップ数の偶奇性に注目する
- 2つの数列の差が与えられたステップ数Kより大きいなら一致不可能
- 差がK以下なら, +/-を交互に行うことで残りの手数を消費できる (偶数ならちょうど消費できる)

### 026: 隣り合わない頂点を取り出す
DFSで訪問順に交互に色を塗っていく

### 027: レコードが登録されているかの確認
集合を使うだけ

### 028: 複数の長方形の重なった面積
領域にすべての点をメモしておいて, 最後に累積和で重なっている数をセルに記録する (いもす法)
- 1001 x 1001の2次元配列aを用意
    - 与えられる点の範囲が0から1000であることに注目
- 与えられた長方形の点(lx,ly), (rx,ry)に対して次のように記録
    - `a[lx][ly]++`
    - `a[rx][ry]++`
    - `a[lx][ry]--`
    - `a[rx][ly]--`
    - 長方形領域ごとに毎回加算するとTLEになってしまうことに注意
- 行方向の累積和をaに記録後, 列方向に累積和をaに記録
    - これで各セルに重なっている長方形の数が記載される

### 029: 区間の最大値の更新と取得
遅延評価付きのセグメント木で解く

### 030: N以下の素因数の数
エラトステネスのふるいで解く

### 032: 最小となる組み合わせを探索
空間が小さいため, 全探索する
- 全パターンを試すときにnext_permutationを使っても良い

### 033: ライトをつける位置
コーナーケース(例外)に気をつける

### 034: K種類以下の連続する最大部分列
単調性を利用して1長さを減らしたり増やしたりする (尺取り法というらしい)

### 036: 最大マンハッタン距離
点を45度回転させると考えやすい

### 037: 重さの範囲があるナップサック問題
DPで解くが, 最大値を求めるときにセグメント木を使う

### 038: 大きい数の最小公倍数
lcm(a, b) = a * b / gcd(a, b)
オーバーフローに注意して, しきい値より大きいかの判定には除算を使う

### 039: 木のすべての頂点の組の最短距離の和
各辺を何回通る必要があるかを考える

1. 深さ優先探索で各部分木に頂点がいくつあるかを調べる
2. それぞれの辺は頂点を2つの集合に分けるため, 1で求めた頂点の数からその辺を通る回数を求める

### 042: 各桁の和がKになる9の倍数の数
「9の倍数 = 各桁の和が9の倍数」という性質を使う.
Kが9の倍数でなければゼロ, Kが9の倍数なら各桁の和がKとなる数をDPで求める

### 043: 迷路でゴールするまでの曲がる回数の最小値
dequeを使った01BFSで, コストが小さいところからたどっていく
- 位置だけでなく, たどってきた向きも記録しておく
- 迷路の周りを壁で囲んでおくと, はみ出るかどうかの処理が楽になる
- priority_queueを使ったダイクストラでもOKだが計算コストは少し増える

### 044: 配列のシフトを頻繁に行う問題
シフトした数を覚えておいて, 実際にはシフトしない

### 046: 3つの数列からそれぞれ1つずつ選んだ整数の和が46の倍数になる総数
mod 46で考えて, それぞれの数列で個数をカウントして, 全探索(46^3)する

### 048: 試験の時間配分最適化
1分かけて`部分点b`がとれて, さらに1分かけると`(満点a-部分点b)(<a/2)`がとれることを利用して, ソートして上位k個を選ぶ

### 050: 階段を登る総数
漸化式を立ててDPで解く

