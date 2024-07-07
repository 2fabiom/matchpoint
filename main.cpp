#include <iostream>
#include <vector>
#include <string>

using namespace std;

//PADEL: um set são 6 jogos

//---------------------------------------------------------------------------
struct PadelStep {
    int scoreTeamA;
    int scoreTeamB;
    bool sideToServe; // true for left, false for right
};


//---------------------------------------------------------------------------
class PadelGame {
private:
    int scoreTeamA;
    int scoreTeamB;
    bool sideToServe; // true for left, false for right
    std::vector<PadelStep> history; // Record of previous steps
    bool gameFinished;

public:
    PadelGame() : scoreTeamA(0), scoreTeamB(0), sideToServe(true), gameFinished(false) {}

    void teamAScores() {
        if (!gameFinished) {
            history.push_back({scoreTeamA, scoreTeamB, sideToServe});
            scoreTeamA++;
            sideToServe = !sideToServe; // Change side to serve
            updateGameStatus();
        }
    }

    void teamBScores() {
        if (!gameFinished) {
            history.push_back({scoreTeamA, scoreTeamB, sideToServe});
            scoreTeamB++;
            sideToServe = !sideToServe; // Change side to serve
            updateGameStatus();
        }
    }

     bool canGoBack() const {
        return !history.empty();
    }

    void goBackOneStep() {
        if (!history.empty()) {
            auto lastStep = history.back();
            scoreTeamA = lastStep.scoreTeamA;
            scoreTeamB = lastStep.scoreTeamB;
            sideToServe = lastStep.sideToServe;
            history.pop_back();
            updateGameStatus(); // Reset game status
        }
    }

    int getScoreTeamA() const {
        return scoreTeamA;
    }

    int getScoreTeamB() const {
        return scoreTeamB;
    }

    std::string getSideToServe() const {
        return sideToServe ? "Left" : "Right";
    }

    std::string getGameStatus() const {
        return gameFinished ? "Finished" : "Ongoing";
    }

    std::string getScoreString() const {
        return formatScore(scoreTeamA) + "-" + formatScore(scoreTeamB);
    }


private:
    void updateGameStatus() {
        if (scoreTeamA >= 4 && scoreTeamB >= 4) {
            if (scoreTeamA == scoreTeamB + 1 || scoreTeamB == scoreTeamA + 1) {
                gameFinished = true; // Advantage or deuce
            }
        } else if (scoreTeamA >= 4 && scoreTeamB >= 4) {
            if (scoreTeamA == scoreTeamB) {
                gameFinished = false; // Reset to "iguais" (deuce)
            } else {
                gameFinished = true; // Game won
            }
        }
    }

    std::string formatScore(int score) const {
        if (score == 0) {
            return "0";
        } else if (score == 1) {
            return "15";    
        } else if (score == 2) {
            return "30";
        } else if (score == 3) {
            return "40";
        } else if (score == 4) {
            return "Ad"; // Game won
        }
        return ""; // Invalid score
    }
};

//---------------------------------------------------------------------------

class PadelSet {
private:
    std::vector<PadelGame> games;
    int currentGameIndex;

public:
    PadelSet(int numGames) : games(numGames), currentGameIndex(0) {}

    void teamAScores() {
        games[currentGameIndex].teamAScores();
    }

    void teamBScores() {
        games[currentGameIndex].teamBScores();
    }

    void goBackOneStep() {
        if (!games[currentGameIndex].canGoBack()) {
            // Move to the previous game
            currentGameIndex = (currentGameIndex - 1 + games.size()) % games.size();
        }
        games[currentGameIndex].goBackOneStep();
    }
};

//------------------------------------------------------------------------

int main() {
    PadelGame game;
    std::cout << "Inicial - TESTAR PADELGAME" << std::endl;
    std::cout << "Score: " << game.getScoreString() << " (" << game.getSideToServe() << ") - Status: " << game.getGameStatus() << std::endl;
    game.teamBScores();
    std::cout << "Score: " << game.getScoreString() << " (" << game.getSideToServe() << ") - Status: " << game.getGameStatus() << std::endl;
     game.teamBScores();
    std::cout << "Score: " << game.getScoreString() << " (" << game.getSideToServe() << ") - Status: " << game.getGameStatus() << std::endl;
     game.teamBScores();
    std::cout << "Score: " << game.getScoreString() << " (" << game.getSideToServe() << ") - Status: " << game.getGameStatus() << std::endl;
     game.teamBScores();
    std::cout << "Score: " << game.getScoreString() << " (" << game.getSideToServe() << ") - Status: " << game.getGameStatus() << std::endl;
    game.goBackOneStep();
    std::cout << "back Score: " << game.getScoreString() << " (" << game.getSideToServe() << ") - Status: " << game.getGameStatus() << std::endl;
    game.goBackOneStep();
    std::cout << "back Score: " << game.getScoreString() << " (" << game.getSideToServe() << ") - Status: " << game.getGameStatus() << std::endl;
    game.goBackOneStep();
    std::cout << "back Score: " << game.getScoreString() << " (" << game.getSideToServe() << ") - Status: " << game.getGameStatus() << std::endl;
    game.goBackOneStep();
    std::cout << "back Score: " << game.getScoreString() << " (" << game.getSideToServe() << ") - Status: " << game.getGameStatus() << std::endl;

    game.teamAScores();
    std::cout << "Score: " << game.getScoreString() << " (" << game.getSideToServe() << ") - Status: " << game.getGameStatus() << std::endl;
    game.teamBScores();
    std::cout << "Score: " << game.getScoreString() << " (" << game.getSideToServe() << ") - Status: " << game.getGameStatus() << std::endl;
    game.teamAScores();
    std::cout << "Score: " << game.getScoreString() << " (" << game.getSideToServe() << ") - Status: " << game.getGameStatus() << std::endl;
    game.teamBScores();
    std::cout << "Score: " << game.getScoreString() << " (" << game.getSideToServe() << ") - Status: " << game.getGameStatus() << std::endl;
    game.teamAScores();
    std::cout << "Score: " << game.getScoreString() << " (" << game.getSideToServe() << ") - Status: " << game.getGameStatus() << std::endl;
    game.teamBScores();
    std::cout << "Score: " << game.getScoreString() << " (" << game.getSideToServe() << ") - Status: " << game.getGameStatus() << std::endl;
    game.teamAScores();
    std::cout << "Score: " << game.getScoreString() << " (" << game.getSideToServe() << ") - Status: " << game.getGameStatus() << std::endl;
    game.teamBScores();
    std::cout << "Score: " << game.getScoreString() << " (" << game.getSideToServe() << ") - Status: " << game.getGameStatus() << std::endl;
    game.teamAScores();
    std::cout << "Score: " << game.getScoreString() << " (" << game.getSideToServe() << ") - Status: " << game.getGameStatus() << std::endl;
    game.teamBScores();
    std::cout << "Score: " << game.getScoreString() << " (" << game.getSideToServe() << ") - Status: " << game.getGameStatus() << std::endl;
    game.teamAScores();
    std::cout << "Score: " << game.getScoreString() << " (" << game.getSideToServe() << ") - Status: " << game.getGameStatus() << std::endl;
    game.teamBScores();
    std::cout << "Score: " << game.getScoreString() << " (" << game.getSideToServe() << ") - Status: " << game.getGameStatus() << std::endl;
    
    std::cout << "Inicial - TESTAR PADELSET" << std::endl;
    PadelSet padelSet(3); // Create a set with 3 games
    
    return 0;
}