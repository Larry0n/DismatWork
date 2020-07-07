#include <iostream>
#include "Graph.cpp"
int main() {
  Graph sd(5);
  //Рандомный массив
  sd.randomizeGraph();
//Ручной вариант ввода массива
  bool** dots;
      dots = new bool* [sd.size]; 
    for (int i = 0; i < sd.size; i++)
        dots[i] = new bool [sd.size]; 
        dots[0][0]=0;
        dots[0][1]=1;
        dots[0][2]=1;
        dots[0][3]=0;
        dots[0][4]=0;

        dots[1][0]=1;
        dots[1][1]=0;
        dots[1][2]=1;
        dots[1][3]=0;
        dots[1][4]=0;

        dots[2][0]=1;
        dots[2][1]=1;
        dots[2][2]=0;
        dots[2][3]=1;
        dots[2][4]=1;

        dots[3][0]=0;
        dots[3][1]=0;
        dots[3][2]=1;
        dots[3][3]=0;
        dots[3][4]=1;

        dots[4][0]=0;
        dots[4][1]=0;
        dots[4][2]=1;
        dots[4][3]=1;
        dots[4][4]=0;
//на случай если будет необходимость показать на статичном графе
  // sd.setgraphDots(dots);
   




}
