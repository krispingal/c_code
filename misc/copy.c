//A simple program to copy a file using file descriptors
#include<stdio.h>

int main (int argc, char *argv[]){
  int i;
  char *buf;
  FILE *fp1, *fp2;
  if (argc < 2){
    error ("Error: Usage of cp requires 2 arguments,\n");
    return 1;
  }
  if ((fp1 = fopen (argv[1], "r")) == NULL){
    error ("Error: Unable to open %s\n",argv[1]);
    return 1;
  }
  if ((fp2 = fopen(argv[2], "a")) == NULL){
    error ("Error: Unable to create %s", argv[2]);
    return 1;
  }
  while ((i = fscanf(fp1, "%s", buf)) > 0){
    if (fprintf(fp2,"%s", buf) != i) 
      error("Error:in writting output");
  }
  //  i = close (fd1);
  // i = close (fd2);
  return 0;
}
