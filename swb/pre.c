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