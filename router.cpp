// Authors Nathan Lin, Vijay Kumar

#include "TripsRunner.h"
#include "router.h"


Router::Router(int numCities, int numFlights, Flight *flights)
{
  arr = new vertex[numCities];
  //arr->adj = new unsigned[numCities];
  for(int i = 0; i < numCities; i++)
  {
    arr[i].adj = new unsigned[numCities];
  }//for(i)
  edges = new Flight[numFlights];
  for(int i = 0; i < numFlights; i++)
  {
    arr[flights[i].originIndex].adj[arr[flights[i].originIndex].count] = flights[i].destinationIndex;
    arr[flights[i].originIndex].count++;
  }//for(i)
} // Router()


void Router::findRoute(const Trip* trip, Itinerary *itinerary)
{
   itinerary->numFlights = 0;  // to be set by student
}  // findRoute

