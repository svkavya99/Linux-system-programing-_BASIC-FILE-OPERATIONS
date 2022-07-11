#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
	int n,f;
	char buff[10];
	f=open("seeking",O_RDWR|O_CREAT);
	read(f,buff,10);
	write(1,buff,10);
	lseek(f,10,SEEK_SET);//skips 5 characters from the current position
	read(f,buff,10);
	write(1,buff,10);
	
}
