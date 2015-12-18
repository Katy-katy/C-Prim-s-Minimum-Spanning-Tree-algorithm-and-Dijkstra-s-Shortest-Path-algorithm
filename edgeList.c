/* Ekaterina Tcareva CruzID etcareva
 * edgeList.c
 * dfs02
 */
#include <stdlib.h>
#include "edgeList.h"

struct EdgeListNode
{
    EdgeInfo edge;
    EdgeList next;
};

const EdgeList edgeNil = NULL;

typedef struct EdgeListNode EdgeListNode;

EdgeInfo edgeFirst(EdgeList oldL)
{
	return oldL -> edge;
}

EdgeList edgeRest(EdgeList oldL)
{
	return oldL ->next;
}

EdgeList edgeCons(EdgeInfo newE, EdgeList oldL)
{
	 EdgeList newList = calloc(1, sizeof(struct EdgeListNode));
    newList->edge = newE;
    newList->next = oldL;
    return newList;
}

