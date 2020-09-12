//Noah Johnson
//CSCE 1040.302

#include <stdio.h>

int LiarLiar( int n ) {
	return ( n < 3 ? -1 : 2*(LiarLiar(n-1)+LiarLiar(n-2)));
}//int LiarLiar(int)

int main( ) {
	short n;
	printf( "Number of Liar-Liar numbers to display (1-23): " );
	scanf( "%hd", &n );
	printf( "123456789012345678901234567890\n" );
	for( short i = 1; i <= n; i++ )
		printf( "Liar-Liar(%2hd) = %12d\n", i, LiarLiar(i) );
}//main()
