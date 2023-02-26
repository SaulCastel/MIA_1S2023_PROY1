#include "mkdisk.h"
#include <string.h>
#include <iostream>

int size;
std::string path;
std::string fit = "ff";
char unit = 'm';

void mkdisk(char *arguments){
    char *argument = strtok(NULL, " ");
    while(argument != NULL){
        std::string tmp_str = argument;
        std::string param = "";
        std::string value = "";
        int split_index;
        char c;
        for(int i=0; i < tmp_str.length(); i++){
            c = tmp_str.at(i);
            if(c == '='){
                split_index = i;
                break;
            }
            param += c;
        }
        for(int i=split_index; i < tmp_str.length(); i++){
            c = tmp_str.at(i);
            value += c;
        }
        if(param == ">size"){
            size = stoi(value);
        }
        else if(param == ">path"){
            path = value;
        }
        else if(param == ">fit"){
            fit = value;
        }
        else if(param == ">unit"){
            unit = value.at(0);
        }
        param = strtok(NULL, " ");
    }
    FILE *disk = fopen(path.c_str(), "wb");
    fseek(disk, 0, SEEK_SET);
    char data[1000]= "";
    for (int i = 0; i < size; i++)
    {
        fwrite(&data, sizeof(data), 1, disk);
    }
    fclose(disk);
}