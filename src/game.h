/*
 * Helper utility for game state.
 * This software uses the MIT license.
 * Written by Jordan Sola 2019-2020
 */

#ifndef GAME_h
#define GAME_h

#include <string>
#include "player.h"
#include "deck.h"

using std::string;

class GameModel
{
protected:
    int player_count = 0;
    int original_player_count = 0;
    int round_count = 1;
    vector<PlayerController> players;
    int winning_token_count = 0;
};

class GameInterface : public GameModel
{
public:
    GameInterface() : GameModel{} {};

    //getters
    const int PCount();
    const int Round();
    const int OPCount();
    const int WinningTokenCount();
    vector<PlayerController> Players();
    PlayerController PCurrent();
    int FindWinner();

    //setters
    void SetPCount(int input);
    void SetOPCount(int input);
    void SetPlyrs(vector<PlayerController> input);
    void SetWinningTokenCount(int input);
    void SetStrtngPlyr(int output);
};

class GameController : public GameInterface
{
public:
    GameController() : GameInterface{} {};

    void BuildPCount();
    void BuildPContainer();
    bool PCountCorrect(int input);
    void FixPCount();
    void BuildWinningTokenCount();
    void BuildStartingPlyr();
    int GenerateNumberWithinRange(int range);
    int GetPlayerGuess();
    bool CorrectGuessInput(int output);
    void FixGuessInput(int input);
    bool DuplicateGuess(vector<int> guess_container, int guess);
    void DealStartingHand(DeckController &deck);
    void ClearWinner();
    void ClearPlaying();
    void ProcessDraw(DeckController &deck);
    char DrawInput();
    bool CorrectDrawInput(char input);
    char FixDrawInput();
};

#endif