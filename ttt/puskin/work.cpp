#include"work.h"
int check_word( char c )
{
	if( ( ( c >= 'À' ) && ( c <= 'ß' ) ) || 
		( ( c >= 'A' ) && ( c <= 'Z' ) ) ||
		( ( c >= 'à' ) && ( c <= 'ÿ' ) ) ||
		( ( c >= 'a' ) && ( c <= 'z' ) ) )
		return 1 ;
	else
		return NULL ;
}
int read_word( FILE* in  , std::string &word )
{
	word.clear() ;

	if( feof( in ) )
		return NULL ;


	char c = getc( in ) ;

	while( check_word( c ) == 0 )
		c = getc( in ) ;


	while( check_word( c ) )
	{
		word.push_back( c ) ;

		if( feof( in ) )
			return NULL ;

		c = getc( in ) ;
	}

	if( feof( in ) )
		return NULL ;
	else
		return 1 ;
}
void read_book( const char* fail_name , std::map< std::string , int > &wor )
{
	std::cout << "READING BOOK " << std::endl ;
	std::string word ;

	FILE* in ;
	fopen_s( &in , fail_name , "r" ) ;

	while( read_word( in , word ) )
	{
		if( feof( in ) )
			break ;
		wor[word]++ ;	
	}

	fclose( in ) ;
}
void print_result( const char* fail_name , std::vector<words> wors )
{
	std::ofstream out ;
	out.open( fail_name ) ;

	for( std::vector< words >::iterator it = wors.begin() ; it != wors.end() ; it++ )
		out<<it->word<<"\t"<<it->lexic<<std::endl ;

	out.close() ;
	std::cout << "Reading Done" << std::endl ;
}
int check_bad_word ( std::string word, std::map< std::string , int > wor )
{
	if( wor[word] == NULL )
		return NULL ;
}
void exception_bad_word( const char* fail_name , std::map< std::string , int > &wor )
{
	std::vector< std::string > bad ;
	std::map< std::string , int > tmp ;

	std::ifstream in ;
	in.open( fail_name ) ;

	std::string word ;
	while ( in >> word )
		bad.push_back( word ) ;
	
	for ( std::vector< std::string >::iterator it_vector = bad.begin() ; it_vector != bad.end() ; it_vector++ )
		if( check_bad_word( *it_vector , wor ) != NULL )
			wor[*it_vector] = NULL ;
}
void ask( std::vector<words> wors , std::map< std::string , int > &wor )
{
	std::cout<<"How mach favorite words you need ?"<<std::endl ;
	int i ;
	std::cin >> i ;

	if( i > wors.size() )
		std::cout<<"Sorry I find only "<< wors.size() <<" words"<<std::endl;

	for( std::vector< words >::iterator it = wors.begin() ; ( it != wors.end() ) && ( i>=0 ) ; it++ , i-- )
		std::cout<<it->lexic<<"\t"<<it->word<<std::endl ;
	
	std::cout<<"Lexicon of you book "<<wors.size()<<" words"<<std::endl;
}
int sorter(words &A, words &B)
{
	return ( A.lexic > B.lexic );
}
void create_result_words( std::vector<words> &wors , std::map< std::string , int > wor )
{	 	
	wors.resize( wor.size() ) ;
	int i = 0 ;
	for ( std::map< std::string , int >::iterator it_wor = wor.begin() ; it_wor != wor.end() ; it_wor++ , i++ )
	{
		wors[i].word = it_wor->first ;
		wors[i].lexic = it_wor->second ;
	}

	std::sort( wors.begin() , wors.end() , sorter ) ;
}