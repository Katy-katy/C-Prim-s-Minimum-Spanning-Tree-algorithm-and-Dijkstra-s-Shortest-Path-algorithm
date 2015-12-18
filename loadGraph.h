// Ekaterina Tcareva CruzID etcareva

/* loadGraph.h
 * This file defined the standatr interface between the files loadGraph.c and a
 * file which will have #include <loadGraph.h> statement
 */
#include <stdio.h>
#include "edgeList.h"
 
/** preconditions: an array of EdgeLists, a text file whcih contains an weighted graph
 * postcondition: the array has  EdgeLists of adjasted vertex
 */ 
void loadWeightedEdges (EdgeList adjVertices[], FILE *infile, int directed);


