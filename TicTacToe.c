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

char Win() {
    for (int i = 0; i < 3; i++) {
        if (matrix[i][0] == player && matrix[i][1] == player && matrix[i][2] == player) return player;
        if (matrix[0][i] == player && matrix[1][i] == player && matrix[2][i] == player) return player;
    }
    if (matrix[0][0] == player && matrix[1][1] == player && matrix[2][2] == player) return player;
    if (matrix[0][2] == player && matrix[1][1] == player && matrix[2][0] == player) return player;

    return '/';
}

int main(){
    n = 0;
    Draw();
    while (1) {
        n++;
        Input();
        Draw();
        if (Win() == 'X') {
            printf("X wins!!!\n");
            break;
        } else if (Win() == 'O') {
            printf("O wins!!!\n");
            break;
        } else if (n == 9) {
            printf("Draw :(\n");
            break;
        }
        TogglePlayer();
    }
    system("pause");
    return 0;
}