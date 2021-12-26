class AllOne:

    def __init__(self):
        self.count = {}
        self.strings = defaultdict(set)
        return 

    def inc(self, key: str) -> None:
        self.count[key] = self.count[key]+1 if key in  self.count else 1
        self.strings[self.count[key]].add(key)
        if self.count[key]>1: 
            self.strings[self.count[key]-1].remove(key)
            if not self.strings[self.count[key]-1]:
                del self.strings[self.count[key]-1]
        return

    def dec(self, key: str) -> None:
        self.count[key] = self.count[key]-1
        if self.count[key]:
            self.strings[self.count[key]].add(key)
        self.strings[self.count[key]+1].remove(key)
        if not self.strings[self.count[key]+1]:
            del self.strings[self.count[key]+1]
        return
   
    def getMaxKey(self) -> str:
        _max = max(self.strings.keys()) if self.strings.keys() else 0
        return next(iter(self.strings[_max])) if _max else ""

    def getMinKey(self) -> str:
        _min = min(self.strings.keys()) if self.strings.keys() else 0
        return next(iter(self.strings[_min])) if _min else ""

# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()
