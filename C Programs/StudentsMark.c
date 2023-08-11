#include <stdio.h>
#include <string.h>

#define MAX 50

struct student{
int num;
int id;
char name[10][10];
};

int main(){

char sub[10][10] = {"Tamil","English","Maths","Science","Social"};
struct student s1;//object for students;
int i,m,a,s=0,n,k,c1 = 0;
char names[10][50];


printf("Enter number of Students: ");
scanf("%d",&n);

int marks[n][5];
int tot_mark[n];
getchar();

for(i=0;i<n;i++)
{
    tot_mark[i] = 0;
    //printf("Enter student %d Name: ",i+1);
    //fgets(s1.name[i],MAX,stdin);
    //s1.name[i][strcspn(s1.name[i], "\n")] = '\0';
    printf("======================\n");
    printf("Enter student %d Marks:\n",i+1);
    printf("----------------------\n");

    for(int j = 0;j<5;j++)
    {
        printf("Enter %s Mark:",sub[j]);
        scanf("%d",&marks[i][j]);
        tot_mark[i] += marks[i][j];
        s++;
    }

}

//int b;
//for(b=0;b<5;b++){
//tot_mark  += marks[b];
//}
//int avg;
//avg = tot_mark /5;

printf("=====================\n");
printf("Students List: \n");
printf("=====================\n");

for(k=0;k<n;k++){

    for(a=0;a<5;a++){
       printf("student %d %s Mark:%d\n",k+1,sub[a],marks[k][a]);

    }

    printf("-------------------\n");
    printf("Total Mark: %d/500\n",tot_mark[k]);
    printf("-------------------\n");

}
return 1;


}
