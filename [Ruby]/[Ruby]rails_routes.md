# Rails Routing
1. routes.rb를 읽는 방법
2. 직접 라우팅을 작성하는 방법 (리소스 베이스 & match 메소드)
3. 컨트롤러의 액션에 넘길 라우트 매개변수를 선언하는 방법
4. 라우트 헬퍼를 사용해서 경로나 URL을 자동생성하는 방법
5. 제한을 추가하거나 Rack 엔드포인트 추가하는 방법

## 1. 라우터의 목적
### **++컨트롤러의 액션에 요청 매칭시켜주기!++**
```ruby
GET /posts/17 					 #이러한 요청을 받을경우
get '/posts/:id', to: 'posts#show' #posts컨트롤러의 show액션에 연결!
```

### **++코드로부터 URL 생성하기++**
1. route.rb
```ruby
get '/posts/:id', to: 'posts#show', as: 'post'
```

2. posts_controller.rb
```ruby
@post = Post.find(17)
```

3. show.html.erb
```ruby
#Show Post 링크 클릭 시에 post/17로 이동
#id를 지정해주지 않아도 되므로 유지보수가 쉽다!
<%= link_to 'Show Post', post_path(@post) %>
```

## 2. RESTful한 라우팅 선언하기
##### * `resources :posts` 를 선언하면?
1. 7가지 라우팅 생성
>`index`/`new`/`create`/`show`/`edit`/`update`/`destroy` 
2. `posts_path`는 `/posts`를 돌려준다.
3. `new_posts_path`는 `/posts/new`를 돌려준다.
4. `edit_posts_path(:id)`는 `/posts/:id/edit`을 돌려준다.
5. `posts_path(:id)`는 `/posts/:id`를 돌려준다.

##### * 네임스페이스로 컨트롤러 그룹묶기
1. 블록 사용하기
```ruby
namespace :admin do
	resources :posts, :comments
end
```
| 경로 | 액션 | 헬퍼 |
|--------|--------|--------|
| /admin/posts | admin/posts#index | admin_posts_path |
| /admin/posts/new | admin/posts#new | new_admin_post_path |
| /admin/posts | admin/posts#create | admin_posts_path |
| /admin/posts/:id | admin/posts#show | admin_post_path(:id) |
| /admin/posts/:id/edit | admin/posts#edit | edit_admin_post_path(:id) |
| /admin/posts/:id | admin/posts#update | admin_post_path(:id) |
| /admin/posts/:id | admin/posts#destroy | admin_post_path(:id) |

2. 블록 사용하지않기
```ruby
resources :posts, path: '/admin/posts'
```
| 경로 | 액션 | 헬퍼 |
|--------|--------|--------|
| /admin/posts | posts#index | posts_path |
| /admin/posts/new | posts#new | new_post_path |
| /admin/posts | posts#create | posts_path |
| /admin/posts/:id | posts#show | post_path(:id) |
| /admin/posts/:id/edit | posts#edit | edit_post_path(:id) |
| /admin/posts/:id | posts#update | post_path(:id) |
| /admin/posts/:id | posts#destroy | post_path(:id) |

