# 1. 명명법
#### 1. Lower Camel Case : function, method, variable, constant
   > someVariableName

#### 2. Upper Camel Case : type(class, struct, enum, extension)
   > Person, Point, Week

# 2. console log
#### 1. print
   > print("출력 내용")

#### 2. dump
   > dump(출력내용)

# 3. 문자열 보간법
출력 내용 안에 변수 또는 상수의 값을 출력하기 위해 사용한다.
> print("/(변수또는 상수명)")

# 4. 상수
swift는 띄어쓰기에 민감한 언어이기 때문에 주의하자.
```swift
//상수 선언
let 상수이름: 타입 = 값

//값의 타입이 명확하다면 타입 생략 가능
let 상수이름 = 값

//초기화 하기
let constant: String = "상수의값"

//상수의 값을 변경하면 오류가 발생한다.
//constnt = "변경하고싶은값"
```

선언 뒤에 단 한번 값을 할당 할 수 있다.
```swift
let sum: Int
let inputA: Int = 100
let inputB: Int = 200

// 선언 후 첫 할당
sum = inputA + inputB

// sum = 1 // 그 이후에는 다시 값을 바꿀 수 없습니다, 오류발생
```

# 5. 변수
```swift
//변수 선언
var 변수이름: 타입 = 값

//값의 타입이 명확하다면 타입 생략 가능
var 변수이름 = 값

//초기화 하기
var variable: String = "변수의 값"
```

# 6. 기본 데이터타입
#### 1. Bool
```swift
var someBool: Bool = true
someBool = false

// 0과 1로 bool값 표현이 불가능하다.
// someBool = 0 // 컴파일 오류발생
// someBool = 1 // 컴파일 오류발생
```

#### 2. Int, UInt
```swift
// Int
var someInt: Int = -100
// someInt = 100.1 // 컴파일 오류발생

//UInt
var someUInt: UInt = 100
// someUInt = -100 // 컴파일 오류발생
// someUInt = someInt // 컴파일 오류발생
```

#### 3. Float, Double
```swift
// Float
var someFloat: Float = 3.14
someFloat = 3

// Double
var someDouble: Double = 3.14
someDouble = 3
// someDouble = someFloat // 컴파일 오류발생
```

#### 4. Character, String
`Character형` 에는 문자 하나만 저장 가능하다.
```swift
// Character
var someCharacter: Character = "D"
someCharacter = "😄"
someCharacter = "가"
someCharacter = "A"
// someCharacter = "하하하" // 컴파일 오류발생
print(someCharacter)

// String
var someString: String = "하하하"
someString = someString + "웃으면 복이와요"
print(someString)

// someString = someCharacter // 컴파일 오류발생
```

# 7. Any
swift의 모든 타입을 지칭하는 키워드
```swift
var someAny: Any = 100
someAny = "어떤 타입도 수용 가능합니다"
someAny = 123.12

// Any 타입에 Double 자료를 넣어두었더라도 Any는 Double 타입이 아니기 때문에 할당할 수 없다.
// 명시적으로 타입을 변환해 주어야 한다.
let someDouble: Double = someAny  // 컴파일 오류발생
```

# 8. AnyObject
모든 클래스 타입을 지칭하는 프로토콜
```swift
class SomeClass {}
var someAnyObject: AnyObject = SomeClass()

// AnyObject는 클래스의 인스턴스만 수용 가능하기 때문에 클래스의 인스턴스가 아니면 할당할 수 없다.
someAnyObject = 123.12    // 컴파일 오류발생
```

# 9. nil
할당된 값이 없음을 의미하는 키워드
```swift
// someAny는 Any 타입이고, someAnyObject는 AnyObject 타입이기 때문에 nil을 할당할 수 없다.
var someAny: Any = 100
var someAnyObject: AnyObject = SomeClass()

someAny = nil         // 컴파일 오류발생
someAnyObject = nil   // 컴파일 오류발생
```

# 10. 컬렉션 타입
#### 1. Array
인덱스를 가지는 컬렉션 타입
```swift
// 1. Array 선언 및 생성
var integers: Array<Int> = Array<Int>()

// 위와 동일한 표현
// var integers: Array<Int> = [Int]()
// var integers: Array<Int> = []
// var integers: [Int] = Array<Int>()
// var integers: [Int] = [Int]()
// var integers: [Int] = []
// var integers = [Int]()


// 2. Array 활용
integers.append(1)
integers.append(100)

// Int 타입이 아니므로 Array에 추가할 수 없습니다
//integers.append(101.1)

print(integers)	// [1, 100]

// 멤버 포함 여부 확인
print(integers.contains(100)) // true
print(integers.contains(99)) // false

// 멤버 교체
integers[0] = 99

// 멤버 삭제
integers.remove(at: 0)
integers.removeLast()
integers.removeAll()

// 멤버 수 확인
print(integers.count)

// 인덱스를 벗어나 접근하려면 익셉션 런타임 오류발생
//integers[0]


// 3. 불변 Array: let을 사용하여 Array 선언
let immutableArray = [1, 2, 3]

// 수정이 불가능한 Array이므로 멤버를 추가하거나 삭제할 수 없습니다
//immutableArray.append(4)
//immutableArray.removeAll()
```

#### 2. Dictionary
key-value 쌍으로 이루어진 컬렉션 타입
```swift
// 1. Dictionary의 선언과 생성
// Key가 String 타입이고 Value가 Any인 빈 Dictionary 생성
var anyDictionary: Dictionary<String, Any> = [String: Any]()

// 위와 동일한 표현
// var anyDictionary: Dictionary <String, Any> = Dictionary<String, Any>()
// var anyDictionary: Dictionary <String, Any> = [:]
// var anyDictionary: [String: Any] = Dictionary<String, Any>()
// var anyDictionary: [String: Any] = [String: Any]()
// var anyDictionary: [String: Any] = [:]
// var anyDictionary = [String: Any]()


// 2. Dictionary 활용
// 키에 해당하는 값 할당
anyDictionary["someKey"] = "value"
anyDictionary["anotherKey"] = 100

print(anyDictionary) // ["someKey": "value", "anotherKey": 100]

// 키에 해당하는 값 변경
anyDictionary["someKey"] = "dictionary"
print(anyDictionary) ["someKey": "dictionary", "anotherKey": 100]

// 키에 해당하는 값 제거
anyDictionary.removeValue(forKey: "anotherKey")
anyDictionary["someKey"] = nil
print(anyDictionary)


// 3. 불변 Dictionary: let을 사용하여 Dictionary 선언
let emptyDictionary: [String: String] = [:]
let initalizedDictionary: [String: String] = ["name": "yagom", "gender": "male"]

// 불변 Dictionary이므로 값 변경 불가
//emptyDictionary["key"] = "value"

// "name"이라는 키에 해당하는 값이 없을 수 있으므로 String 타입의 값이 나올 것이라는 보장이 없어서 컴파일 오류 발생
// let someValue: String = initalizedDictionary["name"]
```

#### 3. Set
중복되지 않는 멤버가 순서업이 존재하는 컬렉션
배열과 헷갈리지 않게 주의.
```swift
// 1. Set 생성 및 선언
var integerSet: Set<Int> = Set<Int>()

// insert : 새로운 멤버 입력
// 동일한 값은 여러번 insert해도 한번만 저장됩니다.
integerSet.insert(1)
integerSet.insert(99)
integerSet.insert(99)
integerSet.insert(99)
integerSet.insert(100)

print(intigerSet) // {100, 99, 1}

// contains: 멤버 포함 여부 확인
print(integerSet.contatins(1)) // true
print(integerSet.contains(2)) // false

// remove: 멤버 삭제
integerSet.remove(99) // {100, 1}
integerSet.removeFirst() // {1}

// count: 멤버 개수
integerSet.count // 1


// 2. Set의 활용
// 멤버의 유일성이 보장되기 때문에 집합 연산에 활용하면 유용하다.
let setA: Set<Int> = [1, 2, 3, 4, 5]
let setB: Set<Int> = [3, 4, 5, 6, 7]

// 합집합
let union: Set<Int> = setA.union(setB)
print(union) // [2, 4, 5, 6, 7, 3, 1]

// 합집합 오름차순 정렬
// 배열로 반환된다.
let sortedUnion: [Int] = union.sorted()
print(sortedUnion) // [1, 2, 3, 4, 5, 6, 7]

// 교집합
let intersection: Set<Int> = setA.intersection(setB)
print(intersection) // [5, 3, 4]

// 차집합
let subtracting: Set<Int> = setA.subtracting(setB)
print(subtracting) // [2, 1]
```