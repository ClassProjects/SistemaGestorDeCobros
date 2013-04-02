//
//  TDAFile.cpp
//  Sistema Gestor de Cobros
//
//  Created by Jorge Caballero on 2/11/13.
//  Copyright (c) 2013 Jorge Caballero. All rights reserved.
//

#include "TDAFile.h"

bool TDAFile::isEOF(){
    return stream.eof();
}

bool TDAFile::open(string filename){
    //Opens File
    stream.open(filename);
    //Returns the size of the file
    stream.seekg(0, ios::end);
    size = stream.tellg();
    stream.seekg (0, ios::beg);
    //Allocate Memory
    buffer = new char [size];
    if (stream.is_open()) {
        return true;
    }
    return false;
}

void TDAFile::read(char * buff, int siz){
    //Reads the file and allocates the read to the array "buff"
    stream.read(buff, siz);
}

void TDAFile::write(char * buff, int siz){
    //Writes Buffer to File.
    stream.write (buff,siz);
}

bool TDAFile::trunc(){
    
}

void TDAFile::flush(){
    stream.flush();
}

bool TDAFile::close(){
    stream.close();
}

bool TDAFile::seek(int offset){
    stream.seekg(offset);
}

bool TDAFile::isOk(){
    return stream.good();
}

bool TDAFile::is_open(){
    return stream.is_open();
}

int TDAFile::tell(){
    return stream.tellg();
}