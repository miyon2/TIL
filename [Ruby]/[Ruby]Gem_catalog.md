## haml
**https://github.com/haml/haml**
```ruby
gem 'haml', '~> 4.0.5'
```
```
$ bundle install
```
이후에 에디터에서 language-haml package를 설치해준다. (알록달록)

## simple_form
**form을 bootstrap과 연동하기 쉽게 관리해준다!**
**https://github.com/plataformatec/simple_form**
```ruby
gem 'simple_form'
```
```
$ bundle install
$ rails generate simple_form:install
$ rails generate simple_form:install --bootstrap
$ rails generate simple_form:install --foundation
```

## bootstrap_sass
**https://github.com/twbs/bootstrap-sass**
```ruby
gem 'bootstrap-sass', '~> 3.3', '>= 3.3.7'
```
```
$ bundle install
```

## paperclip
**https://github.com/thoughtbot/paperclip**
**' ImageMagick ' must be installed and Paperclip must have access to it.**
```ruby
gem 'paperclip', '~> 5.1'
```
```
$ bundle install
```

## ImageMagick
**이미지를 수정할수있는 툴**
**http://www.imagemagick.org/script/index.php**
```
$ brew install ghostscript imagemagick
```

## cocoon
**nested form을 관리하기 위한 gem**
**https://github.com/nathanvda/cocoon**
```ruby
gem 'cocoon', '~> 1.2', '>= 1.2.9'
```
```
$ bundle install
```
이후 `assets/application.js`에 추가
```ruby
//= require cocoon
```

## devise
**https://github.com/plataformatec/devise**
```ruby
gem 'devise', '~> 4.2'
```
```
$ bundle install
```

## masonry-rails
**윈도우 크기가 바뀔때 함께 바뀌는 요소배치를 좀더 부드러운 효과로 연출할 수 있다.**
**https://github.com/kristianmandrup/masonry-rails**
```ruby
gem 'masonry-rails', '~> 0.2.4'
```
```
$ bundle install
```

## acts_as_votable
**좋아요 처럼 클릭시 횟수 증가하는 element를 만들수 있다**
**https://github.com/ryanto/acts_as_votable**
```ruby
gem 'acts_as_votable', '~> 0.10.0'
```
```
$ bundle install
```

## pry
**irb console을 바꿔준다**
**https://github.com/pry/pry**
```ruby
gem 'pry', '~> 0.10.4'
```
```
$ bundle 
$ rails c
```

## pry-rails
**rails console을 바꿔준다**
**https://github.com/rweng/pry-rails**
```ruby
gem 'pry-rails', '~> 0.3.4'
```
```
$ bundle 
$ rails c
```

## awesome_print
**console 창에서 출력되는 화면을 어-썸하게 바꿔준다**
**https://github.com/awesome-print/awesome_print**
```ruby
gem 'awesome_print', '~> 1.7'
```
```
$ bundle install
$ vi ~/.pryrc
```

## faker
****
**https://github.com/stympy/faker**
```ruby
gem 'faker', '~> 1.7', '>= 1.7.2'
```
```
$ bundle install
```
