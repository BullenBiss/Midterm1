/*
 * GPS.h
 *
 *  Created on: 9 sep. 2019
 *      Author: Max
 */

#ifndef GPS_H_
#define GPS_H_
#define BUFFSIZE 200

#include <stdio.h>
#include "datatypes.h"

  typedef struct{
	  int element[10];
  }Node;



  typedef struct List{
  	Node nodeBuff[BUFFSIZE];
  	Node *pBuffBegin;
  	Node *pBuffEnd;
  	int size;
  }List;

  typedef struct{
	  Node initialState;
	  Node goalState;
	  int nUsedElements;
	  int nRules;
	  Node (*rules)(Node N, int iCase);
  }Problem;

// *************************************************** //
  void listInit(List *list);
  void listAppend(List *list, Node node);
  Node listPopFront(List *list);
  bool listIsEmpty(List* list);
  Node listElementAt(List *list, int element);
  bool listContains(List *list, Node comparisonNode);

  Node expandNode(Problem problem, Node open, Node closed, Node New);
  bool nodeIsGoal(Problem problem, Node N);

  Node rulesTwoJugs(Node N, int iCase);
  void twoJugsProblem(Problem *problem);
  int generalProblemSolver(void);
#endif /* GPS_H_ */
