// Authors Nathan Lin, Vijay Kumar

#include "TripsRunner.h"
#include "router.h"


Router::Router(int numCities, int numFlights, Flight *flights)
{
  arr = new vertex[5700];
  //arr->adj = new unsigned[numCities];
  valid = new int[numCities];
  edges = new Flight[numFlights];
  done = 0;
  /*for(int i = 0; i < numCities; i++)
  {
    arr[i].adj = new unsigned[numCities];
    arr[i].count = 0;
    
    for(int j = 0; j < numFlights; j++)
    {
      if(flights[j].originIndex == arr[i].current)
        arr[i].adj[arr[i].count] = flights[j].destinationIndex;
      else
        continue;
    }//for(j)
  }//for(i)*/
  //int j;
  for(int i = 0; i < numFlights; i++)
  {
    //j = arr[flights[i].originIndex].count;
    //arr[i] = flights[i].destinationIndex;
    if(!arr[flights[i].originIndex].current)
    {
      arr[flights[i].originIndex].adj = new unsigned[numCities];
      valid[done] = flights[i].originIndex;
      done++;
      arr[flights[i].originIndex].current = 1;
    }//if
    arr[flights[i].originIndex].adj[arr[flights[i].originIndex].count] = flights[i].destinationIndex;
    arr[flights[i].originIndex].count++;
    //arr[flights[i].originIndex].count++;
    edges[i] = flights[i];
  }//for(i)
} // Router()


void Router::findRoute(const Trip* trip, Itinerary *itinerary)
{
  int count = 0;
  PairingHeap< unsigned short > heap;
  vector<PairingHeap < unsigned short >::Position > p(done);
  for(int i = 0; i < done; i++)
  {
    if((unsigned)valid[i] == trip->originIndex)
      arr[valid[i]].time = 0;
    else
      arr[valid[i]].time = ~0;
    arr[valid[i]].previous = NULL;
    arr[valid[i]].known = false;
    p[i] = heap.insert(arr[valid[i]].time, arr[valid[i]]);
  }//for(i)
  
  arr[trip->originIndex].time = 0;

  //for(int i = 0; i < done; i++)
  while(1)
  {
    vertex v;
    if(heap.isEmpty())
    {
      break;
    }//if
    heap.deleteMin(v);
    //if(!v)
      //break;
    v.known = true;
    for(int j = 0; j < v.count; j++)
    {
      vertex w = arr[v.adj[j]];
      if(!w.known)
      {
        if(v.time + 3 < w.time)
        {
          w.time = v.time;
          w.previous = &v;
          
        }//if(v.time)
      }//if(!w)
    }//for(j)
  }//for(i)

   itinerary->numFlights = count/*0*/;  // to be set by student
}  // findRoute

