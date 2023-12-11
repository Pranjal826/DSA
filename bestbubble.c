#include <stdio.h>
int main()
{
      int n, c = 0, k = 0, flag = 1;
      scanf("%d", &n);
      int a[n], i, b[n];
      for (i = 0; i < n; i++)
 
    {
            scanf("%d", &a[i]);
            b[i] = a[i];
         
    }
      int t;
      for (i = 1; i <= n - 1 && flag == 1; i++)
 
    {
            flag = 0;
            for (int j = 0; j < n - i; j++)
   
        {
                  if (a[j] > a[j + 1])
     
            {
                        t = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = t;
                        c++;
                        flag = 1;
                     
            }
               
        }
         
    }
      flag = 1;
      for (i = 1; i <= n - 1 && flag == 1; i++)
 
    {
            flag = 0;
            for (int j = 0; j < n - i; j++)
   
        {
                    if (b[j] < b[j + 1])
       
            {
                          t = b[j];
                          b[j] = b[j + 1];
                          b[j + 1] = t;
                          k++;
                          flag = 1;
                       
            }
               
        }
         
    }
      if (k > c)
    printf("%d", c);
      else     printf("%d", k);
}