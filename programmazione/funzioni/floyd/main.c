#include <stdio.h>

void floyd(int n) {
    int conta = 1;
    for (int i = 0; i < n; ++i) {
        int x = 0;
     for (int j = 0; j < i + 1; ++j) {
         printf("%3d", conta);
         conta++;
     }
        printf("\n");
    }
}

int main(void) {
    floyd(5);
    return 0;
}
