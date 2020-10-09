// M.2.2 - Ejercicio de pilas y colas dinámicas.

// Diaz Reynoso Luis Gerardo - 1260642

// Un polinomio se puede representar con una cola. 
// El primer elemento de la cola representa el primer término del polinomio, 
// el segundo elemento al segundo término del polinomio y así sucesivamente.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float cst;
    float exp;
    struct Node * next;
} Node;

Node * insertValue(Node * head, float data, float * grado) {
    Node * temp = (Node*)malloc(sizeof(Node));

    temp->next = NULL;
    if (head != NULL) temp->next = head;
    temp->cst = data;
    temp->exp = *grado;

    *grado = *grado + 1;
    return temp;
}

Node * fillList(Node * head, float * grado) {
    float c = 0.0;

    while (c <= 5.0) {
        head = insertValue(head, c, grado);
        c = c + 0.5;
    }
    return head;
}

Node * eliminateByCoeficiente(Node * head, float data) {
    Node * temp = NULL;
    Node * node = head;

    if (head == NULL) return NULL;

    if (head->cst == data) {
        temp = head->next;
        printf("\nNodo con coeficiente %.1f eliminado.\n", head->cst);
        getchar();
        free(head);
        return temp;
    }

    while (node->next != NULL) {
        if (node->next->cst == data) {
            temp = node->next;
            node->next = temp->next;
            printf("\nNodo con coeficiente %.1f eliminado.\n", temp->cst);
            getchar();
            free(temp);
            return head;
        }
        node = node->next;
    }

    printf("\nNo se encontro el nodo con el coeficiente especificado.\n");
    getchar();
    return head;
}

Node * eliminateByExponencial(Node * head, float data) {
    Node * temp = NULL;
    Node * node = head;

    if (head == NULL) return NULL;

    if (head->exp == data) {
        temp = head->next;
        printf("\nNodo con exponente %.1f eliminado.\n", head->exp);
        getchar();
        free(head);
        return temp;
    }

    while (node->next != NULL) {
        if (node->next->exp == data) {
            temp = node->next;
            node->next = temp->next;
            printf("\nNodo con exponente %.1f eliminado.\n", temp->exp);
            getchar();
            free(temp);
            return head;
        }
        node = node->next;
    }

    printf("\nNo se encontro el nodo con el exponente especificado.\n");
    getchar();
    return head;
}

void printList(Node * head) {
    while (head != NULL)
    {
        printf("Constante: %f\n", head->cst);
        printf("Exponencial: %f\n", head->exp);
        printf("Next: %p\n", head->next);
        printf("\n");
        head = head->next;
    }
}

void printPolinomios(Node * head) {
    while (head != NULL)
    {
        if (head->exp == 1) {
            printf("%+.1fx ", head->cst);
        }
        else if (head->exp == 0) {
            printf("%+.1f ", head->cst);
        }
        else {
            printf("%+.1fx^%.0f ", head->cst, head->exp);
        }
        head = head->next;
    }
}

int main() {

    Node * head = NULL; 
    float grado = 0, data = 0;

    int op = 1;
    while (op != 0) {
        system("cls");
        printf("~~~~~~~~~~~~~~~ MENU ~~~~~~~~~~~~~~~\n");
        printf("Programa para capturar polinomios en listas dinamicas.\n\n");
        printf("1) Capturar termino.\n");
        printf("2) Llenar lista con terminos desde 0.0, 0.5, ... 5.0.\n");
        printf("3) Ver polinomio.\n");
        printf("4) Generar tabla de valores.\n");
        printf("5) Eliminar termino por coeficiente.\n");
        printf("6) Eliminar termino por grado.\n");
        printf("0) Salir.\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        scanf("%d", &op);
        printf("\n\n");

        switch (op)
        {
        case 1:
            printf("Coeficiente: ");
            scanf("%f", &data);
            head = insertValue(head, data, &grado);
            getchar();
            break;
        case 2:
            head = fillList(head, &grado);
            break;
        case 3:
            printPolinomios(head);
            getchar();getchar();
            break;
        case 4:
            printList(head);
            getchar();getchar();
            break;
        case 5:
            printf("Coeficiente a eliminar: ");
            scanf("%f", &data);
            head = eliminateByCoeficiente(head, data);
            getchar();
            break;
        case 6:
            printf("Exponente a eliminar: ");
            scanf("%f", &data);
            head = eliminateByExponente(head, data);
            getchar();
            break;
        }
    }
    return 0;
}
