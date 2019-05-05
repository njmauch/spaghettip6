/****************************** deleteAirport ******************************
void deleteAirport(Graph graph, char szAirport[]
 Purpose:
    Given a specified airport, it sets that airports bExists to FALSE indicating
    it does not exist in the vertexM array anymore.  In addition, since it does
    not exists no more, removes all flights pertaining to that airport from other
    airports successor/predecessor lists.
Parameters:
    O Graph graph         Graph containing all connections of airports/flights
    I char szAirport      Specified airport wanting to be removed
Notes:
    1. Implements two for-loops that go through an airports successor and 
       predecessors list to ensure all flights relating to that deleted airport
       are removed.
Returns:
    N/A
*******************************************************************************/
void deleteAirport (Graph graph, char szAirport[])
{
    int i;                    // iterator through number of vertices 
    EdgeNode *eSuc;           // EdgeNode for successor list of airport/vertex
    EdgeNode *ePrev;          // EdgeNode for predecessor list of airport/vertex
    EdgeNode *eSucPrecedes;   // EdgeNode for preceding successors edge 
    EdgeNode *ePrevPrecedes;  // EdgeNode for preceding predecessors edge
    
    /* Loop through all vertices/airports in 
    ** vertexM array.
    */
    for (i = 0; i < graph->iNumVertices; i++)
    {
        // Set to NULL 
        eSucPrecedes = NULL;
        ePrevPrecedes = NULL;
        /* Go through current vertex successorList and check
        ** if specified airport being deleted is in it  and remove.
        */
        for (eSuc = graph->vertexM[i].successorList; eSuc != NULL; eSuc = eSuc->pNextEdge)
        {
            /* compare if destination is removed airport.
            ** If it is, update EdgeNodes connections and free edge
            */
            if (strcmp(eSuc->flight.szDest, szAirport) == 0)
            {              
                eSucPrecedes->pNextEdge = eSuc->pNextEdge;
                free(eSuc);          
                continue;
            }
            eSucPrecedes = eSuc;
        }
        
        /* Go through current vertex predecessorList and check
        ** if specified airport being deleted is in it  and remove.
        */
        for (ePrev = graph->vertexM[i].predecessorList; ePrev != NULL; ePrev = ePrev->pNextEdge)
        {
            /* compare if origin is removed airport.
            ** If it is, update EdgeNodes connections and free edge
            */
            if (strcmp(ePrev->flight.szOrigin, szAirport) == 0)
            {               
                ePrevPrecedes->pNextEdge = ePrev->pNextEdge;
                free(ePrev);          
                continue;
            }
            ePrevPrecedes = ePrev;
        }
    }
    
    // Find airport in the vertexM array and set its bExists to FALSE
    int deletePort;
    deletePort = findAirport(graph, szAirport);
    graph->vertexM[deletePort].bExists = FALSE;
    // Since airport is gone, no pred/sucs... set to NULL
    graph->vertexM[deletePort].predecessorList = NULL;
    graph->vertexM[deletePort].successorList = NULL;
}
