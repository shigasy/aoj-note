// 連結リスト
// 双方向連結リストはいくつかのポインタをつなぎ替えるだけだから、O(1)で済む ->
// 要素を追加するところがわかっていれば、O(1)で間に削除・挿入できるね

// 配列ではA[i]のように定数時間で指定した要素にアクセスできる。
// リストでは要素を特定するためにポインタをたどる必要がある。そのため、N個の要素を含むリストに対する検索はO(N)のアルゴリズムになる
// 双方向連結リストの戦闘・末尾の要素の削除はO(1)で行うことが出来るが、特定のKeyを持つノードの削除はリストの要素を順番にたどる必要があるため、O(N)の計算量
// 探索と削除にO(N)の計算量が必要でリスト単体ではあまり実用性がないが、データ構造の部品として活かすことが出来る

#include <stdio.h>

#include <cstdlib>
#include <cstring>
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
// 新しいNodeは後ろにつないでいくイメージ 番兵 -> new -> old -> 番兵
// リストの先頭に追加していく
void insert(int key) {
  Node *x = (Node *)malloc(sizeof(Node));
  x->key = key;
  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

//探索が了して番兵が戻るか、該当するkeyを持つNodeが返る
Node *listSearch(int key) {
  Node *cur = nil->next;
  while (cur != nil && cur->key != key) {
    cur = cur->next;
  }
  return cur;
}

// Nodeの前とNodeの後を変えるだけで済む
void deleteNode(Node *t) {
  // tが番兵の場合は処理しない
  if (t == nil) {
    return;
  }
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}

// 最新のNode
// 先頭のNode
void deleteFirst() { deleteNode(nil->next); }
// 最初のNode
void deleteLast() { deleteNode(nil->prev); }

void deleteKey(int key) { deleteNode(listSearch(key)); }

void printList() {
  Node *cur = nil->next;
  int isFirst = 0;
  while (1) {
    if (cur == nil) {
      break;
    }
    if (isFirst++ > 0) {
      printf(" ");
    }
    printf("%d", cur->key);
    cur = cur->next;
  }
  printf("\n");
  return;
}

int main() {
  int n, key;
  char command[20];
  scanf("%d", &n);
  init();
  for (int i = 0; i < n; i++) {
    scanf("%s %d", command, &key);
    if (command[0] == 'i') {
      insert(key);
    } else if (command[0] == 'd') {
      if (strlen(command) > 6) {
        if (command[6] == 'F') {
          deleteFirst();
        } else if (command[6] == 'L') {
          deleteLast();
        }
      } else {
        deleteKey(key);
      }
    }
  }

  printList();
  return 0;
}