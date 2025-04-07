#include <nds.h>
#include <stdio.h>
#include "hello-world.h"

#include <fat.h>
#include <string.h>

void save_file(SaveFile data)
{
    FILE* savefile = fopen("fat:/savefile.sav", "wb");
    fwrite(&data, 1, sizeof(SaveFile), savefile);
    fclose(savefile);
}

void read_file(SaveFile* data)
{
    FILE* savefile = fopen("fat:/savefile.sav", "rb");
    fread(data, 1, sizeof(SaveFile), savefile);
    fclose(savefile);
}

int main(int argc, char* argv[])
{
	consoleDemoInit();
    printf("Console initialized\n");

    if (!fatInitDefault())
    {
        printf("fatInitDefault failure: terminating\n");
    }

    while(1) {
        swiWaitForVBlank();
        scanKeys();
        int pressed = keysDown();
        if(pressed & KEY_START) break;
    }

    SaveFile data_write, data_read;

    printf("Read save file:\n");
    read_file(&data_read);
    printf("Data in save file is: %s\n", data_read.var3);

    printf("Writing save data");
    strcpy(data_write.var3, "Writen line!\n");

    printf("Writing save file");
    save_file(data_write);

    printf("Read save file again:\n");
    read_file(&data_read);
    printf("Data in save file now is: %s\n", data_read.var3);



    return 0;
}

