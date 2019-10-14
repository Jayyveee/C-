#include <iostream>


using namespace std;        //if this not declared, string data type becomes unidentified
char pos[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char user = 'X';
int r,col;
bool draw = false;

bool result(){
    for(int i = 1;i<3;i++){
        if(pos[i][0]==pos[i][1] && pos[i][0]==pos[i][2] || pos[0][i]==pos[1][i] && pos[0][i]==pos[2][i])
        {
            return false;
        }
    }
    if(pos[0][0]==pos[1][1] && pos[0][0]==pos[2][2] || pos[0][2]==pos[1][1] && pos[0][2]==pos[2][0]){
            return false;
    }
    for(int i = 1;i<3;i++){
        for(int j = 1;j<3;j++){
            if(pos[i][j] != 'X' && pos[i][j] != 'O')
                return true;
        }
    }
    draw = true;
    return false;
}




void board(){
    // system("cls");      //to avoid displaying the new board on evry turn
    cout << "\t\t     |     |     \n"; 
    cout << "\t\t  "<<pos[0][0]<<"  |  "<<pos[0][1]<<"  |   "<<pos[0][2]<<" \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  "<<pos[1][0]<<"  |  "<<pos[1][1]<<"  |   "<<pos[1][2]<<" \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  "<<pos[2][0]<<"  |  "<<pos[2][1]<<"  |   "<<pos[2][2]<<" \n";
    cout << "\t\t     |     |     \n";
}

void turn()
{
    int choice;
    if(user == 'X')
    {
        cout<< "\n\t Player1 [X] turn:";
    }
    else
    {
        cout<< "\n\t Player2 [O] turn:";
    }
    cin >> choice;
    
    switch(choice)
    {
        case 1:
            r=0,col=0; break;
        case 2:
            r=0,col=1;
            break;
        case 3:
            r=0,col=2;
            break;
        case 4:
            r=1,col=0;
            break;
        case 5:
            r=1,col=1;
            break;
        case 6:
            r=1,col=2;
            break;
        case 7:
            r=2,col=0;
            break;
        case 8:
            r=2,col=1;
            break;
        case 9:
            r=2,col=2;
            break;
        default:
            cout << "invalid input";
            break;
    
    }

    if (user == 'X' && pos[r][col] != 'X' && pos[r][col] != 'O' )
    {
        pos[r][col] = 'X';
        user = 'O';
    }
    else if(user == 'O' && pos[r][col] != 'X' && pos[r][col] != 'O')
    {
        pos[r][col] = 'O';
        user = 'X';
    }
    else{
        cout << "Alreafy filled, please try a new position!";
    }
}

int main()
{
    
    cout<< "welcome to jaYzee application \n";
    cout<< "*************************** \n";
    cout<< "\t TIC TAC TOE GAME \n";
    cout<< "*************************** \n";
    cout<<"\t Player1 [X] \t Player2 [O] \n";
    while(result()){
        board();
        turn();
        result();
    } 

    if (user == 'X' && draw == false){
        cout<<"Player2 [O] won!!";
    }

    else if (user == 'O' && draw == false){
        cout<<"Player1 [X] won!!";
    }
    else{
        cout << "Game Draw!!!\n";
    }
return 0;
}

