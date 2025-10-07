#include <stdio.h>
//for unicode
#include <locale.h>
char board[6][7];
int roundNumber = 0;
//prints state of the board
void printMenu(){
    char cont;
    printf("Welcome to the Connect Four Experience!\n");
    printf("Enter S to Start.\n");
}
void printBoard(){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            //Check for X
            if(board[i][j]=='X'){
                printf("%c ",'X');
            }
            //Check for O
            else if(board[i][j]=='O'){
                printf("%c ",'O');
            }
            //if there's nothing
            else {
                printf("%c ",'-');
            }
        }
        //generate new line
        printf("\n");
    }
}

int checkIfWin(int row, int column, int Player){
    return 0;
}

int main(void){
    //initialize board
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            board[i][j] = '-';
        }
    }
    printBoard();
    return 0;
}
