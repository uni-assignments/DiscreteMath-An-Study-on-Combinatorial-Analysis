#include "stdio.h"
#include "stdlib.h"

int n1, n2, k1, k2;
int ****memo;

int ****generate_memoization_matrix(int n1, int n2, int k1, int k2){
    
    int ****memo = (int****)malloc(n1*sizeof(int***));
    for (size_t i = 0; i < n1; i++){
        memo[i] = (int***)malloc(n2*sizeof(int**));
        for (size_t j = 0; j < n2; j++){
            memo[i][j] = (int**)malloc(k1*sizeof(int*));
            for (size_t k = 0; k < k1; k++){
                memo[i][j][k] = (int*)malloc(k2*sizeof(int));
                for (size_t l = 0; l < k2; l++){
                    memo[i][j][k][l] = -1;    
                }    
            }
        }
    }

    return memo;
    
}

void test(int n1, int n2, int k1, int k2){
    int count = 0;
    for (size_t i = 0; i < n1; i++){
        for (size_t j = 0; j < n2; j++){
            for (size_t k = 0; k < k1; k++){
                for (size_t l = 0; l < k2; l++){
                    count ++;
                    printf("%d ", memo[i][j][k][l]);
                }    
            }
        }
    }
    printf("\n%d", count);
}
int ceasars_legions(int n1, int n2, int sf, int sh){
    if((n1 < 0) || (n2 < 0) || (sf > k1) || (sh > k2)) return 0;    
    if(n1 == 0 && n2 == 0) return 1;
    if(memo[n1][n2][sf][sh] != -1) return memo[n1][n2][sf][sh];
    
    return memo[n1][n2][sf][sh] = (ceasars_legions(n1-1, n2,sf+1,0) + ceasars_legions(n1,n2-1,0,sh+1));

}


char *greedy_response(int n1, int n2, int k1, int k2){
    
    int size = n1 + n2, aux1 = k1, aux2 = k2;
    char *resp = (char*)malloc(size*sizeof(char));
    
    for (size_t i = 0; i < size; i++){
        if(n1 == 0 && n2 == 0){
            resp[i] = '*';
            break;
        }
        if(n1 >= n2){
            if(aux1 > 0){
                n1--;
                aux1--;
                resp[i] = 'S';
                aux2 = k2;
            } else {
                n2--;
                aux2--;
                resp[i] = 'H';
                aux1 = k1;
            }    
        } else {
            if(aux2 > 0){
                n2--;
                aux2--;
                resp[i] = 'H';
                aux1 = k1;
            } else {
                n1--;
                aux1--;
                resp[i] = 'S';
                aux2 = k2;
            }
        }
    }
    return resp;
}

int main(){
    scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
    memo = generate_memoization_matrix(n1 + 1, n2 + 1, k1 + 1, k2 + 1);
    printf("Quantidade de maneiras de colocar uma sequencia: %d\n", ceasars_legions(n1, n2, 0, 0));
    char *resp = greedy_response(n1,n2, k1, k2);
    if(resp[n1+n2-1] != '*'){
        for (size_t i = 0; i < n1+n2; i++){
            printf("%c", resp[i]);
        }
    }
    printf("\n");
}