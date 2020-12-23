#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){

  char * line;
  char * out;
  mkfifo("output", 0666);

  while(1){
    int input = open("input", O_RDONLY);
    read(input, line, sizeof(line));
    close(input);

    while(*line){
       *out = (*line - 'a' + 13) % 26 + 'a';
       line++;
       out++;
    }


    int output = open("output", O_WRONLY);
    write(output, out, sizeof(output));
    close(output);

  }

  return 0;
}
