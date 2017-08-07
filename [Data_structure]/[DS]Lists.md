# Lists
## 1. Single Linked List
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

```c
/* 노드 생성 문제 버전 */
Node* SLL_CreateNode(int NewData){
	Node NewNode; 			/* 자동 메모리에 새로운 노드 생성 */
    NewNode.Data = NewData;
    NewNode.NextNode = NULL;
    
    return &NewNode; 		/* NewNode가 생성된 메모리의 주소를 반환 */
}/* 함수가 종료되면서 NewNode는 자동 메모리에서 제거된다. */
```

다음 코드는 코드블럭 범위를 고려하지 않아서 NewNode를 반환하지만 자동 메모리에서 제거된다.
따라서 다음과 같이 코드를 수정해주어야한다.

```c
/* 노드 생성 */
Node* SLL_CreateNode(ElementType NewData){
	Node* NewNode = (Node*)malloc(sizeof(Node));
    
    NewNode->Data = NewData;	  /* 데이터를 저장한다. */
    NewNode->NextNode = NULL;	 /* 다음 노드에 대한 포인터는 NULL로 초기화한다. */
    
    return NewNode;			   /* 노드의 주소를 반환한다. */
}
```

노드의 소멸은 간단하게 `free()`함수를 이용하면 된다.
```c
/* 노드 소멸 */
void SLL_DestroyNode(Node *Node){
	free(Node);
}
```

#### 5. Node 추가
`SLL_CreateNode()`함수를 이용하여 자유저장소에 노드를 생성한 다음, 새로 생성한 노드의 주소를 Tail의 NextNode 포인터에 대입하면 된다.
```c
void SLL_AppendNode(Node** Head, Node* NewNode){
	/* 헤드 노드가 NULL이라면 새로운 노드가 Head */
    if( (*Head) == NULL ){
    	*Head = NewNode;
    }
    else{
    	/* Tail을 찾아 NewNode를 연결한다. */
        Node* Tail = (*Head);
        while(Tail->NextNode != NULL){
        	Tail = Tail->NextNode;
        }
        
        Tail->NextNode = NewNode;
    }
}
```

**중요! >>>> 이중포인터를 사용하는 이유 ?**
[--> 참고링크 : 리스트 구현시 이중포인터를 사용하는 이유](http://blog.naver.com/PostView.nhn?blogId=dunlod&logNo=220844585669&parentCategoryNo=&categoryNo=99&viewDate=&isShowPopularPosts=true&from=search)

#### 6. Node 탐색
탐색 연산은 링크드 리스트가 갖고 있는 약점중의 하나이다. 배열과는 다르게 인덱스를 가지고 있지 않아서 `Head`부터 탐색 연산을 해야만 원하는 노드에 접근할 수 있다.

```c
/* 노드 탐색 */
Node* SLL_GetNodeAt(Node* Head, int Location){
	Node* Current = Head;
    
    /* Head가 없거나 전체 노드를 탐색했을 때 */
    while( Current!=NULL && (--Location)>=0 ){
    	Current = Current->NextNode;
    }
    return Current;
}
```

#### 7. Node 삭제
Node 삭제 연산은 삭제하고자 하는 노드를 찾은 후, 해당 노드의 다음 노드를 이전 노드의 NextNode 포인터에서 제거하면 된다.

```c
/* 노드 제거 */
void SLL_RemoveNode(Node** Head, Nocd* Remove){
	if( *Head == Remove ){
    	*Head = Remove->NextNode;
    }
    else{
    	Node* Current = *Head;
        while( Current!=NULL && Current->NextNode!=Remove ){
        	Current = Current->NextNode;
        }
        if( Current!=NULL ){
        	Current->NextNode = Remove->NextNode;
        }
    }
}
```

#### 8. Node 삽입
새로운 Node의 Prev,NextNode를 설정해준 뒤 기존Node의 Prev,NextNode를 새 Node로 지정해주면 된다.
```c
/* 노드 삽입 */
void SLL_InsertAfter(Node* Current, Node* NewNode){
	NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}
```

#### 9. Node 개수 세기
```c
/* 노드 개수 세기 */
int SLL_GetNodeCount(Node* Head){
	int Count = 0;
    Node* Current = Head;
    
    while( Current != NULL ){
    	Current = Current->NextNode;
        Count++;
    }
    
    return Count;
}
```

#### 10. Linked List의 장/단점
**1. 단점**
* 다음 노드를 가리키는 포인터 때문에 각 노드마다 **4byte**의 메모리가 추가로 필요하다.
* 특정 위치에 있는 노드를 얻는 비용이 크며 속도가 느리다.

**2. 장점**
* 배열에 비해 새로운 노드의 `추가/삽입/삭제`가 쉽고 빠르다.
* 현재 노드의 다음 노드를 얻어오는 연산에 대해서는 비용이 발생하지 않는다.

## 2. Double Linked List
#### 1. Double Linked List?
Linked List의 탐색 기능을 개선한 자료구조로, `Head->Tail` / `Tail->Head` 양방향 탐색이 가능하다. 현재 Node에는 NextNode에 대한 포인터 이외에도 PrevNode에 대한 포인터도 가지고 있다.
```c
typedef struct tagNode{
	int Data;					/* 데이터필드 */
    struct tagNode* PrevNode;	/* 이전 노드를 가리키는 포인터 */
    struct tagNode* NextNode;	/* 다음 노드를 가리키는 포인터 */
}Node;
```

#### 2. Node 생성/소멸
```c
/* 노드 생성 */
Node* DLL_CreateNode(ElementType NewData){
	Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = NewData;
    
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;
    
    return NewNode;
}

/* 노드 소멸 */
void DLL_DestroyNode(Node* Node){
	free(Node);
}
```

#### 3. Node 추가
```c
/* 노드 추가 */
void DLL_AppendNode(Node** Head, Node* NewNode){
	/* Head가 NULL이라면 새로운 노드가 Head */
	if( (*Head)==NULL ){
    	*Head = NewNode;
    }
    else{
    	/* Tail을 찾아 NewNode를 연결한다. */
        Node* Tail = (*Head);
        while( Tail->NextNode != NULL ){
        	Tail = Tail->NextNode;
        }
        
        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail;
    }
}
```

#### 4. Node 탐색
```c
Node* DLL_GetNodeAt(Node* Head, int Location){
	Node* Current = Head;
    while( Current!=NULL && (--Location)>=0 ){
    	Currnet = Current->NextNode;
    }
    
    return Current;
}
```

#### 5. Node 삭제
```c
/* Node 제거 */
void DLL_RemoveNode(Node** Head, Node* Remove){
	if( *Head == Remove ){
    	*Head = Remove->NextNode;
        if( (*Head)!=NULL )
        	(*Head)->PrevNode = NULL;
        
        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
    else{
    	Node* Temp = Remove;
        Remove->PrevNode->NextNode = Temp->NextNode;
        /* Remove->PrevNode->NextNode = Remove->NextNode; 와는 어떤 차이가 있을까*/
        if( Remove->NextNode!=NULL ){
        	Remove->NextNode->PrevNode = Temp->PrevNode;
        }
        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
}
```

#### 6. Node 삽입
```c
/* 노드 삽입 */
void DLL_InsertAfter( Node* Current, Node* NewNode ){
	NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Currnet;
    
    if( Current->NextNode != NULL ){
    	Current->NextNode->PrevNode = NewNode;
    }
    Current->NextNode = NewNode;
}
```

#### 7. Node 개수 세기
```c
/* 노드 개수 세기 */
int DLL_GetNodeCount(Node* Head){
	unsigned int Count = 0;
    Node*		Current = Head;
    
    while( Current != NULL ){
    	Current = Current->NextNode;
        Count++;
    }
    
    return Count;
}
```

## 3. Circular Linked List
#### 1. Circular Linked List ?
Head와 Tail을 연결한 Linked List로, Tail에 접근하는 비용이 거의 없는 것이나 다름 없을 정도로 작아져서 `AppendNode()`함수의 성능을 획기적으로 개선시킬 수 있으며, 뒤에서부터 노드를 찾아나가는 탐색 루틴을 구현할 수도 있다.

#### 2. 유의점
* Tail은 Head의 **앞노드**이다.
* Head는 Tail의 **뒷노드**이다.
* 앞/뒤에 유의하며 코드작성하기

#### 3. Node 추가
```c
/* 노드 추가 */
void CDLL_AppendNode(Node** Head, Node* NewNode){
	/* Head가 NULL이라면 새로운 노드가 Head */
    if( (*Head)==NULL ){
    	*Head=NewNode;
        (*Head)->NextNode=*Head;
        (*Head)->PrevNode=*Head;
    }
    else{
    	/* Tail과 Head사이에 NewNode를 삽입한다. */
        Node* Tail = (*Head)->PrevNode;
        
        Tail->NextNode->PrevNode = NewNode;
        Tail->NextNode = NewNode;
        
        NewNode->NextNode = (*Head);
        NewNode->PrevNode = Tail;
    }
}
```

#### 4. Node삭제
```c
/* 노드 삭제 */
void CDLL_RemoveNode(Node** Head, Node* Remove){
	if( *Head == Remove ){
    	(*Head)->NextNode->PrevNode = (*Head)->PrevNode;
        (*Head)->PrevNode->NextNode = (*Head)->NextNode;

        (*Head) = Remove->NextNode;
    }
    else{
    	Node* Temp = Remove;
        Remove->NextNode->PrevNode = Temp->PrevNode;
        Remove->PrevNode->NextNode = Temp->NextNode;
    }
    Remove->PrevNode = NULL;
    Remove->NextNode = NULL;
}
```