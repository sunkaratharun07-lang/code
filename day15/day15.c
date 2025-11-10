#include <stdio.h>

int main( )
{
   int n , i ;
   int marks[10] ;
   int highest = 0 , lowest = 100 ;
   int sum = 0 ;
   float average = 0 ;
   int pass = 0 , fail = 0 ;

   int aplus = 0 , a = 0 , b = 0 , c = 0 , d = 0 , f = 0 ;

   printf("========= student performance analyzer =========\n");
   printf("enter total number of students (max 10) : ");
   scanf("%d" , &n);

   if ( n > 10 || n <= 0 )
   {
       printf("invalid number of students !\n");
       return 0 ;
   }

   printf("enter marks for each student : \n");

   for ( i = 0 ; i < n ; i++ )
   {
       printf("student %d : ", i + 1 );
       scanf("%d", &marks[i]);

       if ( marks[i] > 100 || marks[i] < 0 )
       {
           printf("invalid marks entered, please restart program.\n");
           return 0;
       }

       sum = sum + marks[i];

       if ( marks[i] > highest )
          highest = marks[i];
       if ( marks[i] < lowest )
          lowest = marks[i];

       if ( marks[i] >= 50 )
          pass = pass + 1 ;
       else
          fail = fail + 1 ;

       if ( marks[i] >= 90 )
          aplus = aplus + 1 ;
       else if ( marks[i] >= 80 )
          a = a + 1 ;
       else if ( marks[i] >= 70 )
          b = b + 1 ;
       else if ( marks[i] >= 60 )
          c = c + 1 ;
       else if ( marks[i] >= 50 )
          d = d + 1 ;
       else
          f = f + 1 ;
   }

   average = (float)sum / n ;

   printf("========= result summary =========\n");
   printf("average marks : %.2f\n", average );
   printf("highest marks : %d\n", highest );
   printf("lowest marks  : %d\n", lowest );
   printf("total passed students : %d\n", pass );
   printf("total failed students : %d\n", fail );

   printf("grade distribution : \n");
   printf("a+ : %d\n", aplus );
   printf("a  : %d\n", a );
   printf("b  : %d\n", b );
   printf("c  : %d\n", c );
   printf("d  : %d\n", d );
   printf("fail : %d\n", f );

   printf("==================================\n");

   return 0 ;
}
