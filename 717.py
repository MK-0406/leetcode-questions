class Solution:
    def isOneBitCharacter(self, bits: list[int]) -> bool:
        oneBit = True
        for i in range(len(bits) - 1):
            if not oneBit:
                oneBit = True
                continue
            if bits[i] == 1:
                oneBit = False
                i += 1
            print(i, oneBit)
        return oneBit

s = Solution()
print(s.isOneBitCharacter([1,1,1,0]))
print(s.isOneBitCharacter([1,1,1,1,1,1,0]))