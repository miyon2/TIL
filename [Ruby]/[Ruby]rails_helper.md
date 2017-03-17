#Rails Helper

##link_to
##### * 지정된 텍스트로 링크를 생성한 후 클릭시에 이동할곳을 지정!
* Edit 링크를 클릭하면 /post/edit 으로 이동되며 post를 객체로 넘겨준다
```ruby
<%= link_to "Edit", edit_post_path(@post) %>
```
해당 링크는 다음 a태그로 변환된다.
```
<a href="http://localhost:3000/post/edit">Edit</a>
```

* 다수의 객체를 넘길 수도 있다.
```ruby
<%= link_to 'Ad details', url_for([@magazine, @ad]) %>
```
