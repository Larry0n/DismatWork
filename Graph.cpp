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
  //Вывести граф с указанием на строки и столбцы 
  void showGraph()
  {
    for(int x=0;x<size;x++)
    {
      for(int y=0;y<size;y++)
      {
          cout<<x;
          cout<<":";
          cout<<y;
          cout<<"=";
          cout<<graphDots[x][y];
      }
      cout<<endl;
    }
  }
 void exportGraph()
  {
    cout << "Exported graph: " << endl;
    for(int x=0;x<size;x++)
    {
        for(int y=0;y<size;y++)
        {
            cout<<graphDots[x][y];
            cout<<",";
        }
        cout<<endl;
    }
  }
  //Задать массив точек через другой массив
  void setgraphDots(bool **newGraphDots){
    graphDots = newGraphDots;
  }
};       
