# include<stdio.h>
# include<malloc.h>
# include<string.h>
// #include "stdlib.h"
# include "functions.c"

// int main(){
//     char * str = (char*)malloc(sizeof(char)*20);
//     for(int i=0 ; i<3;i++){
//         if(i==2){
//             scanf("%s",str);
//         }else
//         scanf("%[^,]%*c",str);
//         printf("\n%s",str);
//     }
//     system("pause");
//     return 0;
// }


//测试functions.c中的InitMenu用的main函数
int main()
{
	char tempC ;
	char * inputCSVfile = (char*)malloc(200*sizeof(char));
 	printf("输入存储邻接矩阵的CSV文件的地址：\n>");
	// while((tempC = getchar()) != '\n' && tempC != EOF);           //清空stdin的输入缓存,如果前方没有输入加该句反而会导致意外停止
	fgets(inputCSVfile,200 , stdin);   //输入的文件路径长度限为200个字符，超过就会报错（linux环境下gcc不支持gets）
	// fputs(inputCSVfile,stdout);     //输出写法
	if(inputCSVfile[strlen(inputCSVfile) - 1] == '\n') //fgets取得的字符串末尾会含'\n',导致该路径字符串不可用，因此需要将其最后一个字符换为'\0'
        inputCSVfile[strlen(inputCSVfile) - 1] = '\0' ;//
	CreateUDN(inputCSVfile);
	CreateUDN("./inputExamples/matrix.CSV");

	system("pause");
	return 0;
}

// //测试search.c
// int main(){
//     search();
// 	return 0;

// }



// int split(char **arr, char *str, const char *delim){
//     char *s = strtok(str, delim);
//     int c=0;
//     while (s!=NULL) {
//         *arr++ = s;
//         s = strtok(NULL, delim);
//         c++;
//     }
//     return c;
// }

// int main(){
//     char * str[NUM]; //string 类型的指针能存入NUM个字符串
//     for(int i;i<NUM;i++){
//         str[i]=(char *)calloc(20,sizeof(char));//每个子串给20个字符的空间，相比malloc能够初始化，便于通过其内的字符来判断是否为空
//     }
//     char * getin = (char *)calloc(70 , sizeof(char));
//     gets(getin);
//     split(str,getin,",");
//     for(int i=0 ; i< NUM;i++){
//         printf("%s\n",str[i]);
//     }
//     return 0;
// }
