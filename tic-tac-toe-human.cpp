#include <iostream>
using namespace std;
char space[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8', '9'}};
int row;
int col;
char token = 'X';
string n1= "";
string n2 = "";
bool tie = false;

void design(){

    cout<< "     |     |    \n";
    cout<< "   "<<space[0][0] << " |  " <<space[0][1] <<"  |  " <<space[0][2]<< "  \n";
    cout<< " ____|_____|____\n";
    cout<< "     |     |    \n";
    cout<< "   "<<space[1][0] << " |  " <<space[1][1] <<"  |  " <<space[1][2]<<  "  \n";
    cout<< " ____|_____|____\n";
    cout<< "     |     |    \n";
    cout<< "   "<<space[2][0] << " |  " <<space[2][1] <<"  |  " <<space[2][2] <<"  \n";
    cout<< "     |     |    \n";
}


void check(){
    // check for any invalid value

    int digit;
    if (token == 'X'){
        cout << n1 <<" please enter ";
        cin>>digit;
    }
    if (token == '0'){
        cout<< n2 << " please enter ";
        cin>>digit;
    }

    if (digit ==1){
        row = 0;
        col = 0;
    }
    if (digit ==2){
        row = 0;
        col = 1;
    }
    if (digit ==3){
        row = 0;
        col = 2;
    }
    if (digit ==4){
        row = 1;
        col = 0;
    }
    if (digit ==5){
        row = 1;
        col = 1;
    }
    if (digit ==6){
        row = 1;
        col = 2;
    }
    if (digit ==7){
        row = 2;
        col = 0;
    }
    if (digit ==8){
        row = 2;
        col = 1;
    }
    if (digit ==9){
        row = 2;
        col = 2;
    }
    else if (digit <1 || digit>9){
        printf ("Invalid");
    }

    if(token == 'X' && space[row][col] != 'X' && space[row][col] != '0'){
        space[row][col] = 'X';
        token = '0';
    }
    else if (token=='0' && space[row][col] !='X' && space[row][col] != '0'){
        space[row][col] ='0';
        token = 'X';
    }
    else{
        printf ("There is no empty space");
        check();
    }
    design();
}

bool result(){
    for (int i=0; i<3; i++){
        if (space[i][0] == space[i][1] && space[i][1]== space[i][2]){
            return true;
        }
        if (space[0][i] == space[1][i] && space[1][i] == space[2][i]){
            return true;
        }
        if (space[0][0] == space[1][1] && space[0][0] == space[2][2]){
            return true;
        }
        if (space[0][2] == space[1][1]  && space[0][2] == space[2][0]){
            return true;
        }
        for (int i = 0; i<3; i++){
            for (int j = 0; j<3; j++){
                if (space[i][j] != 'X' && space[i][j] != '0'){
                    return false;
                }
            }
        }
        tie = true;
        return false;
    }
    
}

int main(){
    cout <<"Enter the name of the first player: ";
    getline(cin,n1);

    cout <<"Enter the name of the second player: ";
    getline(cin,n2);

    cout<< n1 << "is player 1 so he/she will play first \n" ;
    cout<< n2 << "is player 2 so he/she will play second \n";

    while(!result()){
        design();
        check();
        result();
    }
    if (token == 'X' && tie == false){
        cout << n2 << "wins!" << endl;

    }
    else if (token == '0' && tie == false){
        cout << n1 << " wins!"<< endl;
    }
    else{
        printf("Draw");
    }

    
}
