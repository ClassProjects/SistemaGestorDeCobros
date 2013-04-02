//
//  TDAFile.h
//  Sistema Gestor de Cobros
//
//  Created by Jorge Caballero on 2/11/13.
//  Copyright (c) 2013 Jorge Caballero. All rights reserved.
//

#ifndef __Sistema_Gestor_de_Cobros__TDAFile__
#define __Sistema_Gestor_de_Cobros__TDAFile__

#include <iostream>
#include <fstream>

using namespace std;

class TDAFile {
    fstream stream;
    string filename;
    size_t size;
    char * buffer;
    
public:
    TDAFile(){
        filename = "";
    }
    TDAFile(string file){
        filename = file;
    }
    bool isEOF();
    bool open(string filename);
    void read(char * buff, int size);
    void write(char * buff, int size);
    bool trunc();
    void flush();
    bool close();
    bool seek(int offset);
    bool isOk();
    bool is_open();
    int tell();
};



#endif /* defined(__Sistema_Gestor_de_Cobros__TDAFile__) */