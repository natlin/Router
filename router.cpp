// Authors Nathan Lin, Vijay Kumar

#include "TripsRunner.h"
#include "router.h"


Router::Router(int numCities, int numFlights, Flight *flights)
{
  arr = new vertex[5700];
  //arr->adj = new unsigned[numCities];
  valid = new int[numCities];
  edges = new Flight[numFlights];
  int done = 0;
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
    }//if
    arr[flights[i].originIndex].adj[arr[flights[i].originIndex].count] = flights[i].destinationIndex;
    arr[flights[i].originIndex].count++;
    //arr[flights[i].originIndex].count++;
    edges[i] = flights[i];
  }//for(i)
} // Router()


void Router::findRoute(const Trip* trip, Itinerary *itinerary)
{
   itinerary->numFlights = 0;  // to be set by student
}  // findRoute

