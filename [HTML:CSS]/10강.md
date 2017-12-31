# 10> HTML5와 시맨틱 태그

## 시맨틱 태그?
1. 가독성을 위해 추가한 표준
2. 시각장애인용 화면 낭독기를 위한 표준
3. **레이아웃을 표준화하는 태그**

## 레이아웃에 왜 시맨틱태그가 필요할까?
* 코드를 해석하지 않고 태그만 봐도 레이아웃이 어떻게 구성되었는지 알수 있다.

## 문서구조를 위한 시맨틱 태그
### 1> header
머리말에 해당하고 `<nav>`나 `<form>`이 들어간다
> cf) head와는 다르다. head는 보이지 않는정보, header는 드러나는정보!

```html
<header>
	<nav class = "navi">
		<ul>
    		<li><a href="#">이용안내</li>
            <li><a href="#">객실소개</li>
        	<li><a href="#">예약방법</li>
        	<li><a href="#">예약하기</li>
    	</ul>
	</nav>
</header>
```

### 2> nav
문서를 연결하는 **navigation link!**
사용위치의 영향을 받지않아 	`<header>`, `<footer>`,`<aside>` 에도 사용가능하다.
```html
<nav class = "navi">
	<ul>
    	<li><a href="#">이용안내</li>
        <li><a href="#">객실소개</li>
        <li><a href="#">예약방법</li>
        <li><a href="#">예약하기</li>
    </ul>
</nav>
```

### 3> section
주제별로 컨텐츠를 나눠준다.

```html
<section id="theme1"><h1>국어</h1></section>
<section id="theme2"><h1>수학</h1></section>
<section id="theme3"><h1>사회</h1></section>
<section id="theme4"><h1>과학</h1></section>
```

### 4> article
각 컨텐츠에 내용을 넣는다.

> cf) `<section>`과는 다르다. `<section>`는 컨텐츠를 주제별로 묶을때 쓰고, `<article>`은 실제 내용을 가져올때 사용한다.

### 5> iframe
외부 문서를 가져온다. **(= inline frame)**
```html
<iframe src="경로" [속성 = "속성 값"]> </iframe>
```
| 속성 | 설명 |
|--------|--------|
| width | 너비를 설정한다. 픽셀이나 백분율 값으로 표시 |
| height | 높이를 설정한다. 픽셀이나 백분율 값으로 표시 |
| name | 인라인 프레임의 이름을 설정한다. |
| src | 프레임에 표시할 문서의 주소를 지정한다. |
| seamless | 프레임의 테두리를 제거하고 본문의 일부처럼 보이게한다. (크롬, 사파리 외에서는 작동하지 않는다) |

### 6> footer
제작 정보와 저작권 정보 표시하기

### 7> address
제작자의 연락처 정보를 넣는 데 사용된다. 하지만 단순히 우편 주소를 표기할 용도라면 `<p>`를 사용하는게 더 좋다.