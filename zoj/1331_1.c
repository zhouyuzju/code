#include<stdio.h>
main()
{
	int d,i,j,k;
	for(d=1;d<=200;d++)
		for(i=2;i<d;i++)
			for(j=i+1;j<d;j++)
				for(k=j+1;k<d;k++)
					if(d*d*d==i*i*i+j*j*j+k*k*k)
						printf("Cube = %d, Triple = (%d,%d,%d)\n",d,i,j,k);
}