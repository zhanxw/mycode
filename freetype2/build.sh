# build sample freetype2 
gcc -o ff ff.c -I/usr/include/freetype2 -lfreetype -lm 
./ff /usr/share/cups/fonts/FreeMono.ttf a > out

# build pngwriter, output test.png
g++ -o pngwriter pngwriter.c -I/usr/include/freetype2 -lfreetype  -lpngwriter -lpng
./pngwriter

# my code using freetype2 to draw a character in test.png
g++ -o ff_png ff_png.c -I/usr/include/freetype2 -lfreetype  -lpngwriter -lpng
./ff_png /usr/share/cups/fonts/FreeMono.ttf abc
