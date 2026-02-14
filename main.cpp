#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

void quiz(string username){
    ifstream file("questions.txt");

    string question, opt1, opt2, opt3, opt4;
    int correct, score=0, userAns;

    while(getline(file, question)){
        getline(file, opt1);
        getline(file, opt2);
        getline(file, opt3);
        getline(file, opt4);
        file>>correct;

        cout<<endl<<question<<endl;
        cout<<"1. "<<opt1<<endl;
        cout<<"2. "<<opt2<<endl;
        cout<<"3. "<<opt3<<endl;
        cout<<"4. "<<opt4<<endl;

        cout<<" Your Answer: ";
        cin>> userAns;

        if(userAns == correct){
            cout<<"Correct!!"<<endl;
            score += 10;
        }else{
            cout<<"Wrong!!"<<endl;
            score -= 2;
        }
    }
    file.close();

    cout<<"Your Final Score: "<<score<<endl;

    ofstream fileScore("score.txt", ios::app);
    fileScore<<username<<": "<<score<<endl;

    fileScore.close();
}

void leaderboard();

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

int main(){
    menu();

    return 0;
}

