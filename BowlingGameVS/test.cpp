#include "BowlingGame.h"
#include <cassert>
#include <iostream>
using namespace std;

void testNormalGame() {
    cout << "Running testNormalGame..." << endl;
    BowlingGame game("Alice");
    for (int i = 0; i < 10; ++i) game.addFrame(3, 4);
    assert(game.getFinalScore() == 70);
    cout << "testNormalGame passed!" << endl;

}

void testAllSpares() {
    cout << "Running testAllSpares..." << endl;
    BowlingGame game("Bob");
    for (int i = 0; i < 9; ++i) game.addFrame(5, 5);
    game.addFrame(5, 5, 5);
    assert(game.getFinalScore() == 150);
    cout << "testAllSpares passed!" << endl;
}

void testPerfectGame() {
    cout << "Running testPerfectGame..." << endl;
    BowlingGame game("Charlie");
    for (int i = 0; i < 9; ++i) game.addFrame(10, 0);
    game.addFrame(10, 10, 10);
    assert(game.getFinalScore() == 300);
    cout << "testPerfectGame passed!" << endl;
}

void testMixedGame() {
    cout << "Running testMixedGame..." << endl;
    BowlingGame game("Dana");
    game.addFrame(10, 0);
    cout << "Added frame 1: Strike" << endl;
    
    game.addFrame(5, 5);
    cout << "Added frame 2: Spare" << endl;
    
    game.addFrame(7, 2);
    for (int i = 3; i < 9; ++i) 
    {
        game.addFrame(3, 4); // Normal frame
        cout << "Added frame " << i + 1 << ": 3-4" << endl;
    }
    game.addFrame(3, 6);
    cout << "Added final frame: 3-6" << endl;

    int finalScore = game.getFinalScore();
    cout << "Final score: " << finalScore << endl;

    assert(game.getFinalScore() == 97);
    cout << "testMixedGame passed!" << endl;
}

void testInvalidInput() {
    cout << "Running testInvalidInput..." << endl;
    try {
        BowlingGame game("Eve");
        game.addFrame(8, 5);  // Invalid: 8 + 5 > 10
        assert(false);        // Should not reach here
    }
    catch (const invalid_argument& e) {
        cout << "testInvalidInput passed (caught expected exception)!" << endl;
    }
}

void runTests() {
    cout << "==== Running Bowling Game Tests ====" << endl;
    testNormalGame();
    testAllSpares();
    testPerfectGame();
    testMixedGame();
    testInvalidInput();

    cout << "All unit tests passed!" << endl;
}

int main() {
    runTests();
    return 0;
}
