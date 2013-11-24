#!/usr/bin/env  python

import os
import Image

support_format = ['bmp', 'gif', 'jpg', 'png']

def process(arg, dirs, files):
    for file in files:
        file_ext = os.path.splitext(file)[1].lower()[1:]
        if file_ext in support_format:
            img = Image.open(os.path.dirname(dirs)+"/full/"+file)
            if img.size[0] > img.size[1]:
                rate = 1.0 * arg / img.size[0]
            else:
                rate = 1.0 * arg / img.size[1]

            size = (int)(img.size[0] * rate), (int)(img.size[1] * rate)
            print "Thumbnail the file "+file

            img.thumbnail(size, Image.ANTIALIAS)
            img.save(os.path.dirname(dirs)+"/thumbnail/"+file)


if __name__ == '__main__':
   
    os.path.walk('./full', process, 150)
