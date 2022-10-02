import requests
import serial
import json
import time
import platform
from bs4 import BeautifulSoup

sys = platform.system()
port = "/dev/ttyUSB0" if sys == "Linux" else "COM8"

print("System:", sys) 
print("Port:", port)

serialPort = serial.Serial(port, baudrate=9600)
time.sleep(2)

if serialPort.isOpen():
  while (True):
    tries = 3
    for i in range(tries):
      try:
        req = requests.get("https://api.cryptowat.ch/markets/zonda/ethpln/summary")
        scrap = BeautifulSoup(req.text, 'html.parser').get_text()
        resultJson = json.loads(scrap)
        print(resultJson)
        lastPrice = resultJson["result"]["price"]["last"]
        changePercentage = resultJson["result"]["price"]["change"]["percentage"]
        message = "ETH-PLN " + "{:.2%}".format(changePercentage) + "|" + str(lastPrice) + "|"
        serialPort.write(message.encode())
        time.sleep(20)
      except KeyError as e:
        if i < tries - 1:
          continue
        else:
          raise
      break 
