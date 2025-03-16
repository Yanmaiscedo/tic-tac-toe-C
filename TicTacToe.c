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

void Input() {
    int a;
    printf("It's %c turn. Press the number of the field: ", player);
    scanf("%d", &a);

    int row = (a - 1) / 3;
    int col = (a - 1) % 3;

    if (matrix[row][col] == '1' + (a - 1)) {
        matrix[row][col] = player;
    } else {
        printf("Field is already in use, try again!\n");
        Input();
    }
}

void TogglePlayer() {
    player = (player == 'X') ? 'O' : 'X';
}

int main(){

    return 0;
}