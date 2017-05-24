# Javascript의 자료형과 변수

## 1.변수
***위치(주소)를 기억하는 저장소***

메모리에 값을 저장하기 위해서는 필요한 저장단위(byte)를 알아야한다.
값의 종류에 따라 값을 저장하기 위해 확보해야할 메모리의 크기가 다르기 때문이다. 이때의 값의 종류 즉 데이터의 종류를 자료형(Data Type)이라 한다.

> cf> C나 Java같은 C-family 언어는 Static Typing 언어로 변수선언시 변수에 저장할 값의 종류에 따라 사전에 자료형을 지정해야 한다.
> 그러나 JavaScript는 Dynamic Typing 언어로 변수의 변수선언이 필요없이 값이 할당되는 과정에서 자동으로 자료형이 결정된다.

## 2. Data Type
***여러 종류의 데이터를 식별하는 분류***

#### 2-1 Primitive Data Type(기본자료형)
***변경 불가능한 값(immutable value), pass-by-value***

###### 2-1-1 Boolean
논리적인 요소를 나타내며 `true`, `false` 두가지 값을 가질 수 있다.
**비어있는 문자열, null, undefined, 숫자 0 은 false로 간주된다.**

###### 2-1-2 null
null타입은 딱 한자기 값, `null`만을 가질수 있다.

```javascript
var foo  = null;
console.log(typeof foo); // object
```
->`null`의 타입은 null임에도 불구하고 설계상의 문제 때문에 object를 반환했다는 점에 주의해야한다. null타입 변수인지 확인할때는 일치연산자(===)를 사용해야한다
```javascript
var foo  = null;
console.log(typeof foo === null); // false
console.log(foo === null);        // true
```

###### 2-1-3 undefined
값을 할당하지 않은 변수는 `undefined`값을 가진다.

###### 2-1-4 Number
C의 경우, 정수/실수형을 구분하여 int, long, float, double 등 다양한 자료형이 존재하지만, JavaScript에서는 하나의 숫자 자료형만 존재한다.

JavaScript에는 Integer 자료형이 따로 존재하지 않고, double형(64비트 부동소수점 형) 자료형만이 존재한다.

추가적으로 세가지 기호에 관한 값들도 표현할 수 있다.
1. `+/- Infinity`
2. `NaN`(not-a-number)

```javascript
var x = 10;    // 정수
var y = 10.12; // 실수
var z = -20;   // 음의 정수

var foo = 42 / -0;
console.log(foo);        // -Infinity
console.log(typeof foo); // number

var bar = 1 * 'string';
console.log(bar);        // NaN
console.log(typeof bar); // number
```

###### 2-1-5 String
한번 문자열이 생성되면 그 문자열을 변경할 수 없으며, 배열처럼 인덱스를 통해 접근할 수 있다.
한번 생성된 문자열은 `read only`로서 수정은 불가하다. 그러나 원래 문자열에서 일부가 수정된 다른 문자열을 만드는건 가능하다.
```javascript
var str = 'string';
console.log(str); // string

str = 'String';
console.log(str); // String

str += ' test';
console.log(str); // String test

str.substring(0, 3);
console.log(str); // Str

str = str.toUpperCase();
console.log(str); // STR
```

###### 2-1-6 Symbol
C의 `enum`형과도 비슷하며, 변경불가능한 기본값이다. object의 key값으로 사용가능하다.

#### 2-2 Object(객체형, 참조형)
객체는 `pass-by-reference` 이다.
1. 함수(Function)
2. 배열(Array)
3. 날짜(Data)
4. 정규식(RegExp)

## 2. Variable
변수명은 identifier(식별자)로 불리기도 하며 명명 규칙이 존재한다.
* 반드시 영문자(특수문자 제외), underscore(_), 또는 달러 기호($)로 시작하여야 한다. 이어지는 문자에는 숫자(0~9)도 사용 가능하다.
* 대/소문자 구별이 가능하다.

## 3. Dynamic Typing
***동적타이핑이란?***
JavaScript는 `Dynamic typed` 언어 혹은 `loosely typed` 언어다.
변수의 선언이 필요없이 값이 할당되는 과정에서 자동으로 자료형이 결정된다는 뜻이다.
따라서 같은 변수에 여러 data type의 값을 대입할 수 있다.

## 4. 변수 호이스팅(Variable Hoisting)
```javascript
console.log(foo); // ① undefined
var foo = 123;
console.log(foo); // ② 123
{
  var foo = 456;
}
console.log(foo); // ③ 456
```
1에서 undefined가 출력되는 이유는 **모든 선언문은 호이스팅(Hoisting)되기 때문이다.**

*호이스팅(Hoisting)은 JavaScript변수 생성과 할당이 분리되어 진행되기 때문에 일어나는 현상으로, var 또는 function 선언문을 Scope의 맨 위로 옮기는 것을 말한다.*

JavaScript의 변수는 다른 C-family와 달리 block-level-scope를 가지지 않고 function-level-scope를 갖는다.
>cf> let keyword를 사용하면 block-level-scope를 사용할 수 있다.