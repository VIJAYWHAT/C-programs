#include <stdio.h>

int main() {
    
	int year;
	printf("enter the year:");
	scanf("%d",&year);
	
	if(year%100 == 0)
	{
	    if(year%400 == 0)
	    {
	        printf("leap year");
	        
	    }
	    else
	    {
	        printf("not a leap year");
	    }
	}
	else
	{
	    if(year%4 == 0)
	    {
	        printf("leap year");
	        
	    }
	    else
	    {
	        printf("not a leap year");
	    }
	}
	return 0;
}