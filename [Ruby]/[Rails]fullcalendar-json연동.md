##full calender 사용시 주의사항
* `json`파일 생성시에 fullcalender에서 인식할 수 있는 변수명들을 model이 가지고 있어야한다.
* index에서 `json`을 만들어 줘야한다.
* 또한 `json`파일 경로를 `/캘린더와연동할모델명.json`으로 해주어야한다

##model column name

```
$ rails g migration rename_oldname_to_newname
```

```
class RenameoldnameTonewname < ActiveRecord::Migration
  def change
    rename_column :tablename, :oldname, :newname
  end
end
```
##제목
```
$ rails g migration AddTitleToReservation title:integer
```

```
before_validation :titlesetting

def titlesetting
	self.title = self.user.studentid
end
```
##컬러
```
$ rails g migration AddColorToReservation color:string
```

```
before_validation :colorsetting

def colorsetting
	self.color = self.group.color
end
```

