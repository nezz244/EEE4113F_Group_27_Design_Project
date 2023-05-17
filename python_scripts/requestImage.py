import requests
import subprocess
import time


ssid = "SCT2"
pwd = "12345678"
bssid = "C4:DE:E2:12:48:D9"

output = {}
print("checking for {} network".format(ssid))
while not bssid in output:
    output = subprocess.check_output('nmcli device wifi list', shell=True, text=True)
    time.sleep(5)

print("found {}!".format(ssid))

print("trying to connect to {}".format(ssid))

try:
    subprocess.run('nmcli device wifi connect "{}" password "{}"'.format(ssid, pwd), shell=True, check=True)
except subprocess.CalledProcessError as e:
    print("Could not connect to {}. Error: {}".format(ssid, e))


def download_data(fileName):
    # link = " http://192.168.4.1?arg={}".format(arg)
    
    link = "http://192.168.4.1/"
    # response = requests.get(link)
    response = requests.get(link, params={"filename": fileName})

    if response.status_code == 200:
        imgData = response.json()
        with open(fileName, "wb") as file:
            file.write(response.content)
        
        print(imgData)
    else:
        print("{}".format(response.status_code))


FileName = "picture37.jpg"
download_data("picture.jpg")
# request_data(FileName)