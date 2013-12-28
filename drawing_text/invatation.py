#!/usr/bin/env  python
#coding=utf-8

import os
import Image
import ImageDraw
import ImageFont

img = Image.open("res/invatation.jpg")
name = os.sys.argv[1]

cname = name.decode('utf-8')

length = len(cname)


draw = ImageDraw.Draw(img)
#font = ImageFont.truetype("font/Comic_Sans_MS_Bold.ttf", 17)
font = ImageFont.truetype("font/xingkai.TTF", 130)

i = 0
if length == 3:
    while i <= length-1:
        draw.text((1410,825+130*i), cname[i], (255,255,0),font=font)
        i = i+1
else:
    while i <= length-1:
        draw.text((1410,825+250*i), cname[i], (255,255,0),font=font)
        i = i+1

img.save('./output/'+name+'00.jpg')


