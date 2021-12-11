#!/bin/env python3
import json
import sys
from datetime import datetime

leaderboardFile = open(sys.argv[1])
leaderboardJson = json.load(leaderboardFile)

day = sys.argv[2]
part = sys.argv[3] if len(sys.argv) == 4 else "2"

def hasDayAndPart(m):
    return day in m and part in m[day]

mems = leaderboardJson["members"]

def cdl(m):
    return mems[m]["completion_day_level"]

m = [(datetime.fromtimestamp(cdl(m)[day][part]["get_star_ts"]), mems[m]["name"]) for m in mems if hasDayAndPart(cdl(m))]

m.sort()

for p in m:
    print(f'{p[1]} {p[0]}')
