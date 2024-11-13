#include <stdio.h>
#include <string.h>

int main(){
    int n,m,l;
    char e[100], s[100], t[100], frase[100];
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i+=1){  
        scanf("%s %s", &e[i], &s[i]);
        t[i]=s[i]-e[i];
    }
    for(int i=-1; i<m; i++){
        fgets(frase, sizeof(frase), stdin);
        for(int j=0; j<(strlen(frase)); j++){
            for(int k=0; k<(strlen(t)); k++){
                if(frase[j]==e[k]){
                    frase[j]+=t[k];
                }else if(frase[j]==s[k]){
                    frase[j]-=t[k];
                }
            }
        }
        if(i>-1) printf("%s", frase);
    }
    printf("\n");
    return 0;
}