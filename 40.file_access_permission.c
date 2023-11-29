#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
int main(int argc, char **argv) {
 int result;
 char *filename = (char *)malloc(512);
 if (argc < 2) {
 strcpy(filename, "/usr/bin/adb");
 } else {
 strcpy(filename, argv[1]);
 }
 result = access (filename, R_OK); 
 if ( result == 0 ) {
 printf("%s is readable\n",filename); 
 } else {
 printf("%s is not readable\n",filename); 
 }
 result = access (filename, W_OK); 
 if ( result == 0 ) {
 printf("%s is Writeable\n",filename); 
 } else {
 printf("%s is not Writeable\n",filename); 
 }
 result = access (filename, X_OK); 
 if ( result == 0 ) {
 printf("%s is executable\n",filename); 
 } else {
 printf("%s is not executable\n",filename); 
 }
 free(filename);
 return 0;
 }
