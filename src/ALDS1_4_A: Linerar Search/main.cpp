// 線形探索
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
    for (int j = 0; j < n; j++) {
      if (T[i] == S[j]) {
        includeCount++;
        break;
      }
      cout << j << endl;
    }
  }

  cout << includeCount << endl;

  return 0;
}