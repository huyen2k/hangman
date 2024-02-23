#include <bits/stdc++.h>

using namespace std;

mt19937 rng;
int ran(int l, int r){
    return l + rng() % (r - l + 1);
}

string chooseword(){
    rng.seed(time(0));
    vector<string> word = {"happy", "sad", "tired", "bored", "good", "bad", "angry"};
    int num = ran(0, 6);
    return word[num];
}

void rendergame(string guessword, int badguesscount){
    vector<string> render = {
    " -----------------\n  |              \n  |              \n  |             \n  |             \n  |                 \n  |                \n-----",
    " -----------------\n  |              |\n  |              \n  |             \n  |             \n  |                 \n  |                \n-----",
    " -----------------\n  |              |\n  |              o\n  |             \n  |             \n  |                 \n  |                \n-----",
    " -----------------\n  |              |\n  |              o\n  |              |\n  |             \n  |                 \n  |                \n-----",
    " -----------------\n  |              |\n  |              o\n  |             /|\n  |             \n  |                 \n  |                \n-----",
    " -----------------\n  |              |\n  |              o\n  |             /|\\ \n  |             \n  |                 \n  |                \n-----",
    " -----------------\n  |              |\n  |              o\n  |             /|\\ \n  |             /  \n  |                 \n  |                \n-----",
    " -----------------\n  |              |\n  |              o\n  |             /|\\ \n  |             / \\ \n  |                 \n  |                \n-----"
    };
    cout << render[badguesscount] << '\n';
    cout << "Secretword : " << guessword << '\n';
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
        if(guessword == secretword) {
            cout << "Congratulations!\n";
            break;
        }
        if(badguesscount == 7){
            cout << "You lose!\n";
            break;
        }
        char guess = guess_in();
        if(contain(secretword, guess))
            update(guessword, secretword, guess);
        else badguesscount ++;
    }while(1);
}

int main()
{
    gameplay();
    return 0;
}
