# Searchkick
### 1. `elasticsearch` 설치하기
```terminal
$ brew install elasticsearch
$ brew services start elasticsearch
```
설치하지 않으면 `port 9200`어쩌구 오류가 난다. 조심!

### 2. `searchkick` 설치하기
```ruby
gem 'searchkick'
```
```ruby
class 모델명 < ActiveRecord::Base
  searchkick
end
```
```terminal
$ rake searchkick:reindex:all
```
또는 필요한 모델만 적용시킬수 있다.
```terminal
$ rake searchkick:reindex CLASS=모델명
```

### 3. `searchkick` 사용하기
```ruby
#=> home_controller.rb
def index
   @users = User.search "mw"
   @users.each do |user|
   puts user.name
end
#=> index.html.erb
<%= @users %>			#=> Searchkick::Results 를 배열형태로 반환한다.
<%= @users.result %>	#=> 결과를 attribute별로 반환한다. 비슷한 내용까지 전부 반환한다.
```
* `misspellings: false` 옵션으로 결과의 정확도를 조절할수 있다.

### 4. 실제 사용해보기
##### ISSUE 1
* `ku_festival` 에서는 `daum map API`에서의 검색기능을 적용하기 위해 json파일을 만들어주어야 했다.

##### ISSUE 2
* form을 통해 검색 키워드를 입력받아야 했다.

##### SOLVE 1
* `render:json`이 적용되지 않아서 github문서를 참조했다. 다음과 같이 해결할 수 있었다.
```ruby
render json: User.search(params[:search], {
  fields: ["name", "age"],
  limit: 10,
  load: false,
  misspellings: false
})
```

##### SOLVE 2
**controller에서 search 액션 지정, routes.rb 에서 get "users/search" 지정 이후**
1. `_form.html.erb`에서 routes를 지정해줬다.
```erb
<%= form_tag users_search_path, method: :get, class: "navbar-form navbar-right", role: "search" do %>
  <p>
    <%= text_field_tag :search, params[:search], class: "form-control" %>
    <%= submit_tag "Search", name: nil, class: "btn btn-default" %>
  </p>
<% end %>
```

2. controller의 search 액션 내용을 구현했다.
```ruby
if params[:search].present?
  @users = User.search(params[:search])
else
  @users = User.all
end
```

3. `Couldn't find User with id=search` 라는 이슈가 떠서 라우트 지정을 다시 해주어야했다.
```ruby
resources :users do
  collection do
    get 'search'
  end
end
```

## 참고
| 참고 | url |
|:--------:|:--------:|
| github | **https://github.com/ankane/searchkick**<br>**https://github.com/mackenziechild/movie_review** |
| Tutorial | **http://www.munocreative.com/nerd-notes/tutor-portal** |
| StackOverflow | **http://stackoverflow.com/questions/24618807/couldnt-find-user-with-id-search** |
