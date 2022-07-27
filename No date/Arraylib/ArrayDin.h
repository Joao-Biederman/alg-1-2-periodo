//Biblioteca de arrays dinâmicos

//==============================//
// Tipos de dados               //
//==============================//

typedef struct
{
    int *dados;
    unsigned n;
} TVetDin;

typedef struct
{
    int **dados;
    unsigned l;
    unsigned c;
} TMatDin;

//==============================//
//Funções                       //
//==============================//

// cria um vetor dinâmico com o tamanho size
void initVetDin(TVetDin *V, unsigned size);

// deleta um vetor dinâmico
void deleteVetDin(TVetDin *V);

// lê um vetor dinâmico
void scanVetDin(TVetDin *V);

// escreve um vetor dinâmico
void printVetDin(TVetDin V);

// realoca um vetor dinâmico
void realocaVetDin(TVetDin *V, unsigned newSize);

// aloca ma matriz dinâmica
void initMatDin(TMatDin *M, unsigned lines, unsigned cols);

// deleta uma matriz dinâmica
void deleteMatDin(TMatDin *M);

// lê uma matriz dinâmica
void scanMatDin(TMatDin *M);

// escreve uma matriz dinâmica
void printMatDin(TMatDin M);

// realoca uma matriz dinâmica
void realocaMatDin(TMatDin *M, unsigned newLines, unsigned newCols);
