#include<iostream>
using namespace std;

class Queen{
    int row; 
    int col;

    public: 
        Queen(int row, int col){
            this->setRow(row);
            this->setCol(col);
        }
        void setRow(int row){
            this->row = row;
        }
        void setCol(int col){
            this->col = col;
        }
        int getRow(){
            return this->row;
        }
        int getCol(){
            return this->col;
        }

};
int main(){
    Queen* Q1 = new Queen(0, 0);
    int chessboard[4][4] = {0};
    //placing first queen in first row and first column
    chessboard[0][0] = 1;
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            if(chessboard[i][j] == 1){
                if(i == j){
                    continue;
                }
            }
        }
    }

    return 0;
}