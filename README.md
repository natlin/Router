1. router.h : changed struct vertex: unsigned *adj; to unsigned adj[1000];
2. router.h : changed struct vertex: int *flightAdj; to short flightAdj[1000];
3. router.cpp: added #include <cstring>  and #include <cstdlib>
4. router.h: changed private: vertex *arr; to vertex arr[5700];
5. router.cpp: commented out arr = new vertex[5700]; in the constructor
6. router.cpp: added line after edges = new Flight[numFlights];
      added line: memcpy(edges, flights, numFlights * sizeof(Flight));
7. router.cpp: commented out the two lines wit new in them in the for loop:
      removed line: arr[flights[i].originIndex].adj = new unsigned[numCities];
      removed line: arr[flights[i].originIndex].flightAdj = new int[numFlights];
8. router.cpp: added a ++ in two lines in the for loop:
    added: arr[flights[i].originIndex].adj[arr[flights[i].originIndex].count++] = flights[i].destinationIndex;
    added: arr[flights[i].originIndex].flightAdj[arr[flights[i]].originIndex].itr++] = i;
9. commented out two lines because of the ++ from step 8:
    removed: arr[flights[i].originIndex].count++;
    removed: arr[flights[i].originIndex].itr++;
10. commented out line edges[i] = flights[i];
11. router.cpp: around line 140, there was an if statement that said if(dur < 30)
    changed the if statement to fix up djikstras:
      changed line: if(dur < 30 && v->current != trip->originIndex)
