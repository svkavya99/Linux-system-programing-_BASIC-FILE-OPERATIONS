#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
int main()
{
int fd,seek_pos=0,sz;
char buff[50];
fd=open("output.txt",O_RDWR|O_CREAT);
if(fd<0)
{
printf("OPEN FAILS");
}
seek_pos=lseek(fd,0,SEEK_SET);
printf("INITIAL POS OF CURSOR IS %d\n",seek_pos);
seek_pos=lseek(fd,2,SEEK_SET);
printf("POS OF CURSOR IS %d\n",seek_pos);
seek_pos=lseek(fd,6,SEEK_CUR);
printf("POS OF CURSOR IS %d\n",seek_pos);
sz=read(fd,buff,10);
printf("read bytes from file after lseek is %d\n",sz);
buff[sz]='\0';
printf("read bytes=%s\n",buff);
seek_pos=lseek(fd,0,SEEK_END);
strcpy(buff,"new string appended\n");
sz=write(fd,buff,strlen(buff));
close(fd);
return 0;
}
