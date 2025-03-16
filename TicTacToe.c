#include <stdio.h>
#include <stdlib.h>

char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player = 'X';
int n;

void Draw() {
    system("cls"); // No Linux, use: printf("\033[H\033[J");
    printf("!!!!El Roego De la Abuelita!!!!\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("      %c ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){

    return 0;
}