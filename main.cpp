#include <bits/stdc++.h>

using namespace std;

mt19937 rng;
int ran(int l, int r){
    return l + rng() % (r - l + 1);
}

string chooseword(){
    vector<string> word = {"happy", "sad", "tired", "bored", "good", "bad", "angry"};
    int num = ran(0, 6);
    return word[num];
}

void rendergame(string guessword, int badguesscount){

}

char guess_in(){

}

string update

void gameplay(){
    string secretword = chooseword();
    string guessword = string(secretword.length(), '-');
    int badguesscount = 0;

    do{
        rendergame(guessword, badguesscount);
        char guess = guess_in();
        if(contain(secretword, guess))

    }while(1);
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
