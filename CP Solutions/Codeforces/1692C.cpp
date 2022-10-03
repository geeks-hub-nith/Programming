// Link: https://codeforces.com/contest/1692/problem/C
// Author: darkwhite0
#include <stdio.h>
int main(){
    int t, i, j, k;
    char str[8][8];
    scanf("%d", &t);
    for(i = 0; i < t; i++){
        for(j = 0; j < 8; j++){
            scanf("%s", &str[j]);
        }
        for(j = 0; j < 8; j++){
            for(k = 0; k < 8; k++){
                if(str[j][k] == '#'){
                    break;
                }
            }
            if(str[j - 1][k - 1] == '#'
            && str[j - 1][k + 1] == '#'
            && str[j + 1][k - 1] == '#'
            && str[j + 1][k + 1] == '#'){
                printf("%d %d\n", j+1, k+1);
                break;
            }
        }
    }
}