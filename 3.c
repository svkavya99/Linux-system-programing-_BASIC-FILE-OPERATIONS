#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
int n,f,f1;
char buff[6];
f=open("seek",O_RDWR|O_CREAT);
//read(f,buff,6);
//write(1,buff,6);
f1=lseek(f,10,SEEK_SET);
printf("pointer is at %d psition\n",f1);
read(f,buff,6);
write(1,buff,6);
return 0;
}
