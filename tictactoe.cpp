#include <iostream>
using namespace std;
void boarddisplay(char board[]);
bool correctrange(int cell);
bool cellempty(int cell, char board[]);
void turnchange(char &turn);
bool three(char turn, char board[]);
bool threerow(char turn, char board[]);
bool threecolumn(char turn, char board[]);
bool threediagonal(char turn, char board[]);
struct Node {
   int movenum;
   char board[9];
   Node *nextPtr;
};
void displayList( Node *head);
int main() {
	char board[9];
	for(int i = 0; i < 9; i++)
		board[i] = ' ';
	
	Node *head = NULL; 
    Node *tempPtr;
	int movenum = 0;
	char turn = 'X';
	int cell = 0;
	boarddisplay(board);
	while(movenum < 9) {
		displayList(head);
		cout<<"*****************************"<<endl;
		cout<<"Move number: "<<movenum<<endl;
		cout << "TURN: "<< turn << " make your move: ";
		cin >> cell; 
		if(correctrange(cell)) { 
			if(cellempty(cell-1, board)){
				board[cell-1] = turn;
				if(three(turn, board)) {
boarddisplay(board);
					cout << "Congratulations player "<<turn<< " You win!!";
					cin >> cell; 
					return 1;
				}
				tempPtr = new Node;
				tempPtr->movenum = movenum; 
				for(int i=0;i<9;i++) { 			
tempPtr->board[i]=board[i];
						}
				tempPtr->nextPtr = head;
				head = tempPtr; 
				movenum++; 
				turnchange(turn);
				
				}
			else { 
			cout << "Sorry...cell "<< cell << " has already been used, try again: " << endl;
			}
		}
		else {
			cout << "Sorry...cell "<< cell << " is outside the range 1-9, try again: " << endl;
		}
	}
	cout<<"Game Ended: No Winners";
	cin >>cell;
	return 1;
}
void displayList( Node *head)
{
   Node *tempPtr = head;
   cout << "\n List contains: "<<endl;
   while( tempPtr != NULL) {
      boarddisplay(tempPtr->board);
	  cout<<"Move Number: "<<tempPtr->movenum<<endl<<endl;
      tempPtr = tempPtr->nextPtr;
   }
   cout << "\n\n";
}
void boarddisplay(char board[]) {
	cout << " ___   ___   ___ "<<endl;
	cout << "| "<<board[0]<<" |"<<" "<< "| "<< board[1]<<" |"<<" "<< "| "<< board[2]<<" |"<<endl;
	cout << "|___| |___| |___| "<<endl;
	cout << " ___   ___   ___ "<<endl;
	cout << "| "<<board[3]<<" |"<<" "<< "| "<< board[4]<<" |"<<" "<< "| "<< board[5]<<" |"<<endl;
	cout << "|___| |___| |___| "<<endl;
	cout << " ___   ___   ___ "<<endl;
	cout << "| "<<board[6]<<" |"<<" "<< "| "<< board[7]<<" |"<<" "<< "| "<< board[8]<<" |"<<endl;
	cout << "|___| |___| |___| "<<endl;
}
bool correctrange(int cell) {
	if(cell >= 1 && cell <= 9)
		return true;
	else 
		return false;
}
bool cellempty(int cell, char  board[]) {
	if(board[cell]!=' ')
		return false;
	else 
		return true;
}
void turnchange(char &turn) {
	if(turn == 'X')
		turn = 'O';
	else
		turn = 'X';}

bool three(char turn, char board[]) {
	if(threerow(turn, board) || threecolumn(turn,board) || threediagonal(turn,board))
		return true;
	else
		return false;
}
bool threerow(char turn, char board[]) {
	if((board[0] == turn && board[1] == turn && board[2] == turn) ||
	   (board[3] == turn && board[4] == turn && board[5] == turn) ||
	   (board[6] == turn && board[7] == turn && board[8] == turn))
	   return true;
	else 
		return false;
}
bool threecolumn(char turn, char board[]) {
	if((board[0] == turn && board[3] == turn && board[6] == turn) ||
	   (board[1] == turn && board[4] == turn && board[7] == turn) ||
	   (board[2] == turn && board[5] == turn && board[8] == turn))
	   return true;
	else 
		return false;
}
bool threediagonal(char turn, char board[]) {
	if((board[0] == turn && board[4] == turn && board[8] == turn) ||
	   (board[2] == turn && board[4] == turn && board[6] == turn))
	   return true;
	else 
		return false;
}

