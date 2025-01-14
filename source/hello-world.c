#include <nds.h>
#include <stdio.h>
#include "hello-world.h"

int main(void)
{
	consoleDemoInit();
	printf("Hello World\n");

	do
	{
		swiWaitForVBlank();
		
	} while (1);
	
	return(0);
}

