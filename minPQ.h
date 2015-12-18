/* minPQ.h (what is the purpose of this file? Replace this question.)
*/

#ifndef C101MinPQ
#define C101MinPQ
/* Multiple typedefs for the same type are an error in C. */

typedef struct MinPQNode * MinPQ;

#define UNSEEN ('u')
#define FRINGE ('f')
#define INTREE ('t')

/* Access functions 
* precondition: a MinPQ pq exists.
*/

/** isEmpty
*/
int isEmptyPQ(MinPQ pq);

/** getMin
*/
int getMin(MinPQ pq);

/** getStatus
*/
int getStatus(MinPQ pq, int id);

/** getParent
*/
int getParent(MinPQ pq, int id);

/** getPriority
*/
double getPriority(MinPQ pq, int id);

/* Manipulation procedures 
*/

/** delMin
*precondition: the quee is not empty
*postcondition: the element with min priority is delited
*/
void delMin(MinPQ pq);

/** insertPQ
*postcondition: the element is inserted in the quee
*/
void insertPQ(MinPQ pq, int id, double priority, int par);

/** decreaseKey
*/
void decreaseKey(MinPQ pq, int id, double priority, int par);

/* Constructors 
* preconditins: three arrays and n - number of elements
*postcondition: MinPQ with can manipulete these arrays
*/

MinPQ createPQ(int n, int status[], double priority[], int parent[]);


#endif

