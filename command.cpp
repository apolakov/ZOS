//
// Created by alena on 25.12.2022.
//
#include <iostream>
#include <vector>
#include "block.h"
#include "command.h"
#include "fat.h"
//int fat[100];
//description fs_des;
//std::fstream subor ("file_name2",  std::ios::in | std::ios::out | std::ios::binary| std::ios::trunc );

void format(std::vector<std::string> vector1) {

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

void mkdir2(std::string name) {

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

/**
 * nacti_zaklad_fat(char* jmeno)
 * Nacte zakladni udaje o FAT
 * Boot_record, root_directory, fat_table, clusters
 *
 */
/*
void nacti_zaklad_fat(std::string filename) {

    std:: string signature="apolakovaaa";

    while( (signature).size()<8){
        signature = signature + "0";
    }
    if( (signature).size()>8){
        signature = signature.substr(0,8);
    }
    fs_des.signature= signature;

    std::cout<<fs_des.signature;

    subor.write(signature.c_str(), signature.size());

    fs_des.disk_size= 1024;
    subor.write(std::to_string(fs_des.disk_size).c_str(), sizeof( int));

    fs_des.cluster_size= 50;
    subor.write(std::to_string(fs_des.cluster_size).c_str(), sizeof( int));

    fs_des.cluster_count= 50;
    subor.write(std::to_string(fs_des.cluster_count).c_str(), sizeof( int));

    fs_des.fat1_start_address= 200; //for now
    subor.write(std::to_string(fs_des.fat1_start_address).c_str(), sizeof( int));

    fs_des.data_start_address= 400; //for now6
    subor.write(std::to_string(fs_des.data_start_address).c_str(), sizeof( int));


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
    // root.item_name = "root0000/0";
    // root.isFile= true;
    // root.size=50;
    // root.start_cluster = 0;
    subor.seekp(directory_starts);
    subor.write(reinterpret_cast<char *>(root), sizeof(directory_item));

    subor.seekp(0);
    std::string raja;

    while(!subor.eof()){
        subor>>raja;
        std::cout<< raja<<std::endl;
    }

    return;
}
*/