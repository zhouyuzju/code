#include <stdio.h>
      
     void
      emu_undercut(int* aarr,
                  int* barr,
                  size_t sz,
                  int*  aret,
                  int*  bret)
     {
            int i;
            (*aret) = (*bret) = 0;
            for(i = 0; i < sz; i++)
            {
                    if(aarr[i] > barr[i] + 1)
                        (*aret) += aarr[i];
                    else if(barr[i] > aarr[i] + 1)
                        (*bret) += barr[i];
                    else if(barr[i] == 2 && aarr[i] == 1)
                        (*aret) += 6;
                    else if(barr[i] == 1 && aarr[i] == 2)
                       (*bret) += 6;
                   else if(aarr[i] == barr[i] + 1)
                        (*bret) += aarr[i] + barr[i];
                    else if(barr[i] == aarr[i] + 1)
                        (*aret) += aarr[i] + barr[i];
            }
     }
     
     int
     main()
     {
            int counter = 0;
            while(1)
            {
                    size_t sz;
                    scanf("%d", &sz);
                    if(sz == 0)
                        break;
                    int i;
                    int a[sz], b[sz];
                    for(i = 0; i < sz; i++)
                        scanf("%d", &a[i]);
                    for(i = 0; i < sz; i++)
                        scanf("%d", &b[i]);
                    int ascore, bscore;
                    emu_undercut(a, b, sz, &ascore, &bscore);
                    if(counter > 0)
                        printf("\n");
                    counter = 1;
                    printf("A has %d points. B has %d points.\n", ascore, bscore);
            }
            
            return 0;
    }
