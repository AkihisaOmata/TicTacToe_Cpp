#ifndef header_h
#define header_h 1

#include <iostream>
using namespace std;

const int NUM_COL = 3;
const int NUM_ROW = 3;
int TABLE[NUM_ROW][NUM_COL] = { {},{},{} };

int next_player;

bool JudgeGame(void) {
    int game_flag[NUM_COL + NUM_ROW + 2] = {};//LOW ROW CROSS
    int draw_flag = 0;

    for (int i = 0; i < NUM_ROW; i++) {
        for (int j = 0; j < NUM_COL; j++) {
            game_flag[i] += TABLE[i][j];
            game_flag[3 + j] += TABLE[i][j];
            if (i == j) { game_flag[NUM_COL + NUM_ROW] += TABLE[i][j]; }
            if (i + j == 3) { game_flag[NUM_COL + NUM_ROW + 1] += TABLE[i][j]; }
            if (TABLE[i][j] != 0) { draw_flag++; }
        }
    }
    for (int i = 0; i < NUM_COL + NUM_ROW + 2; i++) {
        if (game_flag[i] == 3) {
            cout << "/-/-/-/-/ Player 1 WIN !!! /-/-/-/-/" << endl;
            return true;
        }
        if (game_flag[i] == -3) {
            cout << "/-/-/-/-/ Player 2 WIN !!! /-/-/-/-/" << endl;
            return true;
        }
    }
    if (draw_flag == NUM_COL * NUM_ROW) {
        cout << "/-/-/-/-/ DRAW !! /-/-/-/-/" << endl;
        return true;
    }
    return false;
}

int ChooseMove(void) {
    int choice;
    while (true) {
        if (next_player == 1) {
            cout << ">>> Player 1 : x <<<" << endl;
        }
        else {
            cout << ">>> Player 2 : o <<<" << endl;
        }
        cout << "Choose your move [0-8]  ...  ";
        cin >> choice;
        if (TABLE[(choice - choice % NUM_COL) / NUM_COL][choice % NUM_COL] == 0) {
            break;
        }
        cout << endl;
        cout << "You CANNOT choose there :(" << endl;
        cout << endl;
    }
    TABLE[(choice - choice % NUM_COL) / NUM_COL][choice % NUM_COL] = next_player;
    return choice;
}


void ShowTable(void) {
    cout << endl;
    for (int i = 0; i < NUM_ROW; i++) {
        cout << "-------------" << endl;
        for (int j = 0; j < NUM_COL; j++) {
            if (TABLE[i][j] == 0) { cout << "| " << i * NUM_COL + j << " "; }
            if (TABLE[i][j] == 1) { cout << "| x "; }
            if (TABLE[i][j] == -1) { cout << "| o "; }
        }
        cout << "|" << endl;
    }
    cout << "-------------" << endl;
    cout << endl;
    return;
}

#endif