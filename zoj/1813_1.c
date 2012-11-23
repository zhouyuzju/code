#include<stdio.h>
#define PI 3.1415927
main()
{
	double diameter ,time;
	double distance ,MPH;
	int i;
	long revolutions;
	scanf("%lf%ld%lf",&diameter,&revolutions,&time);
	i=0;
	while(revolutions!=0)
	{
		distance=PI*diameter*revolutions/(1.0*12*5280);
		MPH=distance/time*60*60;
		i++;
		printf("Trip #%d: %.2f %.2f\n",i,distance,MPH);
		scanf("%lf%ld%lf",&diameter,&revolutions,&time);
	}
}