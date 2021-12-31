void HaMiTonian(int n)   /* 哈密尔顿图的遍历 */
{
   while(n<=9){
   NextValue(n);  /*将该顶点加入路径*/
   if(x[n]==0)
    return;
   if(n==8&&G.arcs[0][x[9]-1].adj!=-1) /*找到一条哈密尔顿回路*/
    display();    /* 显示遍历结果 */
   else   /*路径未结束*/
    HaMiTonian(n+1);   /*继续遍历*/
    }
    return;
}

void NextValue(int m)  /*下一顶点*/
{
 int j;
l:x[m]=(x[m]+1)%10;
  if(x[m]==0)
   return;
  if(G.arcs[x[m-1]-1][x[m]-1].adj!=-1)
  {
   for(j=0;j<m;j++)
    if(x[j]==x[m])
     goto l;
    return;
  }
  else
   goto l;
}

void display()   /* 显示遍历结果 */
{
 int i=0;
 printf("/nt");
 for(i=0;i<9;i++)
  printf("%s->",G.vex[x[i]-1].sight);
 printf("出口");
 printf("/n");
}
