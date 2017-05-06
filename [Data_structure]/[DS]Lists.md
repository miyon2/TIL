# Lists
### 1. Linked List
##### 1.Node?
리스트 내의 각 요소
데이터를 보관하는 **필드**와 다음노드와의 연결고리 역할을 하는 **포인터**로 이루어진다.

##### 2. Head / Tail
List 내의 첫번째 요소는 `Head`, 마지막 요소는 `Tail`이라고 한다.

##### 3. 구조체로 Node 생성하기
```c
struct Node
{
    int Data;				/* 데이터 필드 */
    struct Node* NextNode;		/* 다음 노드를 가리키는 포인터 */
};
```
이렇게 Node를 생성할 경우, 인스턴스 생성시 마다 struct 키워드를 동반하므로 아래와 같이 Node를 정의하여 사용하는것이 더 좋다.

```c
typedef struct tagNode{
    int Data;				/* 데이터 필드 */
    struct tagNode* NextNode;		/* 다음 노드를 가리키는 포인터 */
}Node;
```

##### 4. Node 생성/소멸
> *메모리의 종류*
> 
> 정적메모리(Static Memory) : 전역, 정적변수 저장 / 프로그램 종료시 해제
> 자동메모리(Automatic Memory) : 지역변수 저장 / 스택구조 / 코드블록 벗어나면 해제
> 자유저장소(Free Store) : 프로그래머의 관리 영역 / 메모리 해제가 중요하다.

