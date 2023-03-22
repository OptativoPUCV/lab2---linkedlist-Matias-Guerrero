#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List* lista = (List *) malloc(sizeof(List));
    
    lista->head = NULL;
    lista->tail = NULL;
    lista->current = NULL;
    
    return lista;
}

void * firstList(List * list) {
    
    // Verificamos si el primer dato existe
    if(list->head == NULL)
    {
        // Si no existe, retornamos NULL
        return NULL;
    }

    // Si el primer dato de la lista existe, actualizamos el puntero current para que apunte al primer nodo
    list->current = list->head;

    // Por ultimo retornamos el dato del primer nodo
    return list->head->data;
}

void * nextList(List * list) {
    // Verificamos si el dato siguiente al current existe
    if(list->current == NULL || list->current->next == NULL)
    {
        // Si no existe, retornamos NULL
        return NULL;
    }

    // Si el siguiente dato del current existe, actualizamos el puntero current para que apunte al siguiente nodo
    list->current = list->current->next;

    // Retornamos el dato del nodo siguiente
    return list->current->data;
}

void * lastList(List * list) {
    
    // Verificamos si el ultimo dato de la lista existe
    if(list->tail == NULL)
    {
        // Si no existe, retornamos NULL
        return NULL;
    }

    // Si el ultimo dato de la lista existe, actualizamos el puntero current para que apunte al ultimo nodo
    list->current = list->tail;

    // Por ultimo retornamos el dato del ultimo nodo
    return list->tail->data;
}

void * prevList(List * list) {
    // Verificamos si el dato anterior al current existe
    if(list->current == NULL || list->current->prev == NULL)
    {
        // Si no existe, retornamos NULL
        return NULL;
    }

    // Si el anterior dato al current existe, actualizamos el puntero current para que apunte al siguiente nodo
    list->current = list->current->prev;

    // Retornamos el dato del nodo anterior
    return list->current->data;
}

void pushFront(List * list, void * data) {
    Node* nuevoNodo = createNode(data);

    if(list->head == NULL)
    {
        // Si no hay datos en la lista, actualizamos los nodos de la lista con el nuevo nodo
        list->head = nuevoNodo;
        list->tail = nuevoNodo;
    }
    else
    {
        // Si hay datos, agregamos el nuevo nodo al principio, actualizando los nodos correspondientes
        nuevoNodo->next = list->head;
        list->head->prev = nuevoNodo;
        list->head = nuevoNodo;
    }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    // Verificamos si existe un puntero en current, si es nulo, salimos de la funcion
    if(list->current == NULL)
    {
        return;
    }

    // Si existe el puntero current creamos un nuevo nodo para el dato a agregar
    Node* nuevoNodo = createNode(data);

    // Actualizamos los nodos correspondientes del nodo creado
    nuevoNodo->prev = list->current;
    nuevoNodo->next = list->current->next;

    // Verificamos si el nodo current es el ultimo de la lista
    if(list->current->next != NULL)
    {
        // Si no es el ultimo, actualizamos el puntero prev del siguiente nodo a current
        list->current->next->prev = nuevoNodo;
    }
    else
    {
        // Si es el ultimo, actualizamos el nodo tail de la lista con el nuevo nodo
        list->tail = nuevoNodo;
    }

    // Por ultimo actualizamos el puntero next del nodo current al nuevo nodo
    list->current->next = nuevoNodo;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}