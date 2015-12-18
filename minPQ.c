/* minPQ.c 
*/
#include <math.h>
#include <stdlib.h>
#include "minPQ.h"


typedef struct MinPQNode * MinPQ;


struct MinPQNode
{
    int numVertices, numPQ;
    int minVertex;
    double oo;
    int *statusQ;
	 int *parentQ;
   	 double *fringeWgtQ;
};

int isEmptyPQ(MinPQ pq)
{
	int empty;
	if(pq->numPQ == 0)
	{
		empty = 1;//quee is empty
	}
	else 
	{
		empty =0;
	}
	return empty;
}

int getMin(MinPQ pq)
{
	if(pq->minVertex == -1)
	{
		int v;
		double minWgt;
		minWgt=pq->oo;
		for(v=1; v<=pq->numVertices; v++)
		{
			if(pq->statusQ[v]==FRINGE)
			{
				if(pq->fringeWgtQ[v] <minWgt)
				{
					pq->minVertex = v;
					minWgt = pq->fringeWgtQ[v];
				}
			}
		}
	}
	return pq->minVertex;

}

int getStatus(MinPQ pq, int id)
{
	int status;
	status = pq->statusQ[id];
	return status;
}

int getParent(MinPQ pq, int id)
{
	int par;
	par = pq->parentQ[id];
	return par;
}

double getPriority(MinPQ pq, int id)
{
	double priority;
	priority = pq->fringeWgtQ[id];
	return priority;
}

void delMin(MinPQ pq)
{
	int oldMin = getMin(pq);
	pq->statusQ[oldMin] = INTREE;
	pq->minVertex = -1;
	pq->numPQ --;
}

void insertPQ(MinPQ pq, int id, double priority, int par)
{
	pq->parentQ[id] = par;
	pq->fringeWgtQ[id] = priority;
	pq->statusQ[id] = FRINGE;
	pq->minVertex = -1;
	pq->numPQ ++;
}

void decreaseKey(MinPQ pq, int id, double priority, int par)
{
	pq->parentQ[id] = par;
	pq->fringeWgtQ[id] = priority;
	pq->minVertex = -1;
}

MinPQ createPQ(int n, int status[], double priority[], int parent[])
{
	MinPQ pq = calloc(1, sizeof(struct MinPQNode));
	pq->statusQ = status;
	for (int i = 0; i <= n; i++)
		{
			pq->statusQ[i] =UNSEEN;
		}
	pq->parentQ = parent;
   pq->fringeWgtQ = priority;
	pq->numVertices = n;
   pq->numPQ = 0;
   pq->minVertex = -1;
   pq->oo = INFINITY;
   return pq;
}

