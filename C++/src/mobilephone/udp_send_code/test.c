#include <stdio.h>
#include <string.h>

int main()
{
	int a;
	char name[20];
	printf("a=%d\n",(a = 5)== 5);
	printf("a=%d\n",a);
	scanf("%s",name);
	//name[strlen(name)+1] = '\0';
	printf("length:%d\n",strlen(name));
	return 0;
}
