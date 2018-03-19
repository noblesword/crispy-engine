#include<stdio.h>
main()
{
	int i,a[10],b[10],c[20];
	printf("\nEnter 1st array");
       for(i=0;i<10;++i)
	       scanf("%d",&a[i]);
	
	printf("\nEnter 2nd array");
       for(i=0;i<10;++i)
	       scanf("%d",&b[i]);
	       
		   
		   	printf("\n1st array");
       for(i=0;i<10;++i)
	       printf("\n%d",a[i]);
	
	   	printf("\n2nd array");
       for(i=0;i<10;++i)
	       printf("\n%d",b[i])  ; 

	for(i=0;i<20;++i)
	{ 
	   if(a[i]<b[i])
            c[i]=a[i];
		else
		    c[i]=b[i];		
		
		printf("\n%d",c[i]);
	}
	       
}
