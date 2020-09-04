#include <iostream>

using namespace std;
struct Node {
  int key;
  // prev, nextはNode型の値のアドレスを持つことが出来るという宣言
  Node *prev, *next;
};

// nilはNode型のアドレスを持つことが出来る
Node *nil;

// データを動的に変化させる必要があるデータ構造なため、必要な時にメモリを確保・解放する必要がある。
// nextとprevを番兵に繋ぐことによって、空のリストを作る。番兵を作る理由は要素の削除・追加の実装が楽だから。空のリストは実データには含めない。
void init() {
  // 戻り値のポインタはvoid型で返ってくるので
  // (Node *) でNode型ポインタにキャストしている
  // mallocでヒープ領域にメモリを確保 malloc(size_t size)
  // sizeは確保するバイトを指定する 今回はNode型のバイト数のメモリ領域を動的確保
  nil = (Node *)malloc(sizeof(Node));
  // -> はポインタ変数からメンバにアクセスするための演算子でアロー演算子と呼ぶ
  nil->next = nil;
  nil->prev = nil;
}
//新しいNodeは後ろに後ろにつないでいくイメージ 番兵 -> new -> old -> 番兵
void insert(int key) {
  Node *x = (Node *)malloc(sizeof(Node));
  x->key = key;
  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

void deleteNode(Node *t) {}

void deleteFirst() {}
void deleteLast() {}

int main() {
  cout << "HelloWorld" << endl;
  return 0;
}