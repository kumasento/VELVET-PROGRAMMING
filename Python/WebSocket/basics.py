
from ws4py.messaging import TextMessage
from ws4py.websocket import WebSocket
from mock import MagicMock

class EchoWebSocket(WebSocket):
	def received_message(self, message):
		self.send(message.data, message.is_binary)

def data_source():
	yield TextMessage(u'hello world')

source = MagicMock(side_effect=data_source)
ws = EchoWebSocket(sock=source)
ws.send(u'hello world')

