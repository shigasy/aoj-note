// nが小さいので
//（n <= 20）数列の要素を選ぶ組み合わせを列挙するアルゴリズムが適用できる
// O(2^n)になるため、選ぶ or
// 選ばないのn個の通りができる。そのため、nが多いものは動的計画法を使う。今回は全探索する。

#include <stdio.h>

#include <iostream>

using namespace std;

int A[20], n;

// i番目以降の要素を使ってmを作れる場合にtrueを返す
// solve(i, m)はより小さいより小さい部分問題であるsolve(i + 1, m)とsolve(i + 1,
// m - A[i])に分けられる これらを再帰的に調べる

// 選ぶ、選ばないの全探索
// 選ぶと引き、選ばないと引かないという選択をし、全ての通りを調べて、可能であればtrue,
// 不可能であればfalseを返す
bool solve(int i, int m) {
  // 引いた結果、0になるということは、足し合わせるとmiをを作ることが出来るということになるためtrue
  if (m == 0) {
    return true;
  }
  // 最後の要素まで探索して見つからなかった場合
  if (i >= n) {
    return false;
  }
  bool res = solve(i + 1, m) || solve(i + 1, m - A[i]);
  return res;
}

int main() {
  int q, m;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", &m);
    if (solve(0, m)) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }

  return 0;
}