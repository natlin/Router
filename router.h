//Authors Nathan Lin, Vijay Kumar
#ifndef ROUTER_H
#define	ROUTER_H

#include "TripsRunner.h"

class Router
{
public:
  Router(int numCities, int numFlights, Flight *flights);
  void findRoute(const Trip* trip, Itinerary *itinerary);
private:
  

};

#endif	/* ROUTER_H */

