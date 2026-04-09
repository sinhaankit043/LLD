#include<iostream>
#include<deque>
using namespace std;

class Symbol{
    public:
    char mark;

    Symbol(char c){
        this->mark=c
;    }
};

class Player{
    public:
    int id;
    string name;
    Symbol*symbol;
    int score;
    Player(int id, string name,Symbol*symbol){
        this->id=id;
        this->name= name;
        this->symbol=symbol;
        this->score=0;
    }
};



class Board{
   public:
   vector<vector<Symbol*>>grid;
   int size;
   Symbol* emptyCell;

   Board(int size){
      this->size=size;
      this->emptyCell= new Symbol('_');
      this->grid.resize(size,vector<Symbol*>(size,emptyCell));
   }

   bool isCellEmpty(int row, int col){
     if(row>=0 && row<size && col>=0 && col<size){
        return grid[row][col]==emptyCell;
     }
     else return false;
   }

   bool placeMark(int row, int col, Symbol*mark){
          if(!isCellEmpty(row,col)){
              return false;
          }

          grid[row][col]=mark;
          return true;
   }


   void display(){
      for(int i=0;i<size;i++){
        cout<<i<<" ";
      }
      cout<<endl;

      for(int i=0;i<size;i++){
        cout<<i<<" ";
        for(int j=0;j<size;j++){
            cout<<grid[i][j]->mark<<" ";
        }
        cout<<endl;
      }

      cout<<endl;
   }


};


class GameRule{
    public:
    virtual bool checkWinCondition(Board*board,Symbol*symbol)=0;
    virtual bool checkDrawCondition(Board*board)=0;
    virtual bool isValidMove(Board*board,int row, int col)=0;

};

class StandardRule:public GameRule{
   public:

   bool isValidMove(Board*board, int row,int col){
    return board->isCellEmpty(row,col);
   }

   bool checkWinCondition(Board*board, Symbol*symbol){
       int size= board->size;
       //check row

       for(int i=0;i<size;i++){
        bool isWin=true;
        for(int j=0;j<size;j++){
            if( board->grid[i][j]!=symbol){
                isWin=false;
                break;
            }
        }
        if(isWin)return true;
       }


       //check column;

       for(int j=0;j<size;j++){
        bool isWin= true;
        for(int i=0;i<size;i++){
            if( board->grid[i][j]!=symbol){
                isWin=false;
                break;
            }
        }
        if(isWin)return true;
       }

       //check main diagonal

       bool isDiagonal=true;
       for(int i=0;i<size;i++){
          if(board->grid[i][i]!=symbol){
                isDiagonal=false;
                break;
            }
       }

       if(isDiagonal)return true;


       //check anti-diagonal

       bool isAntiDiagonal= true;

       for(int i=0;i<size;i++){
          if(board->grid[i][size-i-1]!=symbol){
                isAntiDiagonal=false;
                break;
            }
       }

       if(isAntiDiagonal)return true;


       return false;
      
   }


   bool checkDrawCondition(Board*board){
      int size= board->size;

        for(int i = 0; i<size ;i++){
          for(int j =0;j<size;j++){
            if(board->isCellEmpty(i,j))return false;
          }
        }
        return true;
   }
};


class TicTacToeGame{
    public:
    
    GameRule*rule;
    Board*board;
    deque<Player*>players;
    bool gameOver;

    TicTacToeGame(int boardSize){
        board= new Board(boardSize);
        rule= new StandardRule();
        gameOver=false;
    }

    void addPlayers(Player*player){
        players.push_back(player);
    }

    void play(){

        if(players.size()<2){
            cout<<"Need atleast 2 players to play"<<endl;
            return ;
        }

        while(!gameOver){
            Player*currentPlayer= players.front();
            

            cout<<currentPlayer->name<<" select row and col to insert"<<currentPlayer->symbol->mark<<endl;
            int row, col;
            cin>>row>>col;


            if(rule->isValidMove(board,row,col)){
                board->placeMark(row,col,currentPlayer->symbol);

                if(rule->checkWinCondition(board,currentPlayer->symbol)){
                    cout<<currentPlayer->name<<" Wins!"<<endl;
                    gameOver= true;
                }

                else if(rule->checkDrawCondition(board)){
                    cout<<"Game Draw!"<<endl;
                    gameOver=true;
                }
                else{
                  players.pop_front();
                  players.push_back(currentPlayer);
                }
            }
            else{
                cout<<"Invalid Move,try another move!"<<endl;
            }
        }
    }
};


enum GameType{
   STANDARD
};

class TicTacToeGameFactory{
    public:
    static TicTacToeGame*createGame(GameType gt,int boardSize){
       if(GameType::STANDARD==gt){
        return new TicTacToeGame(boardSize);
       }
       return nullptr;
    }
};


int main(){
    cout<<"-----------TIC TAC TOE GAME-------------"<<endl;
    int boardSize;
    cout<<"Enter board size"<<endl;
    cin>>boardSize;

    TicTacToeGame* game = TicTacToeGameFactory::createGame(GameType::STANDARD,boardSize);

     Player* player1 = new Player(1, "Aditya", new Symbol('X'));
     Player* player2 = new Player(2, "Harshita", new Symbol('O'));

     game->addPlayers(player1);
     game->addPlayers(player2);

     game->play();
}


//clang++ -std=c++17 tic-tac-toe-game.cpp -o app && ./app

