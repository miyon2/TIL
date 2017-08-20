# Stack
## 1. Stack?
처음에 들어간 데이터가 가장 마지막에 나오도록 되어있는 구조
**FILO(First In Last Out)**라고 한다. (<-> FIFO)
데이터의 삽입과 삭제가 구조의 한쪽 끝에서만 이루어지는 것이 특징이다.

## 2. 배열로 Stack 구현하기
각 노드를 동적으로 생성하고 제거하는 대신, 스택 생성 초기에 사용자가 부여한 용량만큼의 노드를 한꺼번에 생성한다. 또한 최상위 노드의 위치를 나타내는 변수를 이용하여 삽입과 제거 연산을 수행한다.

#### 1. 장/단점
**1. 장점**
* 구현이 간단하다.

**2. 단점**
* 동적으로 스택의 용량을 조절하기가 어렵다.

#### 2. Stack과 Stack의 노드 표현하기
**1. Node 구조체**
배열을 기반으로 구현되는 스택의 노드는 위치는 인덱스로 알 수 있기 때문에 데이터만 담는 구조체로 표현된다.
```c
typedef int ElementType;

typedef struct tagNode{
	ElementType Data;
}Node;
```

**2. Stack 구조체**
배열 기반의 Stack은 다음 세 가지 필드를 가지고 있어야 한다.
* 용량 : 최대 노드 갯수
* 최상위 노드의 위치 : 삽입/제거 시에 최상위 Node에 접근할 수 있게 한다.
* Node 배열 : Stack에 쌓이는 Node 보관에 사용된다.

```c
typedef struct tagArrayStack{
    int		  Capacity;	 /* 용량 */
    int		  Top;		 /* 최상위 노드의 위치 */
    Node*	  Nodes;	 /* 노드 배열 */
}ArrayStack;
```

#### 3. Stack의 생성과 소멸
* AS = ArrayStack

```c
void AS_CreateStack(ArrayStack** Stack, int Capacity){
    /* 스택을 자유 저장소에 생성 */
    (*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
    
    /* 입력된 Capacity만큼의 노드를 자유 저장소에 생성 */
    (*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity);
    
    /* Capacity 및 Top 초기화 */
    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = 0;
}
```
처음의 `malloc`은 **ArrayStack**을 **자유 저장소**에 올리기 위해 사용되었고 그 다음에는 Stack안에 있는 노드를 매개 변수로 입력된 용량만큼 자유 저장소에 생성하는 데 사용됐다.

```c
void AS_DestroyStack(ArrayStack* Stack){
    /* Node를 자유 저장소에서 해제 */
    free(Stack->Nodes);
    
    /* Stack을 자유 저장소에서 해제 */
    free(Stack);
}
```

#### 4. 삽입(Push)연산
C언어에서는 수가 0부터 시작하기 때문에 코드에서는 TOP의 값을 1만큼 증가시켜준다.
```c
void AS_Push(ArrayStack* Stack, ElementType Data){
    int Position = Stack->Top;
    
    Stack->Nodes[Position].Data = Data;
    Stack->Top++;
}
```

#### 5. 제거(Pop)연산
Top 값을 1 낮추고 반드시 데이터를 호출자에게 반환해야 한다.
```c
ElementType AS_Pop(ArrayStack* Stack){
    int Position = --(Stack->Top);
    
    return Stack->Nodes[Position].Data;
}
```

## 3. Linked List로 Stack 구현하기
#### 1. Stack과 Stack의 노드 표현하기
Linked List로 Stack을 구현하려면 자신의 위에 위치하는 노드에 대한 포인터를 갖고 있어야 한다.
```c
typedef struct tagNode{
    char* Data;
    struct tagNode* NextNode;
}Node;
```
**!!! 주의점**
Data 필드의 자료형이 int나 double같은 기본 자료형이라면 **값의 복사**만으로 데이터를 담을 수 있지만, `char*` 형은 포인터이기 때문에 문자열이 저장되어있는 **주소**만을 담을 수 있어야 한다. 또한 이 문자열은 변수의 수명때문에 자동 메모리가 아닌 자유 저장소에 저장되어야 한다.

```c
typedef struct tagLinkedListStack{
    Node* List;
    Node* Top;
}LinkedListStack;
```
Top 포인터는 Linked List의 Tail을 가리킴으로써 최상위 노드에 대한 정보를 유지한다.
Top 포인터 선언으로 4byte를 소비하지만 Tail 탐색시간에 낭비되는 시간을 줄일 수 있다.

**ArrayStack과의 차이점**
1. Linked List Stack은 Stack의 용량, 최상위 노드의 index가 없다.
2. Linked List Stack은 Head, Tail에 대한 포인터가 필요하다.

#### 2. Stack의 생성과 소멸
```c
void LLS_CreateStack(LinkedListStack** Stack){
    /* 스택을 자유 저장소에 생성 */
    (*Stack)	   = (LinkedListStack*)malloc(sizeof(LinkedListStack));
    (*Stack)->List = NULL;
    (*Stack)->Top  = NULL;
}

void LLS_DestroyStack(LinkedListStack* Stack){
    while( !LLS_IsEmpty(Stack) ){		/* Stack이 빌 때까지 반복 */
    	Node* popped = LLS_Pop(Stack);          /* 노드를 Stack에서 제거하고 */
        LLS_DestroyNode(Popped);		/* 자유 저장소에서 해제한다. */
    }
    
    /* Stack을 자유 저장소에서 해제 */
    free(Stack);
}
```

#### 3. Stack Node의 생성과 소멸
1. Stack Node의 생성
```c
Node* LLS_CreateNode(char* NewData){
    /* 자유 저장소에 노드 할당 */
    Node* NewNode = (Node*)malloc(sizeof(Node));
    
    /* 입력받은 문자열의 크기만큼을 자유 저장소에 할당 */
    NewNode->Data = (char*)malloc(strlen(NewData) + 1);
    
    /* 자유 저장소에 문자열 복사 */
    strcpy(NewNode->Data, NewData);		  /* 데이터를 저장한다. */
    
    NewNode->NextNode = NULL;			  /* 다음 노드에 대한 포인터는 NULL로 초기화한다. */
    return NewNode; 				  /* 노드의 주소를 반환한다. */
}
```

2. Stack Node의 소멸
```c
void LLS_DestroyNode(Node* _Node){
    free(_Node->Data);
    free(_Node);
}
```

#### 4. 삽입(push)연산
최상위 Node(Tail)을 찾은 다음 새 Node를 얹은 후 Top필드에 등록한다.
```c
void LLS_Push(LinkedLIstStack* Stack, Node* NewNode){
    if(Stack->List == NULL){
    	Stack->List = NewNode;
    }
    else{
    	/* 최상위 노드를 찾아 NewNode를 쌓는다. */
        Node* OldTop = Stack->List;
        while(OldTop->NextNode != NULL){
        	OldTop = OldTop->NextNode;
        }
        OldTop->NextNode = NewNode;
    }
    
    /* Stack의 Top필드에 새 노드의 주소를 등록한다. */
    Stack->Top = NewNode;
}
```

리스트 포인터와 Top 포인터 둘 다에 삽입 Node를 연결해주어야 하므로 if문과 Top포인터의 새 노드지정이 필요하다.

#### 5. 제거(Pop)연산
제거 연산은 다음 네가지 단계로 수행된다.
1. 현재 최상위 노드의 주소를 다른 포인터에 복사해 둔다.
2. 새로운 최상위 노드, 즉 현재 최상위 노드의 바로 이전(아래) 노드를 찾는다.
3. LinkedListStack 구조체의 Top필드에 새로운 최상위 노드의 주소를 등록한다.
4. <1>에서 포인터에 저장해둔 옛 최상위 노드의 주소를 반환한다.

```c
Node* LLS_Pop(LinkedListStack* Stack){
    /* 현재 최상위 노드의 주소를 다른 포인터에 복사해 둔다. */
    Node* TopNode = Stack->Top;
    
    if(Stack->List == Stack->Top){
    	Stack->List = NULL;
        Stack->Top = NULL;
    }
    else{
    	/* 새로운 최상위 노드를 Stack의 Top필드에 등록한다. */
    	Node* CurrentTop = Stack->List;
        
        while(CurrentTop!=NULL && CurrentTop->NextNode!=Stack->Top){
    		CurrentTop = CurrentTop->NextNode;
    	}
        Stack->Top = CurrentTop;
    	CurrentTop->NextNode = NULL;
    }
    
    return TopNode;
}
```
