#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*	用于获得next数组
**	@param(pattern 模式串)
	@return int[]
*/	
int* get_next(char* pattern){
	int length = strlen(pattern);		//模式串的长度
	int *next = (int*)malloc(sizeof(int)*length);		//用于保存匹配出错跳转位置的next数组
	next[0] = -1;						//初始化next[0]为-1，用于主串匹配位置的跳转
	int max_repeat_length = 0;			//0到当前位置时最长的公共前缀
	for(int i = 1;i<length;++i){
		if(pattern[i] == pattern[max_repeat_length]) {
			max_repeat_length++;
			next[i] = max_repeat_length;
		} else if(pattern[i] == pattern[0]) {
			max_repeat_length = 1;
			next[i] = 1;
		} else {
			max_repeat_length = 0;
			next[i] = 0;
		}
	}
	for(int i = 1;i<length;++i){
		if(next[i] > 0)
			next[i]--;
	}						//处理next数组以便匹配出错时能正确跳转
	return next;
}


/*	@param(pattern 需要匹配的字符串;model 规定了在哪些字符里进行查找) 
**			
**	@return 返回匹配到的位置索引（开头位置），否则返回-1 
*/
int match(char* pattern,char* model){
	int *next = get_next(pattern);

	/*
		检索过程---
			外层循环标示模式串的索引位置，
			用j表示已经匹配到主串哪个位置了，
			j每次变化都进行检测，如果不符合直接返回-1
			如果i循环结束，则返回j的值作为结果
	*/
	int j = 0;
	for(int i = 0;i<strlen(pattern);++i){				
		if(pattern[i] != model[j+i]){		//遇到不匹配的位置则进行处理
			if(next[i] != -1){
				i = next[i];
				j = j+i+1;
				if(j+strlen(pattern)-1>=strlen(model))	//判断是否还有必要继续匹配
					return -1;
				
				i--;
			} else {
				j = j+i+1;
				if(j+strlen(pattern)>=strlen(model))
					return -1;
				i = 0;
			}
		}
	}

	return j;
}
int main() {
	char *pattern = "caabc";
	char *model = "ccaabc";

	int index = match(pattern,model);
	printf("%d\n",index );
}