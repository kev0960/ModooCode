from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.common.exceptions import NoSuchElementException
from selenium.common.exceptions import TimeoutException
from selenium.common.exceptions import StaleElementReferenceException

import time

driver = webdriver.Chrome('/usr/lib/chromium-browser/chromedriver')

for i in range(10, 230):
  driver.implicitly_wait(10)
  driver.get("http://itguru.tistory.com/" + str(i))
  driver.set_page_load_timeout(30)

  try:
    elem = driver.find_element_by_id("ttMorePreviousCommentsFor" + str(i))

    for _ in range(20):
      driver.execute_script("getEntryCommentsByPaging(" + str(i) + ")")
      time.sleep(2)

    comment = driver.find_element_by_class_name("commentList")
    with open('./blog/dump_comment_' + str(i) + ".html", "w") as html_file:
      html_file.write(comment.get_attribute('innerHTML'))

    #elem = driver.find_element_by_class_name("article")
    #with open("./blog/dump_" + str(i) + ".html", "w") as html_file:
    #    html_file.write(elem.get_attribute('innerHTML'))
  except NoSuchElementException:
    try:
      comment = driver.find_element_by_class_name("commentList")
      with open('./blog/dump_comment_' + str(i) + ".html", "w") as html_file:
        html_file.write(comment.get_attribute('innerHTML'))
    except:
      continue
  except TimeoutException:
    continue
  except StaleElementReferenceException:
    comment = driver.find_element_by_class_name("commentList")
    with open('./blog/dump_comment_' + str(i) + ".html", "w") as html_file:
      html_file.write(comment.get_attribute('innerHTML'))

driver.close()
