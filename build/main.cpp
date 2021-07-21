#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

int main()
{
    int soma=0, n,aux,total=0;
    int inst1=0, inst2=0, inst3=0;
    
    srand(time(NULL));
    
    cout<<"=== CONTANDO INSTRUÇÕES ==="<<endl;
    cout<<"\n";
    cout<<"Informe o tamanho da matriz NxN:";
    cin>>n;
    cout<<"\n\n";
    int mat[n][n];
    int cam[n][n];
    cout<<"Gerando matriz aleatória"<<endl;
    cout<<"."<<endl;
    cout<<".."<<endl;
    cout<<"..."<<endl;
    cout<<"...."<<endl;
    cout<<"....."<<endl;
    cout<<"\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aux = (rand() % 99) + 1;
            mat[i][j] = aux;
            inst1++;
        }
        
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
                cam[i][j] = 0;
            
        }
        
    }
    cout<<"\nMatriz gerada:"<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<" | ";
            cout<<setfill(' ')<<setw(2)<<mat[i][j]<<" | ";
        }
        cout<<"\n";
    }
    cout<<"\nPercorrer caminho na matriz:"<<endl;
    int i = 0;
    int j = 0;
    cam[0][0] = mat[0][0];
    mat[0][0] = -1;
    do{
        if(i <(n - 1) && j == 0){
            if(mat[i + 1][j] > mat[i][j + 1]){
                cam[i + 1][j] = mat[i + 1][j];
                mat[i + 1][j] = -1;
                i++;
                inst2++;
            }else{
                cam[i][j + 1] = mat[i][j + 1];
                mat[i][j + 1] = -1;
                j++;
                inst2++;
            }
        }else{
            if(i <(n - 1) && j > 0 && j <(n - 1)){
                if(mat[i + 1][j] > mat[i][j + 1] && mat[i + 1][j] > mat[i][j - 1]){
                cam[i + 1][j] = mat[i + 1][j];
                mat[i + 1][j] = -1;
                i++;
                inst2++;
        }else{
            if(mat[i][j + 1] > mat[i + 1][j] && mat[i][j + 1] > mat[i][j - 1]){
                cam[i][j + 1] = mat[i][j + 1];
                mat[i][j + 1] = -1;
                j++;
                inst2++;
            }else{
                cam[i][j - 1] = mat[i][j - 1];
                mat[i][j - 1] = -1;
                j--;
                inst2++;
            }}
            }else{
                if(i <(n - 1) && j == (n - 1)){
                    if(mat[i + 1][j] > mat[i][j - 1]){
                    cam[i + 1][j] = mat[i - 1][j];
                    mat[i + 1][j] = -1;
                    i++;
                    inst2++;
            }else{
                    cam[i][j - 1] = mat[i][j - 1];
                    mat[i][j - 1] = -1;
                    j--;
                    inst2++;
            }
                }else{
                    if(i == (n - 1)){
                       cam[i][j + 1] = mat[i][j + 1];
                       mat[i][j + 1] = -1;
                       j++;
                       inst2++;
                    }
                }
            }
        }
        
    }while(i != n  && j != n);
    
    
    cout<<"\nCaminho na Matriz:"<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<" | ";
            cout<<setfill(' ')<<setw(2)<<cam[i][j]<<" | "; 
        }
        cout<<"\n";
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            soma = soma + cam[i][j];
            inst3++;
        }
    }
    
    total = inst1 + inst2 + inst3;
    
    cout<<"\nRESULTADOS DO PROGRAMA:\n"<<endl;
    cout<<"Soma do caminho: "<<soma<<endl;
    cout<<"Instruções para preencher matriz aleatória: "<<inst1<<endl;
    cout<<"Instruções para percorrer caminho: "<<inst2<<endl;
    cout<<"Instruções para realizar a soma: "<<inst3<<endl;
    cout<<"Total de Instruções: "<<total<<endl;
    
    cout<<"\n\nPrograma Encerrado!";
    return 0;
}


