    #include<stdio.h>  
    #include<stdlib.h>  
    int cmp(const void *a,const void *b)        
    {        
        return (*(int*)a) > (*(int*)b) ? 1 : -1;        
    }        
    int main()  
    {  
        int num,k,n,m,a[10005],b[10005],i,j;  
        while(scanf("%d%d",&n,&m)!=EOF)  
        {  
            num=0;  
            for(i=0;i<n;i++)  
              scanf("%d",&a[i]);  
            for(i=0;i<m;i++)  
              scanf("%d",&b[i]);    
            qsort(a,n,sizeof(int),cmp);  
            qsort(b,m,sizeof(int),cmp);  
            k=0;  
            for(i=0;i<n;i++)  
            {  
              for(j=k;j<m;j++)  
              {  
                    if(a[i]==b[j])  
                    {  
                        num++;  
                        k=j+1;  
                        break;  
                    }  
              }  
            }  
            printf("%d\n",num);  
        }  
      
         return 0;  
      
      }  