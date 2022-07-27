#include <stdio.h>
#include <stdlib.h>
#include "ListSE.h"

void printBT(TreeNode *bt, short level)
{
    int i;
    if(!bt)
        return;
    else
    {
        printBT(bt->right, level + 1);
        for(i = 0; i < level; i++)
            printf("...|");
        printf("%hd\n", bt->info);
        printBT(bt->left, level + 1);
    }
}


//=================================================================//
// Inserindo na arvore                                             //
//=================================================================//
TreeNode* BTinsert(Tdata x, TreeNode *bt){
    TreeNode *aux;

    //verifica se a raiz é nula
    if(bt == NULL){
        // aloca novo nó
        aux = (TreeNode*)malloc(sizeof(TreeNode));
        if(!aux){
            printf("Erro na alocação\n");
            return NULL;
        } else {
            aux->info = x;
            aux->left = NULL;
            aux->right = NULL;
            return aux;
        }
    } else { // a raiz não é nula. Decide se insere à esquerda ou à direita
        if(x < bt->info) {
            bt->left = BTinsert(x, bt->left); // insere no ramo esquerdo
            return bt;
        } 
        else {
            bt->right = BTinsert(x, bt->right);
            return bt;
        }

    }
}



//=================================================================//
// Deletenado a arvore                                             //
//=================================================================//
TreeNode* BTdelete(Tdata x, TreeNode *bt){
    TreeNode *p,*p2;

    if(!bt){
        return bt;
    }
    if(bt->info == x){
        if(bt->left == bt->right){
            //arvore vaiza
            free(bt); //desaloca
            return NULL;
        }
        else if(bt->left == NULL) { // ou se é uma sub-arvore nula

                p = bt->right;
                free(bt);
                return p;
        }
        else if(bt->right == NULL) { //
            p = bt->left;
            free(bt);
            return p;
        }
        else { // ou as duas sub-arvores estao presente
        p2 = bt->left;
        p = bt->left;
        while (p->right != NULL) {
            p = p->right;
            p->right = bt->right;
            free(bt);
            return p2;
        } 
        if(bt->info > x){
            bt->left - BTdelete(x, bt->left);
        }
        else {
            bt->right = BTdelete(x, bt->right);
        }
        return NULL;
        }
    }
}


//=================================================================//
// Procurar elemento                                               //
//=================================================================//

TreeNode* BTsearch(Tdata x, TreeNode *bt){
    if(bt == NULL){
        return NULL; // ou a árvore esta vazia ou desceu até uma folha e nao achou
    } else if(bt->info == x){
        return bt; // achou o valor da chave
    } else if (x< bt->info){
        return BTsearch(x, bt->left); // procura na sub-árvore esquerda
    } else {
        return BTsearch(x, bt->right); // procura na sub-árvore direita
    }
}

//=================================================================//
// Realiza um percurso em largura de árvore. Utiliza uma lista para//
// realizar este procedimento                                      //
//=================================================================//

void BreathFirst(TreeNode *bt){
    TreeNode *raiz = bt;
    TListSE fila;

    initList(&fila);
    if (raiz != NULL)
    {
        insertRight(raiz, &fila);
        // while (!emptyList(bt)){
        //     //
        // }
        
    }
    
}


//=================================================================//
// Percurso de ordem                                               //
//=================================================================//

void PreOrder(TreeNode *bt){
    if(bt == NULL)
        return;
    else
    {
        printf("%hd", bt->info);
        PreOrder(bt->left);
        PreOrder(bt->right);
    }
}


//=================================================================//
// Percurso de ordem                                               //
//=================================================================//

void Order(TreeNode *bt){
    if(bt == NULL)
        return;
    else
    {
        printf("%hd", bt->info);
        Order(bt->right);
        Order(bt->left);
    }
}


//=================================================================//
// Percurso de ordem                                               //
//=================================================================//

void PosOrder(TreeNode *bt){
    if(bt == NULL)
        return;
    else
    {
        PosOrder(bt->right);
        PosOrder(bt->left);
        printf("%hd", bt->info);
    }
}


//=================================================================//
// Calcula a altura de árvore                                      //
//=================================================================//

short BSTaltura(TreeNode *bt){
    short left, right;
    if (bt == NULL)
        return 0;
    else
    {
        right = BSTaltura(bt->right);
        left = BSTaltura(bt->left);

        if (left > right)
            return left+1;
        else
            return right+1;    
    }        
    
}


// ==================== main ====================

int main()
{
    TreeNode *BT = NULL;
    int op;
    Tdata v;
    TreeNode *found;
    do {
        printf("Arvore Binarias de Busca (BSTs)\n");
        printf("Árvore atual: \n\n");
        printBT(BT, 0);
        printf("\n\n");
        printf("Selecione a opção desejada: \n\n");
        printf("\t(0)Sair\n");
        printf("\t(1)Inserir elemento\n");
        printf("\t(2)Remover elemento\n");
        printf("\t(3)Procurar elemento\n");
        printf("\t(4)Percurso em largura\n");
        printf("\t(5)Percurso pré-ordem\n");
        printf("\t(6)Percurso em ordem\n");
        printf("\t(7)Percurso pós-ordem\n");
        printf("\t(8)Altura da árvore\n");
        printf("\t(9)Largura da árvore\n");
        scanf("%d", &op);

        switch(op){
            case 0:
                printf("Saindo. . .");
                break;
            case 1:
                printf("Qual Valor? >> ");
                scanf("%hu", &v);
                BTinsert(v, BT);
                break;
            case 2:
                printf("Qual valor >> ");
                scanf("%hu", &v);
                BT = BTdelete(v, BT);
                break;
            case 3:
                printf("Qual valor? > ");
                scanf("%hu", &v);
                found = BTsearch(v, BT);
                if(found)
                    printf(">>> Valor a ser encontrado no endereço %p <<<\n", found);
                else
                    printf(">>> Valor não encontrado <<<\n");
                break;
            case 4:
                printf("\t\t>>> Percurso em largura <<<\n");
                BreathFirst(BT);
                printf("\n\n");
                break;
            case 5:
                printf("\t\t >> Percurso em pré-ordem <<\n");
                PreOrder(BT);
                printf("\n\n");
                break;
            case 6:
                printf("\t\t >> Percurso em ordem <<\n");
                Order(BT);
                printf("\n\n");
                break;
            case 7:
                printf("\t\t >> Percurso em pós-ordem <<\n");
                PosOrder(BT);
                printf("\n\n");
                break;
            case 8:
                printf(">>> Altura da árvore <<<\n");
                printf("%hd", BSTaltura(BT));
                printf("\n\n");
        }

    }while(op != 0);
    printf("Limpando a árvore . . .\n");
    //BTclear(BT);
    printf("Árvore limpa! \n");
    return 0;
}