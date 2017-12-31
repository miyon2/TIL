# 6 > 텍스트 관련 스타일
## 글꼴 관련스타일
### 1. `font-family` : **글꼴 지정하기**
```html
font-family: <글꼴이름1>[, <글꼴이름2>, <글꼴이름3>];
```
해당하는 글꼴이 존재하지 않을경우 글꼴이름2 , 글꼴이름3 순으로 적용한다.
또한 글꼴이 설치되어 있지 않은 시스템일 경우, **브라우저 기본값을 사용한다.**

##### > `@font-face` 속성 : **웹 폰트 사용하기**
* **웹폰트란?**
웹문서를 작성할 때 웹 문서 안에 글꼴 정보도 함께 저장했다가 사용자가 웹 문서에 접속하면 글꼴을 사용자 시스템으로 다운로드 시키는 방식

* **구글 웹폰트 사용하기**
**https://fonts.google.com/earlyaccess**
```html
  <style>
    @import url(//fonts.googleapis.com/earlyaccess/nanumpenscript.css);
    h1 {
      font-family: 'Nanum Pen Script', cursive;
    }
  </style>
```
다음과 같이 url을 import하고, `font-family`를 적용하면 된다.

* **웹 폰트 업로드해 사용하기**
`ttf`파일은 크기가 너무 크기때문에 `eot`(http://eotfast.com)또는 `woff`(http://people.mozilla.com/~jkew/woff)를 이용하면 된다.

* **웹 폰트 적용하기**
```
<style>
      @font-face {
        font-family: 'trana'; 				/* 글꼴 */
        src: local('trana'),
            url('trana.eot'),				 /* 위치 지정 */
            url('trana.woff') format('woff'),
            url('trana.ttf') format('truetype');
       }
      .w-font {
        font-family:'trana', sans-serif;      /* 웹 폰트 지정 */
      }
      p {
        font-size:30px; 					  /* 글자 크기 */
      }
    </style>
```
`ttf`파일은 용량이 크기때문에 가장 마지막에 선언하고, **IE8** 이하 버전에서는 `eot`만 지원하므로 가장 먼저 선언해준다.

### 2. `font-size` : 글자 크기 조절하기
```html
font-size: <절대크기> | <상대크기> | <크기> | <백분율>
```
| 속성 값 | 설명 |
|:--------:|:--------:|
| <절대크기> | 브라우저에서 지정한 글자 크기<br>xx-small / x-small / small / medium / large / x-large / xx-large 사용가능|
| <상대크기> | 부모 요소의 글자 크기(font-size)를 기준으로 더 크게 또는 작게표시<br>larger / smaller 사용가능 |
| <크기> | 브라우저와 상관없이 글자 크기를 직접 지정 |
| <백분율> | 부모 요소의 글자 크기르 기준으로 해당하는 %를 계산해 표시 |

| 단위 | 설명 |
|:--------:|:--------:|
| em | 해당 글꼴의 대문자 M의 너비를 기준으로 크기조절 |
| ex | x-height(엑스 하이트)<br>해당 글꼴의 소문자 x의 높이를 기준으로 크기조절 |
| px | 픽셀, 모니터에 따라 상대적 크기가 된다 |
| pt | 포인트, 일반 문서에서 많이 사용하는 단위 |

##### > `px`사용하기
`px`를 사용하면 폰트크기가 고정되기 때문에 창 크기가 작은 모바일 기기로 볼때도 같은크기로 화면에 표시된다.
그래서 이때는 `em`이 더 좋다.

##### > `em`사용하기
