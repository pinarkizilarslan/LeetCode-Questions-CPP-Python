class Solution:
    def watchedVideosByFriends(self, watchedVideos: List[List[str]], friends: List[List[int]], id: int, level: int) -> List[str]:
        friends = [set(item) for item in friends]

        tempRow = friends[id]
        oldFriends = {id}
        for _ in range(1, level):
            oldFriends.update(tempRow)
            nextRow = set()
            for friend in tempRow:
                nextRow.update(friends[friend])
            tempRow = nextRow - oldFriends

        videos = defaultdict(int)
        for friend in tempRow:
            for video in watchedVideos[friend]:
                videos[video] += 1

        return [item for _, item in sorted((freq, item) for item, freq in videos.items())]
