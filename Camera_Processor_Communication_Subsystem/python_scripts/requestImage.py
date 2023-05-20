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


def download_data(targetFile, destFile):
    # link = " http://192.168.4.1?arg={}".format(arg)
    
    link = "http://192.168.4.1/file?file={}".format(targetFile)
    # response = requests.get(link)
    response = requests.get(link)

    if response.status_code == 200:
        with open(destFile, "wb") as file:
            file.write(response.content)
            return True
        
    else:
        print("{}".format(response.status_code))

    return False


FileName = "imageList.txt"
download_data(FileName,FileName)

print("Got the list of files!")

with open(FileName, "r") as file:
    for line in file:
        if download_data(line, line):
            print("downloaded file {}".format(line))
        else:
            print("Could not find {}".format(line))
    

print("done downloading files")
# request_data(FileName)