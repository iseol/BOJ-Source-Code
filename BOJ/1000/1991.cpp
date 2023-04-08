#include <iostream>
using namespace std;

int lc[27], rc[27];
void preorder(int cur) {
    cout << static_cast<char>(cur+'A'-1);
    if (lc[cur] != 0) preorder(lc[cur]);
    if (rc[cur] != 0) preorder(rc[cur]);
}
void inorder(int cur) {
    if (lc[cur] != 0) inorder(lc[cur]);
    cout << static_cast<char>(cur+'A'-1);
    if (rc[cur] != 0) inorder(rc[cur]);
}
void postorder(int cur) {
    if (lc[cur] != 0) postorder(lc[cur]);
    if (rc[cur] != 0) postorder(rc[cur]);
    cout << static_cast<char>(cur+'A'-1);
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char temp, l, r;
        cin >> temp >> l >> r;
        if (l != '.') lc[temp-'A'+1] = l-'A'+1;
        if (r != '.') rc[temp-'A'+1] = r-'A'+1;
    }
    preorder(1);
    cout << '\n';
    inorder(1);
    cout << '\n';
    postorder(1);
}