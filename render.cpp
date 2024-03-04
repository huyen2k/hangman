#include <iostream>
#include <string>
#include <vector>
#include "lib.h"

using namespace std;

void rendergame(string guessword, int badguesscount){
    vector<string> render = {
    " -----------------\n"
    "  |               \n"
    "  |               \n"
    "  |               \n"
    "  |               \n"
    "  |               \n"
    "  |               \n"
    "-----",
    " -----------------\n"
    "  |          |    \n"
    "  |               \n"
    "  |               \n"
    "  |               \n"
    "  |               \n"
    "  |               \n"
    "-----",
    " -----------------\n"
    "  |          |    \n"
    "  |          o    \n"
    "  |               \n"
    "  |               \n"
    "  |               \n"
    "  |               \n"
    "-----",
    " -----------------\n"
    "  |          |    \n"
    "  |          o    \n"
    "  |          |    \n"
    "  |               \n"
    "  |               \n"
    "  |               \n"
    "-----",
    " -----------------\n"
    "  |          |    \n"
    "  |          o    \n"
    "  |         /|    \n"
    "  |               \n"
    "  |               \n"
    "  |               \n"
    "-----",
    " -----------------\n"
    "  |          |    \n"
    "  |          o    \n"
    "  |         /|\\  \n"
    "  |               \n"
    "  |               \n"
    "  |               \n"
    "-----",
    " -----------------\n"
    "  |          |    \n"
    "  |          o    \n"
    "  |         /|\\  \n"
    "  |         /     \n"
    "  |               \n"
    "  |               \n"
    "-----",
    " -----------------\n"
    "  |          |    \n"
    "  |          o    \n"
    "  |         /|\\  \n"
    "  |         / \\  \n"
    "  |               \n"
    "  |               \n"
    "-----",

    };
    cout << render[badguesscount] << '\n';
    cout << "Secretword : " << guessword << '\n';
}

string dancingman(){
    const static string figure[] = {
        " -----------------\n"
        "  |         /     \n"
        "  |         o     \n"
        "  |        /|\\   \n"
        "  |        / \\   \n"
        "  |               \n"
        "  |               \n"
        "-----",
        " -----------------\n"
        "  |          |    \n"
        "  |          o    \n"
        "  |         /|\\  \n"
        "  |         / \\  \n"
        "  |               \n"
        "  |               \n"
        "-----",
        " -----------------\n"
        "  |           \\  \n"
        "  |           o   \n"
        "  |          /|\\ \n"
        "  |          / \\ \n"
        "  |               \n"
        "  |               \n"
        "-----",
        " -----------------\n"
        "  |          |    \n"
        "  |          o    \n"
        "  |         /|\\  \n"
        "  |         / \\  \n"
        "  |               \n"
        "  |               \n"
        "-----",
    };
    int num_of_figure = sizeof(figure) / sizeof(string);
    static int currentfigure = 0;
    return figure[(currentfigure ++) % num_of_figure];
}

string hangman(){
    const static string figures[] = {
        "    O    \n"
        "   /|\\  \n"
        "   | |   \n",

        "    O    \n"
        "   /|\\  \n"
        "   / \\  \n",

        "  __O__  \n"
        "    | \n"
        "   / \\ \n",

        "   \\O/ \n"
        "    | \n"
        "   / \\ \n",

        "  __O__ \n"
        "    | \n"
        "   / \\ \n",

        "    O \n"
        "   /|\\ \n"
        "   / \\ \n" ,

        "   O \n"
        "   /|\\ \n"
        "   / \\ \n" ,

        "    O \n"
        "   /|\\ \n"
        "   / \\ \n" ,

        "     O \n"
        "   /|\\ \n"
        "   / \\ \n" ,

        "    O \n"
        "   /|\\ \n"
        "   / \\ \n" ,

    };
    int num_of_figures = sizeof(figures) / sizeof(string);
    static int currentfigures = 0;
    return figures[(currentfigures ++) % num_of_figures];
}

void finalresult(bool won, int badguesscount){
    while(1){
        if (system("CLS")) system("clear");
        if(won){
            cout << "Congratulations! You win\n";
            cout << dancingman();
        }
        else {
            //return;
            cout << "You lose!\n";
            cout << hangman();
        }
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}
