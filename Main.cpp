#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(NULL)); 
    char mat[3][3] = { {'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'} }; // matrix filled with dots to indicate empty
    // main variables
    char choice, choice2, confirm, confirm2;
    string name, name2;
    int position, count2 = 1, uob;
    int arr[9] = {0};
    
    do {
        int count = 0; 

        // Reset the grid
        for (int i = 0; i < 9; i++) {
            arr[i] = 0;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                mat[i][j] = '.';
            }
        }

        // Prompt to start a new game
        if (count2 == 1) {
            cout << "Do you want to play Tic Tac Toe? [y/n]: ";
            cin >> confirm2;
        } else {
            cout << "Do you want to play again? [y/n]: ";
            cin >> confirm2;
        }

        // input check
        while (confirm2 != 'y' && confirm2 != 'n') {
            cout << "Re-enter choice:\n";
            cin >> confirm2;
        }

        if (confirm2 == 'y') {
            count2++;

            cout << "Here is the initial board:\n";
            cout << "1 | 2 | 3\n---------\n4 | 5 | 6\n---------\n7 | 8 | 9" << endl;

            cout << "Press (1) to play against a person, Press (2) to play against the bot:\n";
            cin >> uob;

            // mode selection
            while (uob != 1 && uob != 2) {
                cout << "Invalid number, re-enter number:\n";
                cin >> uob;
            }

            if (uob == 1) { // two-player game
                // enter names
                cout << "Player 1, do you want to enter a name? [y/n]:\n";
                cin >> confirm;
                while (confirm != 'y' && confirm != 'n') {
                    cout << "Re-enter choice:\n";
                    cin >> confirm;
                }
                if (confirm == 'y') {
                    cout << "Enter name: ";
                    cin >> name;
                } else {
                    cout << "Ok, your name will be Player 1\n";
                    name = "Player 1";
                }

                cout << "Player 2, do you want to enter a name? [y/n]:\n";
                cin >> confirm;
                while (confirm != 'y' && confirm != 'n') {
                    cout << "Re-enter choice:\n";
                    cin >> confirm;
                }
                if (confirm == 'y') {
                    cout << "Enter name: ";
                    cin >> name2;
                } else {
                    cout << "Ok, your name will be Player 2\n";
                    name2 = "Player 2";
                }
                
                // symbol selection
                cout << name << " choose X or O (lowercase):\n";
                cin >> choice;
                while (choice != 'x' && choice != 'o') {
                    cout << "Invalid character, re-enter character:\n";
                    cin >> choice;
                }

                // assign symbol
                if (choice == 'x') {
                    choice2 = 'o';
                    cout << name2 << " has: " << choice2 << endl;
                } else {
                    choice2 = 'x';
                    cout << name2 << " has: " << choice2 << endl;
                }

                // 9 turns max
                while (count < 9) {
                    count++;
                    if (count % 2 != 0) {
                        cout << name << ", choose the position to place your character:\n";
                        cin >> position;
                        while (position < 1 || position > 9 || arr[position - 1] != 0) {
                            cout << "Invalid or occupied position, re-enter position:\n";
                            cin >> position;
                        }
                        arr[position - 1] = 1;
                        
                        switch (position) {
                            case 1: mat[0][0] = choice; break;
                            case 2: mat[0][1] = choice; break;
                            case 3: mat[0][2] = choice; break;
                            case 4: mat[1][0] = choice; break;
                            case 5: mat[1][1] = choice; break;
                            case 6: mat[1][2] = choice; break;
                            case 7: mat[2][0] = choice; break;
                            case 8: mat[2][1] = choice; break;
                            case 9: mat[2][2] = choice; break;
                        }
                    } else {
                        cout << name2 << ", choose the position to place your character:\n";
                        cin >> position;
                        while (position < 1 || position > 9 || arr[position - 1] != 0) {
                            cout << "Invalid or occupied position, re-enter position:\n";
                            cin >> position;
                        }
                        arr[position - 1] = 2;

                        switch (position) {
                            case 1: mat[0][0] = choice2; break;
                            case 2: mat[0][1] = choice2; break;
                            case 3: mat[0][2] = choice2; break;
                            case 4: mat[1][0] = choice2; break;
                            case 5: mat[1][1] = choice2; break;
                            case 6: mat[1][2] = choice2; break;
                            case 7: mat[2][0] = choice2; break;
                            case 8: mat[2][1] = choice2; break;
                            case 9: mat[2][2] = choice2; break;
                        }
                    }

                    // Print board
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            cout << mat[i][j];
                            if (j < 2) cout << "|";
                        }
                        cout << endl;
                        if (i < 2) cout << "-----\n";
                    }

                    // Check win for Player 1
                    if ((mat[0][0] == choice && mat[0][1] == choice && mat[0][2] == choice) ||
                        (mat[1][0] == choice && mat[1][1] == choice && mat[1][2] == choice) ||
                        (mat[2][0] == choice && mat[2][1] == choice && mat[2][2] == choice) ||
                        (mat[0][0] == choice && mat[1][0] == choice && mat[2][0] == choice) ||
                        (mat[0][1] == choice && mat[1][1] == choice && mat[2][1] == choice) ||
                        (mat[0][2] == choice && mat[1][2] == choice && mat[2][2] == choice) ||
                        (mat[0][0] == choice && mat[1][1] == choice && mat[2][2] == choice) ||
                        (mat[0][2] == choice && mat[1][1] == choice && mat[2][0] == choice)) {
                        cout << "You won " << name << "!" << endl;
                        break;
                    }

                    // Check win for Player 2
                    if ((mat[0][0] == choice2 && mat[0][1] == choice2 && mat[0][2] == choice2) ||
                        (mat[1][0] == choice2 && mat[1][1] == choice2 && mat[1][2] == choice2) ||
                        (mat[2][0] == choice2 && mat[2][1] == choice2 && mat[2][2] == choice2) ||
                        (mat[0][0] == choice2 && mat[1][0] == choice2 && mat[2][0] == choice2) ||
                        (mat[0][1] == choice2 && mat[1][1] == choice2 && mat[2][1] == choice2) ||
                        (mat[0][2] == choice2 && mat[1][2] == choice2 && mat[2][2] == choice2) ||
                        (mat[0][0] == choice2 && mat[1][1] == choice2 && mat[2][2] == choice2) ||
                        (mat[0][2] == choice2 && mat[1][1] == choice2 && mat[2][0] == choice2)) {
                        cout << "You won " << name2 << "!" << endl;
                        break;
                    }
                }

                if (count == 9) {
                    cout << "Game ended in a tie!" << endl;
                }
                
            } else if (uob == 2) { // game against bot
                
                cout << "Player 1, do you want to enter a name? [y/n]:\n";
                cin >> confirm;
                
                while (confirm != 'y' && confirm != 'n') {
                    cout << "Re-enter choice:\n";
                    cin >> confirm;
                }
                if (confirm == 'y') {
                    cout << "Enter name: ";
                    cin >> name;
                } else {
                    cout << "Ok, your name will be Player 1\n";
                    name = "Player 1";
                }

                cout << name << " choose X or O (lowercase):\n";
                cin >> choice;
                
                while (choice != 'x' && choice != 'o') {
                    cout << "Invalid character, re-enter character:\n";
                    cin >> choice;
                }
                
                if(choice == 'x') {
                    choice2 = 'o';
                    cout << "Bot has: " << choice2 << endl;
                } else {
                    choice2 = 'x';
                    cout << "Bot has: " << choice2 << endl;
                }

                while (count < 9) {
                    count++;
                    if (count % 2 != 0) {
                        cout << name << ", choose the position to place your character:\n";
                        cin >> position;
                        
                        while (position < 1 || position > 9 || arr[position - 1] != 0) {
                            cout << "Invalid or occupied position, re-enter position:\n";
                            cin >> position;
                        }
                        arr[position - 1] = 1;

                        switch (position) {
                            case 1: mat[0][0] = choice; break;
                            case 2: mat[0][1] = choice; break;
                            case 3: mat[0][2] = choice; break;
                            case 4: mat[1][0] = choice; break;
                            case 5: mat[1][1] = choice; break;
                            case 6: mat[1][2] = choice; break;
                            case 7: mat[2][0] = choice; break;
                            case 8: mat[2][1] = choice; break;
                            case 9: mat[2][2] = choice; break;
                        }
                    } else {
                        int move = rand() % 9 + 1; // bot random move
                        while (arr[move - 1] != 0) {
                            move = rand() % 9 + 1; // change if occupied
                        }
                        arr[move - 1] = 2;
                        switch (move) {
                            case 1: mat[0][0] = choice2; break;
                            case 2: mat[0][1] = choice2; break;
                            case 3: mat[0][2] = choice2; break;
                            case 4: mat[1][0] = choice2; break;
                            case 5: mat[1][1] = choice2; break;
                            case 6: mat[1][2] = choice2; break;
                            case 7: mat[2][0] = choice2; break;
                            case 8: mat[2][1] = choice2; break;
                            case 9: mat[2][2] = choice2; break;
                        }
                        cout << "Bot chose position: " << move << endl;
                    }

                    // Print board
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            cout << mat[i][j];
                            if (j < 2) cout << "|";
                        }
                        cout << endl;
                        if (i < 2) cout << "-----\n";
                    }

                    // Check win for Player 1
                    if ((mat[0][0] == choice && mat[0][1] == choice && mat[0][2] == choice) ||
                        (mat[1][0] == choice && mat[1][1] == choice && mat[1][2] == choice) ||
                        (mat[2][0] == choice && mat[2][1] == choice && mat[2][2] == choice) ||
                        (mat[0][0] == choice && mat[1][0] == choice && mat[2][0] == choice) ||
                        (mat[0][1] == choice && mat[1][1] == choice && mat[2][1] == choice) ||
                        (mat[0][2] == choice && mat[1][2] == choice && mat[2][2] == choice) ||
                        (mat[0][0] == choice && mat[1][1] == choice && mat[2][2] == choice) ||
                        (mat[0][2] == choice && mat[1][1] == choice && mat[2][0] == choice)) {
                        cout << "You won " << name << "!" << endl;
                        break;
                    }

                    // Check win for Bot
                    if ((mat[0][0] == choice2 && mat[0][1] == choice2 && mat[0][2] == choice2) ||
                        (mat[1][0] == choice2 && mat[1][1] == choice2 && mat[1][2] == choice2) ||
                        (mat[2][0] == choice2 && mat[2][1] == choice2 && mat[2][2] == choice2) ||
                        (mat[0][0] == choice2 && mat[1][0] == choice2 && mat[2][0] == choice2) ||
                        (mat[0][1] == choice2 && mat[1][1] == choice2 && mat[2][1] == choice2) ||
                        (mat[0][2] == choice2 && mat[1][2] == choice2 && mat[2][2] == choice2) ||
                        (mat[0][0] == choice2 && mat[1][1] == choice2 && mat[2][2] == choice2) ||
                        (mat[0][2] == choice2 && mat[1][1] == choice2 && mat[2][0] == choice2)) {
                        cout << "Bot won!" << endl;
                        break;
                    }
                }

                if (count == 9) {
                    cout << "Game ended in a tie!" << endl;
                }
            }
        }
    } while (confirm2 == 'y');
}
