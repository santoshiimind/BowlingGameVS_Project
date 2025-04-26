
// BowlingGame.cpp
#include "BowlingGame.h"
#include <stdexcept>

Frame::Frame(int r1, int r2, int bonus) : roll1(r1), roll2(r2), bonusRoll(bonus) {
    isStrike = (roll1 == 10);
    isSpare = (!isStrike && roll1 + roll2 == 10);
}

int Frame::getBaseScore() const {
    return roll1 + roll2 + bonusRoll;
}

Player::Player(const string& playerName) : name(playerName) {}

void Player::addFrame(const Frame& frame) {
    if (frames.size() >= 10) {
        throw runtime_error("Cannot add more than 10 frames");
    }
    frames.push_back(frame);
}

int Player::getTotalScore() const {
    int totalScore = 0;
    for (size_t i = 0; i < frames.size(); ++i) {
        totalScore += frames[i].getBaseScore();

        if (frames[i].isStrike && i + 1 < frames.size()) {
            totalScore += frames[i + 1].roll1;
            if (frames[i + 1].isStrike && i + 2 < frames.size()) {
                totalScore += frames[i + 2].roll1;
            } else {
                totalScore += frames[i + 1].roll2;
            }
        } else if (frames[i].isSpare && i + 1 < frames.size()) {
            totalScore += frames[i + 1].roll1;
        }
    }
    return totalScore;
}

int Player::getFrameCount() const
{
     return frames.size();
}

BowlingGame::BowlingGame(const string& playerName) : player(playerName) {}

void BowlingGame::addFrame(int roll1, int roll2, int bonusRoll) {
    if (roll1 < 0 || roll2 < 0 || bonusRoll < 0) {
        throw invalid_argument("Negative pins are not allowed");
    }

    int currentFrame = player.getFrameCount();

    if (currentFrame >= 10) {
        throw invalid_argument("Cannot add more than 10 frames");
    }

    // For first 9 frames, validate total pin count (unless it's a strike)
    if (currentFrame < 9) {
        if (roll1 != 10 && (roll1 + roll2 > 10)) {
            throw invalid_argument("Invalid pin count in a frame");
        }
    }

    // 10th frame: no total pin limit due to bonus rolls

    player.addFrame(Frame(roll1, roll2, bonusRoll));
}


int BowlingGame::getFinalScore() const {
    return player.getTotalScore();
}
