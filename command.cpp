//
// Created by alena on 25.12.2022.
//
#include <iostream>
#include <vector>
#include "block.h"
#include "command.h"
#include "fat.h"
#include "global.h"
//int fat[100];
//description fs_des;
//std::fstream subor ("file_name2",  std::ios::in | std::ios::out | std::ios::binary| std::ios::trunc );
extern int sektors;
extern int vyuzitelna_kapacita;
extern int pocet_clusteru;
extern int fat_start;
extern int directories_start;
extern int data_start;
extern int fat_tabulka_sektoru;

using namespace std;

int format(std::vector<std::string> vector1) {

    if(vector1.size()!=2){
        std::cout<<"CAN NOT CREATE FILE ...Chybny pocet parametrov";
        cout<<vector1.size();
        return-1;
    }

    std::vector<std::string>::iterator it = vector1.begin();
    it++;
    std::string s1 =  *it;

    int size = stoi(s1);


    size = size*1024*4*1024;
   // cout<<"size>>>>";
   // cout<<size<<endl;
  //  size = 5;

    cout<<size;
    sektors = size/sektor_size;




    vyuzitelna_kapacita = (size-512);
    pocet_clusteru = sektors / cluster_size;
    fat_tabulka_sektoru = 1 + (sizeof(int) * pocet_clusteru) / sektor_size;
    cout<<"sektors:";
    cout<<sektors<<endl;
    cout<<"OK";
return 0;
}

void load(std::vector<std::string> vector1) {

}

void outcp(std::vector<std::string> vector1) {

}

void incp(std::vector<std::string> vector1) {

}

void info(std::vector<std::string> vector1) {

}

void pwd(std::vector<std::string> vector1) {

}

void cd(std::vector<std::string> vector1) {

}

void cat(std::vector<std::string> vector1) {

}

void ls(std::vector<std::string> vector1) {

}

void rmdir(std::vector<std::string> vector1) {
    if(vector1.size()!=1){
        std::cout<<"Chybny pocet parametrov";
        return;
    }

    std::vector<std::string>::iterator it = vector1.begin();
    it++;
    std::string s1 =  *it;
    s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());


}

void rm(std::vector<std::string> vector1) {
    if(vector1.size()!=1){
        std::cout<<"Chybny pocet parametrov";
        return;
    }

    std::vector<std::string>::iterator it = vector1.begin();
    it++;
    std::string s1 =  *it;
    s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());


}

void mv(std::vector<std::string> vector1) {
    if(vector1.size()!=2){
        std::cout<<"Chybny pocet parametrov";
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

void cp(std::vector<std::string> vector1) {

    if(vector1.size()<3||vector1.size()>3){
        std::cout<<"Chybny pocet parametrov";
        return;
    }

    std::vector<std::string>::iterator it = vector1.begin();
    it++;
    std::string s1 =  *it;
    s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());
    it++;
    std::string s2 =  *it;
    s2.erase(remove(s2.begin(), s2.end(), ' '), s2.end());

    std::cout <<"vybrali ste si prikaz cp"<<std::endl;
    std::cout <<"parameter s1 je "<<s1;
    std::cout <<" a parameter s2 je "<<s2<<std::endl;
}

void mkdir(std::vector<std::string> vector1) {

    if(vector1.size()!=2){
        std::cout<<"CAN NOT CREATE FILE ...Chybny pocet parametrov";
        cout<<vector1.size();
        return;
    }

    std::vector<std::string>::iterator it = vector1.begin();
    it++;
    std::string path =  *it;

    string str1 ("\\");
    string str2 ("/");

    if (((path.find(str1))||(path.find(str2))) != string::npos) {
        mkdir_absolut(path);
    }
    else mkdir_relativ(path);



    /*
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

    std::cout<< sizeof(directory_item);
*/
}

void mkdir_relativ(string basicString) {

}

void mkdir_absolut(string basicString) {



}

bool contains(std::vector<std::string> v, std::string name) {

    if (std::count(v.begin(), v.end(), name)) {
        return true;
    }
    else {
        return false;
    }
    return false;
}