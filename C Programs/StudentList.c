#include <stdio.h>
#include <string.h>

#define MAX 50

struct student{
int num;
int id;
char name[10][10 ];
};

int main(){

char sub[10][10] = {"Tamil","English","Maths","Science","Social"};
struct student s1;//object for students;
int i,m;
char names[10][50];
int marks[100];
int tot_mark=0;

printf("Enter number of Students: ");
scanf("%d",&s1.num);
getchar();

for(i=0;i<s1.num;i++){

    printf("Enter student %d Name: ",i+1);
    fgets(s1.name[i],MAX,stdin);
    s1.name[i][strcspn(s1.name[i], "\n")] = '\0';

    for(int j = 0;j<5;j++){
        printf("Enter %s %s Mark:",s1.name[i],sub[j]);
        scanf("%d",&marks[j]);
    }
    getchar();


}
for(i=0;i<5;i++){
tot_mark  += marks[i];
}
int avg;
avg = tot_mark /5;
printf("=====================\n");
printf("Students Name: \n");
printf("=====================\n");

for(int k=0;k<s1.num;k++){
    printf("Name: ");
    puts(s1.name[k]);
    printf("Mark: %d\n",tot_mark);
    printf("Percentage: %d\%% \n",avg);
    printf("===============");

}
return 1;


}
