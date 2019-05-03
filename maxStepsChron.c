#include "cs2123p6.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************** maxStepsChron ***********************************
int maxStepsChron(Graph graph, int iVertex, int iDestVertex, int iPrevArrTm2400);
Purpose:
	Determines the maximum number of steps to go to from the origin to the destination.
Parameters:
	O Graph graph           Graph containing connections of airports/flights
	I Flight flight         Flight containing information used for insertion
	I EdgeNode **eList      Flights successor or predecessor list
Notes:
	(UPDATE TO ADD ANY NOTES)
Returns
	(Not too sure correct return value)
*******************************************************************************/


// 	This is invoked due to the MAXSTEPS command.  It determines the maximum number of steps to go from the origin to the destination:
// •	Initially, iVertex is the origin vertex.  On subsequent calls, it is a successor vertex.
// •	This uses a depth first traversal to return the maximum number of steps to reach the destination.  
// •	Since we have many paths we must set and reset the bVisited flag in this function.  If we have already visited a destination in the current path, we won't include the flight in the count.  
// •	This only considers successor flights which occur after the arrival of the previous flight.  Please see Time Considerations in the Assignment 5 documentation. 

int maxStepsChron(Graph graph, int iVertex, int iDestVertex, int iPrevArrTm2400)
{
	EdgeNode *e;
	int i = 0;

	//base case >>>
	if(iVertex ==)

	//change bVisited to TRUE	
	graph->vertexM[iAirportVertex].bVisited = TRUE;

	for (e = graph->vertexM[iAirportVertex].successorList; e != NULL; e = e->pNextEdge)
	{
		if (iPrevArrTm2400 <= e->flight.iDepTm2400 + SAFE_DELTA_BETWEEN_FLIGHTS && iAirportVertex != e->iDestVertex)
		{
			i += 1;
		}
	}
	//change bVisited to FALSE
	graph->vertexM[e->iDestVertex].bVisited = FALSE;
}

