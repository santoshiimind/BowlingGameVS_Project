
// BowlingGame.h
#ifndef BOWLINGGAME_H
#define BOWLINGGAME_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Frame {
public:
    int roll1, roll2, bonusRoll;
    bool isStrike, isSpare;

    Frame(int r1 = 0, int r2 = 0, int bonus = 0);
    int getBaseScore() const;
};

class Player {
private:
    string name;
    vector<Frame> frames;

public:
    Player(const string& playerName);
    void addFrame(const Frame& frame);
    int getTotalScore() const;
};

class BowlingGame {
private:
    Player player;

public:
    BowlingGame(const string& playerName);
    void addFrame(int roll1, int roll2, int bonusRoll = 0);
    int getFinalScore() const;
};

#endif
