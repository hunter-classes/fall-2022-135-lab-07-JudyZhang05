#include <iostream>
#include "edit.h"

int main(){
    std::cout << "\n\nTask A\n"<< removeLeadingSpaces("//bad-code\n\n") << std::endl;
    std::cout << "\nTask B\n" << countChar("//Indent & Count", ';') << std::endl;

    return 0;
}