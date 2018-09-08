import os
import imghdr

path = "/home/jaebum/ModooCode/views/img"
for filename in os.listdir('../views/img'):
    img_type = imghdr.what(os.path.join(path, filename))
    os.rename(os.path.join(path, filename), os.path.join(path, filename + "." + img_type))

