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
    VertexType vex[NUM+1]; //VertexType vex[NUM];    /* 图中的顶点，即为建筑 */          /*建筑,编号从1开始，留着哨兵位置方便search,也能用其中vex[0].int存地点总数*/
    ArcCell arcs[NUM][NUM]; /* 图中的边，即为建筑间的距离 */
    int vexnum, arcnum;     /* 顶点数，边数 */
} MGraph;                   /* 定义图的类型 */
MGraph G;                   /* 把图定义为全局变量 */

long int D[NUM];            /* 辅助变量存储最短路径长度 */
int x[NUM] = {0};              //原框架为int x[9] = {0}; 

int CreateUDN(char * inputCSVfile);//void CreateUDN(int v, int a);        /* ---造图函数 */
void narrate();                      /*---说明函数*/
void ShortestPath(int num);          /*最短路径函数*/
void output(int sight1, int sight2); /*输出函数*/
char Menu();                         /*---主菜单 */
char InitiMenu();                  /*---初始化子菜单*/
void search();                       /*---查询建筑信息 */
char SearchMenu(int *pt);                   /*---查询子菜单 */
void HaMiTonian(int input);                /* 哈密尔顿图的遍历 */
void NextValue(int input);
void display(); /* 显示遍历结果 */