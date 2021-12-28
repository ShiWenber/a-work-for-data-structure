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
void CreateUDN(int v, int a);        /* 造图函数 */
void narrate();                      /*说明函数*/
void ShortestPath(int num);          /*最短路径函数*/
void output(int sight1, int sight2); /*输出函数*/
char Menu();                         /* 主菜单 */
void search();                       /* 查询建筑信息 */
char SearchMenu();                   /* 查询子菜单 */
void HaMiTonian(int);                /* 哈密尔顿图的遍历 */
void NextValue(int);
void display(); /* 显示遍历结果 */








void main()     /* 主函数 */
{
    int v0, v1;
    char ck;
    system("color fc");
    CreateUDN(NUM, 11);
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
        case '3':
            system("cls");
            narrate();
            x[0] = 1;
            HaMiTonian(1);
            printf("\n\n\t\t\t\t 请按任意键继续...\n");
            getchar();
            getchar();
            break;
        };
    } while (ck != 'e');
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
        printf("\n\t\t\t┏━━━━━━━━━━━━━━━┑\n");
        printf(  "\t\t\t┃               ┃\n");
        printf(  "\t\t\t┃ 1、查询建筑路径┃\n");
        printf(  "\t\t\t┃ 2、查询建筑信息┃\n");
        printf(  "\t\t\t┃ 3、选择出发点和目的地 ┃\n");
        printf(  "\t\t\t┃ e、退出        ┃\n");
        printf(  "\t\t\t┃               ┃\n");
        printf(  "\t\t\t┗━━━━━━━━━━━━━━━┛\n");
        printf(  "\t\t\t\t 请输入您的选择：");
        scanf("%c", &c);
        if (c == '1' || c == '2' || c == '3' || c == 'e')
            flag = 0;
    } while (flag);
    return c;
}