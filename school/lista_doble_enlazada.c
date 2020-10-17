// M2.3. Ejercicio de pilas y colas dinámicas.

// Diaz Reynoso Luis Gerardo - 1260642

// Listas doblemente enlazadas.
// Se pide que implemente un programa para administrar una pantalla espectacular, el programa cuenta con las siguientes opciones:
// 1. Insertar alumno.
// 2. Eliminar alumno.
// 3. Modificar alumno (sólo el promedio).
// 4. Mostrar alumnos ordenados ascendentemente alfabéticamente.
// 5. Mostrar alumnos ordenados descendentemente por promedio.

// Nota:
// No se debe permitir que dos alumnos tengan el mismo nombre.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char nombre[50];
    float promedio;
    struct Node * next;
    struct Node * prev;
    struct Node * sort;
} Node;

Node * insertNode(Node * head, char nombre[], float promedio) {
    Node * temp = (Node*)malloc(sizeof(Node));
    Node * current = head;

    if (head != NULL) {
        while (current != NULL) {
            if (strcmp(current->nombre, nombre) == 0) {
                printf("\n\n~~~ ERROR: No se pueden agregar alumnos que tengan el mismo nombre.\n\n");
                return head;
            }
            current = current->next;
        }
        head->prev = temp;
    }

    strcpy(temp->nombre, nombre);
    temp->promedio = promedio;
    temp->next = head;
    temp->prev = NULL;
    return temp;
}

Node * deleteNode(Node * head, char nombre[]) {
    Node * delete = head;
    Node * next = head;
    Node * prev = head;

    if (delete == NULL) {
        return head;
    }
    if (delete->prev == NULL && delete->next == NULL) {
        if (strcmp(delete->nombre, nombre) == 0) {
            free(delete);
            return NULL;
        }
        return head;
    }

    /* 
        Se puede refactorizar el codigo.
    */
    while (delete != NULL) {
        next = delete->next;
        if (strcmp(delete->nombre, nombre) == 0) {
            prev->next = next;
            if (next != NULL) next->prev = prev;
            if (delete->prev == NULL) {
                next->prev = NULL;
                free(delete);
                return next;
            }
            free(delete);
            return head;
        }
        prev = delete;
        delete = next;
    }

    printf("Alumno no encontrado\n");
    getchar();
    return head;
}

Node * modifyNode(Node * head, char nombre[], float promedio) {
    Node * modify = head;

    if (head == NULL) {
        return head;
    }
    else if (head == NULL || (head->prev == NULL && head->next == NULL)) {
        if (strcmp(head->nombre, nombre) == 0) {
            head->promedio = promedio;
        }
        return head;
    }

    while (modify != NULL) {
        if (strcmp(modify->nombre, nombre) == 0) {
            modify->promedio = promedio;
            return head;
        }
        modify = modify->next;
    }

    printf("Alumno no encontrado\n");
    getchar();
    return head;
}

void prettyPrint(Node * head) {
    printf("\n\n");
    while (head != NULL) {
        printf("( %s , %.2f ), ", head->nombre, head->promedio);
        head = head->next;
    }
    printf("\n\n\n\n");
}

void printList(Node * head) {
    printf("----- HEAD -----\n");
    while (head != NULL) {
        printf("# %p\n", head);
        printf("Nombre: %s\n", head->nombre);
        printf("Promedio: %f\n", head->promedio);
        printf("Next: %p\n", head->next);
        printf("Prev: %p\n\n", head->prev);
        head = head->next;
    }
};

/*
    Merge Sort: Evalua y junta por promedios
*/
Node * mergePromedio(Node * l1, Node * l2) {
    Node * sorted = (Node*)malloc(sizeof(Node));
    Node * current = sorted;

    while (l1 != NULL && l2 != NULL) {
        if (l1->promedio >= l2->promedio) {
            current->next = l1;
            l1 = l1->next;
        }
        else {
            current->next = l2;
            l2 = l2->next;
        }

        current = current->next;
    }

    while (l1 != NULL) {
        current->next = l1;
        l1 = l1->next;
    }
    while (l2 != NULL) {
        current->next = l2;
        l2 = l2->next;
    }

    return sorted->next;
}

/* 
*   Separa la lista enlazada en 2 partes... recursivamente. 
*   [head...temp] [slow...fast]
*/
Node * orderPromedio(Node * head) {
    if (head == NULL || head->next == NULL) return head;

    Node * temp = head;
    Node * slow = head;
    Node * fast = head;

    while (fast != NULL) {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    temp->next = NULL;

    Node * left = orderPromedio(head);
    Node * right = orderPromedio(slow);

    Node * sortedList = mergePromedio(left, right);

    return sortedList;
}

void printOrderPromedio(Node * head) {
    /* 
        Copia lista enlazada a otro espacio de memoria para no perder la original
    */
    Node * newHead = (Node*)malloc(sizeof(Node));
    Node * temp = newHead;

    strcpy(newHead->nombre, head->nombre);
    newHead->promedio = head->promedio;
    newHead->next = NULL;
    newHead->prev = NULL;

    head = head->next;

    while (head != NULL) {
        Node * newNode = (Node*)malloc(sizeof(Node));
        temp->next = newNode;

        strcpy(newNode->nombre, head->nombre);
        newNode->promedio = head->promedio;
        newNode->next = NULL;
        newNode->prev = temp;

        head = head->next;
        temp = temp->next;
    }

    newHead = orderPromedio(newHead);

    prettyPrint(newHead);
    printList(newHead);
}

/*
    Merge Sort: Evalua y junta por nombres alfabeticamente
*/
Node * mergeNombre(Node * l1, Node * l2) {
    Node * sorted = (Node*)malloc(sizeof(Node));
    Node * current = sorted;

    while (l1 != NULL && l2 != NULL) {
        printf("[ %s , %s ]\n", l1->nombre, l2->nombre);
        if (l1->nombre[0] <= l2->nombre[0]) {
            current->next = l1;
            l1 = l1->next;
        }
        else {
            current->next = l2;
            l2 = l2->next;
        }

        current = current->next;
    }

    while (l1 != NULL) {
        current->next = l1;
        l1 = l1->next;
    }
    while (l2 != NULL) {
        current->next = l2;
        l2 = l2->next;
    }

    return sorted->next;
}

/* 
*   Separa la lista enlazada en 2 partes... recursivamente. 
*   [head...temp] [slow...fast]
*/
Node * orderNombre(Node * head) {
    if (head == NULL || head->next == NULL) return head;

    Node * temp = head;
    Node * slow = head;
    Node * fast = head;

    while (fast != NULL) {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    temp->next = NULL;

    Node * left = orderNombre(head);
    Node * right = orderNombre(slow);

    Node * sortedList = mergeNombre(left, right);

    return sortedList;
}

void printOrderNombre(Node * head) {
    /* 
        Copia lista enlazada a otro espacio de memoria para no perder la original
    */
    Node * newHead = (Node*)malloc(sizeof(Node));
    Node * temp = newHead;

    strcpy(newHead->nombre, head->nombre);
    newHead->promedio = head->promedio;
    newHead->next = NULL;
    newHead->prev = NULL;

    head = head->next;

    while (head != NULL) {
        Node * newNode = (Node*)malloc(sizeof(Node));
        temp->next = newNode;

        strcpy(newNode->nombre, head->nombre);
        newNode->promedio = head->promedio;
        newNode->next = NULL;
        newNode->prev = temp;

        head = head->next;
        temp = temp->next;
    }

    newHead = orderNombre(newHead);

    prettyPrint(newHead);
    printList(newHead);
}

int main() {
    Node * head = NULL;
    float promedio;
    char nombre[50];

    int op = 10;
    while (op != 0) {
        system("cls");
        printf("~~~~~~~~~~~~~~~ MENU ~~~~~~~~~~~~~~~\n");
        printf("1) Insertar alumno.\n");
        printf("2) Eliminar alumno.\n");
        printf("3) Modificar alumno (solo el promedio).\n");
        printf("4) Mostrar alumnos ordenados ascendentemente alfabeticamente.\n");
        printf("5) Mostrar alumnos ordenados descendentemente por promedio.\n\n");
        printf("9) Print.\n");
        printf("0) Salir.\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Nombre del alumno: ");
            scanf("%s", nombre);
            printf("Promedio del alumno: ");
            scanf("%f", &promedio);
            head = insertNode(head, nombre, promedio);
            getchar();
            break;
        case 2:
            printf("Nombre del alumno a eliminar: ");
            scanf("%s", nombre);
            head = deleteNode(head, nombre);
            getchar();
            break;
        case 3:
            printf("Nombre del alumno a modificar: ");
            scanf("%s", nombre);
            printf("Nuevo promedio: ");
            scanf("%f", &promedio);
            head = modifyNode(head, nombre, promedio);
            getchar();
            break;
        case 4:
            printOrderNombre(head);
            getchar();getchar();
            break;
        case 5:
            printOrderPromedio(head);
            getchar();getchar();
            break;
        case 9:
            printList(head);
            getchar();getchar();
            break;
        }
    }
}