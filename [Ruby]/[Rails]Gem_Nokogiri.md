# Nokogiri 사용법

## 1. 설치
```ruby
# gemfile
gem 'nokogiri', '~> 1.8'
```
```
bundle install
```

## 2. 사용
```ruby
#! /usr/bin/env ruby

require 'nokogiri'
require 'open-uri'

# Fetch and parse HTML document
# 크롤링 할 주소를 open('url') 형식으로 넣는다
doc = Nokogiri::HTML(open('http://www.nokogiri.org/tutorials/installing_nokogiri.html'))

puts "### Search for nodes by css"
doc.css('nav ul.menu li a', 'article h2').each do |link|
  puts link.content
end

puts "### Search for nodes by xpath"
doc.xpath('//nav//ul//li/a', '//article//h2').each do |link|
  puts link.content
end

puts "### Or mix and match."
doc.search('nav ul.menu li a', '//article//h2').each do |link|
  puts link.content
end
```

## 3. 크롤링과 파싱
1. 크롤링 : 파싱결과 중 원하는 특정 데이터만을 가져오는것
2. 파싱 : 웹사이트의 페이지 소스 html 문서를 가져오는것
