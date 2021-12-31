/*
    date: 2021.12.31
    author: shiwenbo
*/


#include "string.h"
#include "stdio.h"
#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#define Max 20000
#define NUM 10   // 地点个数   //原框架为#define NUM 9
int P[NUM][NUM];            /*存图的全局邻接矩阵*/

void CreateUDN(char* inputCSVfile)   //inputCSVfile表示输入的CSV文件的路径，全局变量P[][]存储输出的邻接矩阵
{
	int i,j;
	int k=0;
	int count=0;  //统计文件中字符个数
	int sum_row;  //统计文件中字符个数
	int flag=0;
	FILE *fp;  //文件指针
	FILE *fp1;
	fp=fopen(inputCSVfile,"r");   //打开文件，只读
	//fp1=fopen("int_data.txt","r"); 
	fp1=fopen(inputCSVfile,"r"); 
	if(fp==NULL)  
	{  
		printf("File cannot open! " );  
		//exit;  
		return;
	}  
	
while(!feof(fp))   //读文件，直到文件末尾
{
    flag = fgetc(fp);  //将文件内容附给flag
    if(flag == '\n')  //如果为\n表示到行尾，便行数加1
      count++;
}
sum_row = count; //邻接矩阵总行数
printf("邻接矩阵总行数为：%d",sum_row);  //打印文件行数，因为每行只有一个数，所以即统计文件中有多少个数
printf("\n");

char temp;
for(i=0;i<sum_row;i++)  //控制行数
{
		for (j=0;j<sum_row;j++)  //控制列数 //因为这里都是方阵就直接用2*sum_row-1来表示其最大列数，如果是','就不记录，如果是数字就记录
		{
			if(j == sum_row-1)//读到最后一个数字时改变读取方式，不加上，
			{
				fscanf(fp1,"%d",&P[i][j]);
				k++;
				break;
			}
			fscanf(fp1,"%d,",&P[i][j]);  //将文件其中一行内容保存到数组中
			k++; //记录已存的数字个数
		}
}
printf("文件内容为：\n");
for (int i=0;i < sum_row;i++)  //循环打印保存到数组中的数据,i表行，j表列，num表示数组元素总数
{
	for(j=0;j<sum_row;j++)
	{
		printf("%d\t",P[i][j]);  //打印
	}
	printf("\n");
}
fclose(fp);  //关闭文件，释放指向文件的指针
fclose(fp1);  //关闭文件，释放指向文件的指针
return;
} 


int main()
{
	char * inputCSVfile = (char*)malloc(200*sizeof(char));
	fgets(inputCSVfile,200 , stdin);   //输入的文件路径长度限为200个字符，超过就会报错（linux环境下gcc不支持gets）
	// fputs(inputCSVfile,stdout);     //输出写法
	if(inputCSVfile[strlen(inputCSVfile) - 1] == '\n') //fgets取得的字符串末尾会含'\n',导致该路径字符串不可用，因此需要将其最后一个字符换为'\0'
        inputCSVfile[strlen(inputCSVfile) - 1] = '\0' ;//
	CreateUDN(inputCSVfile);
}





// int main(){
//     printf("hello world\n");
//     printf("hello world\n");
//     return 0;


// }