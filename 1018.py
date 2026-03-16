class Solution:
    def prefixesDivBy5(self, nums: list[int]) -> list[bool]:
        answer = []
        total = 0
        for num in nums:
            total <<= 1
            total |= num
            print(total)
            if total % 5 == 0:
                answer.append(True)
            else:
                answer.append(False)
        return answer

s = Solution()
print(s.prefixesDivBy5([0,1,1,1,1,1]))
