//
// Created by alena on 25.12.2022.
//

#include "fat.h"
#include <iostream>
#include <vector>
#include "block.h"
#include "command.h"
#include "global.h"


using namespace std;
//int fat[100];
char empty_cluster[4*512] ={0};
description fs_des;
std::fstream subor ("file_name2",  std::ios::in | std::ios::out | std::ios::binary| std::ios::trunc );
int sektors;
int vyuzitelna_kapacita;
int pocet_clusteru;
int fat_start;
int directories_start;
int data_start;
int fat_tabulka_sektoru;
/*
int cluster_size = 4; // v sektoroch
int fat_tabulka_sektoru;
int sektor_size = 512;
char help_sektor[512];
char help_cluster[512*4];

*/


/**
 * nacti_zaklad_fat(char* jmeno)
 * Nacte zakladni udaje o FAT
 * Boot_record, root_directory, fat_table, clusters
 *
 */

void nacti_zaklad_fat(std::string filename) {

/*
    int kapacita = format(1MB);
    int kapacita = 4194304; //celeho disku
    int sektors = kapacita/sektor_size;
    int vyuzitelna_kapacita = (kapacita-512);
    int pocet_clusteru = sektors / cluster_size;
    fat_tabulka_sektoru = 1 + (sizeof(int) * pocet_clusteru) / sektor_size;

    */



    std::vector<string> v;
    v.push_back("format ");
    v.push_back("1MB");



    format(v);

    cout<<"sektors:";
    cout<<sektors<<endl;


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

    subor.seekp(512, std::ios::beg);


    for (int i =0; i< sektors-1; i++){
        subor.write(empty_cluster,512);
    //    cout<<subor.tellp()<<endl;
    }

    fat_start =512;
    subor.seekp(512, std::ios::beg);                    //512
    int buffer[512/sizeof(int)]={0};
    buffer[0]= -2;
    buffer[1]=-1;
    subor.write(reinterpret_cast<const char *>(buffer), 512);

    directories_start = (1+fat_tabulka_sektoru)*sektor_size;
    cout<<endl<<directories_start<<"placevinom:";
    directory_item current;
    strcpy(current.item_name,".");
    current.start_cluster = 1;
    current.size= 0;
    current.isFile=false;

    subor.seekp((1+fat_tabulka_sektoru)*sektor_size); // 1024
    subor.write(reinterpret_cast<const char *>(&current), sizeof(directory_item));

    subor.seekp((1+fat_tabulka_sektoru)*sektor_size+512+32); /// akoze size of directory item ale lepsie aby to vyslo
    directory_item parent;
    strcpy(parent.item_name,"PREBOHAAA");
    parent.start_cluster = 1;
    parent.size= 0;
    parent.isFile=false;
    subor.write(reinterpret_cast<const char *>(&parent), sizeof(directory_item));
/*
    char arr[512];
    read_sector(0,&arr[0]);
*/

/*
    char buff[512];
    for (int i = 0; i < sizeof(buff); i++) {
        buff[i] = 'a';
    }
    write_sector(0, &buff[0]);

    char arr[512];
    read_sector(0,&arr[0]);

 */


    return;
}
int   _from_cluster(int cluster ){
    //sektor = 1 + pocet fat sektoru + (cluster-1) * velikost clusteru
    int sector;
    sector = 1 + fat_tabulka_sektoru + (cluster-1) * cluster_size;
    return sector;
}

int byte_from_sector(int sector){
   int byte = sector * sektor_size;
   return byte;
}

//tu malo byt to pole asi vyreturnovane ale C to nevie, tak som to utobila tak ze to pole je public, lebo predpolkadam,ze bude len jedno

void read_sector(int number, char *arr){

    //subor.seekg(sector_start_address + number*sektor_size);
    subor.seekg(number*sektor_size);
    subor.read(arr, sizeof(arr));
};

void write_sector(int number, char *buff){

    subor.seekp(number*sektor_size);
    subor.write(buff, sizeof(buff));
};

/*
void read_sector(int number){

    subor.seekp(number*sektor_size);
    subor.read(const_cast<char *>(reinterpret_cast<const char *>(&help_sektor)), sektor_size);
};
 */

void read_cluster(int number){

    subor.seekp(512+number*cluster_size*sektor_size);
    subor.read(const_cast<char *>(reinterpret_cast<const char *>(&help_cluster)), cluster_size*sektor_size);
};

/*
void write_sector(int number, char buff[512]){

    subor.seekp(number*sektor_size);
    subor.write(const_cast<char *>(reinterpret_cast<const char *>(&buff)), sektor_size);
};
 */

void write_cluster(int number, char buff[512*4]){

    subor.seekp(512+number*sektor_size*cluster_size);
    subor.write(const_cast<char *>(reinterpret_cast<const char *>(&buff)), cluster_size*sektor_size);
};

int next_number(int cluster){
    /*
    precteni dalsiho cisla ve fat tabulce (jako argument je cislo sektoru), ale pozor - cislo clusteru je ve fat_tabulce jako 4B tzn: prectes 1 sektor (512B),
    pretypujes ho na sektor co obsahuje integery (512/4 integeru), sektor ve fat tabulce se spocita: sektor = cluster / (velikost sektoru / sizeof(int)),
    index ve fat tabulce: index = cluster % (velikost sektoru / sizeof(int))
     */

    int sektor = cluster / (sektor_size / sizeof(int));
    int index = cluster%(sektor_size/sizeof(int));

    return index;
}

int read_dir(int cluster){

    /*
    precteni slozky - ctes dokud nenarazis na -1,
     potom stop, pri precteni jednoho clusteru čteš v cyklu od i = 0
     do velikost_clusteru / 32 něco jako: directory_item* item = &buffer[i*32];
     */
    int next;

    do{
        next = next_number(cluster);
        read_cluster(next);


    }while (next=!-1);

    return 0;
}
