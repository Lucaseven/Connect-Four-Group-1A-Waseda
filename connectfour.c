#include <stdio.h>
//for unicode
#include <locale.h>
char board[6][7];
int gameActive = 1;
int roundNumber = 0;
int p1_score = 0;
int p2_score = 0;
int lastPlayer = 1;
int p1w, p2w, draw;
//prints state of the board
void printMenu(){
    //if no matches are played, then initialize
    if (p1w == 0 && p2w == 0 && draw == 0){
    printf("Welcome to the Connect Four Experience!\n");
    printf("Enter S to Start.\n");
    }
    else{
        //show score
        printf("Current Score is\n Player1 %dpt : Player2 %dpt\n",p1w,p2w);
        printf("Another Round?\n");
    }
}

void reset(){
    roundNumber = 1;
    p1_score = 0;
    p2_score = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            board[i][j] = '-';
        }
    }
}
int addPiece(int player, int column){
    column;
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

int checkIfWin(int column){
    int row = 0;
    while (board[row][column] == '-'){
        row++;
    }
    char playerPiece = board[row][column];
    printf("Playerpiece is %c \n",playerPiece);
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
        printf("Row is %d \n",row);
        printf("Column is %d \n",column);
        printf("Playerpiece is %c \n",playerPiece);
        printf("Connected is %d \n",connected);
        printf("Line 65 Win\n");
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
        printf("Line 90 Win\n");
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
        printf("Line 118 Win\n");
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
        printf("Line 146 Win\n");
        return 1;
    }
    printf("No winner yet\n");
    return 0;
}

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

void turns(int Player){
    if(Player==0){
        printf("Player 2's turn\n");
    }
    else{
        printf("Player 1's turn\n");
    }
    printboard();
    int targetc;
    int status=0;
    while(status==0){
        printf("Target column:");
        scanf("%d",&targetc);
        targetc--;
        status=addPiece(Player,targetc);
        if(status==0){
            printf("Invalid column\n");
        }
    }
    if(checkIfWin(targetc)){
        printf("%d Wins!", Player);
        gameActive = 0;
        return;
    }
}

void printboardold(){
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

int main(void){
    //initialize board
    reset();
    while(gameActive){
        turns(lastPlayer%2);
        lastPlayer++;
    }
    printboard();
}
