# 멤버연산자
## 1. 멤버연산자
단순 구조체 내의 멤버변수에 접근할 때 사용한다.
```c
#include <stdio.h>
typedef struct tagNode{
	int data;
}Node;

int main(void){
	Node NewNode;
    printf("%d", NewNode.data);
}
```

## 2. 구조체 멤버 연산자
vh