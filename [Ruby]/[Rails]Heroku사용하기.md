# Heroku 사용하기
## Issue 1
```
$ heroku pg:reset DATABASE_URL
```
실행되지 않을때
```
$ DATABASE_URL=$(heroku config:get DATABASE_URL -a 지정한_앱_이름)
```
이후
```
$ heroku run rake db:migrate
```
참고 https://devcenter.heroku.com/articles/connecting-to-heroku-postgres-databases-from-outside-of-heroku