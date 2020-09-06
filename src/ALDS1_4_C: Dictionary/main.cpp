// ハッシュ
// データのキーから配列の添字を決定する関数から構成される
// 動的な挿入、検索、削除を効率的に行うことができる（連結リストだと検索、削除にはO(n)かかる）

// ハッシュ関数はハッシュ値が0からm-1の値を取るように実装する
// （ex. h(k) = k mod m）
// このままでは衝突が起きるか旺盛があるため、解決する方法の1ととして、オープンアドレス法が知られている
// h1(k)で求めて衝突が起きた場合にh2(k)だけ移動し、空いている位置を探していくアルゴリズム
#include <stdio.h>

#include <cstring>
#include <iostream>

using namespace std;

#define M 1046527
#define NIL (-1)

// 文字列の長さ
#define L 14

// ハッシュテーブルのサイズ
char H[M][L];

// 文字から数値に変換
int getChar(char ch) {
  switch (ch) {
    case 'A':
      return 1;
    case 'C':
      return 2;
    case 'G':
      return 3;
    case 'T':
      return 4;
    default:
      return 0;
  }
}

// 文字列から数値へ変換してkeyを生成する
long long getKey(char str[]) {
  long long sum = 0, p = 1, i;
  for (i = 0; i < strlen(str); i++) {
    sum += p * (getChar(str[i]));
    p *= 5;
  }
  return sum;
}

int h1(int key) { return key % M; }

int h2(int key) { return 1 + (key % (M - 1)); }

// 同じstrなら何もしない
// 空だったらH[h]にコピー
bool insert(char str[]) {
  long long key, i, h;
  key = getKey(str);
  for (i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str) == 0) {
      return 1;
    } else if (strlen(H[h]) == 0) {
      strcpy(H[h], str);
      return 0;
    }
  }
  return 0;
}

bool find(char str[]) {
  long long key, i, h;
  key = getKey(str);

  // 等しければtrue
  // 等しくなければiをインクリメントして再度
  // 空ならfalse
  for (i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str) == 0) {
      return true;
    } else if (strlen(H[h]) == 0) {
      return false;
    }
  }
  return false;
}

int main() {
  int i, n, h;
  char str[L], com[9];
  for (i = 0; i < M; i++) {
    // 終端文字埋め
    H[i][0] = '\0';
  }

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    // insert AAA
    scanf("%s %s", com, str);

    if (com[0] == 'i') {
      insert(str);
    } else {
      if (find(str)) {
        printf("yes\n");
      } else {
        printf("no\n");
      }
    }
  }
  return 0;
}