#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#define MAX_KEYS 8

typedef struct btNode *bTree;

struct btNode
{
    int isLeaf;     ///e ou nao e no, eis a questao///
    int numKeys;    ///quantas chaves o no contem? ///
    int keys[MAX_KEYS]; ///valor qualquer///
    struct btNode *kids[MAX_KEYS+1];  ///creancinhas < keys///
};

///cria uma arvore b vazia ///
bTree bTree_Create(void);

///taca fogo na arvore e destroi ela///
void bTree_Destroy(bTree b);

///procura um valor na arvore///
static int searchKey(int n, const int *a, int key);

///retorna um valor !0 se a key estiver na arvore b///
int bTree_Search(bTree b, int key);

///faz a insercao interna///
static bTree bTree_Insert_Internal(bTree b, int key, int *median);

///insere um novo elemento na arvore b///
void bTree_Insert(bTree b, int key);

///imprime os valores da arvore b em forma de arvore///
void bTree_Print_Keys_TreeMode(bTree b);

///imprime os valores da arvore b///
void Btree_Print_Keys(bTree b);

///retorna o maior valor na arvore///
int bTree_MAX (bTree b);

///retorna o menor valor na arvore///
int bTree_MIN (bTree b);

///retona a altura da arvore///
int bTree_Height (bTree b);

///conta todos os valores na arvore///
int bTree_Count_All(bTree b);

///conta as folhas da arvore///
int bTree_Count_Leaf(bTree b);

///faz a leitura de um arquivo///
bTree *Btree_Read_File(bTree b);

void read_search_txt_B(bTree raiz, FILE* result_search_Btree);

#endif // BTREE_H_INCLUDED
