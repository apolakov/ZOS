#include <iostream>
#include <vector>
#include "block.h"
#include "command.h"
#include "fat.h"

using namespace std;


//int fat[100];
//description fs_des;
//std::fstream subor ("file_name2",  std::ios::in | std::ios::out | std::ios::binary| std::ios::trunc );
int main() {

    std::string name= "system";
    nacti_zaklad_fat(name);
    std::string s;

    for(;;) {
    getline(std::cin, s);
    std::vector<std::string>v;
    v.push_back("");
    int counter = 0;
    int i =0;
    int b = 1;
    for (i; i<s.length(); i++){
        char a = s.at(i);
        if(a!=32){
            b=1;
            v[counter]= v[counter]+a;
        }
        if(a==32){
            if(b!=0){
                b = 0;
                v.push_back("");
                counter++;
            }
        }
    }
        if ((v.front() == "exit")|| (v.front() == "e")){
            break;
        } else if (v.front() == "cp") {
            cp(v);
        } else if (v.front() == "mv") {
            mv(v);
        } else if (v.front() == "rm") {
            rm(v);
        } else if (v.front() == "mkdir") {
            mkdir(v);
        } else if (v.front() == "rmdir") {
            rmdir(v);
        } else if (v.front() == "ls") {
            ls(v);
        } else if (v.front() == "cat") {
            cat(v);
        } else if (v.front() == "cd") {
            cd(v);
        } else if (v.front() == "pwd") {
            pwd(v);
        } else if (v.front() == "info") {
            info(v);
        } else if (v.front() == "incp") {
            incp(v);
        } else if (v.front() == "outcp") {
            outcp(v);
        } else if (v.front() == "load") {
            load(v);
        } else if (v.front() == "format") {
            format(v);
        } else {
            cout << "Chybny prikaz";
        }
    }

    return 0;
}



