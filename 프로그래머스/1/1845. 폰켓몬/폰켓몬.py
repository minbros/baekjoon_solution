import ast


def solution(nums):
    dic = [0] * 200000

    for num in nums:
        dic[num - 1] += 1

    dic = [d for d in dic if d >= 1]

    if len(nums) // 2 <= len(dic):
        answer = len(nums) // 2
    else:
        answer = len(dic)

    return answer