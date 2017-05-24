#include "stdio.h"

int main(void){
  int n;
  scanf("%d", &n);

  if(n%5 == 0){
    printf("%d", n/5);
  }
  else if(n%5 == 3){
    printf("%d", (n/5)+1);
  }
  else if((n%5 == 4)&&(n%3 == 0)){
    printf("%d", n/3);
  }
  else{
    printf("-1");
  }
}
