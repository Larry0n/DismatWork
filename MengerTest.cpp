#include <iostream>
#include <math.h>
#include <string>
#include "Graph.cpp"
using namespace std;

class MengerTest
{
  public:
    static int dotsPath(Graph graph,int startDot,int finishDot,bool* checked,int count=0)
    {
      int k=count;
        checked[startDot]=true;
        bool* sEdges=graph.getVerticesEdges(startDot);
        if(sEdges[finishDot])
        {
          sEdges[finishDot]=false;
          graph.setVerticesEdge(startDot,sEdges);
          k++;
          Graph temp(graph.size);
          temp.clearGraph();
          k=dotsPath(graph,startDot+1,finishDot,checked,k);
        }else{
          cout<<startDot<<endl;
          for(int e=0;e<sizeof(sEdges);e++)
          {
            
            if(sEdges[e]&&!checked[e])
            {
              checked[e]=true;
              sEdges[e]=false;
              graph.setVerticesEdge(startDot,sEdges);
              if(e==finishDot)
              {
                if(e+1<graph.size)
                {
                  e++;
                  k=dotsPath(graph,e,finishDot,checked,k);
                }
              }else dotsPath(graph,e,finishDot,checked,k);
            }
          }
        }
        return k;
    }
};
