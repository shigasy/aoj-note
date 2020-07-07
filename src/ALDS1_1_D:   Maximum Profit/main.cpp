#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 200000;

int main()
{
  int R[MAX], n;

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> R[i];
  int maxv = -1000000000; // 最大利益
  int minv = R[0];        // 最小値
  for (int i = 1; i < n; i++)
  {
    maxv = max(maxv, R[i] - minv);
    minv = min(minv, R[i]);
  }
  cout << maxv << endl;
  return 0;
}