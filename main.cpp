#include <iostream>
#include <vector>
#include <list>
#include "block.h"
#include <fstream>

std::fstream f;
std::fstream subor ("file_name2",  std::ios::in | std::ios::out | std::ios::binary| std::ios::trunc );
int fat[100];
//std::vector<int> fattable;

//std::vector<std::string> names ;
//int dir_size = 10;
description fs_des;
//int fs_atribut = 6;

//std::ofstream file;


void nacti_zaklad_fat(std::string meno);


using namespace std;


int main() {

    std::string name= "system";
    fill_description("blabla");
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
/*
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
    */

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

    fill_description(basicString);
    make_dir_table();
    make_fat();
}

void make_fat() {

}

void fill_description(string basicString) {

    /*
    fs_des.signature="apolakov";
    fs_des.disk_size= 1024;
    fs_des.cluster_size = sizeof (directory_item)*3;
    fs_des.cluster_count= 50;
    fs_des.fat_count = 100;
    fs_des.fat1_start_address = 200;
    fs_des.data_start_address = 400;
     */



}



void make_dir_table(){
/*
    directory_item root;
    root.size=dir_size;
    root.isFile= false;
    root.item_name = "root";
    root.start_cluster = fs_atribut+1;
    */

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
    subor.write(reinterpret_cast<char*>(&fs_des.signature), sizeof(fs_des.signature.substr(0,8)));

    subor.seekp (subor.tellp());
    fs_des.disk_size= 1024;
    subor.write(reinterpret_cast<char*>(& fs_des.disk_size), sizeof( fs_des.disk_size));

    subor.seekp (subor.tellp());
    fs_des.cluster_size= 50;
    subor.write(reinterpret_cast<char*>(&fs_des.cluster_size), sizeof(fs_des.cluster_size));

    subor.seekp (subor.tellp());
    fs_des.cluster_count= 50;
    subor.write(reinterpret_cast<char*>(&fs_des.cluster_count), sizeof(fs_des.cluster_count));


    subor.seekp (subor.tellp());
    fs_des.fat1_start_address= 200; //for now
    subor.write(reinterpret_cast<char*>(&fs_des.fat1_start_address), sizeof(fs_des.fat1_start_address));

    subor.seekp (subor.tellp());
    fs_des.data_start_address= 400; //for now
    subor.write(reinterpret_cast<char*>(&fs_des.data_start_address), sizeof(fs_des.data_start_address));



    //fat
    for (int i =0; i< sizeof(fat); i++){
        char ch = '-';
        subor.seekp (subor.tellp());
        subor.write(reinterpret_cast<char *>(&ch), sizeof(ch));

    }


    /*
    long pos;

    fstream subor ("file_name2",  ios::in | ios::out | ios::binary| ios::trunc );
    subor.write( reinterpret_cast<char*>(&fs_des), sizeof(fs_des) );

    for(int i =0; i<fs_des.fat_count; i++){
        fattable.push_back(-5);
    }

    pos = subor.tellp();
    subor.seekp (pos);
    subor.write( reinterpret_cast<char*>(&fattable), sizeof(int)*fs_des.fat_count );

    for(int i =0; i<fs_des.cluster_count; i++){
        cluster c;
        std::vector<directory_item>v;
        int dir_in_cl= fs_des.cluster_size/sizeof(directory_item);

        for(int j =0; j<dir_in_cl; j++) {
            directory_item d;
            v.push_back(d);
        }
        c.dire=v;

        subor.write( reinterpret_cast<char*>(&v), sizeof(int)*sizeof(v));
    }

    for(int i =0; i<(fs_des.disk_size-(fs_des.cluster_size*fs_des.cluster_count)-sizeof(fattable)-sizeof(description));i++){
        subor.write( reinterpret_cast<char*>(-9), sizeof(int));
    }

    

    pos = subor.tellp();
    subor.seekp (pos);

    file.close();
     */
    return;
}



