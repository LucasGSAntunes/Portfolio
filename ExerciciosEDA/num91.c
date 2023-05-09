#include <stdio.h>
#include <stdlib.h>

int f91(int n);

int main() {
    int n[1000000], result,i=0;

    while(scanf("%d", &n[i])!=EOF){
        if(n[i]==0)
            break;
        i++;
    }
        
    for(int j=0;j<i;j++){
        result = f91(n[j]);
        printf("f91(%d) = %d\n", n[j],result);
    }

    return 0;
}

int f91(int n){
    if(n>=101)
        return n-10;
    else
        return f91(f91(n+11));
}