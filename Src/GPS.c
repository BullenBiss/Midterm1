/*
 * GPS.c
 *
 *  Created on: 9 sep. 2019
 *      Author: Max
 */

#include "GPS.h"

uint16_t jugOne[4] = {JugOne0_Pin, JugOne1_Pin, JugOne2_Pin, JugOne3_Pin};
uint16_t jugTwo[3] = {JugTow0_Pin, JugTwo1_Pin, JugTwo2_Pin};

Node rulesTwoJugs(Node N, int iCase)
{
	switch(iCase)
	{
	case 1:
		if(N.element[0] < 4 )
		{
			N.element[0] = 4;
			return N;
		}
		break;

	case 2:
		if(N.element[1] < 3 )
		{
			N.element[1] = 3;
			return N;
		}
		break;

	case 3:
		if(N.element[0] > 0 )
		{
			N.element[0] = 0;
			return N;
		}
		break;

	case 4:
		if(N.element[1] > 0 )
		{
			N.element[1] = 0;
			return N;
		}
		break;

	case 5:
		if(((N.element[0] + N.element[1]) >= 4) && N.element[1] > 0)
		{
			N.element[0] = 4;
			N.element[1] = N.element[1]-(4 - N.element[0]);
			return N;
		}
		break;

	case 6:
		if(((N.element[0] + N.element[1]) >= 3) && N.element[0] > 0)
		{
			N.element[0] = N.element[0] - (3 - N.element[1]);
			N.element[1] = 3;
			return N;
		}
		break;

	case 7:
		if(((N.element[0] + N.element[1]) <= 4) && N.element[1] > 0)
		{
			N.element[0] = N.element[0] + N.element[1];
			N.element[1] = 0;
			return N;
		}
		break;

	case 8:
		if(((N.element[0] + N.element[1]) <= 3) && N.element[0] > 0)
		{
			N.element[1] = N.element[0] + N.element[1];
			N.element[0] = 0;

			return N;
		}
		break;
	}

	N.element[0] = -1;
	return N;
}

void twoJugsProblem(Problem *problem)
{
	problem->initialState.nUsedElements = 2;
	problem->initialState.element[0] = 0;
	problem->initialState.element[1] = 0;

	problem->goalState.element[0] = 2;
	problem->goalState.element[1] = 0;
	problem->nRules = 8;
	problem->rules = rulesTwoJugs;

}



Node rulesManWolfGoatCabbage(Node N, int iCase)
{
	// The order goes (Man, wolf, goat, cabbage)
	// 0 = starting side of the river
	// 1 = opposite side of the river
	switch(iCase)
	{
	case 1:
		if((N.element[1] != N.element[2]) && // Move man alone
		   (N.element[2] != N.element[3]))
		{
			N.element[0] = !N.element[0];
			return N;
		}
		break;

	case 2:
		if(N.element[2] != N.element[3] &&  // Move wolf
		   N.element[0] == N.element[1])
		{
			N.element[0] = !N.element[0];
			N.element[1] = !N.element[1];

			return N;
		}
		break;

	case 3:
		if(N.element[0] == N.element[2])  // Move goat
		{
			N.element[0] = !N.element[0];
			N.element[2] = !N.element[2];

			return N;
		}
		break;

	case 4:
		if(N.element[1] != N.element[2] &&  // Move cabbage
		   N.element[0] == N.element[3])
		{
			N.element[0] = !N.element[0];
			N.element[3] = !N.element[3];

			return N;
		}
		break;
	}

	N.element[0] = -1;
	return N;
}
void manWolfGoatCabbageProblem(Problem *problem)
{
	problem->initialState.nUsedElements = 4;
	problem->initialState.element[0] = 0;
	problem->initialState.element[1] = 0;
	problem->initialState.element[2] = 0;
	problem->initialState.element[3] = 0;

	problem->goalState.element[0] = 1;
	problem->goalState.element[1] = 1;
	problem->goalState.element[2] = 1;
	problem->goalState.element[3] = 1;
	problem->nRules = 4;
	problem->rules = rulesManWolfGoatCabbage;

}

void listInit(List *list)
{
	list->pBuffBegin = list->nodeBuff;
	list->pBuffEnd = list->nodeBuff;
	list->size = 0;
}

void listAppend(List *list, Node node)
{
	if(list->pBuffEnd > &list->nodeBuff[BUFFSIZE-1])
	{
		list->pBuffEnd = &list->nodeBuff[0];
	}
	*list->pBuffEnd = node;
	list->pBuffEnd++;
	list->size++;
}

Node listPopFront(List *list)
{
	Node temp;
	temp.element[0] = -1;
	if(list->pBuffBegin != list->pBuffEnd)
	{
		if(list->pBuffBegin > &list->nodeBuff[BUFFSIZE-1])
		{
			list->pBuffBegin = &list->nodeBuff[0];
		}
		temp = *list->pBuffBegin;
		list->pBuffBegin++;
		list->size--;
	}

	return temp;
}

Node listPopBack(List *list)
{
	Node temp;
	temp.element[0] = -1;
	if(list->pBuffBegin != list->pBuffEnd)
	{
		list->pBuffEnd--;
		temp = *list->pBuffEnd;
		list->size--;
	}

	return temp;
}


bool listIsEmpty(List* list)
{
	if(list->pBuffBegin == list->pBuffEnd)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Node listElementAt(List *list, int element)
{
	Node temp;
	Node *pTemp;
	pTemp = list->pBuffBegin;
	temp.element[0] = -1;
	if(list->pBuffBegin != list->pBuffEnd)
	{
		for(int i = 0; i < element; i++)
		{
			list->pBuffBegin++;
			if(list->pBuffBegin > &list->nodeBuff[BUFFSIZE-1])
			{
				list->pBuffBegin = &list->nodeBuff[0];
			}
		}
		temp = *list->pBuffBegin;
		list->pBuffBegin = pTemp;
	}

	return temp;
}

Node listCompareAndRead(List *list, Node comparisonNode)
{
	for(int iList = 0; iList < list->size; iList++)
	{
		Node listTempNode = listElementAt(list, iList);
		int correct = 0;

		for(int i = 0; i < comparisonNode.nUsedElements; i++)
		{
			if(comparisonNode.element[i] == listTempNode.element[i])
			{
				correct++;
			}
		}
		if(correct == comparisonNode.nUsedElements)
		{
			return listTempNode;
		}

	}
}

bool listContains(List *list, Node comparisonNode)
{
	for(int iList = 0; iList < list->size; iList++)
	{
		Node listTempNode = listElementAt(list, iList);
		int correct = 0;

		for(int i = 0; i < comparisonNode.nUsedElements; i++)
		{
			if(comparisonNode.element[i] == listTempNode.element[i])
			{
				correct++;
			}
		}
		if(correct == comparisonNode.nUsedElements)
			return true;
	}

	return false;
}

bool nodeIsGoal(Problem problem, Node N)
{
	int correct = 0;
	for(int i = 0; i < N.nUsedElements; i++)
	{
		if(N.element[i] == problem.goalState.element[i])
		{
			correct++;
		}
	}

	if(correct == N.nUsedElements)
		return true;
	else
		return false;

}


void addParent(Node *parent, Node*child)
{
	for(int i = 0; i < parent->nUsedElements; i++)
	{
		child->parentElement[i] = parent->element[i];
	}
}

Node getParent(Node child)
{
	Node temp;
	temp.nUsedElements = child.nUsedElements;
	for(int i = 0; i < child.nUsedElements; i++)
	{
		temp.element[i] = child.parentElement[i];
	}

	return temp;
}

bool nodeIsSame(Node original, Node comparisonNode)
{
	int correct = 0;
	for(int i = 0; i < original.nUsedElements; i++)
	{
		if(original.element[i] == comparisonNode.element[i])
		{
			correct++;
		}
	}

	if(correct == original.nUsedElements)
		return true;
	else
		return false;
}

void getSolutionPath(List *SOLUTION, List *CLOSED, Problem problem, Node N)
{
	Node solutionPathNode;
	solutionPathNode = N;
	listAppend(SOLUTION, solutionPathNode);

	while(!nodeIsSame(solutionPathNode, problem.initialState))
	{
		solutionPathNode = getParent(solutionPathNode);
		if(listContains(CLOSED, solutionPathNode))
		{
			solutionPathNode = listCompareAndRead(CLOSED, solutionPathNode);
			listAppend(SOLUTION, solutionPathNode);
		}
	}

}

void sendToLED(Node node)
{
	resetLed();
	for(int i = 0; i < node.element[0]; i++)
	{
		HAL_GPIO_WritePin(JugOne0_GPIO_Port, jugOne[i], 1);
	}

	for(int j = 0; j < node.element[1]; j++)
	{
		HAL_GPIO_WritePin(JugOne0_GPIO_Port, jugTwo[j], 1);
	}

}

void resetLed(void)
{
	for(int i = 0; i < 4; i++)
	{
		HAL_GPIO_WritePin(JugOne0_GPIO_Port, jugOne[i], 0);
	}
	for(int j = 0; j < 3; j++)
	{
		HAL_GPIO_WritePin(JugOne0_GPIO_Port, jugTwo[j], 0);
	}
}

void blinkLEDS(void)
{
	resetLed();
	for(int times = 0; times < 6; times++)
	{
		for(int i = 0; i < 4; i++)
		{
			HAL_GPIO_TogglePin(JugOne0_GPIO_Port, jugOne[i]);
		}
		for(int j = 0; j < 3; j++)
		{
			HAL_GPIO_TogglePin(JugOne0_GPIO_Port, jugTwo[j]);
		}
		HAL_Delay(400);
	}
}

int generalProblemSolver(List* SOLUTION)
{
	Problem problem;
	Node N;
	twoJugsProblem(&problem);
	//manWolfGoatCabbageProblem(&problem);

	List OPEN;
	listInit(&OPEN);
	List NEW;
	listInit(&NEW);

	/*
	* 	1. Put the initial state S in an empty list called OPEN.
	*	OPEN contains nodes for expansion.
	*/
	listAppend(&OPEN, problem.initialState);


	/*
	* 	2. Create an empty list CLOSED which
	*	contains already expanded nodes.
	*/
	List CLOSED;
	listInit(&CLOSED);

	while(1)
	{
		/*
		 * 3. If OPEN is empty, finish with failure.
		 */
		if(listIsEmpty(&OPEN))
		{
			int failed = 0;
			return failed;
		}


		/*
		 * 4. Select the first node N in OPEN. Remove N from OPEN and place it in CLOSED.
		 */
		//N = listPopFront(&OPEN);
		N = listPopBack(&OPEN);
		listAppend(&CLOSED, N);


		/*
		 * 5. If N represents a goal state, finish with success.
		 * (We've found a way from S to N)
		 */
		if(nodeIsGoal(problem, N))
		{
			sendToLED(N);
			getSolutionPath(SOLUTION, &CLOSED, problem, N);
			int success = 1;
			return success;
		}


		/*
		 * 6. Expand N, i.e. use the rules to find a set, NEW, of nodes that we can reach from N.
		 * 	  Add the nodes in NEW that are not already in OPEN or CLOSED, to OPEN.
		 */
		for(int ruleIterator = 1; ruleIterator <= problem.nRules; ruleIterator++)
		{
			// Iterate through the rules and return a viable expanded node
			Node NEW = problem.rules(N, ruleIterator);

			// -1 means that the node could not be expanded for the specific rule it checked
			if(NEW.element[0] != -1)
			{
				//check if expanded node exists in the lists
				if(!listContains(&OPEN, NEW) && !listContains(&CLOSED, NEW))
				{
					addParent(&N, &NEW);
					listAppend(&OPEN, NEW);
				}
			}
		}

		sendToLED(N);
		HAL_Delay(1000);
		/*
		 * 7. GoTo 3
		 */
	}
}
