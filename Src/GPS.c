/*
 * GPS.c
 *
 *  Created on: 9 sep. 2019
 *      Author: Max
 */

#include "GPS.h"


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
		if((comparisonNode.element[0] ==  listTempNode.element[0]) && (comparisonNode.element[1] == listTempNode.element[1]))
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
		if((comparisonNode.element[0] ==  listTempNode.element[0]) && (comparisonNode.element[1] == listTempNode.element[1]))
		{
			return true;
		}

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


int generalProblemSolver(List* SOLUTION)
{
	Problem problem;
	Node N;
	twoJugsProblem(&problem);

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
		N = listPopFront(&OPEN);
		listAppend(&CLOSED, N);

		/*
		 * 5. If N represents a goal state, finish with success.
		 * (We've found a way from S to N)
		 */
		if(nodeIsGoal(problem, N))
		{
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
			Node tempNode = problem.rules(N, ruleIterator); // Iterate through the 8 rules and return a viable expanded node
			if(tempNode.element[0] != -1) // -1 means that the node could not be expanded for the specific rule it checked
			{
				if(!listContains(&OPEN, tempNode) && !listContains(&CLOSED, tempNode)) //check if expanded node exists in the lists
				{
					addParent(&N, &tempNode);
					listAppend(&OPEN, tempNode);
				}
			}
		}


		/*
		 * 7. GoTo 3
		 */
	}



}
