/*
You will write a program that will gather various information about a directory, specifically:
1) list all the files in the directory (done)
2) specify which files are directories (if any) (done)
3) show the total size of all the regular files the directory (done)
note that you do not have to recursively go through any subdirectories to find their size for this part (unless you want to, but that is not a simple task)
Have the program scan the current directory
*/
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main(){
    DIR* pointer = opendir(".");
    struct dirent* entry;
    entry = readdir(pointer);

    struct stat buffer;
    int size=0;

    while (entry){
        if (entry->d_type == 4){
            printf("directory %s\n", entry->d_name);
        }
        else{
            printf("%s\n", entry->d_name);
            stat(entry->d_name, &buffer);
            size+=buffer.st_size;
        }
        entry = readdir(pointer);
    }
    printf("%d\n",size);
    return 0;
}