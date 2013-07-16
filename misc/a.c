#include <stdio.h>

main(int argc, char *argv[])
{
  FILE *fp, *fp2;
  void filecopy(FILE *, FILE *);
  if (argc == 1) /* no args; copy standard input */
    filecopy(stdin, stdout);
  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("cat: can't open %s\n", argv[1]);
    return 1;
  }
  else if ((fp2 = fopen(argv[2], "a")) == NULL){
   error ("cat: can't open %s\n", argv[2]);
   return 1;
 }
 else {
filecopy(fp, fp2);
fclose(fp);
}
return 0;
}
/* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
int c;
while ((c = getc(ifp)) != EOF)
putc(c, ofp);
}
