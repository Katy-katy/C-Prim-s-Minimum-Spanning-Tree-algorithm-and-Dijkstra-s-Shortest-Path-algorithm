//Ekaterina Tcareva CruzID etcareva

/* edgeList.h
 * This file defined the standatr interface between the files edgeList.c and a
 * file which will have #include <edgeList.h> statement
 */

#ifndef C101EdgeList
#define C101EdgeList
/* Multiple typedefs for the same type are an error in C. */

typedef struct EdgeListNode * EdgeList;

typedef struct EdgeInfoStruct
    {
    int to;
    double wgt;
    }
    EdgeInfo;

/** edgeNil denotes the empty EdgeList */
extern const EdgeList edgeNil;

/* Access functions
 * the precondition is that EdgeList is not an empty list
 */

/** first
*/
EdgeInfo edgeFirst(EdgeList oldL);

/** rest
*/
EdgeList edgeRest(EdgeList oldL);

/* Constructors
 * the precondition is that we have an EdgeList and EdgeEnfo srtuct
 * the postcondition is a new EdgeList
 */

/** cons
*/
EdgeList edgeCons(EdgeInfo newE, EdgeList oldL);

#endif

