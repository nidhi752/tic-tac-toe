#include <iostream>
#include <string>

using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, col;
char token = 'X';
string n1 = "";
string n2 = "";
bool tie = false;

void design() {
    cout << "     |     |     \n";
    cout << "  " << space[0][0] << "  |  " << space[0][1] << "  |  " << space[0][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << space[1][0] << "  |  " << space[1][1] << "  |  " << space[1][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << space[2][0] << "  |  " << space[2][1] << "  |  " << space[2][2] << "  \n";
    cout << "     |     |     \n";
}

void check() {
    int digit;
    if (token == 'X') {
        cout << n1 << ", please enter a number: ";
    } else {
        cout << n2 << ", please enter a number: ";
    }
    cin >> digit;

    row = (digit - 1) / 3;
    col = (digit - 1) % 3;

    if (digit < 1 || digit > 9 || space[row][col] == 'X' || space[row][col] == '0') {
        cout << "Invalid move. Try again.\n";
        check();
    } 
    else{
        space[row][col] = token;
        if (token == 'X') {
            token = '0';
        } 
        else{
            token = 'X';
        }
    }
    design();
}

bool result() {
    for (int i = 0; i < 3; i++) {
        if (space[i][0] == space[i][1] && space[i][1] == space[i][2]) {
            return true;
        }
        if (space[0][i] == space[1][i] && space[1][i] == space[2][i]) {
            return true;
        }
    }
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2]) {
        return true;
    }
    if (space[0][2] == space[1][1] && space[1][1] == space[2][0]) {
        return true;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'X' && space[i][j] != '0') {
                return false;
            }
        }
    }
    tie = true;
    return false;
}

void resetBoard() {
    char initial = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            space[i][j] = initial++;
        }
    }
    token = 'X';
    tie = false;
}

int main2() {
    char playAgain;

    do {
        cout << "Enter the name of the first player: ";
        cin >> n1;

        cout << "Enter the name of the second player: ";
        cin >> n2;

        cout << n1 << " is player 1, so they will play first.\n";
        cout << n2 << " is player 2, so they will play second.\n";

        resetBoard();
        design();

        while (!result()) {
            check();
        }

        if (token == 'X' && !tie) {
            cout << n2 << " wins!\n";
        } else if (token == '0' && !tie) {
            cout << n1 << " wins!\n";
        } else {
            cout << "It's a draw!\n";
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing!\n";
    return 0;
}
