//临时调用函数
# include "functions.c"

#include "string.h"
#include "stdio.h"
#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"

/////////////////////////////该段定义放置于pre.c文件中了
// #define Max 20000
// #define NUM 10   // 地点个数   //原框架为#define NUM 9
// typedef struct ArcCell
// {
//     int adj; /* 相邻接的建筑之间的路程 */
// } ArcCell;   /* 定义边的类型 */
// typedef struct VertexType
// {
//     int number;        /* 建筑编号 */
//     char *sight;       /* 建筑名称 */
//     char *description; /* 建筑描述 */
// } VertexType;          /* 定义顶点的类型 */
// typedef struct
// {
//     VertexType vex[NUM];    /* 图中的顶点，即为建筑 */
//     ArcCell arcs[NUM][NUM]; /* 图中的边，即为建筑间的距离 */
//     int vexnum, arcnum;     /* 顶点数，边数 */
// } MGraph;                   /* 定义图的类型 */
// MGraph G;                   /* 把图定义为全局变量 */
// int P[NUM][NUM];            /* */
// long int D[NUM];            /* 辅助变量存储最短路径长度 */
// int x[NUM] = {0};              //原框架为int x[9] = {0}; 
///////////////////////////////////////////

// void CreateUDN(char * inputCSVfile);//void CreateUDN(int v, int a);        /* 造图函数 */
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
    int initialized = 0; //记录是否完成初始化
    char tempC;//用于清空缓存的临时字符
    system("color fc");
    //初始化
     do
    {
        ck = Menu_Create();
        switch (ck)
        {
            case '1':
                initialized = CreateUDN("./inputExamples/matrix.CSV"); //原有框架为CreateUDN(NUM, 11);
                if(initialized)
                {
                    printf("初始化成功\n");
                    system("pause");  //窗口暂停，显示输出结果，不然会直接清空结果
                    ck ='e';//设置退出该界面的标记
                }else{
                    printf("初始化出错\n");
                    ck = 'c';//出错就继续循环初始化界面
                }
                break;
            case '2':
                inputCSVfile = (char*)malloc(200*sizeof(char));
                printf("输入存储邻接矩阵的CSV文件的地址：\n>");
                while((tempC = getchar()) != '\n' && tempC != EOF);           //清空stdin的输入缓存
                fgets(inputCSVfile,200 , stdin);   //输入的文件路径长度限为200个字符，超过就会报错（linux环境下gcc不支持gets）
                // fputs(inputCSVfile,stdout);     //输出写法
                if(inputCSVfile[strlen(inputCSVfile) - 1] == '\n') //fgets取得的字符串末尾会含'\n',导致该路径字符串不可用，因此需要将其最后一个字符换为'\0'
                inputCSVfile[strlen(inputCSVfile) - 1] = '\0' ;//
                initialized = CreateUDN(inputCSVfile);
                if(initialized)
                {
                    printf("初始化成功\n");
                    ck ='e';//设置退出该界面的标记
                }else{
                    printf("初始化出错\n");
                    ck = 'c';//出错就继续循环初始化界面
                }
                system("pause");  //窗口暂停，显示输出结果，不然会直接清空结果
                ck = 'e';//设置退出该界面的标记
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
        system("cls"); //清空控制台
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
        printf(  "\t\t\t┃ |   1.查询建筑路径        | ┃\n");
        printf(  "\t\t\t┃ |   2.查询建筑信息        | ┃\n");
        printf(  "\t\t\t┃ |   2.选择出发点和目的地  | ┃\n");
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