#include <iostream>
#include <cctype>
#include <fstream>
#include "edit.h"

//woah cool code

std::string removeLeadingSpaces(std::string line){
    std::string word; bool loop = false;

    while (std::cin >> word){
        line += word + ' ';
        //std::cout << word << std::endl;
        for (int i = 0; i < word.length(); i++){
            if (word[i] == '{' || word[i] == '}' || word[i] == '!' || word[i] == '>'){
                line += '\n';
            }
            else if (word[i] == '('){
                loop = true;
            }
            else if (word[i] == ')'){
                loop = false;
            }
            if (word[i] == ';' && loop == false){
                line += '\n';
            }
        }
    }

    std::ofstream fix;

    fix.open("bad-code-unindented.cpp");
    
    if (fix.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    else{
        fix << line;
    }
    fix.close();

    return line;
}


/*
    while (std::cin >> word){
        line += word + ' ';
        for (int i = 0; i < word.length(); i++){
            if (word[i] == '{' || word[i] == '}' || word[i] == '!'){
                line += '\n';
            }
        }
        if (word == "1;" || word == "i;" || word == "endl;" || word ==  "<iostream>"){
            line += '\n';
        }
        //std::cout << word << std::endl;
        }
        
    return line;
}


int main(){
     std::cout << removeLeadingSpaces("//bad-code\n\n")<<std::endl;
     return 0;
}

*/