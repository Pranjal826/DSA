#include<stdio.h>
int sum(int a,int b){
    return a+b;
    
}
int main(){
    int x,y;
    x=10,y=20;
    int add=sum(x,y);
    printf("The sum of %d and %d is %d",x,y,add);
}