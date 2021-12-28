/*
    date: 
    author: 
*/
# include<stdio.h>
# include<stdlib.h>
bool finish(bool *S,int n)          //是否完成 找寻 
{
    for(int i=0;i<n;i++)
    {
        if(!S[i])
        return false;
    }
    return true; 
}




void ShortestPath(int num)//num为起点（V0）的编号
{
    //初始化数组，NUM为宏定义的最大结点个数
    for(int i=0;i<NUM;i++)
    D[i]=P[num][i];
    D[num]=0;
    //初始化已访问数集S;
    bool S[NUM];

    for(int i=0;i<NUM;i++)
    S[i]=false;

    S[t]=true;

    int j;
    int min;

    while (!finish(S,NUM))
    {   j=0;
        min=MAX;

        for(int i=0;i<NUM;i++)        //寻找最短路径 
        {
            if(S[i]) continue;

            if(min>D[i]) 
            {min=D[i];j=i;}     
        }   

        S[j]=true;      //将j纳入点集S中 

        for(int i=0;i<NUM;i++)        //更新当前最短路径
        {
            if(S[i]) continue;
            if(D[i]>D[j]+P[j][i])
            D[i]=D[j]+P[j][i];      
        }


    }

}

int main(){
    printf("hello world");
    return 0;
}
