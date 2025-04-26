
// test.cpp
#include "BowlingGame.h"
#include <cassert>
#include <iostream>

void runTests() {
    BowlingGame game1("Alice");
    for (int i = 0; i < 10; ++i) game1.addFrame(3, 4);
    assert(game1.getFinalScore() == 70);

    BowlingGame game2("Bob");
    for (int i = 0; i < 9; ++i) game2.addFrame(5, 5);
    game2.addFrame(5, 5, 5);
    assert(game2.getFinalScore() == 150);

    BowlingGame game3("Charlie");
    for (int i = 0; i < 9; ++i) game3.addFrame(10, 0);
    game3.addFrame(10, 10, 10);
    assert(game3.getFinalScore() == 300);

    BowlingGame game4("Dana");
    game4.addFrame(10, 0);
    game4.addFrame(5, 5);
    game4.addFrame(7, 2);
    for (int i = 3; i < 9; ++i) game4.addFrame(3, 4);
    game4.addFrame(3, 6);
    assert(game4.getFinalScore() == 80);

    try {
        BowlingGame game5("Eve");
        game5.addFrame(8, 5);
        assert(false);
    } catch (invalid_argument&) {}

    cout << "All unit tests passed!" << endl;
}

int main() {
    runTests();
    return 0;
}
