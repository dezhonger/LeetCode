class Robot:
    def __init__(self, width: int, height: int):
        self.w, self.h, self.s = width, height, 0

    def step(self, num: int) -> None:
        # 由于机器人只能走外圈，那么走 (w+h-2)*2 步后会回到起点
        # 同时，将 s 取模固定在 [1,(w+h-2)*2] 范围内，这样不需要特判处于原点时的方向
        self.s = (self.s + num - 1) % ((self.w + self.h - 2) * 2) + 1

    def get(self):
        s, w, h = self.s, self.w, self.h
        # 第一次的话0 会落在这个if里，后续s不会再为0了
        if s < w: return s, 0, "East"
        if s < w + h - 1: return w - 1, s - w + 1, "North"
        if s < w * 2 + h - 2: return w * 2 + h - 3 - s, h - 1, "West"
        return 0, (w + h - 2) * 2 - s, "South"

    def getPos(self) -> List[int]:
        x, y, _ = self.get()
        return [x, y]

    def getDir(self) -> str:
        return self.get()[2]
