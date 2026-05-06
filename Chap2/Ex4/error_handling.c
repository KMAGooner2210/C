#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(){
  printf("--- BAT LOI HE THONG LINUX --- \n");
  FILE *fp = fopen("/root/secret.txt", "r");
  if(fp == NULL){
     printf("\n[Cach 1] In nguyen ban ma loi (errno):\n");
     printf("Error code: %d\n", errno);
     printf("\n[Cach 2] Tu dich ma loi sang tieng Anh (strerror):\n");
     printf("Mo ta: %s\n", strerror(errno));
     printf("\n[Cach 3] Cach tieu chuan (perror):\n");
     perror("Loi mo file"); 
  }else{
     printf("Mo file thanh cong!");
     fclose(fp);
  }
  return 0;
}
