#ifndef FUNC_H
#define FUNC_H

#include <string>
#include <iostream>

int compare(std::string s1, std::string s2){
    FILE *f1;
    if((f1 = fopen(s1.c_str(), "r")) == NULL){
        std:: cout << "Cannot open file" << s1 << std::endl;
        exit(1);
    }
    FILE *f2;
    if((f2 = fopen(s2.c_str(), "r")) == NULL){
        std:: cout << "Cannot open file" << s2 << std::endl;
        exit(1);
    }
    char c1, c2;
    c1 = fgetc(f1);
    c2 = fgetc(f2);
    for(unsigned long i = 1; (c1 != EOF) && (c2 != EOF); i++){
        c1 = fgetc(f1);
        c2 = fgetc(f2);
        if(c1 != c2){
            fclose(f1);
            fclose(f2);
            return 0;
        }
    }
    fclose(f1);
    fclose(f2);
    if((c1 == EOF && c2 != EOF) || (c1 != EOF && c2 == EOF))
        return 0;
    return 1;
}

#endif // FUNC_H
