#Ruby
###Blocks
* {} 또는 do...end문으로 엮인것
* {} : 한줄 > do...end : 여러줄
* yield : 코드블록 여러번 호출하기
> 예제
		def call_block
			puts “Start of method“
            yield
			yield
			puts “End of method“
		end
		call_block { puts “In the block“ } 
>결과
		Start of method
		In the block
		In the block
		End of method