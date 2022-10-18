#include <iostream>
#include <cctype>
#include <fstream>
#include "edit.h"

int countChar(std::string line, char c){

    std::string in; std::string copy; int bracket; bool loop = false; int result;
    std::ifstream file;
    file.open("bad-code-unindented.cpp");
    if (file.fail()){
        std::cerr << "File cannot be opened for reading" << std::endl;
        exit(1);
    }
    else{
        while (std::getline(file, in)){
            for ( int i = 0; i < in.length(); i++){
                if ( in[i] == c){
                    result += 1;
                }
                else if ( in[i] == ')'){
                    loop = true;
                }
                else if (in[i] == '{'){
                    bracket += 1;
                }
                else if (in[i] == '}' ){
                    bracket -= 1;
                }
            }
            if ( loop == false ){ 
                for ( int b = 0; b < bracket; b++){
                    copy += '\t';
                }
            }
            else if ( loop == true ){
                for (int c = 0; c < bracket-1; c++){
                    copy += '\t';
                }
            }
            loop = false;
            copy += in + '\n';
        }
        file.close();
    }

    std::ofstream out;
    out.open("bad-code-indented.cpp");
    if (out.fail()){
        std::cerr << "File cannot be opened for reading" << std::endl;
        exit(1);
    }
    else{
        out << copy;
    }
    out.close();
    
    return result;
}