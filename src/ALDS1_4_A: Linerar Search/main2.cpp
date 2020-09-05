// 答え見ながら書いた線形探索

#include <iostream>

// 線形探索
bool search(int A[], int n, int key) {
  int i = 0;
  A[n] = key;
  while (A[i] != key) {
    i++;
  }
  // i ==
  // nでnと同じ数探索した場合、A[n]にkeyを入れて、最後に該当するためwhileを抜け出して見つからなかったとして、falseを返す
  // iがnより小さい = nと違う場合、見つかったということになりtrueを返す
  return i != n;
}

int main() {
  // 10000 + 1としているのは後でA[n]にkeyを入れているから
  int i, n, A[10000 + 1], q, key, sum = 0;
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