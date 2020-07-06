#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class Graph
{
  public:
  bool **graphDots;
  int size;
  int connections;
  int kConnection; //K - связность
  Graph(int Size)
  {
    size = Size;
    graphDots = new bool* [size]; 
    for (int i = 0; i < size; i++)
        graphDots[i] = new bool [size]; 
    for(int x=0;x<size;x++)
    {
        for(int y=0;y<size;y++)
        {
            if(x==y)
                graphDots[x][y]=0;
            else
                graphDots[x][y]=1;
        }
        
    }
  }
};       
