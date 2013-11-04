#include "string"
#include "map"
#include "vector"
#include "fstream"
#include "iostream"
#include "algorithm"
#include "words.h"

void read_book(				const char* fail_name , std::map< std::string , int > &wor ) ;
void print_result(			const char* fail_name , std::vector< words > wors ) ;
void exception_bad_word(	const char* fail_name , std::map< std::string , int > &wor ) ;
void ask(					std::vector<words> wors , std::map< std::string , int > &wor );
void create_result_words(	std::vector<words> &words , std::map< std::string , int > wor ) ;