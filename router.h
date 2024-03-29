//Authors Nathan Lin, Vijay Kumar
#ifndef ROUTER_H
#define	ROUTER_H

#include "TripsRunner.h"
#include <iostream>
#include "LinkedList.h"

struct vertex
{
  unsigned current;
  unsigned adj[1000];
  bool known;
  unsigned short time;
  //List<Flight> flightAdj;
  //ListItr<Flight> itr;
  short flightAdj[1000];
  int itr;
  unsigned index;
  int duration;
  int count;
  int previous;
  int flightNum;
};

/*struct edge
{
  unsigned *adj;
  bool known;
  int time;
  vertex *previous;
}; Same as Flight struct*/

class Router
{
public:
  Router(int numCities, int numFlights, Flight *flights);
  void findRoute(const Trip* trip, Itinerary *itinerary);
private:
  vertex arr[5700];
  Flight *edges;
  int *valid;
  int done;
  int numFlight;
  
};

#include "BinaryHeap.h"
#include "PairingHeap.h"
#endif	/* ROUTER_H */

