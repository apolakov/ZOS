//
// Created by alena on 15.11.2022.
//

#ifndef ZOS_BLOCK_H
#define ZOS_BLOCK_H

#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <vector>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
//#include <wsman.h>


const int32_t FAT_UNUSED = INT32_MAX - 1;
const int32_t FAT_FILE_END = INT32_MAX - 2;
const int32_t FAT_BAD_CLUSTER = INT32_MAX - 3;



struct description {
    std::string signature;              //login autora FS
    int32_t disk_size;              //celkova velikost VFS
    int32_t cluster_size;           //velikost clusteru
    int32_t cluster_count;          //pocet clusteru
    int32_t fat_count;        	    //pocet polozek kazde FAT tabulce
    int32_t fat1_start_address;	    //adresa pocatku FAT1 tabulky
   // int32_t fat2_start_address;     //adresa pocatku FAT2 tabulky
    int32_t data_start_address;     //adresa pocatku datovych bloku (hl. adresar)
};




struct directory_item {
    std::string item_name;              //8+3 + /0 C/C++ ukoncovaci string znak
    bool isFile;		     //identifikace zda je soubor (TRUE), nebo adresář (FALSE)
    int32_t size;                    //velikost souboru, u adresáře 0 (bude zabirat jeden blok)
    int32_t start_cluster;           //počáteční cluster položky
};

void make_fs(std::string basicString);

void mkdir(std::vector<std::string> v);

bool contains(std::vector<std::string> vector1, std::string basicString);
void cp(std::vector<std::string> vector1);

void mv(std::vector<std::string> vector1);

void rm(std::vector<std::string> vector1);

void rmdir(std::vector<std::string> vector1);

void ls(std::vector<std::string> vector1);

void cat(std::vector<std::string> vector1);

void cd(std::vector<std::string> vector1);

void pwd(std::vector<std::string> vector1);

void info(std::vector<std::string> vector1);

void incp(std::vector<std::string> vector1);

void outcp(std::vector<std::string> vector1);

void load(std::vector<std::string> vector1);

void format(std::vector<std::string> vector1);

void make_dir_table();

void make_fat();

void fill_description(std::string basicString);
#endif //ZOS_BLOCK_H
