#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXLEN 255
//定长顺序存储
typedef struct{
    char ch[MAXLEN];
    int length;
}SString;
//堆分配存储表示
typedef struct{
    char *ch;
    int length;
}HString;
//块链存储表示

//暴力模式匹配
int index(SString S, SString T){
    int i = 0, j =0;
    while(i < S.length && j < T.length){
        if(S.ch[i] == T.ch[j]){
            ++i;
            ++j;
        }else{
            i = i-j+1;//指针后退重新开始匹配
            j = 0;
        }
    }
    if(j >= T.length){
        return i - T.length;
    }else{
        return 0;
    }
}

//KMP 指针不回退  前缀，后缀和最大公共前后缀长度 next
/*next[ j ]的含义是:在子串的第j个字符与主串发生失配时,则跳到子串的next[ j ]位置重新与主串当前位置进行比较。

通过分析，可以知道，除第一个字符外，模式串中其余的字符对应的next数组的值等于其最大公共前后缀长度加上1*/
void get_next(SString T, int *next){
	int i = 1, j = 0;
	next[1] = 0;
	while (i < T.length){
		if(j==0 || T.ch[i]==T.ch[j]){	//ch[i]表示后缀的单个字符，ch[j]表示前缀的单个字符
			++i; ++j;
			next[i] = j;	//若pi = pj， 则next[j+1] = next[j] + 1
		}else{
			j = next[j];	//否则令j = next[j]，j值回溯，循环继续
		}
	}
}

int Index_KMP(SString S, SString T){
	int i=1, j=1;
	int next[255];	//定义next数组
	get_next(T, next);	//得到next数组
	while(i<=S.length && j<=T.length){
		if(j==0 || S.ch[i] == T.ch[j]){	//字符相等则继续
			++i; ++j;
		}else{
			j = next[j];	//模式串向右移动，i不变
		}
	}
	if(j>T.length){
		return i-T.length;	//匹配成功
	}else{
		return 0;
	}
}

void get_nextval(SString T, int *nextval){
	int i = 1, j = 0;
	nextval[1] = 0;
	while (i < T.length){
		if(j==0 || T.ch[i]==T.ch[j]){	//ch[i]表示后缀的单个字符，ch[j]表示前缀的单个字符
			++i; ++j;

			if(T.ch[i] != T.ch[j]){	//若当前字符与前缀字符不同
				nextval[i] = j;	//则当前的j为nextval在i位置的值
			}else{
				//如果与前缀字符相同
				//则将前缀字符的nextval值给nextval在i位置上的值
				nextval[i] = nextval[j];
			}
		}else{
			j = nextval[j];	//否则令j = next[j]，j值回溯，循环继续
		}
	}
}



