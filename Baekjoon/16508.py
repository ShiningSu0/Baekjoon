#N,K=map(int, input().split())
#a1=list(map(int, input().split()))
from itertools import combinations
import copy
T=list(input())
N=int(input())
target=[0]*26
words=[]
for i in range(N):
    C,W=map(str,input().split())
    temp=[0]*26
    for j in list(W):
        temp[ord(j)-65]+=1
    words.append([int(C),temp])
for i in T:
    target[ord(i)-65]+=1
#찾으려는 단어 빈도수 배열 target[26]
#words-> 전공책도 각각 크기 26의 빈도수 배열로 변환

ans=[]
for i in range(1,N+1):
    for lst in list(combinations(words,i)):#개수 별 모든 전공책 조합 생성
        temp=copy.deepcopy(target)
        price=0#가격 초기화
        for case in lst: # 조합에서 전공책 빈도수배열 하나씩 빼서 비교
            price+=case[0]
            for j in range(26): 
                if temp[j]>0 and case[1][j]>0:#찾으려는 단어 글자 빈도수 >0이고 전공책 빈도수배열 글자 빈도수 >0이면
                    temp[j]-=case[1][j]# 서로 빼버림
        cnt=0
        for k in range(26):
            if temp[k]>0:#다 찾으면 target 배열 체크해서
                continue
            else:
                cnt+=1
        if cnt==26:#다 찾아썼으면 가격을 업데이트
            ans.append(price)
if len(ans)==0:
    print(-1)
else:
    print(min(ans))#가격 최소값


