#include <stdio.h>

int main()
{
	FILE *fptr;

	fptr = fopen("/usr/share/astro/ObjectList.lst","r");

	if (fptr == NULL) {
	   printf("\nCan't open file...\n");
	} else {
	   printf("\nOpened file...\n");
	   fclose(fptr);
	}
	exit(0);
}
