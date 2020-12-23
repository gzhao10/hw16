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
  mkfifo("input", 0666);

  while(1){
    int input = open("input", O_WRONLY);
    fgets(line, sizeof(line), stdin);
    write(input, line, sizeof(line));
    close(input);

    int output = open("output", O_RDONLY);
    read(output, out, sizeof(out));
    printf("%s\n", out);
    close(output);
  }

  return 0;

}
