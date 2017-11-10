//
//  main.cpp
//  ProgrammingCompetition
//
//  Created by Julien Esposito on 11/10/17.
//  Copyright © 2017 Julien Esposito. All rights reserved.
//

#include <iostream>

#include <stdio.h> // At least for NULL and FILE
#include <string.h> // for memset
#include <iostream> // for cout, cin
#include <string> // for std::string
#include <fstream> // for std::fstream

#define FILENAME "Cupcakes.txt"

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
std::ifstream g_filestream;

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void CreateNumberContentToAFile( const char* filename )
{
    const char* lineEnding = "\r\n";
    FILE* f = fopen( filename, "w" ); // we are opening our file in write only mode
    fprintf( f, "3%s", lineEnding );
    fprintf( f, "1 2  3   4    5     6%s", lineEnding );
    fclose( f ); // In order to store our changes, we must close the file
    return;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void RedirectCinToReadFromFileAndNotFromConsole()
{
    const char filename[] = FILENAME;
    CreateNumberContentToAFile( filename );
    
    g_filestream.open( filename );
    std::cin.rdbuf( g_filestream.rdbuf() );
//    std::string line;
//    std::cin >> line;
//    std::cout << "First Line From File is <" << line << ">" << std::endl;
    return;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int main(int argc, const char * argv[]) {
    RedirectCinToReadFromFileAndNotFromConsole();
    std::string line;
    std::cin >> line;
    std::cout << "First Line From File is <" << line << ">" << std::endl;
    return 0;
}

