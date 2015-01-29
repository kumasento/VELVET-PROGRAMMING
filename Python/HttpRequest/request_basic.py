import requests

url = "http://162.105.146.180:8059"

response = requests.get(url)

print "status code:", response.status_code
print "content-type:", response.headers['content-type']
print response.content
