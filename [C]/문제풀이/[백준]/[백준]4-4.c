#include <stdio.h>
#include <stdlib.h>

int main(void){
  int count_num;
  int *grade;
  int highest;
  int i;
  int standard_num = 0;
  double fixed_grade[3];
  double fixed_sum = 0;

  scanf("%d", &count_num);
  grade = (int*)malloc(sizeof(int)*count_num);

  for(i=0; i<count_num; i++){
      scanf("%d", &grade[i]);
      if(standard_num<grade[i]){
        standard_num = grade[i];
      }
  }

  for(i=0; i<count_num; i++){
    fixed_grade[i] = (double)grade[i]/(double)standard_num*100;
    fixed_sum += fixed_grade[i];
  }

  printf("%.2f",  fixed_sum / 3);

}
