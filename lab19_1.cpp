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

void importDataFromFile(string filename,vector<string> &names,vector<int> &scores,vector<char> &grades){
    ifstream text("name_score.txt");
    char format[]="%[^:]: %d %d %d";
    string line;
    char name[100];
    int score1,score2,score3;
    while(getline(text,line)){
        sscanf(line.c_str(),format,name,&score1,&score2,&score3);
        scores.push_back(score1+score2+score3);
        names.push_back(name);
        grades.push_back(score2grade(score1+score2+score3));
	}
}

void getCommand(string &c,string &k){
	cout<<"Please input your command: ";
    char format[]="%s %[^\n]";
    string text;
    char com[20],key[100];
    getline(cin,text);
    sscanf(text.c_str(),format,com,key);
    c = com;
    k = key;
}

void searchName(vector<string> names,vector<int> scores,vector<char> grades,string key){
    cout << "---------------------------------\n";
    bool ch=0;
    for(unsigned int i=0;i<scores.size();i++){
        if(key==toUpperStr(names[i])){
             ch=1;
            cout<< names[i]<<"'s score = "<<scores[i]<<endl;
            cout<< names[i]<<"'s grade = "<<grades[i]<<endl;
            break;
        }
    }
    if(ch==0) cout<<"Cannot found."<<endl;
    cout << "---------------------------------\n";
}

void searchGrade(vector<string> names,vector<int> scores,vector<char> grades,string key){
    cout << "---------------------------------\n";
    for(unsigned int i=0;i<scores.size();i++){
        if(key[0]==grades[i]){
            cout<< names[i]<<" ("<<scores[i]<<")"<<endl;
        }
    }
    cout << "---------------------------------\n";
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