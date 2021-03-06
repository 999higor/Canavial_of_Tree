#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "menu.h"
#include "avl.h"

int avl()
{
    int vrau=0;
    int op;
    int numero;
    int altura;
    struct Node *root = NULL; ///AVL
    FILE *arquivoGravadoAVL;
    FILE *result_search_AVL;
    FILE *result_delete_AVL;

    clock_t t_inicial, t_final;
    double tempo=0;

    do{
            printf(">>>>>> AVL - Balanced Binary Search Tree <<<<<\n");
            printf("1 - INSERT\n");
            printf("2 - DELETE\n");
            printf("3 - SEARCH\n");
            printf("4 - PRINT - IN Order\n");
            printf("5 - PRINT - PRE Order\n");
            printf("6 - RECORD - POS Order\n");
            printf("7 - COUNT - All Elements\n");
            printf("8 - COUNT - All Leafs\n");
            printf("9 - VERIFY - The Height of the Tree\n");
            printf("11 - VERFIFY - The Higher Value\n");
            printf("22 - VERIFY - The Lower Value\n");
            printf("33 - READ - VALUES.TXT\n");
            printf("44 - READ - SEARCH.TXT\n");
            printf("55 - READ - REMOVE.TXT\n");
            printf("0 - EXIT\n");
            printf(">");
            scanf("%i",&op);

            switch(op)
            {
                case 1:
                printf("\nValue: ");
                scanf("%d",&numero);
                root = insert(root, numero);


                break;

                case 2:
                printf("\nValue: ");
                scanf("%d",&numero);

                t_inicial = clock();

                root = deleteNode(root ,numero);

                t_final = clock();
                tempo = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                printf("Time: %lf \n",tempo);



                break;

                case 3:
                printf("\nValue: ");
                scanf("%d",&numero);

                t_inicial = clock();

                printf("\nReturn: %d",search(root, numero));

                t_final = clock();
                tempo = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                printf("Time: %lf \n",tempo);
                break;

                case 4:
                inOrder(root);

                break;

                case 5:
                preOrder(root);

                break;

                case 6:
                arquivoGravadoAVL = fopen("arquivoGravadoAVL.txt" ,"w");
                postOrder(root ,arquivoGravadoAVL);


                fclose(arquivoGravadoAVL);
                break;

                case 7:
                vrau = countElement(root);
                printf("\nTotal of Elements: %d\n",vrau);
                break;

                case 8:
                vrau = countLeaf(root);
                printf("\nTotal of Leafs: %d\n",vrau);
                break;

                case 9:
                vrau = heightTree(root);
                printf("\nTree Height: %d\n",vrau);
                break;

                case 10:
                printf("\n ERRRRROU (voz do faustao.mp3)\n");
                break;

                case 11:
                vrau = higherElement(root);
                printf("\nHigher Element: %d\n",vrau);
                break;

                case 22:
                vrau = smallerElement(root);
                printf("\nLower Element: %d\n",vrau);
                break;

                case 33:

                t_inicial = clock();

                root = ler_arquivoAVL(root);

                t_final = clock();
                tempo = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;
                printf("\nFile Read\n");
                printf("Time: %lf \n",tempo);

                break;

                case 44:
                    t_inicial = clock();

                    result_search_AVL = fopen("result_search_AVL.txt" ,"w");
                    read_search_txt_AVL(root ,result_search_AVL);
                    fclose(result_search_AVL);

                    t_final = clock();

                    tempo = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;

                   // printf("\nFile Read\n");
                    printf("Time: %lf \n",tempo);
                    break;

                case 55:
                    t_inicial = clock();

                    result_delete_AVL = fopen("result_delete_AVL.txt" ,"w");
                    read_delete_txt_AVL(root, result_delete_AVL);

                    altura = heightTree(root);

                    fprintf(result_delete_AVL,"%d",altura);

                    fclose(result_delete_AVL);

                    t_final = clock();

                    tempo = ((double) (t_final - t_inicial)) /CLOCKS_PER_SEC;

                   // printf("\nFile Read\n");
                    printf("Time: %lf \n",tempo);
                    break;

                case 0:
                    break;

                default:
                    printf("\nsera q estou em alagoinha? \n");
            }

    }while(op!=0);

    free_avl(root);

    return 0;
}

