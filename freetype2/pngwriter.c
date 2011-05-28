#include <pngwriter.h>


int main()
{
   int i;
   pngwriter png(300,300,0,"test.png");
   for(i = 1; i < 300;i++)
     {
        png.plot(i,150+100*sin((double)i*9/300.0), 0.0, 0.0, 1.0);
     }
   png.close();
   return 0;
}
