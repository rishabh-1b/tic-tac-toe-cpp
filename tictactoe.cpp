#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}};
char current_marker;
int current_player = 1;

void displayBoard()
{
  cout << "\n";
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << " " << board[i][j] << " ";
      if (j < 2)
        cout << "|";
    }
    cout << "\n";
    if (i < 2)
      cout << "-----------" << "\n";
  }
  cout<<"\n";
}

bool checkWinner()
{
  for (int i = 0; i < 3; i++)
  {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] || board[0][i] == board[1][i] && board[1][i] == board[2][i])
      return true;
  }
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] || board[0][2] == board[1][1] && board[1][1] == board[2][0])
    return true;
  return false;
}

bool isBoardFull()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (board[i][j] != 'X' && board[i][j] != 'O')
        return false;
    }
  }
  return true;
}

bool placeMove(int move)
{
  int row = (move - 1) / 3, col = (move - 1) % 3;
  if(board[row][col]!='X' && board[row][col]!='O')
  {
    board[row][col]=current_marker;
    return true;
  }
  return false;
}

void swapPlayerAndMarker()
{
  current_marker = current_marker == 'X' ? 'O' : 'X';
  current_player = current_player == 1 ? 2 : 1;
}

void game()
{
  while (true)
  {
    displayBoard();
    int move;
    cout << "Player " << current_player << " (" << current_marker << "), Enter your move (1-9): ";
    cin >> move;
    if(move<1 || move>9 || !placeMove(move))
    {
      cout<<"Invalid move! Try again."<<"\n";
      continue;
    }
    if(checkWinner())
    {
      displayBoard();
      cout<<"Player "<<current_player<<" wins!"<<"\n";
      break;
    }
    if(isBoardFull())
    {
      displayBoard();
      cout<<"It's a draw!"<<"\n";
      break;
    }
    swapPlayerAndMarker();
  }
}

int main()
{
  cout << "Welcome to Tic-Tac-Toe Game!" << "\n";
  cout << "Player 1, choose your marker (X or O): ";
  cin >> current_marker;
  while (current_marker != 'X' && current_marker != 'O')
  {
    cout << "Invalid choice! Choose (X or O): ";
    cin >> current_marker;
  }
  game();
  return 0;
}