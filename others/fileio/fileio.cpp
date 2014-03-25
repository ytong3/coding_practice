#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;
int main(){
    
    unordered_map<string,int> accounts;
    
    //ifstream readfile("./config.txt");
    ifstream readfile;
    readfile.open("./config.txt");
    ofstream newfile("copy.txt");
    string line;
    string acc;
    int sum;
    if (readfile.is_open()){
        while (getline(readfile,line)){
            //do something to the line
            istringstream parser(line);
            istringstream (line) >> acc;
            parser>>acc>>sum;
            
            cout<<acc<<" "<<sum<<endl;
            //sscanf(line.c_str(),"%s %d",acct,&sum);
            accounts.insert(make_pair(acc,sum));
            newfile<<line<<'\n';
        }
        readfile.close();
        newfile.close();
    }else
        cout<<"Failed to open file\n";
    cout<<"Queries"<<endl; 
    cout<<accounts["1004"]<<endl;
    
    //let's do it word-by-word
    int buffer1;
    int buffer2;
    readfile.open("config.txt");
    while((readfile.good())){
        readfile>>buffer1>>buffer2;
        cout<<buffer1<<" "<<buffer2<<endl;
    }
    readfile.close();

    
}
