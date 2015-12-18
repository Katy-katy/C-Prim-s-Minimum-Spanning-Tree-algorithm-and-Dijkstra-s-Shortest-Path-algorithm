An implementation in "C" of Prim's Minimum Spanning Tree algorithm (MST) and Dijkstra's Shortest-Path algorithm (SSSP).

This program was written for “Algorithms and Abstract Data Types” (CMPS_101) class at University of California Santa Cruz (November, 2015)

The program executes MST or SSSP based on a command-line option.

The only differences between the algorithms is the function to calculate
priority and whether the graph is undirected or directed.

The input for this program is a text file which describe a weighted graph. 

Example input:
6
1 3 4.5
1 2 1.5
2 3 7.8
2 4 8.8
4 1 7.0
5 6 2.0
1 6 1.0
4 5 1.0
3 4 10.0

The examples of command-line arguments:

Prim MST starting at vertex 5
	greedy04 -P 5 test_example1.in

Dijkstra SSSP starting at vertex 2
	greedy04 -D 2 test_example2.in

OUTPUT: The program prints: 
the original graph, 
a heading that states which algorithm was run and what the start vertex is,
a table on stdout. 

The table includes the columns:
vertex number, 
status, 
priority (cost, depending on which task), 
parent.

An example of run:

./greedy04 -P 5 test_example2.in 
 --------output---------------------------------
 The graph has 6 vertex.
 1 [ 6&1.00, 4&7.00, 2&1.50, 3&4.50]
 2 [ 4&8.80, 3&7.80, 1&1.50]
 3 [ 4&10.00, 2&7.80, 1&4.50]
 4 [ 3&10.00, 5&1.00, 1&7.00, 2&8.80]
 5 [ 4&1.00, 6&2.00]
 6 [ 1&1.00, 5&2.00]

Pirm's MST with the start vertex 5. 

V	Status	Priority	Parent
1	 t	 1.000000	 6	 
2	 t	 1.500000	 1	 
3	 t	 4.500000	 1	 
4	 t	 1.000000	 5	 
5	 t	 0.000000	 -1	 
6	 t	 2.000000	 5	