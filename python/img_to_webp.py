from PIL import Image
import os

path = "/home/jaebum/ModooCode/views/img"
for filename in os.listdir('../views/img'):
  image_name = os.path.join(path, filename)
  image_only_name = image_name[:image_name.find(".")]

  im = Image.open(image_name).convert("RGB")
  im.save(image_only_name + ".webp", "WEBP")
