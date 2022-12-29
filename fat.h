//
// Created by alena on 25.12.2022.
//

#ifndef ZOS_FAT_H
#define ZOS_FAT_H

#include <string>


void read_sector(int number, char *arr);

void write_sector(int number, char *arr);



void nacti_zaklad_fat(std::string meno);


#endif //ZOS_FAT_H
