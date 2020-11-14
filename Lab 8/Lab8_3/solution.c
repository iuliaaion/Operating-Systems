#include <stdio.h>
#include <string.h>
int main()
{
       int word=0;
       int line=0;

       FILE *fp;
       char buf[1000];
       fp = fopen("iuli.txt", "r");

       if (!fp) {
         return 1;
       }

       while (fgets(buf,1000,fp) != NULL) {
         int len = strlen(buf);
         int x;
         for(x=0; x<len; x++) {
           if (buf[x+1]==' '){
             word++;
           }else if (buf[x]=='\n') {
             line++;
             word++;
             printf("line %i: %i words\n", line, word);
             word=0;
           }
         }

       }

       fclose(fp);

       return 0;
}
