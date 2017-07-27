//数据结构与算法分析——C语言描述 习题1.4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using std::string;

#define MAX 100

void process_file(const char *filename)

int main()
{
	process_file("stdio.h");
	return 0;
}

void process_file(const char *filename)
{
	static char opened[MAX][MAX];	//存储文件标识符
	static int cnt = 0;
	FILE *fin;
	char line[MAX];

	//判断文件是否已打开
	for(int i = 0; i < cnt; i++){
		if(strcmp(opened[i], filename) == 0)
			return;
	}

	string str("d:\\" + filename);
	fin = fopen(s.c_str(), "r");
	if(fin == NULL)
		return;

	strcpy(opened[cnt], filename);
	cnt++;

	printf("%s\n", filename);
	char *newfile;
	while(fgets(line, MAX, fin)){
		if(line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		if(newfile = strstr(line, "#include")){
			char *start = strchr(line, '<');
			char temp[MAX];
			strcpy(temp, start + 1);
			temp[strlen(temp) - 1] = '\0';
			process_file(temp); 
		}
	}
}
