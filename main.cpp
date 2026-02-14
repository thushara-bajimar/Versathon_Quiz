#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

void menu(){
    string username;
    int choice;

    cout<< " ***** Welcome To YOUR QUIZ PLATFORM !!! ***** " << endl;
    cout<< "Enter your USERNAME: ";
    cin>> username;

    cout<< "1. Start Quiz"<<endl;
    cout<< "2. Show Leaderboard"<<endl;
    cout<< "Enter your choice: ";
    cin>> choice;

    if(choice == 1){
        quiz(username);
    }else if(choice == 2){
        leaderboard();
    }
}

void quiz(string username);
void leaderboard();

int main(){
    menu();

    return 0;
}

