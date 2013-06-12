// Authors Nathan Lin, Vijay Kumar

#include "TripsRunner.h"
#include "router.h"
#include <cstdlib>
#include <cstring>


Router::Router(int numCities, int numFlights, Flight *flights)
{
  //arr = new vertex[5700];
  numFlight = numFlights;
  //arr->adj = new unsigned[numCities];
  valid = new int[numCities];
  edges = new Flight[numFlights];
  memcpy(edges, flights, numFlights * sizeof(Flight));
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
      //arr[flights[i].originIndex].index = flights[i].originIndex;
      //arr[flights[i].originIndex].adj = new unsigned[numCities];
      //arr[flights[i].originIndex].flightAdj = new int[numFlights];
      valid[done] = flights[i].originIndex;
      done++;
      arr[flights[i].originIndex].count = arr[flights[i].originIndex].itr = 0;
      arr[flights[i].originIndex].current = flights[i].originIndex;
    }//if
    arr[flights[i].originIndex].adj[arr[flights[i].originIndex].count++] = flights[i].destinationIndex;
    //cout << i << " ";
    //arr[flights[i].originIndex].flightAdj[arr[flights[i].originIndex].count] = flights[i].flightNum;
    //cout << arr[flights[i].originIndex].flightAdj[arr[flights[i].originIndex].count] << " ";
    //arr[flights[i].originIndex].count++;
    arr[flights[i].originIndex].flightAdj[arr[flights[i].originIndex].itr++] = i;
    //if(i == 93)
      //cout << "here" << endl;
    //arr[flights[i].originIndex].itr++;
    //arr[flights[i].originIndex].flightAdj.insert(
    //arr[flights[i].originIndex].count++;
    //edges[i] = flights[i];
    //if(i == 99)
    //cout << "here" <<endl;
  }//for(i)
} // Router()


void Router::findRoute(const Trip* trip, Itinerary *itinerary)
{
  int count = 0;
  PairingHeap< unsigned short > heap;
  vector<PairingHeap < unsigned short >::Position > p(done);
  vector<int> pindex(done);
  int pindexArr[5700];
  //BinaryHeap<unsigned short > heap;
  for(int i = 0; i < done; i++)
  {
    if((unsigned)valid[i] == trip->originIndex)
      arr[valid[i]].duration = 0;
    else
      arr[valid[i]].duration = 2147483647;
    arr[valid[i]].previous = -1;
    arr[valid[i]].known = false;
    //heap.insert(arr[valid[i]].duration, &arr[valid[i]]);
    p[i] = heap.insert(arr[valid[i]].duration, &arr[valid[i]]);
    pindex[i] = arr[valid[i]].current;
    pindexArr[arr[valid[i]].current] = i;
  }//for(flights[i].originIndex)
  
  arr[trip->originIndex].time = trip->departureTime;
  //arr[trip->originIndex].duration = 0;

  //vertex *v = &arr[trip->originIndex];
  //vertex *test2 = new vertex;
  //test2->duration = 2147483647;
  while(1)
  {
    //vertex *test = test2;
    /*for(int i = 0; i < done; i++)
    {
      if(!arr[valid[i]].known)
        if(test->duration > arr[valid[i]].duration)
        {
          test = &arr[valid[i]];
          v = test;
        }//if*/
      /*if(!(test->known))
      {
        v = test;
      }//if*/
    //}//for(i)
    //delete test;
    if(heap.isEmpty())
      break;
    int vv;
    heap.deleteMin(vv);
    vertex *v = &arr[vv];
    //if(v->known)
      //break;
    v->known = true;
    for(int i = 0; i < v->count; i++)
    {
      vertex *w = &arr[v->adj[i]];
      //cout << "test" << endl;
      if(!w->known)
      {
        //cout << "inside if" << endl;
        for(int j = 0; j < v->itr; j++)
        {
          //cout << "test" << endl;
          Flight temp;
          //temp.duration = 0;
          if(edges[v->flightAdj[j]].destinationIndex == w->current)
            temp = edges[v->flightAdj[j]];
          else
            continue;
          //if(temp.duration == 0)
            //continue;
          int dur;
          if(temp.departureTime - v->time < 0)
            dur = 1440 + (temp.departureTime - v->time);
          else
            dur = temp.departureTime - v->time;
          if(dur < 30 && v->current != trip->originIndex)
          {
            dur = dur + 1440;
          }//if
          //cout << "here i am " << endl;
          //cout << dur << endl;
          //if(temp.flightNum == 21 && trip->destinationIndex == 2675)
            //cout << "here" <<endl;
          if(v->duration + dur + temp.duration < w->duration)
          {
            //cout << "test duration assign" << endl;
            w->duration = v->duration + dur + temp.duration;
            unsigned short t = temp.departureTime + temp.duration;
            if(t >= 1440)
            {
              t = t - 1440;
            }
            w->time = t;
            w->previous = v->current;
            w->flightNum = temp.flightNum;
            //for(int q = 0; q < done; q++)
              //if((unsigned)pindex[q] == w->current)
                heap.decreaseKey(p[pindexArr[w->current]], w->duration);
          }
   
        }//for
      }//if
    }//for
  }//while
            //if(trip->destinationIndex == 2675)
              //cout << "help!" << endl;

  int num = 0;
  int flightArr[20];
  //v = NULL;
  //vertex w = arr[trip->destinationIndex];
  int w = 0;
  w = trip->destinationIndex;

  while(1)
  {
    //cout << "here ";
    if(arr[w].previous >= 0)
    {
      flightArr[num] = arr[w].flightNum;
      w = arr[w].previous;
      num++;
    }//if
    else
      break;
  }//while
  //itinerary->flightNums = flightArr;

  for(int h = num - 1; h >= 0; h--)
  {
    itinerary->flightNums[count] = flightArr[h];
    count++;
  }//for(h)
  #define BUNNY

  #ifndef BUNNY
  #define
  while(1)
  {
    vertex *test = test2;
    for(int i = 0; i < done; i++)
    {
      if(!arr[valid[i]].known)
        if(test->duration > arr[valid[i]].duration)
        {
          test = &arr[valid[i]];
          v = test;
        }//if
      /*if(!(test->known))
      {
        v = test;
      }//if*/
    }//for(i)
    //delete test;
    if(v->known)
      break;
    v->known = true;
    for(int i = 0; i < v->count; i++)
    {
      vertex *w = &arr[v->adj[i]];
      //cout << "test" << endl;
      if(!w->known)
      {
        //cout << "inside if" << endl;
        for(int j = 0; j < v->itr; j++)
        {
          //cout << "test" << endl;
          Flight temp;
          //temp.duration = 0;
          if(edges[v->flightAdj[j]].destinationIndex == w->current)
            temp = edges[v->flightAdj[j]];
          else
            continue;
          //if(temp.duration == 0)
            //continue;
          int dur;
          if(temp.departureTime - v->time < 0)
            dur = 1440 + (temp.departureTime - v->time);
          else
            dur = temp.departureTime - v->time;
          if(dur < 30)
          {
            dur = dur + 1440;
          }//if
          //cout << "here i am " << endl;
          //cout << dur << endl;
          //if(temp.flightNum == 21 && trip->destinationIndex == 2675)
            //cout << "here" <<endl;
          if(v->duration + dur + temp.duration < w->duration)
          {
            //cout << "test duration assign" << endl;
            w->duration = v->duration + dur + temp.duration;
            unsigned short t = temp.departureTime + temp.duration;
            if(t >= 1440)
            {
              t = t - 1440;
            }
            w->time = t;
            w->previous = v->current;
            w->flightNum = temp.flightNum;
          }
          
        }//for
      }//if
    }//for
  }//while
            //if(trip->destinationIndex == 2675)
              //cout << "help!" << endl;

  int num = 0;
  int flightArr[20];
  //v = NULL;
  //vertex w = arr[trip->destinationIndex];
  int w = 0;
  w = trip->destinationIndex;

  while(1)
  {
    //cout << "here ";
    if(arr[w].previous >= 0)
    {
      flightArr[num] = arr[w].flightNum;
      w = arr[w].previous;
      num++;
    }//if
    else
      break;
  }//while
  //itinerary->flightNums = flightArr;

  for(int h = num - 1; h >= 0; h--)
  {
    itinerary->flightNums[count] = flightArr[h];
    count++;
  }//for(h)
  #endif
  //for(int i = 0; i < done; i++)

   itinerary->numFlights = num/*0*/;  // to be set by student
}  // findRoute
