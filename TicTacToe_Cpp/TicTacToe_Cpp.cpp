#include "header.h"
#include <iostream>
using namespace std;

int main() {
    next_player = 1;
    while (true) {
        ShowTable();
        ChooseMove();
        if (JudgeGame()) { break; }
        next_player *= -1;
    }
    return 0;
}