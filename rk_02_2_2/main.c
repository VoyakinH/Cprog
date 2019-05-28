#include <stdio.h>
#include <string.h>
#define N 100


typedef struct{
	char name[N];
	int year;
	int population;
}city;

void fill_struct(city ct[N], FILE* fsrc)
{
	char buff[N];
	fgets(&*buff, N, fsrc);
	int i = 0;
	while (1)
	{
		printf("%s", buff);
		insert_to_name(ct, buff, i);
		i++;
		if (fgets(&*buff, N, fsrc) == NULL)
			break;
	}
	return;
}

void insert_to_name(city ct[N], char buff, int i)
{
	strcpy(ct[i].name, buff);
	return;
}
	
int main()
{
	FILE *fsrc;
	//FILE *fdst;
	city ct[N];
	fsrc = fopen("in.txt", "r");
	if (!fsrc)
		return 1;
	
	fill_struct(ct, fsrc);
	printf("%s", ct[0].name);
	fclose(fsrc);
	return 0;	
}
