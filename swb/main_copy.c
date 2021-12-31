#include "string.h"
#include "stdio.h"
#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#define Max 20000
#define NUM 10   // 地点个数   //原框架为#define NUM 9
typedef struct ArcCell
{
    int adj; /* 相邻接的建筑之间的路程 */
} ArcCell;   /* 定义边的类型 */
typedef struct VertexType
{
    int number;        /* 建筑编号 */
    char *sight;       /* 建筑名称 */
    char *description; /* 建筑描述 */
} VertexType;          /* 定义顶点的类型 */
typedef struct
{
    VertexType vex[NUM];    /* 图中的顶点，即为建筑 */
    ArcCell arcs[NUM][NUM]; /* 图中的边，即为建筑间的距离 */
    int vexnum, arcnum;     /* 顶点数，边数 */
} MGraph;                   /* 定义图的类型 */
MGraph G;                   /* 把图定义为全局变量 */
int P[NUM][NUM];            /* */
long int D[NUM];            /* 辅助变量存储最短路径长度 */
int x[NUM] = {0};              //原框架为int x[9] = {0}; 
void CreateUDN(char * inputCSVfile);//void CreateUDN(int v, int a);        /* 造图函数 */
void narrate();                      /*说明函数*/
void ShortestPath(int num);          /*最短路径函数*/
void output(int sight1, int sight2); /*输出函数*/
char Menu();                         /* 主菜单 */
char Menu_Create();                  /*初始化菜单*/
void search();                       /* 查询建筑信息 */
char SearchMenu();                   /* 查询子菜单 */
void HaMiTonian(int input);                /* 哈密尔顿图的遍历 */
void NextValue(int input);
void display(); /* 显示遍历结果 */








int main()     /* 主函数 */
{
    int v0, v1;
    char ck;
    char * inputCSVfile; //输入文件的地址
    system("color fc");
    //初始化
     do
    {
        ck = Menu_Create();
        switch (ck)
        {
            case '1':
                CreateUDN("./inputExamples/matrix.CSV"); //原有框架为CreateUDN(NUM, 11);
                break;
            case '2':
                inputCSVfile = (char*)malloc(200*sizeof(char));
                fgets(inputCSVfile,200 , stdin);   //输入的文件路径长度限为200个字符，超过就会报错（linux环境下gcc不支持gets）
                // fputs(inputCSVfile,stdout);     //输出写法
                if(inputCSVfile[strlen(inputCSVfile) - 1] == '\n') //fgets取得的字符串末尾会含'\n',导致该路径字符串不可用，因此需要将其最后一个字符换为'\0'
                inputCSVfile[strlen(inputCSVfile) - 1] = '\0' ;//
                CreateUDN(inputCSVfile);
                break;
        };
    } while (ck != 'e');
    //初始化完毕
   
    do
    {
        ck = Menu();
        switch (ck)
        {
            case '1':
                system("cls");
                narrate();
                printf("\n\n\t\t\t 请选择起点建筑（0～8）：");
                scanf("%d", &v0);
                printf("\t\t\t 请选择终点建筑（0～8）：");
                scanf("%d", &v1);
                ShortestPath(v0); /* 计算两个建筑之间的最短路径 */
                output(v0, v1);   /* 输出结果 */
                printf("\n\n\t\t\t\t 请按任意键继续...\n");
                getchar();
                getchar();
                break;
            case '2':
                search();
                break;
        };
    } while (ck != 'e');
}

char Menu_Create()/*初始化菜单*/
{
    char c;
    int flag;
    do
    {
        flag = 1;
        system("cls");
        narrate();
        printf("\t__   ___   _ _   _     _   _             _             _   _             \n");
        printf("\t\\ \\ / / \\ | | | | |   | \\ | | __ ___   _(_) __ _  __ _| |_(_) ___  _ __  \n");
        printf("\t \\ V /|  \\| | | | |   |  \\| |/ _` \\ \\ / / |/ _` |/ _` | __| |/ _ \\| '_ \\ \n");
        printf("\t  | | | |\\  | |_| |   | |\\  | (_| |\\ V /| | (_| | (_| | |_| | (_) | | | |\n");
        printf("\t  |_| |_| \\_|\\___/    |_| \\_|\\__,_| \\_/ |_|\\__, |\\__,_|\\__|_|\\___/|_| |_|\n");
        printf("\t                                           |___/                         \n");
                                                    
        ///////////////////////////////////////////////////原框架
        // printf("\n\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━┑\n");
        // printf(  "\t\t\t┃                      ┃\n");
        // printf(  "\t\t\t┃ 1、查询建筑路径       ┃\n");
        // printf(  "\t\t\t┃ 2、查询建筑信息       ┃\n");1
        // printf(  "\t\t\t┃ 3、选择出发点和目的地  ┃\n");
        // printf(  "\t\t\t┃ e、退出               ┃\n");
        // printf(  "\t\t\t┃                      ┃\n");
        // printf(  "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━┛\n");
        // printf(  "\t\t\t\t 请输入您的选择：");
        //////////////////////////////////////////////////原框架
        printf("\n\t\t\t .━━━━━━━━━━━━━━━━━━━━━━━━━━━. \n");
        printf(  "\t\t\t┃ .-------------------------. ┃\n");
        printf(  "\t\t\t┃ |                         | ┃\n");
        printf(  "\t\t\t┃ |   1.默认文件初始化      | ┃\n");
        printf(  "\t\t\t┃ |   2.选择文件初始化      | ┃\n");
        printf(  "\t\t\t┃ |   e.退出                | ┃\n");
        printf(  "\t\t\t┃ |                         | ┃\n");
        printf(  "\t\t\t┃ '-------------------------' ┃\n");
        printf(  "\t\t\t '━━━━━━━━━━━━━━━━━━━━━━━━━━━' \n");
        printf(  "\t\t\t 请输入您的选择：");
        scanf("%c", &c);
        if (c == '1' || c == '2' || c == 'e')
            flag = 0;
    } while (flag);
    return c;
}


char Menu() /* 主菜单 */
{
    char c;
    int flag;
    do
    {
        flag = 1;
        system("cls");
        narrate();
        // printf("\n\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━┑\n");
        // printf(  "\t\t\t┃                      ┃\n");
        // printf(  "\t\t\t┃ 1、查询建筑路径       ┃\n");
        // printf(  "\t\t\t┃ 2、查询建筑信息       ┃\n");
        // printf(  "\t\t\t┃ 3、选择出发点和目的地  ┃\n");
        // printf(  "\t\t\t┃ e、退出               ┃\n");
        // printf(  "\t\t\t┃                      ┃\n");
        // printf(  "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━┛\n");
        // printf(  "\t\t\t\t 请输入您的选择：");
        printf("\n\t\t\t .━━━━━━━━━━━━━━━━━━━━━━━━━━━. \n");
        printf(  "\t\t\t┃ .-------------------------. ┃\n");
        printf(  "\t\t\t┃ |                         | ┃\n");
        printf(  "\t\t\t┃ |   1.默认文件初始化      | ┃\n");
        printf(  "\t\t\t┃ |   2.选择文件初始化      | ┃\n");
        printf(  "\t\t\t┃ |   e.退出                | ┃\n");
        printf(  "\t\t\t┃ |                         | ┃\n");
        printf(  "\t\t\t┃ '-------------------------' ┃\n");
        printf(  "\t\t\t '━━━━━━━━━━━━━━━━━━━━━━━━━━━' \n");
        printf(  "\t\t\t 请输入您的选择：");
        scanf("%c", &c);
        if (c == '1' || c == '2' || c == '3' || c == 'e')
            flag = 0;
    } while (flag);
    return c;
}


void CreateUDN(char *inputCSVfile) //inputCSVfile表示输入的CSV文件的路径，全局变量P[][]存储输出的邻接矩阵,v顶点数能从文件中读出，a边数也能从文件中读出
{
	int i, j;
	int k = 0;
	int count = 0; //统计文件中字符个数
	int sum_row;   //统计文件中字符个数
	int flag = 0;
	FILE *fp; //文件指针
	FILE *fp1;
	fp = fopen(inputCSVfile, "r"); //打开文件，只读
	//fp1=fopen("int_data.txt","r");
	fp1 = fopen(inputCSVfile, "r");
	if (fp == NULL)
	{
		printf("File cannot open! ");
		//exit;
		return;
	}

	while (!feof(fp)) //读文件，直到文件末尾
	{
		flag = fgetc(fp); //将文件内容附给flag
		if (flag == '\n') //如果为\n表示到行尾，便行数加1
			count++;
	}
	sum_row = count;				   //邻接矩阵总行数
	printf("顶点个数为：%d", sum_row); //打印文件行数，因为每行只有一个数，所以即统计文件中有多少个数
	printf("\n");

	char temp;
	for (i = 0; i < sum_row; i++) //控制行数
	{
		for (j = 0; j < sum_row; j++) //控制列数 //因为这里都是方阵就直接用2*sum_row-1来表示其最大列数，如果是','就不记录，如果是数字就记录
		{
			if (j == sum_row - 1) //读到最后一个数字时改变读取方式，不加上，
			{
				fscanf(fp1, "%d", &P[i][j]);
				k++;
				break;
			}
			fscanf(fp1, "%d,", &P[i][j]); //将文件其中一行内容保存到数组中
			k++;						  //记录已存的数字个数
		}
	}
	printf("输入的邻接矩阵为：\n");
	for (int i = 0; i < sum_row; i++) //循环打印保存到数组中的数据,i表行，j表列，num表示数组元素总数
	{
		for (j = 0; j < sum_row; j++)
		{
			printf("%d\t", P[i][j]); //打印
		}
		printf("\n");
	}
	fclose(fp);	 //关闭文件，释放指向文件的指针
	fclose(fp1); //关闭文件，释放指向文件的指针
	return;
}

 /*说明函数*/ 
void narrate()
{
    printf("narrate\n");
}   
/*最短路径函数*/                  
void ShortestPath(int num)
{
    printf("ShortestPath\n");
} 


 /*输出函数*/       
void output(int sight1, int sight2)
{
    printf("output\n");
}


  /* 主菜单 */
// char Menu()
// {
//     printf("Menu\n");
//     return 'a';
// }       


 /* 查询建筑信息 */         
void search()
{
    printf("Menu\n");
}         
  /* 查询子菜单 */                
char SearchMenu()
{
    printf("SearchMenu\n");
    return 'a';
}       
  /* 哈密尔顿图的遍历 */             
void HaMiTonian(int input)
{
    printf("HaMiTonian\n");
}               
void NextValue(int input)
{
    printf("NextValue\n");
}       
/* 显示遍历结果 */
void display()
{
    printf("display\n");
}       