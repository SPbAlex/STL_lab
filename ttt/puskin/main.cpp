#include "work.h"

int main()
{
	std::map< std::string , int > wor ;
	std::vector<words> wors ;

	read_book( "in.txt" , wor ) ;
	exception_bad_word( "bad.txt" , wor ) ;
	
	create_result_words( wors , wor ) ;
	ask( wors , wor ) ;
	print_result( "out.txt" , wors ) ;

	return 0 ;
}