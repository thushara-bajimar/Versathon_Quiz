#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
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

void leaderboard(){
    ifstream file("score.txt");

    string username;
    int score;

    vector<pair<string, int>>scores;

    cout<<" *** LEADERBOARD *** "<<endl;
    while(file>>username>>score){
        scores.push_back({username, score});
    }

    for(int i=0 ; i<scores.size() ; i++){
        for(int j=0 ; j<scores.size()-i-1 ; j++){
            if(scores[j].second < scores[j+1].second){
                swap(scores[j], scores[j+1]);
            }
        }
    }

    for(int i=1 ; i<scores.size() ; i++){
        cout<<i<<". "<<scores[i].first<<": "<<scores[i].second<<endl;
    }
    file.close();
}

void menu(){
    string username;
    int choice;

    cout<< " ******* Welcome To YOUR QUIZ PLATFORM !!! ******* " << endl;
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

