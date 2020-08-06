// ! スタック

// C言語はシングルクォーテーションではchar（文字列リテラル）
// ダブルクォーテーションでは囲まれた文字列が格納されたアドレスを表す

// pop と push ともにO(1)
// 実際には空か判定してから，空だったらエラー判定する．その後，popする
// isEmpty = () => top == 0
// pushも同様に，満タンか判定して，満タンだったらエラー判定する．その後pushする
// isFull() = () => top >= MAX - 1

// ==========
// 入力例
// ==========
// 1 2 + 3 4 - *

// ==========
// 出力例
// ==========
// -3
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int top = 0;
int S[1000];

void push(int x) { S[++top] = x; }

int pop() { return S[top--]; }

int main() {
  char s[100];
  int a, b;

  while (scanf("%s", s) != EOF) {
    if (s[0] == '+') {
      a = pop();
      b = pop();
      push(a + b);
    } else if (s[0] == '-') {
      b = pop();  // b, a が反対なのは 20 - 5 が 5 - 20 =
                  // -15のように反転してしまうから
      a = pop();
      push(a - b);
    } else if (s[0] == '*') {
      a = pop();
      b = pop();
      push(a * b);
    } else {
      push(atoi(s));
    }
  }
  printf("%d\n", pop());

  return 0;
}