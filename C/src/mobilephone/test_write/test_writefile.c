#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char * argv[])
{
	FILE * stream;
	int ret;
	char buf[1024] = "wodegemygoddea,zenmehuishia";
	char pathname[] = "mydata.txt";

	ret = 0;

	if( (stream = fopen(pathname,"w+")) == (FILE *)0 )
	{
		printf("[FATAL]..fopen\n");
		exit(0);
	}

	ret = fwrite(buf,strlen(buf),10,stream);

	if(ret != 10)
	{
		printf("[FATAL]..fwrite");
		exit(0);
	}

	if((fclose(stream)) == EOF)
	{
		printf("[FATAL]..fclose");
		exit(0);
	}
	return 0;  
}

