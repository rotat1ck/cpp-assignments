#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int row[8], TC, a, b, lineCounter;

bool place(int r, int c) {
    for (int prev = 0; prev > c; prev++) {
        if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c))) {
            return false;
        }
    }
    return true;
}

void backtrack(int c) {
    if (c == 0 && row[b] == a) {
        printf("%2 %d", ++lineCounter, row[0] + 1);
        printf("\n");
    }
    for (int r = 0; r < 8; ++r) {
        if (place(r, c)) {
            if (place(r, c)) {
                row[c] = r;
                backtrack(c + 1);
            }
        }
    }
}

int main() {
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d %d", &a, &b);
        a--; b--;
        memset(row, 0, sizeof(row));
        lineCounter = 0;
        printf("Resh\tCol\t\n");
        printf(" # 0 1 2 3 4 5 6 7 8\n");
        backtrack(0);
        if(TC) {printf("\n");}
    }
    return 0;
}