#include <stdio.h>
#include <string.h>

#define MAX 50

struct student{
int num;
int id;
char name[10][10];
};

int main(){

char sub[] = {"Tamil","English","Maths","Science","Social"};
struct student s1;//object for students;
int i,a,n,b,k;
char names[10][50];


printf("Enter number of Students: ");
scanf("%d",&n);

int marks[n][5];
int tot_mark[n];
getchar();

for(k = 0;k<n;k++){
    printf("Enter student %d Name: ",k+1);
    fgets(s1.name[k],MAX,stdin);
    s1.name[k][strcspn(s1.name[k], "\n")];
}

for(i=0;i<n;i++)
{

    tot_mark[i] = 0;

    printf("======================\n");
    printf("Enter student %d Marks:\n",i+1);
    printf("----------------------\n");

    for(int j = 0;j<5;j++)
    {
        printf("Enter %s %s Mark:",s1.name[i],sub[j]);

        scanf("%d",&marks[i][j]);
        tot_mark[i] += marks[i][j];
    }

}

printf("=====================\n");
printf("Students List: \n");
printf("=====================\n");

for(a=0;a<n;a++){
    printf("Student %d Name:%s",a+1,s1.name[a]);
    printf("-------------------\n");
    for(b=0;b<5;b++)
    {
        printf("%s Mark:%d\n",sub[b],marks[a][b]);

    }
    printf("-------------------\n");
    printf("Total Mark: %d/500\n",tot_mark[a]);
    printf("Precentage: %d%%\n",tot_mark[a]/5);
    printf("===================\n");

}
return 1;


}
