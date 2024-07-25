#include <stdio.h>
#include <stdlib.h>

// Coloque aqui o valor de cada questao (pi)
int ValorDeCadaQuestao[]  = {3, 2, 4, 5, 1, 6};
// Coloque aqui o valor de cada atraso caso faca a questao (fi)
int AtrasoDeCadaQuestao[] = {0, 1, 2, 2, 1, 1};

int NumQuestoes, Contador;

// Funcao que faz a soma de pontos de i = n, n-1, ..., 1
int SomaPontosDasQuest(int *VetorDePontos, int Index){

    // Verifica se estamos tentando fazer uma questao que nao existe
    if (Index >= NumQuestoes) return 0;

    // Verifica se ja fizemos a questao antes (Checagem na tabela)
    // Se sim, retorna o valor ja encontrado, fazendo com que nao
    // Ajam muitas checagens (E aqui que a Programacao Dinamica) esta
    if (Index >= Contador) {
        return VetorDePontos[Index];
    }

    // S(i) = pi + S(pi + 1 + fi)
    VetorDePontos[Index] = ValorDeCadaQuestao[Index] + SomaPontosDasQuest(VetorDePontos, Index + 1 + AtrasoDeCadaQuestao[Index]);
    
    // Checa se vale a pena ou nao fazer a questao
    if (VetorDePontos[Index] < SomaPontosDasQuest(VetorDePontos, Index + 1)) {
        VetorDePontos[Index] = SomaPontosDasQuest(VetorDePontos, Index + 1);
        // Marca que a questao e melhor nao ser feita
        return 0;
    }

    // Marca que a questao e melhor ser feita
    return 1;
}

int main () {

    // Calcula o numero de questoes de forma dinamica
    Contador = NumQuestoes = (sizeof(ValorDeCadaQuestao) / sizeof(ValorDeCadaQuestao[0]));

    // Vetor/Tabela/Lista necessaria para as comparacoes, a fim de evitar
    // O calculo repetido (superposicao)
    int *VetorDePontos = (int*) malloc(NumQuestoes * sizeof(int));    

    // Vetor/Lista que marca quais questoes devem ser feitas ou nao
    // 1 = deve ser feita
    // 0 = nao deve ser feita
    int *VetorDeQuestoesASeFazer = (int*) malloc(NumQuestoes * sizeof(int));

    // Checagem para ver se foi possivel alocar dinamicamente os vetores
    if ((VetorDePontos == NULL) || (VetorDeQuestoesASeFazer == NULL)) {
        printf ("Erro na alocacao do vetor\n");
        return 0;
    }

    // Loop para verificar quais questoes devem ser feitas ou nao
    while(Contador){
        VetorDeQuestoesASeFazer[Contador-1] = SomaPontosDasQuest(VetorDePontos, Contador-1);
        Contador--;
    }

    // Printando no terminal quais questoes deverao ser realizadas
    printf ("Faça a questao ");
    for (int i = 0; i < NumQuestoes; i++){
        if (VetorDeQuestoesASeFazer[i]) printf ("%d ", i+1);
    } printf ("\n");

    // Liberando o espaco alocado nos dois vetores
    free(VetorDePontos);
    free(VetorDeQuestoesASeFazer);

    return 0;
}
