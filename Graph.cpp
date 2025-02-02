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
    updateConnections();
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
 //Экспорт графа
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
 //=============================================================
  //Задать массив точек через другой массив
  void setgraphDots(bool **newGraphDots){
    graphDots = newGraphDots;
    updateConnections();
  }
  //======================================
  
  //Очистка графа
  void clearGraph()
  {
    for(int x=0;x<size;x++)
    {
      for(int y=0;y<size;y++)
      {
          graphDots[x][y] = 0;
      }  
    }
    connections=0;
    kConnection=0;
  }
 //=============================================================
  
 //Ручной ввод
  void manualInput()
  {
    clearGraph();
    for(int x=0;x<size;x++)
    {
      for(int y=0;y<size;y++)
      {
        bool val;
            cout<<x;
            cout<<":";
            cout<<y;
            cout<<"=";
            cin>>val;
            graphDots[x][y]=val;
      }  
    }
    updateConnections();
  }
//=============================================================
  
//Задаём случайные связи графу
  void randomizeGraph()
  {
    clearGraph();
    srand(time(NULL));

      for(int x=0; x<size;x++)
      {
          
          static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
          // Задаём случайное количество связей для вершины
          int cCount =  (rand() * fraction * (size - 1 + 1) + 1);
          int y=x;
          // Равномерно распределяем рандомное число в нашем диапазоне
          while(cCount>0)
          {
            y = (rand() * fraction * (size ));
            bool b = 1;
            if(x!=y)
            {
              graphDots[x][y] = b;
              graphDots[y][x] = b;
            }
            cCount--;
          }
      }
    updateConnections();
  }
  //==================================================================
  
  void updateConnections()
  {
    int kc = size*size;
    connections=0;
    for(int x=0;x<size;x++)
    {
      int xcon = 0;
      for(int y=0;y<size;y++)
      {
        if(graphDots[x][y])
        {
          connections++;
          xcon++;
        }
      }
      if(xcon<kc)
        kc=xcon;
    }
    kConnection = kc;
    connections=connections/2;
  }
 
 //Позволяет получить связи конкретной вершины 
  bool* getVerticesEdges(int vertics)
  {
     return graphDots[vertics];
  }
  //Позволяет установить связи для конкретной вершины 
  void setVerticesEdge(int vertics,bool* vEdge)
  {
     graphDots[vertics] = vEdge;
     updateConnections();
  }
  
  
  void deleteVertics(int vertics)
  {

    bool **newGraphDots;
    newGraphDots = new bool* [size-1]; 
    for (int i = 0; i < size-1; i++)
      newGraphDots[i] = new bool [size-1];

    for(int x=0;x<vertics;x++)
    {
        for(int y=0;y<vertics;y++)
        {
          newGraphDots[x][y]=graphDots[x][y];
        }
    }
    for(int x=vertics;x<size-1;x++)
    {
        for(int y=vertics;y<size-1;y++)
        {
          newGraphDots[x][y]=graphDots[x+1][y+1];
        }
    }
    size=size-1;
    setgraphDots(newGraphDots);
  }
  
};        
     
