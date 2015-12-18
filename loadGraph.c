//  Ekaterina Tcareva CruzID etcareva
//  loadGraph.c
//  dfs02
#include <stdio.h>
#include <stdlib.h>
#include "loadGraph.h"
#include "edgeList.h"


void loadWeightedEdges (EdgeList adjVertices[], FILE *infile, int directed)
{
	 char	line[100];
    char* fgetsRetn;
    char junk;
    EdgeInfo newE;
    EdgeInfo newE2;//a back edge
	
	fgetsRetn = fgets(line, 100, infile);
	while(fgetsRetn==line) {
			int numFields, from;

    		numFields = sscanf(fgetsRetn, " %d %d %lf %c", &from, &newE.to,  &newE.wgt, &junk);
    		if (directed !=1)//the graph is weighted and underected
    		{
    				newE2.to = from;
    				newE2.wgt = newE.wgt;
    		}
    		    		
    		fgetsRetn = fgets(line, 100, infile);
    
				EdgeList newEdge;
    			if (adjVertices[from] == edgeNil)
    			{
    				newEdge = edgeCons(newE, edgeNil);
   					adjVertices[from] = newEdge;
   		 		}
   		  		else
   		  		{
  					newEdge = edgeCons(newE, adjVertices[from]);
  					adjVertices[from] = newEdge;
			   }
			
			
				if (directed !=1)//the graph is undirected and weighted
				{
					int from2 = newE.to;
					
    				if (adjVertices[from2] == edgeNil)
    				{
    					newEdge = edgeCons(newE2, edgeNil);
   						adjVertices[from2] = newEdge;
   		 	  		}
   		   			else 
   		   			{
  						newEdge = edgeCons(newE2, adjVertices[from2]);
  						adjVertices[from2] = newEdge;
					}	
				}			
   }		
}





