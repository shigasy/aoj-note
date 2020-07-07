// 挿入ソート
// 先頭からソート済みを増やしていく
// 適切な場所に挿入する
// 大きい場合のみ移動するため、安定なソートアルゴリズム

// ソートが最悪 N - 1 + ... + 2 + 1 と行われる。（降順の場合）
// そのため、N - 1 + ... + 2 + 1 = (N^2 - N) / 2 となり O(n^2)
// 1からnまでの和

// O(n^2)
// 昇順でソートされている場合、最短はn回の比較で済む。
// そのため、ある程度ソートされていれば、計算量が少ない・高速に動作する特徴を持つのが挿入ソート

#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int R[n];
  for (int i = 0; i < n; i++)
    cin >> R[i];

  for (int k = 0; k < n; k++)
  {
    cout << R[k];
    if (k == n - 1)
    {
      cout << endl;
    }
    else
    {
      cout << " ";
    }
  }

  int target, j;
  for (int i = 1; i <= n - 1; i++)
  {
    target = R[i];
    j = i - 1;
    // 0個目より1個目の方が大きければ
    // 1個目より2個目の方が大きければ
    while (j >= 0 && R[j] > target)
    {
      // 1個目に0個目を代入
      // 2個目に1個目を代入
      // 大きい方からtargetを比較していって、ずらしていく。
      // 最終的に場所が分かれば、そこにtargetを代入
      R[j + 1] = R[j];
      j--;
    }
    R[j + 1] = target;
    for (int k = 0; k < n; k++)
    {
      cout << R[k];
      if (k == n - 1)
      {
        cout << endl;
      }
      else
      {
        cout << " ";
      }
    }
  }

  return 0;
}