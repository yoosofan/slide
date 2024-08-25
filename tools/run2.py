# python3 -m http.server 8002 --bind 127.0.0.1
# https://docs.python.org/3/library/http.server.html
# def run(server_class=HTTPServer, handler_class=BaseHTTPRequestHandler):


def run_server(PORT = 8002):
  import http.server
  import socketserver
  Handler = http.server.SimpleHTTPRequestHandler
  with socketserver.TCPServer(("", PORT), Handler) as httpd:
      print("serving at port", PORT)
      httpd.serve_forever()

def openBrowser(PORT = 8002):
  import webbrowser
  webbrowser.get('google-chrome').open('http://127.0.0.1:'+ str(PORT), new = 0, autoraise = True)
  
import threading, time
# hovercraft uses 8000 port
PORT = 8002
th1 = threading.Thread(target=run_server, args=(PORT,))
th2 = threading.Thread(target=openBrowser, args=(PORT,))
th1.start()
time.sleep(2)
th2.start()
th1.join()
th2.join()

