
// main.cpp
#include "BowlingGame.h"

int main() {
    BowlingGame game("Sample Player");

    for (int i = 0; i < 10; ++i) {
        game.addFrame(3, 4);
    }

    cout << "Final Score: " << game.getFinalScore() << endl;
    return 0;
}
