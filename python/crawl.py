from selenium import webdriver
from selenium.webdriver.common.keys import Keys

driver = webdriver.Chrome()

for i in range(100) :
    driver.implicitly_wait(10)
    driver.get("http://itguru.tistory.com/" + str(i))

    elem = driver.find_element_by_class_name("tt_article_useless_p_margin")
    print elem.get_attribute('innerHTML')

driver.close()