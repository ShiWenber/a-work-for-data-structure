# include<stdio.h>
# include<malloc.h>
# include<string.h>

int main(){
    char * str = (char*)malloc(sizeof(char)*20);
    for(int i=0 ; i<3;i++){
        if(i==2){
            scanf("%s",str);
        }else
        scanf("%[^,]%*c",str);
        printf("\n%s",str);
    }
    return 0;
}





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
