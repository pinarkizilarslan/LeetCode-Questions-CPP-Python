class Solution:
    def isPathCrossing(self, path: str) -> bool:
        x=0
        y=0
        points= set()

        str="{}, {}".format(x,y)
        points.add(str)
        for i in range(len(path)):
            if(path[i]=='N'):
                y=y+1

            if(path[i]=='S'):
                y=y-1

            if(path[i]=='E'):
                x=x+1

            if(path[i]=='W'):
                x=x-1

            l = len(points) 
            str="{}, {}".format(x,y)
            points.add(str)

            if (len(points) == l):
                return True

        return False