/*
  八皇后问题
*/

#include <iostream>
using namespace std;

int **board; 
int count = 0;

void print_metric()
{
    for (int i=0; i<8; ++i) {
        for (int j=0; j<8; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool is_ok(int row, int column)
{
    int leftup = column-1;
    int rightup = column+1;
    
    for (int i=row-1; i>=0; --i) {
        if(board[i][column]!=0) return false;
        if(leftup >= 0 && board[i][leftup] != 0) return false;
        if(rightup <= 7 && board[i][rightup] != 0) return false;
        leftup --;
        rightup ++;
    }
    return true;
}

void calc_queens(int row)
{
    if (row == 8) {
        count += 1;
        print_metric();
        return;
    }
    
    for (int j=0; j<8; ++j) {
        if (is_ok(row, j)) {
            board[row][j] = 1;
            calc_queens(row+1); 
            board[row][j] = 0;
        }
    }
    
}


int main()
{
    board = new int*[8];
    for (int i=0; i<8; ++i) {
        board[i] = new int[8];
    }
    
    print_metric();
    calc_queens(0);
    cout << "count = " << count << endl;  // 92
    
    for (int i=0; i<8; ++i) {
        delete [] board[i];
    }
    delete [] board;
    
    return 0;
}
