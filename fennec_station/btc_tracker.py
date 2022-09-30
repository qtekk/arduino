import requests
import serial
import json
import time
from bs4 import BeautifulSoup

s = serial.Serial('/dev/ttyUSB0', baudrate=9600)
time.sleep(2)
i = 0

if s.isOpen():
  while (True):
    tries = 3
    for i in range(tries):
        try:
          req = requests.get("https://api.bitfinex.com/v1/pubticker/ethusd")
          scrap = BeautifulSoup(req.text, 'html.parser').get_text()
          resultJson = json.loads(scrap)
          print(resultJson)
          s.write(str(resultJson["last_price"]).encode())
          time.sleep(20)
        except KeyError as e:
            if i < tries - 1: # i is zero indexed
              continue
            else:
              raise
        break 
