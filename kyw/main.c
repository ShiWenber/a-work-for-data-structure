
void HaMiTonian(int n)   /* ���ܶ���ͼ�ı��� */
{
   while(n<=9){
   NextValue(n);  /*���ö������·��*/
   if(x[n]==0)
    return;
   if(n==8&&G.arcs[0][x[9]-1].adj!=-1) /*�ҵ�һ�����ܶ��ٻ�·*/
    display();    /* ��ʾ������� */
   else   /*·��δ����*/
    HaMiTonian(n+1);   /*��������*/
    }
    return;
}

void NextValue(int m)  /*��һ����*/
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

void display()   /* ��ʾ������� */
{
 int i=0;
 printf("/nt");
 for(i=0;i<9;i++)
  printf("%s->",G.vex[x[i]-1].sight);
 printf("����");
 printf("/n");
}
