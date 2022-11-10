#include <bits/stdc++.h>
#include <string>
#include <iostream>  
#include <vector>

// priklad - verze 2022-01
// jedná se o zjednodušený školní filesystém pseudoFAT
// jde jen o příklad, vlastní datové struktury si můžete upravit


// specialni znacky ve FAT tabulce
const int FAT_UNUSED = INT_MAX - 1;
const int FAT_FILE_END = INT_MAX - 2;
const int FAT_BAD_CLUSTER = INT_MAX - 3;



struct description {
    char signature[9];              //login autora FS
    int disk_size;              //celkova velikost VFS
    int cluster_size;           //velikost clusteru
    int cluster_count;          //pocet clusteru
    int fat_count;        	    //pocet polozek kazde FAT tabulce
    int fat1_start_address;	    //adresa pocatku FAT1 tabulky
    int fat2_start_address;     //adresa pocatku FAT2 tabulky
    int data_start_address;     //adresa pocatku datovych bloku (hl. adresar)  
};




struct directory_item {
    char item_name[13];              //8+3 + /0 C/C++ ukoncovaci string znak
    bool isFile;		     //identifikace zda je soubor (TRUE), nebo adresář (FALSE)
    int size;                    //velikost souboru, u adresáře 0 (bude zabirat jeden blok)
    int start_cluster;           //počáteční cluster položky
};

int main()
{
	
	std::string s;
	std::string beg;
  
     
	getline(std::cin, s);// using getline for user input
    
    std::vector<std::string>v;
    v.push_back("");
    
    int counter = 0;
    int i =0;
    for (i; i<s.length(); i++){
    	char a = s.at(i);
    	if(a!=32){
    		v[counter]= v[counter]+a;
    		std::cout << "nerovnam sa 0" << std::endl;
		}
		if(a==32){
			v.push_back("");
			counter++;
			std::cout << "rovnam sa 0"<< std::endl;
		}
	}
	
    for (auto element : v) {
        std::cout << element << std::endl;
    }
    
    
//	beg =  s.substr(0, 3);
  
  
  
  
  
    // Print output
//    std::cout << beg;

}

//vector<string> split (std::string str, char seperator)  
//{  
   
//}  