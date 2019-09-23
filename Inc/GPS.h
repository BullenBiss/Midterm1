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

#define JugOne0_Pin GPIO_PIN_0
#define JugOne0_GPIO_Port GPIOC
#define JugOne1_Pin GPIO_PIN_1
#define JugOne1_GPIO_Port GPIOC
#define JugOne2_Pin GPIO_PIN_2
#define JugOne2_GPIO_Port GPIOC
#define JugOne3_Pin GPIO_PIN_3
#define JugOne3_GPIO_Port GPIOC
#define JugTow0_Pin GPIO_PIN_4
#define JugTow0_GPIO_Port GPIOC
#define JugTwo1_Pin GPIO_PIN_5
#define JugTwo1_GPIO_Port GPIOC
#define JugTwo2_Pin GPIO_PIN_6
#define JugTwo2_GPIO_Port GPIOC

#include <stdio.h>
#include "datatypes.h"
#include "stm32f4xx_hal.h"



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

  void sendToLED(Node node);
  void resetLed(void);
  void showSolutionOnLED(Node );
  void blinkLEDS(void);
#endif /* GPS_H_ */
