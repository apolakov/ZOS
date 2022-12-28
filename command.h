//
// Created by alena on 25.12.2022.
//

#ifndef ZOS_COMMAND_H
#define ZOS_COMMAND_H

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

int format(std::vector<std::string> vector1);

void make_dir_table();

void make_fat();

void fill_description(std::string basicString);

void make_fs(std::string basicString);

void mkdir(std::vector<std::string> vector1);

bool contains(std::vector<std::string> vector1, std::string basicString);
void cp(std::vector<std::string> vector1);

void mkdir_absolut(std::string basicString);

void mkdir_relativ(std::string basicString);

#endif //ZOS_COMMAND_H
