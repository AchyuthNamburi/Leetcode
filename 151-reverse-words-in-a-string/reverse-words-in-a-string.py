class Solution:
    def reverseWords(self, s: str) -> str:
        l=[]
        l.append(s.split(' '))
        p=[]
        for it in l:
            for j in it:
                if j!="":
                    p.append(j)
        ans=""
        p.reverse()
        
        for it in p:
            ans=ans+it+" "
        
        ans=ans.rstrip()
        
        return ans
        
        

        