#include <nds.h>
#include <stdio.h>
#include "hello-world.h"

int main(int argc, char* argv[])
{
	consoleDemoInit();
	printf("Hello World\n");

    while(pmMainLoop()) {
        swiWaitForVBlank();
        scanKeys();
        int pressed = keysDown();
        if(pressed & KEY_START) break;
    }

    return 0;
}

