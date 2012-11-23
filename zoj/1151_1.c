#include  <stdio.h> 
#include  <string.h> 
int main() 
{ 
   int n=0,i=0,s,t,length,h=0; 
   char a[1000]; 
   char *p; 
   scanf("%d",&h); 
   while (h--) 
   { 
       scanf("%d",&n);
       getchar(); 
       while (n>0) 
       { 
           gets(a); 
           length=strlen(a); 
           p=a; 
           s = -1;
           for (i=1; i <= length ; i++) 
           {  
               if (*(p+i) == ' ' || i == length )  
               { 
                   t = i-1; 
                   for (;t>s;t--) 
                   { 
                       printf("%c",*(p+t));  
                   } 
                   if(i != length)
                       printf(" ");
                   s = i;
               }  
           } 
           printf("\n");
           n--; 
       }
       if(h != 0)
           printf("\n");
   } 
   return 0; 
}