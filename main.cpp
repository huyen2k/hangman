#include <bits/stdc++.h>
#include "lib.h"

using namespace std;

mt19937 rng;
int ran(int l, int r){
    return l + rng() % (r - l + 1);
}

string chooseword(){
    rng.seed(time(0));
    ifstream file("word.inp");
    vector<string> word;
    string s;
    while(file >> s)
        word.push_back(s);
    int num = ran(0, word.size());
    return word[num];
}

char guess_in(){
    cout << "Please enter your word! : ";
    char word;
    cin >> word;
    return word;
}

bool contain(string word, char guess){
    for(int i = 0; i < word.length(); i ++)
        if(word[i] == guess) return 1;
    return 0;
}

void update(string &guessword, string secretword, char guess){
    for(int i = 0; i < secretword.length(); i ++)
        if(secretword[i] == guess) guessword[i] = guess;
}

void gameplay(){
    string secretword = chooseword();
    string guessword = string(secretword.length(), '-');
    int badguesscount = 0;

    do{
        if (system("CLS")) system("clear");
        rendergame(guessword, badguesscount);
        if(guessword == secretword){
            finalresult(1, badguesscount);
            return;
        }
        if(badguesscount == 7){
            finalresult(0, badguesscount);
            return;
        }
        char guess = guess_in();
        if(contain(secretword, guess))
            update(guessword, secretword, guess);
        else badguesscount ++;
    }while(1);
}

void multiplay(){
    while(1){
        gameplay();
        cout << "Do you want to play again ?\n";
        cout << "Yes - press 1           No - press 2\n";
        int n;
        cin >> n;
        if(n == 2) break;
    }
}

int main()
{
    multiplay();
    return 0;
}
