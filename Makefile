# Ekaterina Tcareva
# cruzID etcareva

# ===================================================================
# Here we define a few important "make" variables.
# CFLAGS is platform dependent.  This one is for Linux.

CC     = gcc
CFLAGS = -g -Wall -O0 -std=c99 -D_SVID_SOURCE

# The next line has the first target.  Typing "make" without any names
# causes "make" to default to this target.

greedy04:	greedy04.o   loadGraph.o  edgeList.o  minPQ.o
	${CC}  -o greedy04  ${CFLAGS} greedy04.o  loadGraph.o edgeList.o  minPQ.o

greedy04.o:	greedy04.c  loadGraph.h edgeList.h  minPQ.h
	${CC}  -c ${CFLAGS} greedy04.c

edgeList.o:	edgeList.c  edgeList.h
	${CC}  -c  ${CFLAGS}  edgeList.c

minPQ.o:	minPQ.c  minPQ.h
	${CC}  -c  ${CFLAGS}  minPQ.c

loadGraph.o:	loadGraph.c  loadGraph.h  edgeList.h minPQ.h
	${CC}  -c  ${CFLAGS}  loadGraph.c

shuffle:	shuffle.o  edgeList.o minPQ.o
	${CC}  -o shuffle  ${CFLAGS} shuffle.o  edgeList.o minPQ.o

shuffle.o:	shuffle.c edgeList.h minPQ.h
	${CC}  -c  ${CFLAGS} shuffle.c
	
submit04: submit cmps101-avg.f15 greedy04 edgeList.c edgeList.h minPQ.h minPQ.c  loadGraph.h loadGraph.c Makefile test_example2.in test_example1.in README.txt greedy04.c

# ===================================================================