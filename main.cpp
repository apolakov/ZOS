#include <iostream>
#include <vector>

//#include <list>
#include "block.h"
//#include <fstream>


std::fstream subor ("file_name2",  std::ios::in | std::ios::out | std::ios::binary| std::ios::trunc );
int fat[100];
//std::vector<int> fattable;

//std::vector<std::string> names ;
//int dir_size = 10;
description fs_des;
//int fs_atribut = 6;

//std::ofstream file;
int cluster_size =50;

void nacti_zaklad_fat(std::string meno);


using namespace std;


int main() {

    std::string name= "system";
//    fill_description("blabla");
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
            mkdir2("hello");
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

void mkdir2(string name) {

    directory_item item; // ma to bzt jeden blok... netusim co to znamena

    while( (name).size()<8){
        name = name + "0";
    }
    name = name + "/0";

    item.item_name = name;
    item.isFile= true;
    item.size=50;               /// neviem ci tak fakt
    item.start_cluster = 0;
    //subor.seekp(directory_starts);
   // subor.write(reinterpret_cast<char *>(&root), sizeof(root));

    cout<< sizeof(directory_item);

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

/**
 * nacti_zaklad_fat(char* jmeno)
 * Nacte zakladni udaje o FAT
 * Boot_record, root_directory, fat_table, clusters
 *
 */

void nacti_zaklad_fat(string filename) {

    std:: string signature="apolakovaaa";

    while( (signature).size()<8){
        signature = signature + "0";
    }
    if( (signature).size()>8){
        signature = signature.substr(0,8);
    }
    fs_des.signature= signature;

    cout<<fs_des.signature;

    subor.write(signature.c_str(), signature.size());

    fs_des.disk_size= 1024;
    subor.write(to_string(fs_des.disk_size).c_str(), sizeof( int));

    fs_des.cluster_size= 50;
    subor.write(to_string(fs_des.cluster_size).c_str(), sizeof( int));

    fs_des.cluster_count= 50;
    subor.write(to_string(fs_des.cluster_count).c_str(), sizeof( int));

    fs_des.fat1_start_address= 200; //for now
    subor.write(to_string(fs_des.fat1_start_address).c_str(), sizeof( int));

    fs_des.data_start_address= 400; //for now6
    subor.write(to_string(fs_des.data_start_address).c_str(), sizeof( int));


    //fat
    for (int i =0; i< sizeof(fat); i++){
        char ch = '-';
     //   subor.seekp (subor.tellp());
        subor.write(reinterpret_cast<char *>(&ch), sizeof(ch));

    }

    //directory items
    int directory_starts = subor.tellp();
    for (int i =0; i< 300; i++){
        char ch = '+';
        //   subor.seekp (subor.tellp());
        subor.write(reinterpret_cast<char *>(&ch), sizeof(ch));

    }



    //data
    for (int i =0; i< 300; i++){
        char ch = '*';

        subor.write(reinterpret_cast<char *>(&ch), sizeof(ch));

    }
aa* a  = new aa();

    subor.write(reinterpret_cast<const char *>(a), sizeof(aa));
    //"root", true, 50,directory_starts
    directory_item* root = new directory_item(); // ma to bzt jeden blok... netusim
   /* root.item_name = "root0000/0";
    root.isFile= true;
    root.size=50;
    root.start_cluster = 0;*/
    subor.seekp(directory_starts);
    subor.write(reinterpret_cast<char *>(root), sizeof(directory_item));
/*
    string output;
    cout<<output;
    subor.read(reinterpret_cast<char *>(&output),sizeof(root));
    */
    cout<< sizeof(directory_item);
    cout<< sizeof(aa);

    subor.seekp(0);
    string raja;

    while(!subor.eof()){
        subor>>raja;
        cout<< raja<<endl;
    }

    return;
}


