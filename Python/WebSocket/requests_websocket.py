import requests

s = requests.Session()
s.headers['Connection'] = 'Upgrade'
s.headers['Upgrade'] = 'WebSocket'
s.headers['Sec-WebSocket-Version'] = '13'
s.headers['Sec-WebSocket-Key'] = 'sN9cRrP/n9NdMgdcy2VJFQ=='

r = s.get('http://127.0.0.1:9000/ws')