# Daum map API 사용하기
### 1. key 발급받기
1. **http://developers.daum.net/** > 콘솔
2. 앱 만들기
3. 좌측의 `API 키` > `REST/JS API`에서 `+`
4. 플랫폼을 웹브라우저로 선택 후 입력칸에 `http://localhost:3000/`를 입력해 로컬환경에서 사용가능하게 해준다.

### 2. `<script>` 삽입
```
<script type="text/javascript" src="//apis.daum.net/maps/maps3.js?apikey=발급받은 key입력"></script>
```
위 코드를 `<head>`에 삽입 후 다음 코드를 작성한다.

```
<script>
  var container = document.getElementById('map');
  var options = {
    center: new daum.maps.LatLng(33.450701, 126.570667),
    level: 3
  };
  var map = new daum.maps.Map(container, options);
</script>
```
이후, map을 사용할 부분에 `<div id="map"></div>`를 이용해 지도를 넣어준다.