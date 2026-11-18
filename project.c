#include "header.h"
void main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("Usage:./srinath_preprocessor srinath.c\n");
		return;
	}
	FILE *fp=fopen(argv[1],"r");
	remove_comment(fp,argv[1]);
	macro(argv[1]);
	header_file(argv[1]);
}

