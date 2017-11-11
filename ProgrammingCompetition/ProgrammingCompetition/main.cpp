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
#include <vector>
#include <list>
#include <sstream>

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
void example_vector_01()
{
    
    std::cout << "Adding to a vector " << std::endl;
    std::list< int > vector_int;
    vector_int.push_back( 1 );
    vector_int.push_back( 2 );
    vector_int.push_back( 3 );
    vector_int.push_back( 4 );
    
    std::cout << "size of vector = " << vector_int.size() << std::endl;
    
    std::cout << "accessing elements (no iterator needed)" << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void indexOf( void )
{
    std::list< int > list_int;
    list_int.push_back( 1 );
    list_int.push_back( 2 );
    list_int.push_back( 3 );
    list_int.push_back( 4 );
    
    int index = 0;
    
    for (auto it = list_int.begin(); it != list_int.end(); ++it, ++index) {
        if( 4 == *it ) {
            std::cout << "Found value at position " << index << std::endl;
            break;
        }
    }
    return;
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
template <typename T> void RemoveElementFromList( std::list< T >& list, const T& value )
{
    size_t size = list.size();
    std::cout << "list size before = " << size  << std::endl;
    for( typename std::list<  T >::iterator it = list.begin(); it != list.end(); it++ ) {
        if( *it == value ) {
            std::cout << "Removing value " << value << std::endl;
            list.remove( value );
            break;
        }
    }
    size = list.size();
    std::cout << "list size after = " << size  << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void PlayingWithCin( void )
{
    while( !std::cin.eof() ) {
        std::string line;
        //        std::cin >> line;
        std::getline(std::cin >> std::ws, line );
        if( !line.empty() )
            std::cout << "current from From File is <" << line << ">" << std::endl;
    }
    
    return;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
std::vector< int > ParseInts( void )
{
    std::vector< int > numbers;
    char separator = ' ';
    
    const char values[] = "10 10 90 30 75 30";
    
    std::istringstream f(values);
    std::string s;
    while (std::getline(f, s, separator )) {
        int i = std::atoi( s.c_str() );
        //std::cout << s << std::endl;
        numbers.push_back(i);
    }
    
    return numbers;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int main(int argc, const char * argv[]) {
    
    // Note to White Supremacist: relevant part starts afer redirect
    RedirectCinToReadFromFileAndNotFromConsole();
    

    PlayingWithCin(  );
    
    example_vector_01();
    
    indexOf(  );
    
    std::list< int > list_OfInts;
    list_OfInts.push_back( 1 );
    list_OfInts.push_back( 2 );
    list_OfInts.push_back( 3 );
    
    RemoveElementFromList< int >( list_OfInts, 2 );
    
    std::vector< int > theInts = ParseInts(  );
    for( int i = 0; i < theInts.size(); i++ ) {
        std::cout << theInts[ i ] << std::endl;
    }
    
    return 0;
}

