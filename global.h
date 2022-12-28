//
// Created by alena on 28.12.2022.
//

#ifndef FILE_NAME2_GLOBAL_H
#define FILE_NAME2_GLOBAL_H

const int cluster_size = 4; // v sektoroch
static int fat_tabulka_sektoru;
const int sektor_size = 512;
static char help_sektor[512];
static char help_cluster[512*4];

static int sektors;
static int vyuzitelna_kapacita;
static int pocet_clusteru;



#endif //FILE_NAME2_GLOBAL_H
