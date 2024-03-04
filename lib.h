#include<thread>
#include<chrono>
#include<string>
#include<iostream>

using namespace std;

void rendergame(string guessword, int badguesscount);
void finalresult(bool won, int badguesscount);
string dancingman();
string hangman();
