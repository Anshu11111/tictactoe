#include <iostream>
using namespace std;

char layout[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char current_XO;
int current_player;

void makeLayout()
{

     cout << endl;
     cout << " " << layout[0][0] << "  "
          << "|"
          << " " << layout[0][1] << "  "
          << "|"
          << " " << layout[0][2] << endl;
     cout << "-------------" << endl;
     cout << " " << layout[1][0] << "  "
          << "|"
          << " " << layout[1][1] << "  "
          << "|"
          << " " << layout[1][2] << endl;
     cout << "-------------" << endl;
     cout << " " << layout[2][0] << "  "
          << "|"
          << " " << layout[2][1] << "  "
          << "|"
          << " " << layout[2][2] << endl;
     cout << endl;
}

void decidingRowColumn(int placeholder)
{
     int row;
     if (placeholder % 3 == 0)
          row = (placeholder / 3) - 1;
     else
          row = placeholder / 3;
     //     cout<<row<<endl;

     int col;
     if (placeholder % 3 == 0)
          col = 2;
     else
          col = (placeholder % 3) - 1;
     //     cout<<col<<endl;

     layout[row][col] = current_XO;
}
int winner()
{
     for (int i = 0; i < 3; i++)
     {
          if (layout[0][i] == layout[1][i] && layout[1][i] == layout[2][i])
               return current_player;
          else if (layout[i][0] == layout[i][1] && layout[i][1] == layout[i][2])
               return current_player;
     }
     if (layout[0][0] == layout[1][1] && layout[1][1] == layout[2][2])
          return current_player;
     else if (layout[0][2] == layout[1][1] && layout[1][1] == layout[2][0])
          return current_player;

     return 0;
}
void swap_playerAndMarker()
{
    if(current_XO =='X')
    current_XO='O';
    else
    current_XO='X';

    if(current_player==1)
    current_player=2;
    else
    current_player=1;
}
void game()
{
   cout<<"Player 1 ,choose your marker:";
   char marker_p1;
   cin>>marker_p1;

   current_player=1;
   current_XO = marker_p1;
   cout<<endl;
   makeLayout();
   int slot;
   int playerWon;
   for(int i=0 ; i<9 ; i++)
   {
      cout<<endl<<"Player "<<current_player<<" it's your turn enter your slot: ";
      cin>>slot;
      decidingRowColumn(slot);
      makeLayout();
      playerWon= winner();
      if(playerWon==1){
          cout<<"Player 1 is winner, Congratulations!"<<endl;
          break;
      } 
      
      else if(playerWon==2)
      {
          cout<<"Player 2 is winner, Congratulations!"<<endl;
          break;
      }

      swap_playerAndMarker();

   }
   if(playerWon==0){
      cout<<"It's a tie!"<<endl;
   }

}

int main()
{
     cout << endl;
     cout << "****Welcome to Tic Tac Toe Game****" << endl<<endl;
     game();

    
}