# CSS

## Media Query
반응형 웹을 만들때 모바일 기종에 적용하기 위해 사용한다.

~~~css
<!-- CSS media query on a link element -->
<link rel="stylesheet" media="(max-width: 800px)" href="example.css" />

<!-- CSS media query within a stylesheet -->
<style>
@media (max-width: 600px) {
  .facet_sidebar {
    display: none;
  }
}
</style>
~~~

`@media` 이후의 내용이 true일경우 style 태그 내의 속성이 적용되며, 
link태그 내부에 media query가 존재할경우 false가 아닐 경우에만 적용된다.

* Orientation
~~~css
@media all and (orientation:portrait) { … } // 세로 모드. 뷰포트의 높이가 너비에 비해 상대적으로 크면 실행
@media all and (orientation:landscape) { … } // 가로 모드. 뷰포트의 너비가 높이에 비해 상대적으로 크면 실행
~~~
> 참고 : http://naradesign.net/wp/2012/05/30/1823/

## CSS Resetting
* 브라우저마다 CSS속성 기본값이 다르다. 때문에 전부 똑같은 기본값을 주기위해 css reset library를 사용한다.
>Ex> normalize.css

## 임시 이미지(Placeholder images) 생성하기
임시로 이미지를 넣고싶을때 다음과같은 사이트 url 뒤에 크기를 덧붙여 img태그로 첨부 가능하다.
* http://placehold.it
* http://www.dummyimage.com

```html
<img src="http://dummyimage.com/150x100" />
```

## 폰트 적용하기
**https://fonts.google.com/** 참고

## Modal (modal.js)
`data-toggle`, `data-target` 을 이용하여 사용한다.
```html
<!-- Button trigger modal -->
<button type="button" class="btn btn-primary btn-lg" data-toggle="modal" data-target="#myModal">
  Launch demo modal
</button>

<!-- Modal -->
<div class="modal fade" id="myModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title" id="myModalLabel">Modal title</h4>
      </div>
      <div class="modal-body">
        ...
      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
        <button type="button" class="btn btn-primary">Save changes</button>
      </div>
    </div>
  </div>
</div>
```
* 모달에 연결해줄 태그의 id는 `data-target`특성의 것과 일치해야한다.