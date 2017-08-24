# Queue

## 1. Queue?
`FIFO(First In First Out)` 구조

## 2. Queue의 주요 기능
Queue의 가장 앞 요소를 `전단`, 그리고 가장 마지막 요소를 가리켜 `후단`이라고 한다.
Stack은 삽입과 제거가 모두 최상위 노드(Top)에서만 이루어졌지만, Queue는 삽입(Enqueue)은 전단, 제거(Dequeue)는 전단에서 각각 수행된다.
* Enqueue : 후단에 노드를 덧붙여서 새로운 후단을 만드는 연산
* Dequeue : 전단 뒤에 있는 노드를 새로운 전단으로 만드는 연산

## 3. Circular Queue(순환 큐)
#### <?> 순환 큐를 사용하지 않을 시 생길 수 있는 문제점들
1. Dequeue 이후에 나머지 요소들을 한 칸씩 앞으로 옮기는데 비용이 든다.
2. <1>번 문제점이 해결 되더라도 제거 연산을 수행할수록 큐의 가용 용량이 줄어든다.

#### <!> 순환 큐를 이용한 해결방법
1. 변경된 전단의 위치만 관리할 변수를 추가한다.
2. 전단과 후단을 연결한다.

#### <?> 순환 큐를 사용할 때 생길 수 있는 문제점
순환 큐가 비어있는 상태와 가득 차 있는 상태를 구별할 수 없다.
--> 전단과 후단을 가리키는 요소가 둘다 같기 때문!
**--> 실제 용량보다 1만큼 더 크게 큐를 생성해서 미연에 방지할수 있다.**

#### 1. 순환 큐의 선언
순환 큐의 Node 구조체
```c
typedef int ElementType;

typedef struct tagNode{
	ElementType Data;
}Node;
```

순환 큐의 구조체
```c
typedef struct tagCircularQueue{
    int Capacity;		   /* 용량 */
    int Front;		  	   /* 전단의 인덱스 - 실제 메모리주소가 아닌 인덱스 */
    int Rear;			   /* 후단의 인덱스 - 실제 메모리주소가 아닌 인덱스 */
    Node* Nodes;		   /* 노드 배열 - 자유 저장소에 생성 */
}CircularQueue;
```

#### 2. 순환 큐의 생성
순환 큐를 생성하는 `CQ_CreateQueue()`함수는 순환 큐에 대한 포인터인 **Queue**와 용량을 결정하는 **Capacity**를 매개 변수로 받는다.
`CQ_CreateQueue()` 함수는 먼저 순환 큐를 자유 저장소에 생성한 다음, `Node의 크기 X (Capacity + 1)`의 크기로 배열을 자유 저장소에 할당한다. (상태 구분을 위한 Dummy Node가 필요하기 때문)
```c
void CQ_CreateQueue(CircularQueue** Queue, int Capacity){
    /* Queue를 자유 저장소에 생성 */
    (*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));
    
    /* 입력된 Capacity+1 만큼의 노드를 자유 저장소에 생성 */
    (*Queue)->Nodes = (Node*)malloc(sizeof(Node)*(Capacity + 1));
    
    (*Queue)->Capacity = Capacity; /* 큐가 수용할 실제 용량을 저장 */
    (*Queue)->Front = 0;
    (*Queue)->Rear = 0;
}
```

```c
void CQ_DestroyQueue(CircularQueue* Queue){
    free(Queue->Nodes);
    free(Queue);
}
```

#### 3. 삽입(Enqueue)연산
Rear의 위치를 잘 파악하는게 중요하다. 
```c
void CQ_Enqueue(CircularQueue* Queue, ElementType Data){
    int Position = 0;
    
    if(Queue->Rear == Queue->Capacity){
    	Position = Queue->Rear;
        Queue->Rear;
    }
    else{
    	Position = Queue->Rear++;
    }
    Queue->Nodes[Position].Data = Data;
}
```

#### 4. 제거(Dequeue)연산
```c
ElementType CQ_Dequeue(DircularQueue* Queue){
    int Position = Queue->Front;
    
    /* 전단이 곧 배열의 끝에 도달해 있다. */
    if(Queue->Front == Queue->Capacity){
    	Queue->Front = 0;
    }
    else{
    	Queue->Front++;
    }
    
    return Queue->Nodes[Position].Data;
}
```

#### 5. 공백상태 확인
전단과 후단이 같은지 확인한다.
```c
int CQ_IsEmpty(CircularQueue* Queue){
    return (Queue->Front == Queue->Rear);
}
```

#### 6. 포화 상태 확인
두가지 경우를 고려해야 한다.
1. 순환 큐 배열 내에서 전단이 후단 앞에 위치하는 경우, 후단과 전단의 차가 큐의 용량과 동일한지를 봐야한다.
2. 전단이 후단 뒤에 위치하는 경우에는 Rear에 1을 더한 값이 Front와 같은지를 봐야한다.

```c
int CQ_IsFull(CircularQueue* Queue){
    if(Queue->Front < Queue->Rear){
    	return (Queue->Rear - Queue->Front) == Queue->Capacity;
    }
    else{
    	return (Queue->Rear)+1 == Queue->Front;
    }
}
```

## 4. Linked Queue(링크드 큐)
#### 1. Linked Queue와 Node의 선언
Node의 선언
```c
typedef struct tagNode{
    char* Data;
    struct tagNode* NextNode;
}Node;
```
Linked Queue의 선언
```c
typedef struct tagLinkedQueue{
    Node* Front;
    Node* Rear;
    int Count;		/* Node의 수 */
}LinkedQueue;
```

#### 2. Linked Queue의 생성과 소멸
`LQ_CreateQueue()`는 자유저장소에 LinkedQueue 구조체를 생성하고 각 필드를 초기화한다.
```c
void LQ_CreateQueue(LinkedQueue** Queue){
    (Queue*)	    = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    (Queue*)->Front = NULL;
    (Queue*)->Rear  = NULL;
    (Queue*)->Count = 0;
}
```
`LQ_DestroyQueue()`함수는 큐 내부에 있는 모든 노드를 자유 저장소에서 제거하고, 큐도 자유 저장소에서 제거한다.
```c
void LQ_DestroyQueue(LinkedQueue* Queue){
    while(!LQ_IsEmpty(Queue)){
    	Node* Popped = LQ_Dequeue(&Queue);
        LQ_DestroyNode(Popped);
    }
    /* Queue를 자유 저장소에서 해제 */
    free(Queue);
}
```

#### 3. 삽입(Enqueue)연산
후단에 새 노드를 붙인다.
```c
void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode){
    if(Queue->Front == NULL){
	Queue->Front = NewNode;
        Queue->Rear = NewNode;
        Queue->Count++;
    }
    else{
    	Queue->Rear->NextNode = NewNode;	/* 기존 Rear의 다음노드에 새 노드 주소 지정 */
    	Queue->Rear = NewNode;	/* Rear에 새 노드 주소 지정 */
        Queue->Count++;
    }
}
```

#### 4. 제거(Dequeue)연산
```c
Node* LQ_Dequeue(LinkedQueue* Queue){
    /* LQ_Dequeue() 함수가 반환할 최상위 노드 */
    Node* Front = Queue->Front;
    
    if(Queue->Front->NextNode == NULL){
    	Queue->Front = NULL;
        Queue->Rear = NULL;
    }
    else{
    	Queue->Front = Queue->Front->NextNode;
    }
    
    Queue->Count--;
    
    return Front;
}
```
