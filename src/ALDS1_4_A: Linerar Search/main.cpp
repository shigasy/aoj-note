// 線形探索（何も見ずに）
// 線形探索の計算量は、今回O(qn) = O(n)
#include <iostream>

using namespace std;

int main() {
  int n, q;
  int S[10000], T[500];
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }
  cin >> q;

  for (int j = 0; j < q; j++) {
    cin >> T[j];
  }

  int includeCount = 0;

  for (int i = 0; i < q; i++) {
    // 番兵を使わないやり方だと、for文とif文の比較演算子が2つになる
    // Aの終わりにkeyの値を入れる番兵を使うと、
    // while(A[i] != key)で、
    // 比較演算子が1つですみ、whileループが必ず終了することが保証されているため、終了条件を省くことが出来る
    // breakありの方が、O(qn)の計算量が最短でqになるのでは？探索の最初の方にkeyがあると、breakでその後の探索を終えるから
    for (int j = 0; j < n; j++) {
      if (T[i] == S[j]) {
        includeCount++;
        break;
      }
    }
  }

  cout << includeCount << endl;

  return 0;
}