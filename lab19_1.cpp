#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string file,vector<string> &names,vector<int> &scores,vector<char> &grades){
    ifstream filename(file.c_str());
    char name[100];
    string line;
    char format[] = {"%[^:]: %d %d %d"};
    int x,y,z;
    while(getline(filename,line)){
        sscanf(line.c_str(),format,&x,&y,&z);
        names.push_back(name);
        scores.push_back(x+y+z);
        grades.push_back(score2grade(x+y+z));
    }
}

void getCommand(string c,string k){
    cout<<"Please input your command: ";
    string 
   
}

void searchName(vector<string> &names,vector<int> &scores,vector<char> &grades,string k){
    int s = names.size();
    for(int i = 0;i<s;i++){
        if(k == toUpperStr(names[i])){
            cout << names[i]<< "'s" <<" score = "<< scores[i] << endl;
            cout << names[i]<< "'s" <<" grade = " << grades[i] << endl;
        }
    }
}

void searchGrade(vector<string> &names,vector<int> &scores,vector<char> &grades,string k){
    int s = names.size();
    for(int i = 0;i<s;i++){
        string y = toUpperStr(""+grades[i]);
        if(k == y) {
            cout << names[i]<< " " << "(" << scores[i] << endl;
           
        }
    }
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}