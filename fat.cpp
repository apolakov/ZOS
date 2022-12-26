//
// Created by alena on 25.12.2022.
//

#include "fat.h"
#include <iostream>
#include <vector>
#include "block.h"

using namespace std;
//int fat[100];
char empty_cluster[4*512] ={0};
description fs_des;
std::fstream subor ("file_name2",  std::ios::in | std::ios::out | std::ios::binary| std::ios::trunc );


/**
 * nacti_zaklad_fat(char* jmeno)
 * Nacte zakladni udaje o FAT
 * Boot_record, root_directory, fat_table, clusters
 *
 */

void nacti_zaklad_fat(std::string filename) {

    int sektor_size = 512;
    int cluster_size = 4; // v sektoroch
    int kapacita = 4194304; //celeho disku
    int sektors = kapacita/sektor_size;
    int vyuzitelna_kapacita = (kapacita-512);
    int pocet_clusteru = sektors / cluster_size;
    int fat_tabulka_sektoru = 1 + (sizeof(int) * pocet_clusteru) / sektor_size;


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

    fs_des.disk_size= sektors;
    //subor.write(std::to_string(fs_des.disk_size).c_str(), sizeof( int));

    subor.write( reinterpret_cast<char*>(&fs_des.disk_size), sizeof(fs_des.disk_size) );


    fs_des.cluster_size= cluster_size;
    subor.write( reinterpret_cast<char*>(&fs_des.cluster_size), sizeof(fs_des.cluster_size) );
    //subor.write(std::to_string(fs_des.cluster_size).c_str(), sizeof( int));

    fs_des.cluster_count= pocet_clusteru;
    subor.write( reinterpret_cast<char*>(&fs_des.cluster_count), sizeof(fs_des.cluster_count) );
    //subor.write(std::to_string(fs_des.cluster_count).c_str(), sizeof( int));

  //  fs_des.fat1_start_address= 512; //for now
  //  subor.write(std::to_string(fs_des.fat1_start_address).c_str(), sizeof( int));

  //  fs_des.data_start_address= 400; //for now6
    //subor.write(std::to_string(fs_des.data_start_address).c_str(), sizeof( int));



    subor.seekp(512, std::ios::beg);

    for (int i =0; i< sektors-1; i++){

        //   subor.seekp (subor.tellp());
        subor.write(empty_cluster,512);

    }

    subor.seekp(512, std::ios::beg);
    int buffer[512/sizeof(int)]={0};
    buffer[0]= -2;
    buffer[1]=-1;
    subor.write(reinterpret_cast<const char *>(buffer), 512);

    directory_item current;
    strcpy(current.item_name,".");
    current.start_cluster = 1;
    current.size= 0;
    current.isFile=false;
    subor.seekp((1+fat_tabulka_sektoru)*sektor_size); // urobit funkciu s tzm y discirdu
    subor.write(reinterpret_cast<const char *>(&current), sizeof(directory_item));

    subor.seekp((1+fat_tabulka_sektoru)*sektor_size+32); /// akoze size of directory item ale lepsie aby to vyslo
    directory_item parent;
    strcpy(parent.item_name,"..");
    parent.start_cluster = 1;
    parent.size= 0;
    parent.isFile=false;
    subor.write(reinterpret_cast<const char *>(&parent), sizeof(directory_item));



    return;
}
