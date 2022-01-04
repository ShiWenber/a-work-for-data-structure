#include "string.h" 
#include "stdio.h" 
#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#define Max 20000
#define NUM 9
#define ERROR -1
typedef struct ArcCell{
int adj; /* ���ڽӵĽ���֮���·�� */
}ArcCell; /* ����ߵ����� */
typedef struct VertexType{
int number; /* ������� */
char *sight; /* �������� */
char *description; /* �������� */
}VertexType; /* ���嶥������� */
typedef struct{
VertexType vex[NUM]; /* ͼ�еĶ��㣬��Ϊ���� */
ArcCell arcs[NUM][NUM]; /* ͼ�еıߣ���Ϊ������ľ��� */
int vexnum,arcnum; /* ������������ */
}MGraph; /* ����ͼ������ */
MGraph G; /* ��ͼ����Ϊȫ�ֱ��� */
int P[NUM][NUM]; /* */
long int D[NUM]; /* ���������洢���·������ */
int prev[NUM];
int x[9]={0}; 
void CreateUDN(int v,int a); /* ��ͼ���� */
void narrate(); /*˵������*/
void ShortestPath(int S); /*���·������*/
void output(int sight1,int sight2); /*�������*/
char Menu(); /* ���˵� */
void search(); /* ��ѯ������Ϣ */
char SearchMenu(); /* ��ѯ�Ӳ˵� */
void HaMiTonian(int); /* ���ܶ���ͼ�ı��� */
void NextValue(int); 
void display(); /* ��ʾ������� */

void CreateUDN(){
	
 G.vex[0].number=0;
 G.vex[0].sight="zhongshan building";
 G.vex[0].description="teaching building";
 G.vex[1].number=1;
 G.vex[1].sight="libary";
 G.vex[1].description="school libary";
 G.vex[2].number=2;
 G.vex[2].sight="gewu building";
 G.vex[2].description="teaching building";
 G.vex[3].number=3;
 G.vex[3].sight="software building";
 G.vex[3].description="teaching and laboratory building";
 G.vex[4].number=4;
 G.vex[4].sight="hua building";
 G.vex[4].description=" accommodation building";
 G.vex[5].number=5;
 G.vex[5].sight="lixing building";
 G.vex[5].description="teaching building";
 G.vex[6].number=6;
 G.vex[6].sight="zhiwei restaurant";
 G.vex[6].description="restaurant";
 G.vex[7].number=7;
 G.vex[7].sight="qiu building";
 G.vex[7].description=" accommodation building";
 G.vex[8].number=8;
 G.vex[8].sight="nanyuan stadium";
 G.vex[8].description="a place to exercise";
 
 G.vexnum=9;
 G.arcnum=15;
 //��ʼ������ 
 int i,j;
 for(i=0;i<NUM;i++){
 for(j=0;j<NUM;j++)
 G.arcs[i][j].adj=Max;	
 }
 
 
G.arcs[0][1].adj=800;G.arcs[1][0].adj=800;
G.arcs[0][4].adj=300;G.arcs[4][0].adj=300;
G.arcs[1][2].adj=450;G.arcs[2][1].adj=450;
G.arcs[1][4].adj=500;G.arcs[4][1].adj=500;
G.arcs[1][6].adj=600;G.arcs[6][1].adj=600;
G.arcs[2][3].adj=400;G.arcs[3][2].adj=400;
G.arcs[2][5].adj=400;G.arcs[5][2].adj=400;
G.arcs[2][6].adj=300;G.arcs[6][2].adj=300;
G.arcs[2][7].adj=300;G.arcs[7][2].adj=300;
G.arcs[3][5].adj=60;G.arcs[5][3].adj=60;
G.arcs[4][6].adj=800;G.arcs[6][4].adj=800;
G.arcs[4][8].adj=600;G.arcs[8][4].adj=600;
G.arcs[5][7].adj=250;G.arcs[7][5].adj=250;
G.arcs[6][7].adj=200;G.arcs[7][6].adj=200;
G.arcs[6][8].adj=900;G.arcs[8][6].adj=900;
 
}



void ShortestPath(int vs)//vsΪ��� 
{
    int i,j,k;
    int min;
    int tmp;
    int flag[NUM];      // �����Ƿ��Ѿ��ҵ����·�����б�����flag 

    // ��ʼ��
    for (i = 0; i < NUM; i++)
    {
        flag[i] = 0;              
        prev[i] = 0;              // ����ǰ����Ϊ0�� 
        D[i] = G.arcs[vs][i].adj;
    }

    // ��ʼ����� 
    flag[vs] = 1;
    D[vs] = 0;

    // ����NUM-1�Σ��ҵ�NUM-1������ 
    for (i = 1; i < NUM; i++)
    {
        // Ѱ�ҵ�ǰ����С��·��
        min = Max;
        for (j = 0; j < NUM; j++)
        {
            if (flag[j]==0 && D[j]<min)
            {
                min = D[j];
                k = j;
            }
        }
        // ���ö��������ѻ�ȡ���·���Ķ��㼯 
        flag[k] = 1;

        // ������ǰ���·����ǰ������
        for (j = 0; j < NUM; j++)
        {
            //tmp = (G.arcs==Max ? Max : (min + G.arcs[k][j])); // ��ֹ���
            if (flag[j] == 0 && (min + G.arcs[k][j].adj< D[j]))
            {
                D[j] = min + G.arcs[k][j].adj;
                prev[j] = k;
            }
        }
    }

}


void output(int sight1,int sight2){//������� 
	printf("���·������Ϊ:%d\n���·��Ϊ:",D[sight2]);
	
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





void narrate(){
 printf("����0����ɽ�¥");
 printf(" ����1��ͼ���");
 printf("       ����2������¥\n");
 printf("����3������ѧԺ");
 printf("   ����4����Է����¥");
    printf("   ����5������¥\n");
 printf("����6��֪ζ��");
 printf("     ����7���Է����¥");
 printf("   ����8�����ϴ�ѧ�Է������");
 } 

void search(){
 printf("����0����ѧ¥");
 printf("����1������ĵط�");
 printf("����2����ѧ¥");
 printf("����3����ѧ¥ʵ����\n");
 printf("����4������¥");
 printf("����5����ѧ¥");
 printf("����6���Է��ĵط�");
 printf("����7��ס��¥");
 printf("����8�������ĵط�");
}




void HaMiTonian(int){
	
}





int main() /* ������ */
{
int v0,v1;
char ck;
system("color fc");
CreateUDN();
do
{ 
 ck=Menu();
 switch(ck)
{
 case '1':
 system("cls");
 narrate();
 printf("\n\n\t\t\t ��ѡ����㽨����0��8����");
 scanf("%d",&v0);
 printf("\t\t\t ��ѡ���յ㽨����0��8����");
 scanf("%d",&v1);
 ShortestPath(v0); /* ������������֮������·�� */
 output(v0,v1); /* ������ */
 printf("\n\n\t\t\t\t �밴���������...\n");
 getchar();
 getchar();
 break;
 case '2':search();
 break;
 case '3':
 system("cls");
 narrate();
 x[0]=1; 
 HaMiTonian(1); 
 printf("\n\n\t\t\t\t �밴���������...\n");
 getchar();
 getchar();
 break;
 };
}while(ck!='e');
}
char Menu() /* ���˵� */
{
char c;
int flag;
do{
 flag=1;
 system("cls");
 narrate();
  printf("\n\t\t\t��������������������������������������������������\n");
 printf("\t\t\t��                       ��\n");
 printf("\t\t\t�� 1����ѯ����·��       ��\n");
 printf("\t\t\t�� 2����ѯ������Ϣ       ��\n");
 printf("\t\t\t�� 3��ѡ��������Ŀ�ĵ� ��\n");
 printf("\t\t\t�� e���˳�               ��\n");
 printf("\t\t\t��                       ��\n");
 printf("\t\t\t��������������������������������������������������\n");
 printf("\t\t ����������ѡ��");
 scanf("%c",&c);
 if(c=='1'||c=='2'||c=='3'||c=='e')
 flag=0;
}while(flag);
return c;
}
