---
title: "5주차 수업자료 (devise)"
tag: material
author: "우미연"
---
# Devise 사용하기
### 1. devise 설치
```ruby
gem 'devise', '~> 4.2', '>= 4.2.1'
```

```
$ bundle install
$ rails new project_name
$ cd project_name
$ rails g controller Posts
$ rails g model Post title content user:references
$ rails g devise:install
$ rails g devise User
```

### 2. 모델 관계 완성하기
```ruby
# routes.rb
Rails.application.routes.draw do
  devise_for :users
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
  resources :posts
  root "posts#index"
end
```

```ruby
# user.rb
class User < ApplicationRecord
  has_many :posts, dependent: :destroy
  # Include default devise modules. Others available are:
  # :confirmable, :lockable, :timeoutable and :omniauthable
  devise :database_authenticatable, :registerable,
         :recoverable, :rememberable, :trackable, :validatable
end
```
```ruby
# post.rb
class Post < ApplicationRecord
  belongs_to :user
end
```

```
$ rake db:migrate
```

### 3. CRUD
```ruby
# posts_controller.rb
class PostsController < ApplicationController
  before_action :authenticate_user!, except: [ :index, :show ]
  before_action :find_posts, only: [:show, :edit, :update, :destroy]

  def index
    @posts = Post.all.order("created_at DESC")
  end

  def new
    @post = Post.new
  end

  def create
    @post = Post.new(post_params)

    if @post.save
      redirect_to @post
    else
      render 'new'
    end
  end

  def show
  end

  def edit
  end

  def update
    if @post.update(post_params)
      redirect_to @post
    else
      render 'edit'
    end
  end

  def destroy
  	@post.destroy
  	redirect_to posts_path
  end

  private

  def find_posts
  	@post = Post.find(params[:id])
  end

  def post_params
    params.require(:post).permit(:title, :content)
  end
end
```

```erb
<!--index.html.erb-->
<h2>Lists</h2>
<% @posts.each do |post| %>
	<h2><%= link_to post.title, post %></h2>
<% end %>
<%= link_to "new post", new_post_path %>
```

```erb
<!--new.html.erb-->
<h2>New Posts</h2>

<%= render 'form' %>

<%= link_to "Back", posts_path %>
```

```erb
<!--show.html.erb-->
<h2>Title : <%= @post.title %> </h2>
<p> Content : <%= @post.content %></p>

<%= link_to "Home" ,root_path %>
<%= link_to "edit post" , edit_post_path %>
<%= link_to "delete post" , post_path(@post), method: :delete, data: {confirm: "Are you sure?"} %>
```

```erb
<!--_form.html.erb-->
<%= form_for @post do |f| %>
  <div class="field">
    <%= f.label :title %>
    <%= f.text_field :title %>
  </div>
  <div class="field">
    <%= f.label :content %>
    <%= f.text_field :content %>
  </div>
  <div class="actions">
    <%= f.button :submit %>
  </div>
<% end %>
```

```erb
<!-- edit.html.erb -->
<h2>Edit Post</h2>

<%= render 'form' %>

<%= link_to "Back", posts_path %>
```

### 4. nav-bar에 sign in, out, up, my_profile 생성하기
```erb
<!-- application.html.erb -->
<!DOCTYPE html>
<html>
  <head>
    <title>Devise2</title>
    <%= csrf_meta_tags %>

    <%= stylesheet_link_tag    'application', media: 'all', 'data-turbolinks-track': 'reload' %>
    <%= javascript_include_tag 'application', 'data-turbolinks-track': 'reload' %>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/css/bootstrap.min.css" integrity="sha384-rwoIResjU2yc3z8GV/NPeZWAv56rSmLldC3R/AZzGRnGxQQKnKkoFVhFQhNUwEyJ" crossorigin="anonymous">
    <script src="https://code.jquery.com/jquery-3.1.1.slim.min.js" integrity="sha384-A7FZj7v+d/sdmMqp/nOQwliLvUsJfDHW+k9Omg/a/EheAdgtzNs3hpfag6Ed950n" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/tether/1.4.0/js/tether.min.js" integrity="sha384-DztdAPBWPRXSA/3eYEEUWrWCy7G5KFbe8fFjk5JAIxUYHKkDx6Qin1DkWx51bBrb" crossorigin="anonymous"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/js/bootstrap.min.js" integrity="sha384-vBWWzlZJ8ea9aCX4pEW3rVHjgjt7zpkNpZk+02D9phzyeVkE+jo0ieGizqPLForn" crossorigin="anonymous"></script>  </head>

  <body>
    <nav class="navbar navbar-toggleable-md navbar-light bg-faded">
      <button class="navbar-toggler navbar-toggler-right" type="button" data-toggle="collapse" data-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
      </button>
      <%= link_to 'Navbar', root_path, class: "navbar-brand" %>
      <div class="collapse navbar-collapse" id="navbarNav">
        <ul class="navbar-nav">
          <li class="nav-item active">
            <%= link_to 'Home', root_path, class: "nav-link" %>
          </li>
          <% if user_signed_in? %>
            <li class="nav-item">
              <%= link_to 'My Profile', edit_user_registration_path, class: "nav-link" %>
            </li>
            <li class="nav-item">
              <%= link_to 'Sign out', destroy_user_session_path, method: :delete, data: { confirm: "Are you sure?" }, class: "nav-link" %>
            </li>
          <% else %>
            <li class="nav-item">
              <%= link_to 'Sign in', new_user_session_path, class: "nav-link" %>
            </li>
            <li class="nav-item">
              <%= link_to 'Sign up', new_user_registration_path, class: "nav-link" %>
            </li>
          <% end %>
        </ul>
      </div>
    </nav>
    <%= yield %>
  </body>
</html>

```

## Author

written by [우미연](https://miyon2.github.io).

![](https://avatars.githubusercontent.com/miyon2?v=2&s=100)

<a href="https://miyon2.github.io" target="_blank" class="btn btn-black"><i class="fa fa-github fa-lg"></i> Visit on Github Page &rarr;</a>
