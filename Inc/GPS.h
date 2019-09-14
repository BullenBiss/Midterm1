/*
 * GPS.h
 *
 *  Created on: 9 sep. 2019
 *      Author: Max
 */

#ifndef GPS_H_
#define GPS_H_
#define BUFFSIZE 200
#define NODE_ELEMENTS 10
#define BREADTH_FIRST 1


#include <stdio.h>
#include "datatypes.h"



typedef struct {
	  int element[10];
	  int parentElement[10];
	  int nUsedElements;
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
	  int nRules;
	  Node (*rules)(Node N, int iCase);
  }Problem;

// *************************************************** //
  void listInit(List *list);
  void listAppend(List *list, Node node);
  Node listPopFront(List *list);
  Node listPopBack(List *list);
  bool listIsEmpty(List* list);
  Node listElementAt(List *list, int element);
  bool listContains(List *list, Node comparisonNode);
  Node listCompareAndRead(List *list, Node comparisonNode);

  void copyNode(Node* original, Node* copy);
  Node expandNode(Problem problem, Node open, Node closed, Node New);
  bool nodeIsGoal(Problem problem, Node N);
  void addParent(Node *parent, Node *child);
  Node getParent(Node child);
  bool nodeIsSame(Node original, Node comparisonNode);
  void getSolutionPath(List *SOLUTION, List *CLOSED, Problem problem, Node N);

  Node rulesTwoJugs(Node N, int iCase);
  Node rulesManWolfGoatCabbage(Node N, int iCase);
  void manWolfGoatCabbageProblem(Problem *problem);
  void twoJugsProblem(Problem *problem);
  int generalProblemSolver(List *SOLUTION);
#endif /* GPS_H_ */
