#include <stdio.h>
#include <math.h>

int size = 8;

void binario(int n, int *bi, int id){
    if(n == 0){
        bi[id] = n;
    }else{
        binario(n/2, bi, id-1);
        bi[id] = n % 2;
    }
}
void complemento1(int *bi){
    for(int i = 0; i < size; i++){
        if(bi[i]==0){
            bi[i] = 1;
        }else{
            bi[i] = 0;
        }
    }
}
void complemento2(int *bi, int id){
    if(id>=0){
        if(bi[id] == 0){
            bi[id] = 1;
        }else{
            complemento2(bi, id-1);
            bi[id] = 0;
        }
    }
}
int decimal(int *bi){
    int x = 0, pot = size-2;
    for(int i = 1; i < size; i++){
        x += bi[i]*pow(2, pot);
        pot--;
    }
    return x;
}

int main(){
    int n, bi[size];
    
    for(int i = 0; i < size; i++){
        bi[i] = 0;
    }
    
    printf("Digite um numero(de 0 a 127):");
    scanf("%d",&n);
    
    
    printf("\nEntrada:              Saida:\n");
    printf("    %d :     ",n);
    binario(n, bi, size-1);
    for(int i = 0; i < size; i++){
        printf("%d", bi[i]);
    }
    complemento1(bi);
    printf(" -> ");
    for(int i = 0; i < size; i++){
        printf("%d", bi[i]);
    }
    complemento2(bi, size-1);
    printf(" -> ");
    for(int i = 0; i < size; i++){
        printf("%d", bi[i]);
    }
    printf(" -> ");
    printf("%d",decimal(bi));
    
    return 0;
}
