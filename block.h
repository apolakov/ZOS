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

    char item_name[11];              //8+3 + /0 C/C++ ukoncovaci string znak
    bool isFile;		        //identifikace zda je soubor (TRUE), nebo adresář (FALSE)
    int32_t size;                    //velikost souboru, u adresáře 0 (bude zabirat jeden blok)
    int32_t start_cluster;           //počáteční cluster položky
};

struct cluster {
    std::vector<directory_item> dire ;
};




#endif //ZOS_BLOCK_H
