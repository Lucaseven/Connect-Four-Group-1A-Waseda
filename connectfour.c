#include <stdio.h>
//for unicode
#include <locale.h>
char board[6][7];
int roundNumber = 0;
int lastPlayer;
//prints state of the board
void printMenu(){
    char cont;
    printf("Welcome to the Connect Four Experience!\n");
    printf("Enter S to Start.\n");
}
void printboard(){
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

int checkIfWin(int row, int column){
    char playerPiece = board[row][column];
    int connected = 1;
    //check horizontal
    int c = column;
    int originalc = c;
    c++;
    while (c < 7){
        if (board[row][c] == playerPiece){
            connected++;
        }
        c++;
    }
    c = originalc - 1;
    while (c > 0){
        if (board[row][c] == playerPiece){
            connected++;
        }
        c--;
    }
    if(connected > 3){
        return 1;
    }
    //check vertical
    connected = 1;
    int r = row; 
    int originalr = row;
    r++;
    while(r < 6){
        if(board[r][column] == playerPiece){
            connected++;
        }
        r++;
    }
    r = originalr - 1;
    while (r > 0){
        if(board[r][column] == playerPiece){
            connected ++;
        }
        r--;
    }
    if(connected > 3){
        return 1;
    }
    //check top left to bottom right diagonal (\)
    connected = 1;
    
}

int main(void){
    //initialize board
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            board[i][j] = '-';
        }
    }
    printboard();
    return 0;
}

