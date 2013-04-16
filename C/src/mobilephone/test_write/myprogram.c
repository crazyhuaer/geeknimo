/*
 * =====================================================================================
 *
 *       Filename:  myprogram.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/06/2012 10:51:07 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Neo_Skyworth (Skyworth), 20549304@163.com
 *   Organization:  Backgarden-Straw
 *
 * =====================================================================================
 */


#include	<stdlib.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

for (i = 0; i < count; i++) {
	/* code */
}



FILE	*ii;										/* input-file pointer */
char	*ii_file_name = "";		/* input-file name    */

ii	= fopen( ii_file_name, "r" );
if ( ii == NULL ) 
{
	fprintf ( stderr, "couldn't open file '%s'; %s\n",
			ii_file_name, strerror(errno) );
	exit (EXIT_FAILURE);
}


if( fclose(ii) == EOF ) 
{			/* close input file   */
	fprintf ( stderr, "couldn't close file '%s'; %s\n",
			ii_file_name, strerror(errno) );
	exit (EXIT_FAILURE);
}

