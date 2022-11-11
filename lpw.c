#include<stdio.h>
#include<stdlib.h>

struct Node {
    int coeff;
    int power;
    struct Node* next;
};

void create_node(int x, int y, struct Node** temp)
{
    struct Node *r, *z;
    z = *temp;
    if (z == NULL) {
        r = (struct Node*)malloc(sizeof(struct Node));
        r->coeff = x;
        r->power = y;
        *temp = r;
        r->next = (struct Node*)malloc(sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
    else {
        r->coeff = x;
        r->power = y;
        r->next = (struct Node*)malloc(sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
}


void polyadd(struct Node* poly1, struct Node* poly2, struct Node* polya)
{
    while (poly1->next && poly2->next) {
        if (poly1->power > poly2->power) {
            polya->power = poly1->power;
            polya->coeff = poly1->coeff;
            poly1 = poly1->next;
        }

        else if (poly1->power < poly2->power) {
            polya->power = poly2->power;
            polya->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else {
            polya->power = poly1->power;
            polya->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        polya->next
            = (struct Node*)malloc(sizeof(struct Node));
        polya = polya->next;
        polya->next = NULL;
    }
    while (poly1->next || poly2->next) {
        if (poly1->next) {
            polya->power = poly1->power;
            polya->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2->next) {
            polya->power = poly2->power;
            polya->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        polya->next = (struct Node*)malloc(sizeof(struct Node));
        polya = polya->next;
        polya->next = NULL;
    }
}

void polysub(struct Node* poly1, struct Node* poly2, struct Node* polys)
{
    while (poly1->next && poly2->next) {
        if (poly1->power > poly2->power) {
            polys->power = poly1->power;
            polys->coeff = poly1->coeff;
            poly1 = poly1->next;
        }

        else if (poly1->power < poly2->power) {
            polys->power = poly2->power;
            polys->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else {
            polys->power = poly1->power;
            polys->coeff = poly1->coeff - poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        polys->next
            = (struct Node*)malloc(sizeof(struct Node));
        polys = polys->next;
        polys->next = NULL;
    }
    while (poly1->next || poly2->next) {
        if (poly1->next) {
            polys->power = poly1->power;
            polys->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2->next) {
            polys->power = poly2->power;
            polys->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        polys->next = (struct Node*)malloc(sizeof(struct Node));
        polys = polys->next;
        polys->next = NULL;
    }
}

//polymul(struct Node* poly1, struct Node* poly2,struct Node* polym){
 //   while(poly1->next && poly2->next){
 //           while(poly2->next){
 //               polym->coeff = poly1->coeff*poly2->coeff
 //               poly2 = poly2->next;
 //           }
  //          polym->next = (struct Node*)malloc(sizeof(struct Node));
 //           polym = polym->next;
 //           polym->next = NULL;
 //   }
//}

void show(struct Node* node)
{
    while (node->next != NULL) {
        printf("%dx^%d", node->coeff, node->power);
        node = node->next;
        if (node->coeff >= 0) {
            if (node->next != NULL)
                printf("+");
        }
    }
}


int main()
{
    struct Node *poly1 = NULL, *poly2 = NULL, *polya = NULL, *polys = NULL , *polym = NULL;

    create_node(5, 3, &poly1);
    create_node(4, 2, &poly1);
    create_node(2, 1, &poly1);

    create_node(9, 2, &poly2);
    create_node(2, 1, &poly2);

    printf("First Polynomial: ");
    show(poly1);

    printf("\nSecond Polynomial: ");
    show(poly2);

    polya = (struct Node*)malloc(sizeof(struct Node));
    polys = (struct Node*)malloc(sizeof(struct Node));

    polyadd(poly1, poly2, polya);
    polysub(poly1, poly2, polys);


    printf("\nAddition of two polynomials are:");
    show(polya);
    printf("\nSubtraction of Two polynomials are:");
    show(polys);

    return 0;
}
