// ハッシュ
// データのキーから配列の添字を決定する関数から構成される
// 動的な挿入、検索、削除を効率的に行うことができる（連結リストだと検索、削除にはO(n)かかる）

// ハッシュ関数はハッシュ値が0からm-1の値を取るように実装する
// （ex. h(k) = k mod m）
// このままでは衝突が起きるか旺盛があるため、解決する方法の1ととして、オープンアドレス法が知られている
// h1(k)で求めて衝突が起きた場合にh2(k)だけ移動し、空いている位置を探していくアルゴリズム
int main() { return 0; }