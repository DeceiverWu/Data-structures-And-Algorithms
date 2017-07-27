//数据结构与算法分析——C语言描述 习题1.2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DICSIZE 4
#define SIZE 4

int isExist(int x, int y, int dir, int maxLen, char *retWord);	//判断是否有单词产生

//字母表
char puzzle[SIZE][SIZE] = {  
    {'t','h','i','s'},  
    {'w','a','t','s'},  
    {'o','a','h','g'},  
    {'f','g','g','t'}  
}; 

char *dictionary[DICSIZE] = {"this", "two", "fat", "that"};

int isExist(int x, int y, int dir, int maxLen, char *retWord)
{
	char word[SIZE+1];

	for(int i = 0; i < maxLen; i++){
		word[i] = puzzle[x][y];
		word[i+1] = '\0';
		for(int j = 0; j < DICSIZE; j++){
			if(strcmp(word, dictionary[j]) == 0){
				strcpy(retWord, word);
				return 1;
			}
		}

		//确定下个字符位置，即(x,y)
		switch(dir){
			case 0:		//从左到右
				y++;
				break;
			case 1:		//从右到左
				y--;
				break;
			case 2:		//从上到下
				x++;
				break;
			case 3:		//从下到上
				x--;
				break;
			case 4:		//从左上到右下
				x++;
				y++;
				break;
			case 5:		//从右下到左上
				x--;
				y--;
				break;
			case 6:		//从右上到左下
				x++;
				y--;
				break;
			case 7:		//从左下到右上
				x--;
				y++;
				break;
			default:
				puts("Direction error.");
				return 0;
		}
	}
	return 0;
}

int main()
{
	char word[SIZE+1];

	for(int row = 0; row < SIZE; row++){	//坐标轴:x
		for(int col = 0; col < SIZE; col++){	//坐标轴:y
			for(int dir = 0; dir < 8; dir++){	//dir:搜索方向
				for(int cnum = 1; cnum <= 4; cnum++){	//cnum表示字符数
					if(isExist(row, col, dir, cnum, word)){
						printf("%s\n", word);
						break;
					}
				}
			}
		}
	}

	system("pause");
    return 0;
}