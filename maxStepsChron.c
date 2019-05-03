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
	I int iVertex 			Starting vertex 
	I int iDestVertex 		Destination vertex in which the function calculates max steps
	I iPrevArrTm2400 		//ADD NOTE HERE
Notes:
	N/A
Returns
	Returns the maximum number of steps to go from the origin to the destination.
*******************************************************************************/


// 	This is invoked due to the MAXSTEPS command.  It determines the maximum number of steps to go from the origin to the destination:
// •	Initially, iVertex is the origin vertex.  On subsequent calls, it is a successor vertex.
// •	This uses a depth first traversal to return the maximum number of steps to reach the destination.  
// •	Since we have many paths we must set and reset the bVisited flag in this function.  If we have already visited a destination in the current path, we won't include the flight in the count.  
// •	This only considers successor flights which occur after the arrival of the previous flight.  Please see Time Considerations in the Assignment 5 documentation. 

int maxStepsChron(Graph graph, int iVertex, int iDestVertex, int iPrevArrTm2400)
{
	EdgeNode *e;
	int iReturn = 0;

	//base cases
	if(graph->vertexM[iVertex].bVisited)
		return 0;
	if(iVertex == iDestVertex)
		return 1;

	//change bVisited to TRUE	
	graph->vertexM[iVertex].bVisited = TRUE;

	for (e = graph->vertexM[iVertex].successorList; e != NULL; e = e->pNextEdge)
	{
		int iMax = maxStepsChron(graph, e->iDestVertex, iDestVertex);

		if (iPrevArrTm2400 <= e->flight.iDepTm2400 + SAFE_DELTA_BETWEEN_FLIGHTS && iVertex != e->iDestVertex)	//check to see if successor flight occurs after the
		{																												//arrival of the previous flight.
			if (iMax > iReturn)
				iReturn = iMax;
		}
	}
	//change bVisited to FALSE
	graph->vertexM[iVertex].bVisited = FALSE;

	if(iReturn != 0)
		iReturn++;

	return iReturn;
}


