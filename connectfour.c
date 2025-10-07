#include <stdio.h>
//for unicode
#include <locale.h>
char board[6][7];
int roundNumber = 0;
int lastPlayer;
void printboard(){
    // print the board and the sides
    for (int i = 0; i < 6; i++) {
        printf("  "); // leave blanks for the column numbers to line up
        for (int j = 0; j < 7; j++) {
            printf("│");
            if (board[i][j] == '-') {
                printf("   "); // leave blank
            } else {
                printf(" %c ", board[i][j]); // print X or O
            }
        }
        printf("│\n");
    }
    // print a horizontal line to rule out the column numbers
    printf("  ");
    for (int j = 0; j < 10; j++) {
        printf("───");
    }
    printf("\n");


    // print the column numbers
    printf("   ");
    for (int j = 0; j < 7; j++) {
        printf(" %d  ", j + 1);
    }
    printf("\n");
}

//prints state of the board
void printMenu(){
    char cont;
    printf("Welcome to the Connect Four Experience!\n");
    printf("Enter S to Start.\n");
}
int addPiece(int player, int column){
    if(board[0][column] != '-'){
        return 0;
    }
    for(int i = 5; i>=0; i--){
        if(board[i][column] == '-'){
            if(player){
                board[i][column] = 'O';
            }else{
                board[i][column] = 'X';
            }
            break;
        }
    }
    return 1;
}

/*void printboard(){
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
}*/

int checkIfWin(int column){
    int row = 0;
    while (board[row][column] == '-'){
        row++;
    }
    char playerPiece = board[row][column];
    int connected = 1;
    //check horizontal
    int c = column;
    c++;
    while (c < 7){
        if (board[row][c] == playerPiece){
            connected++;
        }else{
            break;
        }
        c++;
    }
    c = column - 1;
    while (c >= 0){
        if (board[row][c] == playerPiece){
            connected++;
        }else{
            break;
        }
        c--;
    }
    if(connected > 3){
        printf("Win\n");
        return 1;
    }
    //check vertical
    connected = 1;
    int r = row; 
    r++;
    while(r < 6){
        if(board[r][column] == playerPiece){
            connected++;
        }else{
            break;
        }
        r++;
    }
    r = row - 1;
    while (r >= 0){
        if(board[r][column] == playerPiece){
            connected ++;
        }else{
            break;
        }
        r--;
    }
    if(connected > 3){
        printf("Win\n");
        return 1;
    }
    //check top left to bottom right diagonal (\)
    connected = 1;
    r = row + 1;
    c = column + 1;
    while ((r < 6) && (c < 7)){
        if(board[r][c] == playerPiece){
            connected++;
        }else{
            break;
        }
        r++;
        c++;
    }
    r = row - 1;
    c = column - 1;
    while ((r >= 0) && (c >= 0)){
        if(board[r][c] == playerPiece){
            connected++;
        }else{
            break;
        }
        r--;
        c--;
    }
    if(connected > 3){
        printf("Win\n");
        return 1;
    }
    //check top right to bottom left diagonal (/)
    connected = 1;
    r = row - 1;
    c = column + 1;
    while ((r >= 0) && (c < 7)){
        if(board[r][c] == playerPiece){
            connected++;
        }else{
            break;
        }
        r--;
        c++;
    }
    r = row + 1;
    c = column - 1;
    while ((r < 6) && (c >= 0)){
        if(board[r][c] == playerPiece){
            connected++;
        }else{
            break;
        }
        r++;
        c--;
    }
    if(connected > 3){
        printf("Win\n");
        return 1;
    }
    printf("No winner yet\n");
    return 0;
}

int main(void){
    //initialize board
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            board[i][j] = '-';
        }
    }
    /*board[5][1] = 'O';
    board[4][2] = 'O';
    board[3][3] = 'O';
    board[2][4] = 'O';
    printboard();
    checkIfWin(3,3);*/
    printboard();
}
