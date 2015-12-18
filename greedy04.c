//  FILE: greedy04.c
//  AUTHOR: Ekaterina Tcareva CruzID etcareva
//  CMPS 101-2 Fall 2015, professor Allen Van Gelder
//  December,2 , 2015

#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "edgeList.h"
#include "loadGraph.h"
#include "minPQ.h"

void prWeightedGraph(int n, EdgeList adjVertices[]);
void greedyTree(EdgeList adjVertices[], int n, int s, int status[], int parent[], double fringeWgt[], int task);
void updateFringe(MinPQ pq, EdgeList adjVertices, int v, int task);
void printOutput(int n, int task, int s, int status[], int parent[], double fringeWgt[]);

int main(int argc, const char * argv[]) {
   
    char	line[100];
    int n;
    int directed;
    char *undirectedP = "-P";//Prim's MST
    char *directedD = "-D"; //Dijkstra's SSSP
    char *typeInput = "-";
    int vertexToStart;
    FILE *infile;
   	
   	 if( argc != 4 )
   	 {
   		printf("\nPlease, print the flag, the number vertex to start, and the name of a text file whcih contains the graph. For example: -P 7 graph1.txt for Pim's and -D 7 graph1.txt for Dijkstra's");
   		return 0;
    }

    char *argv1 = argv[1];
	 char *argv2 = argv[2];
	 char *argv3 = argv[3];
    if (strcmp(argv1, undirectedP) == 0) //we wont Pirm's MST
   	 {
    		directed = 0;//the graph is undirected
    }
    else 
    {
    		directed = 1; //we wont Dijdstra's SSST, the graph is directed
    }
    	
    vertexToStart = atoi(argv2);
   
   if (strcmp(argv3, typeInput) == 0)
   {
   		printf("\nI am sorry, but this functionality does not work yet");
   		return 0;
   }
   else
   {
    	infile = fopen(argv[3], "r"); 
   } 	
    
	if (infile == NULL)
	{
		printf ("Unable to open the file/n");
	}
	
	n = atoi(fgets(line, 100, infile));// to get the number of vertex
	printf("\nThe graph has %d vertex.", n);

		EdgeList adjVertices[n+1]; 
	   for (int i = 0; i <= n; i++)
		{
			adjVertices[i] =edgeNil;
		}
		loadWeightedEdges (adjVertices, infile, directed);
		
		prWeightedGraph(n, adjVertices);		//to print the graph
		
		int *status = calloc(n+1, sizeof(int));// we will not use 0 index
		
    	//Allocate an array of parents
   		int *parent = calloc(n+1, sizeof(int));
    
    	//Allocate an array of weight of fringed edges
   		 double *fringeWgt =calloc(n+1, sizeof(double));
   		
   		 greedyTree(adjVertices, n, vertexToStart, status, parent, fringeWgt, directed);
   		 
    	 printOutput(n, directed, vertexToStart, status, parent, fringeWgt);
    	 
   return 0;
}

void greedyTree(EdgeList adjVertices[], int n, int s, int status[], int parent[], double fringeWgt[], int task)
{
	MinPQ pq;
	pq = createPQ(n, status, fringeWgt, parent);
	insertPQ(pq, s, 0, -1);
	while(isEmptyPQ(pq)==0)
	{
		int v = getMin(pq);
		delMin(pq);
		updateFringe(pq, adjVertices[v], v, task);
	}
}

void updateFringe(MinPQ pq, EdgeList adjVertices, int v, int task)
{
	double myDist = getPriority(pq, v);//for Dijkstra's algorithm
	EdgeList remAdj;
	remAdj = adjVertices;
	while(remAdj != edgeNil)
	{
		EdgeInfo wInfo = edgeFirst(remAdj);
		int w = wInfo.to;
		double newWgt = wInfo.wgt;
		double newDist = myDist + newWgt;//for Dijkstra's algorithm
		
		if (task == 0)//Prim's algorithm
		{
			if(getStatus(pq, w) == UNSEEN)
			{
				insertPQ(pq, w, newWgt, v);
			}
			else if(getStatus(pq, w) == FRINGE)
			{
				if(newWgt < getPriority(pq, w))
				{
					decreaseKey(pq, w, newWgt, v);
				}
			}
		}
		
		else //Dijkstra's algorithm
		{
			if(getStatus(pq, w) == UNSEEN)
			{
			insertPQ(pq, w, newDist, v);
			}
			else if(getStatus(pq, w) == FRINGE)
			{
				if(newDist < getPriority(pq, w))
				{
					decreaseKey(pq, w, newDist, v);
				}
			}	
		}	
		remAdj = edgeRest(remAdj);
	}
}

void printOutput(int n, int task, int s, int status[], int parent[], double fringeWgt[])
{
	if (task == 1)
	{
		printf("\nDijdstra's SSST with the start vertex %d. \n", s);
	}
	else 
	{
		printf("\nPirm's MST with the start vertex %d. \n", s);
	}
	printf("\nV\tStatus\tPriority\tParent\n");
   	for(int i = 1; i < n +1; i++){
   		printf("%d\t %c\t %f\t %d\t \n", i, status[i], fringeWgt[i], parent[i]);		 					 		
   }	
   printf("\n");	
	
}

void prWeightedGraph(int n, EdgeList adjVertices[])
{
	for (int i = 1; i <= n; i++)
		{  
		   printf("\n %d [", i);	
		  
			if (adjVertices[i] != edgeNil)		
			{
						  EdgeList move = adjVertices[i];
		         		  printf(" %d", edgeFirst(move).to);
		         		  printf("&%.2lf", edgeFirst(move).wgt);
				 
						  while (edgeRest(move)!=NULL)
						  {
							  move = edgeRest(move);
						     printf(", %d", edgeFirst(move).to);
						     printf("&%.2lf", edgeFirst(move).wgt);			     
					     }	      
			}	
			printf("]");		
		}	
   printf("\n");
}
