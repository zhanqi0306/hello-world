/*
格子中输出

StringInGrid函数会在一个指定大小的格子中打印指定的字符串。
要求字符串在水平、垂直两个方向上都居中。
如果字符串太长，就截断。
如果不能恰好居中，可以稍稍偏左或者偏上一点。

下面的程序实现这个逻辑，请填写划线部分缺少的代码。

#include <stdio.h>
#include <string.h>

void StringInGrid(int width, int height, const char* s)
{
	int i,k;
	char buf[1000];
	strcpy(buf, s);
	if(strlen(s)>width-2) buf[width-2]=0;

	printf("+");
	for(i=0;i<width-2;i++) printf("-");
	printf("+\n");

	for(k=1; k<(height-1)/2;k++){
		printf("|");
		for(i=0;i<width-2;i++) printf(" ");
		printf("|\n");
	}

	printf("|");

	printf("%*s%s%*s",_____________________________________________);  //填空

	printf("|\n");

	for(k=(height-1)/2+1; k<height-1; k++){
		printf("|");
		for(i=0;i<width-2;i++) printf(" ");
		printf("|\n");
	}

	printf("+");
	for(i=0;i<width-2;i++) printf("-");
	printf("+\n");
}

int main()
{
	StringInGrid(20,6,"abcd1234");
	return 0;
}

对于题目中数据，应该输出：
+------------------+
|                  |
|     abcd1234     |
|                  |
|                  |
+------------------+

（如果出现对齐问题，参看【图1.jpg】）


注意：只填写缺少的内容，不要书写任何题面已有代码或说明性文字。


*/

#include <stdio.h>
#include <string.h>

void StringInGrid(int width, int height, const char* s)
{
    int i,k;
    char buf[1000];
    strcpy(buf, s);
    if(strlen(s)>width-2) buf[width-2]=0;

    printf("+");
    for(i=0;i<width-2;i++) printf("-");
    printf("+\n");

    for(k=1; k<(height-1)/2;k++){
        printf("|");
        for(i=0;i<width-2;i++) printf(" ");
        printf("|\n");
    }

    printf("|");

//    printf("%*s%s%*s",_____________________________________________);  //填空
    printf("%*s%s%*s",(width-strlen(buf)-2)/2,"",buf,(width-strlen(buf)-2)/2,"");  //填空
    printf("|\n");

    for(k=(height-1)/2+1; k<height-1; k++){
        printf("|");
        for(i=0;i<width-2;i++) printf(" ");
        printf("|\n");
    }

    printf("+");
    for(i=0;i<width-2;i++) printf("-");
    printf("+\n");
}

int main()
{
//    printf ("%*s \n",5, "1");
    StringInGrid(20,6,"abcd1234");
    return 0;
}

//主要考的就是%*s这个知识点 前面*用一个数字替换