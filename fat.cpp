//
// Created by alena on 25.12.2022.
//

#include "fat.h"
#include <iostream>
#include <vector>
#include "block.h"

using namespace std;
int fat[100];
description fs_des;
std::fstream subor ("file_name2",  std::ios::in | std::ios::out | std::ios::binary| std::ios::trunc );


/**
 * nacti_zaklad_fat(char* jmeno)
 * Nacte zakladni udaje o FAT
 * Boot_record, root_directory, fat_table, clusters
 *
 */

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
