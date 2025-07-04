/*
 * queue.c
 *
 *  Created on: Jun 25, 2025
 *      Author: rhoblack
 */

#include <my_queue.h>



void Que_Init(Que_TypeDef *q, int sizeofType)
{
	q->front = 0;
	q->rear = 0;
	q->sizeofType = sizeofType;
	for (int i = 0; i < QUE_SIZE; i++) {
		q->queData[i] = malloc(q->sizeofType);
	}
}

void Que_DeInit(Que_TypeDef* q)
{
	for (int i = 0; i < QUE_SIZE; i++) {
		free(q->queData[i]);
	}
}

int isQueFull(Que_TypeDef *q)
{
	return q->front == ((q->rear+1) % QUE_SIZE);
}

int isQueEmpty(Que_TypeDef *q)
{
	return q->front == q->rear;
}

bool enQue(Que_TypeDef *q, void* pData)
{
	if (isQueFull(q)) return false;
	memcpy(q->queData[q->rear], pData, q->sizeofType);
	q->rear = (q->rear+1) % QUE_SIZE;
	return true;
}

bool deQue(Que_TypeDef *q, void* pData)
{
	if (isQueEmpty(q)) return false;
	memcpy(pData, q->queData[q->front], q->sizeofType);
	q->front = (q->front+1) % QUE_SIZE;
	return true;
}

bool peekQue(Que_TypeDef *q, void* pData)
{
	if (isQueEmpty(q)) return false;
	memcpy(pData, q->queData[q->front], q->sizeofType);
	return true;
}



