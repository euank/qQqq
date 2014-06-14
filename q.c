#include<stdio.h>
#include<stdlib.h>


int main ( int argc , char * * argv ) {
  if ( argc != 2 ) {
    fprintf ( stderr , "Must supply only a filename. Usage: %s <file>" , argv [ 0 ] ) ;
    return -1 ;
  }
  FILE * f = fopen ( argv [ 1 ] , "r" ) ;

  int cells [ 1000 ] ;
  int i ;
  for ( i = 0 ; i < 1000 ; i = i + 1 ) {
    cells [ i ] = 0 ;
  }

  char c [ 1000 ] ;
  int currentCell = 0 ;
  while ( ( c [ 0 ] = fgetc ( f ) ) != EOF ) {
    if ( c [ 0 ] != 'q' && c [ 0 ] != 'Q' ) {
      if ( c [ 0 ] == ' ' || c [ 0 ] == '\n' ) {
        continue ;
      } else {
        fprintf ( stderr , "Syntax error: non-q character\n" ) ;
        return -4 ;
      }
    }
    i=1 ;
    c [ i ] = fgetc ( f ) ;

    if ( c [ 1 ] == EOF ) {
      fprintf ( stderr , "Non-grouped Q; fatal\n" ) ;
      return -2 ;
    }
    if ( c [ 0 ] == 'Q' && c [ 1 ] == 'Q' ) {
      cells [ currentCell ] += 1 ;
    }
    else if ( c [ 0 ] == 'q' && c [ 1 ] == 'Q' ) {
      printf ( "%c" , cells [ currentCell ] ) ;
    }
    else if ( c [ 0 ] == 'q' && c [ 1 ] == 'q' ) {
      cells [ currentCell ] -= 1 ;
    }
  }
}
