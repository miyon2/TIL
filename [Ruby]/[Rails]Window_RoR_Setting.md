# Window에 Ruby on Rails 개발환경 만들기

## 1. railsinstaller 다운
* **http://railsinstaller.org** 접속 후 `Ruby 2.3` 다운로드

## 2. rails 환경 설정
* 명령 프롬프트 창이 열리면 `git`에 사용할 `name`, `email`을 입력한다.
* `bundler`와 `rails`를 다운로드한다.
~~~
$ gem install bundler
$ gem install rails
$ rails -v				// 버전확인
~~~

## 3. rails 프로젝트 만들기 및 로컬환경 실행
~~~
$ rails new my_app
$ rails s
~~~

## 4. 주의사항
`rake`가 작동하지 않기 때문에 rails로 바꾸어준다.
~~~
$ rails db:migrate
~~~
