#include <stdio.h>

int main() {
    int scores[2][4] = {
        {65, 92, 35, 70},
        {84, 72, 59, 67}
    };

    printf("Elements of the 2D array are:\n");

    for (int i = 0; i < 2; i++) {           // loop through rows
        for (int j = 0; j < 4; j++) {       // loop through columns
            printf("%d\t", scores[i][j]);
        }
        printf("\n");                       // new line after each row
    }

    return 0;
}

