#include <stdio.h>
  
  int f[21][21][21];
  int w(int a, int b, int c)
  {
      if(a <= 0 || b <= 0 || c <= 0)
          return 1;
     
     if(f[a][b][c])
         return f[a][b][c];    
     
     if(a < b && b < c)
         return f[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
     return f[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
 }
 
 int main()
 {
int a, b, c;
     while(scanf("%d %d %d", &a, &b, &c) != EOF)
     {
         if(a == -1 && b == -1 && c == -1)
             break;
         
         printf("w(%d, %d, %d) = ", a, b, c);
        if(a <= 0 || b <= 0 || c <= 0)
             printf("1\n");
        else
         {
             if(a > 20 || b > 20 || c > 20)
                 a = 20, b = 20, c = 20;
             printf("%d\n", w(a, b, c));
         }
    }
   
    return 0;
}
