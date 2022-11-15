#include <iostream>
#include <vector>
#include <list>
#include "block.h"

std::vector<std::string> names = {};
int dir_size = 10;

using namespace std;

int main() {

    std::string name= "system";

    make_fs( name);
    std::string s;
    std::string beg;

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
        if (v.front() == "exit") {
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

void format(vector<string> vector1) {

}

void load(vector<string> vector1) {

}

void outcp(vector<string> vector1) {

}

void incp(vector<string> vector1) {

}

void info(vector<string> vector1) {

}

void pwd(vector<string> vector1) {

}

void cd(vector<string> vector1) {

}

void cat(vector<string> vector1) {

}

void ls(vector<string> vector1) {

}

void rmdir(vector<string> vector1) {
    if(vector1.size()!=1){
        cout<<"Chybny pocet parametrov";
        return;
    }

    std::vector<std::string>::iterator it = vector1.begin();
    it++;
    std::string s1 =  *it;
    s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());


}

void rm(vector<string> vector1) {
    if(vector1.size()!=1){
        cout<<"Chybny pocet parametrov";
        return;
    }

    std::vector<std::string>::iterator it = vector1.begin();
    it++;
    std::string s1 =  *it;
    s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());


}

void mv(vector<string> vector1) {
    if(vector1.size()!=2){
        cout<<"Chybny pocet parametrov";
        return;
    }

    std::vector<std::string>::iterator it = vector1.begin();
    it++;
    std::string s1 =  *it;
    s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());
    it++;
    std::string s2 =  *it;
    s2.erase(remove(s2.begin(), s2.end(), ' '), s2.end());

}

void cp(vector<string> vector1) {

    if(vector1.size()<3||vector1.size()>3){
        cout<<"Chybny pocet parametrov";
        return;
    }

    std::vector<std::string>::iterator it = vector1.begin();
    it++;
    std::string s1 =  *it;
    s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());
    it++;
    std::string s2 =  *it;
    s2.erase(remove(s2.begin(), s2.end(), ' '), s2.end());

    cout <<"vybrali ste si prikaz cp"<<endl;
    cout <<"parameter s1 je "<<s1;
    cout <<" a parameter s2 je "<<s2<<endl;
}

void mkdir(vector<string> v) {

    if(v.size()!=2){
        cout<<"Chybny pocet parametrov";
        return;
    }

    std::vector<std::string>::iterator it = v.begin();
    it++;
    std::string name =  *it;
    name.erase(remove(name.begin(), name.end(), ' '), name.end());
    cout<<name;

    std::string cesta = "/odkial/mamzobrat/cestu"; //????????
    directory_item dir;

    if(cesta == ""){
        cout <<"PATH NOT FOUND"<<endl;
        return;
    }
    if (contains(names, name)){
        cout <<"EXIST"<<endl;
        return;
    }
    //este dalsich milion veci ale netusim akych
    cout <<"OK"<<endl;
    dir.item_name = "name";
    dir.isFile = false;
    dir.size =dir_size;
    dir.start_cluster;

}

bool contains(vector<string> v, string name) {

    if (std::count(v.begin(), v.end(), name)) {
        return true;
    }
    else {
      return false;
    }
    return false;
}

void make_fs(string basicString) {
    description fs;
    fs.signature="apolakov";
    fs.disk_size= 100;
    fs.cluster_size = 10;
    fs.cluster_count= 5;
    fs.fat_count = 5;
    fs.fat1_start_address = 0b11000000;
    fs.data_start_address = 0b11010100;
}
