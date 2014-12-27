#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "../util.h"
#include "markerDefinition.h"
#include "watershed.h"

int parseMainArguments(int argc, char *argv[]){
	if (argc < 2)
		terminateProgram("Enter\n\t1: Marker definition\n\t2: Flooding");

	if (atoi(argv[1]) != 1 && atoi(argv[1]) != 2)
		terminateProgram("Enter\n\t1: Marker definition\n\t2: Flooding");
	
	return atoi(argv[1]);
}
int main(int argc, char *argv[]){
	int choice = parseMainArguments(argc,argv);
	time_t   start, finish;
	time( &start );

	if (choice == 1)
		MARKER_DEFINITION(argc,argv);
	else
		REGION_GROWING(argc,argv);

	time( &finish );
	printf( "\nProgram takes %6.0f seconds.\n", difftime( finish, start ) );

	return 0;
}
