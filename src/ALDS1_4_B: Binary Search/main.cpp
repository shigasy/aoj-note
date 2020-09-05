#include <iostream>

// 二分探索
// 二分探索は整列されているという制約を有効利用し、適用することができる
// 線形探索はO(n) 二分探索はlog2n回 -> O(logn)となる
// この問題はO(qlogn)
// 整列されていない状態でも、あらかじめ整列を行えば二分探索を適用できる。高等的なソートアルゴリズムと一緒に使うと良い

// left ---- mid ---- right

// もし midがkeyより大きかったら
// right = mid
// もし midがkeyより小さな買ったら
// left = mid + 1

// leftがmid + 1する理由は
// (left + right)/ 2をした時に切り捨てて、最終的にmidが動かなくなるから
// また、left < rightという終了条件であるため
bool search(int A[], int n, int key) {
  int mid;
  int left = 0;
  int right = n;
  while (left < right) {
    // leftがmid + 1する理由は
    // (left + right)/ 2をした時に切り捨てて、最終的にmidが動かなくなるから
    mid = (left + right) / 2;
    if (A[mid] == key) {
      return true;
    }
    if (A[mid] > key) {
      right = mid;
    } else if (A[mid] < key) {
      left = mid + 1;
    }
  }
  return false;
}

int main() {
  int i, n, A[100000], q, key, sum = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    // keyを配列として保存せずに捨てていくのは良い。
    scanf("%d", &key);
    if (search(A, n, key)) {
      sum++;
    }
  }
  printf("%d\n", sum);
  return 0;
}