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
extern int directories_start;
extern std::fstream subor;

bool sector_contains_directory(int i, char *string);

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
    fat_tabulka_sektoru = 1 + (sizeof(int) * (cluster_size*sektor_size));
    cout<<endl<<"fattabulka_sektoru"<<fat_tabulka_sektoru<<endl;
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
/*
    int place = directories_start;

    cout<<endl<<place<<"place";
    cout<<place+cluster_size*sektor_size<<"place2";
    for(int i = place;i<place+(cluster_size*sektor_size);i=i+32){


        subor.seekp(place);
        char a;
        subor.read(reinterpret_cast<char *>(&a), sizeof(char));
        cout<<a<<endl;
        if(a=='.'){
            cout<<endl<<"som v czkle";
            directory_item dir;
            strcpy(dir.item_name,"file1");
            dir.start_cluster = 1;
            dir.size= 0;
            dir.isFile=false;

            subor.write(reinterpret_cast<const char *>(&dir), sizeof(directory_item));
            cout<<"uspesne yzapisane na poziciu>"<<place;
            break;
        }
    }
    */


    /*
    std::vector<std::string>::iterator it = vector1.begin();
    it++;
    std::string path =  *it;
    char first = path.front();

    if (first=='/') {

       char* str = const_cast<char *>(path.c_str());
        char *ptr; // declare a ptr pointer
        ptr = strtok(str, " / "); // use strtok() function to separate string using comma (,) delimiter.
        while (ptr != NULL)
        {

            cout << ptr  << endl; // print the string token
           if ( !sector_contains_directory(0,ptr)){
               cout<<"CESTA NEEXISTUJE";
               break;
           }
            ptr = strtok (NULL, " / ");


        }




    }
     */
   // else mkdir_relativ(path);



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

bool sector_contains_directory(int poradie, char *string) {

    int first_item = directories_start+poradie*cluster_size;
    int last_item =  directories_start+poradie*cluster_size+ (cluster_size*sektor_size);

    for (int i = first_item; i< last_item;i=i+32 ){

        cout<<i<<endl;

        subor.seekp(i);
        char *nazov;
        subor.read(nazov, 8);
        if(nazov==string){
            return true;
        }
    }

    return false;
}

/*
 * určí či je vo vektore zadaný príkaz
 */
bool contains(std::vector<std::string> v, std::string name) {

    if (std::count(v.begin(), v.end(), name)) {
        return true;
    }
    else {
        return false;
    }
    return false;
}
