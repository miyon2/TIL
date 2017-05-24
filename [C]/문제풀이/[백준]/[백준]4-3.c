/*
for문에서 작은 수 저장시에 코드를 좀 더 줄여볼수 있으면 좋을것같다.
작은 수 출력 시 while문도 더 효율적으로 사용할수 있을것같다.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
  int *input;           //동적 배열 생성을 위한 변수
  int user_input;       //배열크기를 입력받기 위한 변수
  int standard_num;     //크고 작음의 기준이 되는 수
  int temp;             //숫자 비교 후 저장을 위한 변수
  int i=0;
  int j=0;
  scanf("%d %d", &user_input, &standard_num);

  /*동적으로 배열 생성 후 0으로 초기화하기*/
  input = (int *)calloc(user_input,sizeof(int));

  for(i=0; i<user_input; i++){
    scanf("%d", &temp);
    if(temp<standard_num){
      input[j]=temp;
      j++;
    }
  }

  temp = 1;
  i = 0;

  while(temp!=0){
    printf("%d ", input[i]);
    i++;
    temp = input[i];
  }

  free(input);
}
