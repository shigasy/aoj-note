// ! キュー
// queue, enqueueともにO(1)
// FIFO
// (head + 1) % LEN でリングバッファになり，インデックスが循環する

// キューが空のときと，満杯のときを区別するために，tailとheadの間には常に1つ以上空きを作る
// const isEmpty = () => tail == head
// const isFull = () => ((tail + 1) % LEN) == head
#include <stdio.h>
#define LEN 100005
typedef struct pp {
  char name[100];
  int t;
} P;
P Q[LEN];
int tail, head;
void enqueue(P u) {
  Q[head] = u;
  head = (head + 1) % LEN;
}

P dequeue() {
  P x = Q[tail];
  tail = (tail + 1) % LEN;
  return x;
}

int min(int a, int b) { return a < b ? a : b; }

int main() {
  int n, q, c;
  int time = 0;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%s", Q[i].name);
    scanf("%d", &Q[i].t);
  }
  tail = 1;
  head = n + 1;
  // whileの条件式が < だった場合，%
  // LENの計算でインデックスが1周してheadが小さくなったら抜けてしまうからwrong
  // answerになる
  while (tail != head) {
    P x = dequeue();
    c = min(x.t, q);  // x.t=50, q=100 c=50 x.t-c=0, x.t=100 q=50 c=50 x.t-c=50
                      // x.tが0より大きいかで判定
    x.t -= c;
    time += c;  // x.t <= q だった場合，cは処理が終えた時間, x.t > q
                // だった場合，cはq
    if (x.t > 0) {
      enqueue(x);
    } else {
      printf("%s %d\n", x.name, time);
    }
  }
  return 0;
}