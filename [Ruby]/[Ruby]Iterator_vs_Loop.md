# Iterator와 반복문은 어떤 차이를 가질까?

Ruby의 튜터링 자료를 만들다 반복자와 반복문의 차이에 대해 관심이 생겨서 공부하게되었다.
반복자와 반복문 모두 같은 코드를 반복하기때문에 명확한 차이가 드러나지 않아 더욱 궁금했다.

## 반복문이 발달된 형태가 Iterator?
OOP의 등장 이전에는 자주 반복되는 코드를 반복문으로 처리했었다.
그러나 OOP 등장 이후에는 특정 자료형 내에 내장된 **Iterator**가 생겨났다.

또, `Ruby에는 Iterator가 있더라~ 공부해보자!` 보다는 
`OOP에는 iterator가 있으니 OOP언어인 Ruby에서도 iterator를 공부해봐야지~` 가 더 맞는것같다.

Ruby에서는 Iterator를 다음과 같이 사용한다.
```ruby
"abcde".each_byte{|c| printf "<%c>", c}; print "\n"

#=> <a><b><c>
```

참고자료에 따르면 위의 코드는 다음과같은 프로세스를 거친다. (Ruby는 C로 만들어진 언어이다.)
```ruby
t = "abcde";i=0
while i<s.length
	printf "<%c>", s[i]; i+=1
end; print "/n"

#=> <a><b><c>
```
코드에서처럼 iterator를 쓸 경우에는 중간에 값을 변경하기가 쉬워보인다.
반면에 변경하지 않을경우 불필요하게 반복함으로써 실행시간은 늘어날것이다.

개인적인 견해로는 Iterator가 매우 편하고 좋지만, 중간에 값을 변경할 일이 없다면 실행시간을 줄이기 위해서 반복문을 쓰는것이 매우 좋은것같다. 어느것이 더 좋다라고 확정짓긴 어려운것같다.


* 참고자료 : **http://ruby-doc.org/docs/ruby-doc-bundle/UsersGuide/rg/iterators.html**