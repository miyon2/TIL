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
	int Capacity;		/* 용량 */
	int Front;		   /* 전단의 인덱스 - 실제 메모리주소가 아닌 인덱스 */
    int Rear;			/* 후단의 인덱스 - 실제 메모리주소가 아닌 인덱스 */
    Node* Nodes;		 /* 노드 배열 - 자유 저장소에 생성 */
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

