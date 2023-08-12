#include<stdio.h>

#define CANDIDATE_COUNT

#define CANDIDATE1 "JHON WICK"
#define CANDIDATE2 "JAMES BONT"
#define CANDIDATE3 "TOM CRUZ"
#define CANDIDATE4 "TONY STARK"


void votesCount(){
printf("\n\n ### Voting Statics ###");
printf("\n %s - %d", CANDIDATE1, votesCount1);
printf("\n %s - %d", CANDIDATE2, votesCount2);
printf("\n %s - %d", CANDIDATE3, votesCount3);
printf("\n %s - %d", CANDIDATE4, votesCount4);
printf("\n %s - %d", "Spoiled Votes", spoiledtvotes);
return 0;void castVote(int choice){
}

void getLeadingCandidate(){
printf("\n\n ### Leading Candidate ###\n\n");
if(votesCount1>votesCount2 && votesCount1>votesCount3 && votesCount1>votesCount4)
printf("[%s]",CANDIDATE1);
else if(votesCount2>votesCount3 && votesCount2>votesCount4 && votesCount2>votesCount1)
printf("[%s]",CANDIDATE2);
else if(votesCount3>votesCount4 && votesCount3>votesCount2 && votesCount3>votesCount1)
printf("[%s]",CANDIDATE3);
else if(votesCount4>votesCount1 && votesCount4>votesCount2 && votesCount4>votesCount3)
printf("[%s]",CANDIDATE4);
else
printf("-----Warning !!! No-win situation---");

}

int main()
{
    int i,choice,select;


            printf("\n\n ### Welcome to Election/Voting 2023 ####");
            printf("\n\n 1. Cast The Vote");
            printf("\n 2. List Candidate Name");
            printf("\n 0. Exit");

            printf("\n\n Please enter your choice: ");
            scanf("%d",&choice);

            if(choice != 0){
                if(choice == 1){
            int votesCount1=0,votesCount2=0,votesCount3=0,votesCount4=0,spoiledtvotes=0;
            printf("\n\n###Please choose your Candidate ###\n\n");
            printf("\n 1.%s",CANDIDATE1);
            printf("\n 2.%s",CANDIDATE2);
            printf("\n 3.%s",CANDIDATE3);
            printf("\n 4.%s",CANDIDATE4);
            printf("\n 5.nota");

            printf("\n\n Input your choice(1-5):");
            scanf("%d",&select);

            switch(select){
            case 1:
                votesCount1++;
                break;
            case 2:
                votesCount2++;
                break;
            case 3:
                votesCount3++;
                break;
            case 4:
                votesCount4++;
                break;
            case 5:
                spoiledtvotes++;
                break;
            default:
                printf("\n Error: Wrong Choice!! Please retry");
            getchar();

                }
            }

        //hold the screen
        getchar();
            }
        return 0;
}
