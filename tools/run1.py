#!python3
# python3 -m http.server 8002 --bind 127.0.0.1
# https://docs.python.org/3/library/http.server.html
# def run(server_class=HTTPServer, handler_class=BaseHTTPRequestHandler):
import http.server
import socketserver

# hovercraft uses 8000 port
PORT = 8005

Handler = http.server.SimpleHTTPRequestHandler

with socketserver.TCPServer(("", PORT), Handler) as httpd:
    print("serving at port", PORT)
    httpd.serve_forever()
