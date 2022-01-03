/*
    date: 
    author: 
*/
# include<stdio.h>
# include<stdlib.h>

int prev[NUM];//宏定义前驱结点数组

void ShortestPath(int vs)//vs为起点 
{
    int i,j,k;
    int min;
    int tmp;
    int flag[NUM];      // 顶点是否已经找到最短路径的判别数组flag 

    // 初始化
    for (i = 0; i < NUM; i++)
    {
        flag[i] = 0;              
        prev[i] = 0;              // 起点的前驱设为0； 
        D[i] = G.arcs[vs][i];
    }

    // 初始化起点 
    flag[vs] = 1;
    D[vs] = 0;

    // 遍历NUM-1次，找到NUM-1个顶点 
    for (i = 1; i < NUM; i++)
    {
        // 寻找当前的最小的路径
        min = Max;
        for (j = 0; j < NUM; j++)
        {
            if (flag[j]==0 && D[j]<min)
            {
                min = D[j];
                k = j;
            }
        }
        // 将该顶点纳入已获取最短路径的定点集 
        flag[k] = 1;

        // 修正当前最短路径和前驱顶点
        for (j = 0; j < NUM; j++)
        {
            //tmp = (G.arcs==Max ? Max : (min + G.arcs[k][j])); // 防止溢出
            if (flag[j] == 0 && (min + G.arcs[k][j]< D[j]))
            {
                D[j] = min + G.arcs[k][j];
                prev[j] = k;
            }
        }
    }

}




void output(int sight1,int sight2){//输出函数 
	printf("最短路径长度为:%d\n最短路径为:",D[sight2]);
	
	int i = sight2;
	int temp[NUM];
	int j = 0;
	printf("%d--->",sight1);
	for(;i>=0;){
		if(prev[i]==0) break;
		temp[j++]=prev[i];
		i = prev[i];
	}
	j--;
	
	for(;j>=0;j--){
		printf("%d--->",temp[j]);
	}
	
	
	printf("%d",sight2);

	
}
