#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#define DATA_SIZE 1000
void createf()
{  char data[DATA_SIZE];
    char n[100];
    FILE * fPtr;
    int i;
    printf("create 2 files \nfile1: with data \nfile2: without data for copying\n");
   for ( i=0;i<2;i++){ 
   printf("enter a file name:");
   gets(n);
    fPtr = fopen(n,"w");
    if(fPtr == NULL)
    {   printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter contents to store in file : \n");
    fgets(data, DATA_SIZE, stdin);
    fputs(data, fPtr);
    fclose(fPtr);
    printf("File created and saved successfully. ?? \n");
}
}
void copyfun(){
char ch, source_file[20], target_file[20];
       FILE *source, *target;
       printf("Enter name of file to copy\n");
       gets(source_file);
       source = fopen(source_file, "r");
       if (source == NULL)
       {
          printf("Press any key to exit...\n");
          exit(EXIT_FAILURE);
       }
       printf("Enter name of target file\n");
       gets(target_file);
       target = fopen(target_file, "w");
       if (target == NULL)
       {
          fclose(source);
          printf("Press any key to exit...\n");
          exit(EXIT_FAILURE);
       }
       while ((ch = fgetc(source)) != EOF)
          fputc(ch, target);
     
       printf("File copied successfully.\n");
       fclose(source);
       fclose(target);
}
void lsandgrep(){
 char fn[10],pat[10],temp[200];
FILE *fp;
char dirname[10];
DIR*p;
struct dirent *d;
printf("Enter directory name\n");
scanf("%s",dirname);
p=opendir(dirname);
if(p==NULL)
  {
  perror("Cannot find directory");
  exit(0);
  }
while(d=readdir(p))
  printf("%s\n",d->d_name);


}

int main(){
 createf();
 copyfun();
 lsandgrep();
}
