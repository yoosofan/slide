#!/usr/bin/python3
from docutils import nodes
from docutils.parsers.rst import Directive, directives
# ~ import pelican.rstdirectives
import hovercraft, graphviz, sys, os, shutil
from typing import List
from pathlib import Path

class GlobalVariables:
  fullDirectoryName: str =''
  directoryName: str = 'temporary03454-images9877/'
  counter: int = 1
  mathjaxFileName: Path = Path('/home/ahmad/research/more_yoosofan/other/current_events/course/tools/mathjax/tex-mml-chtml.js')

def align(argument):
  """Conversion function for the "align" option."""
  return directives.choice(argument, ('left', 'center', 'right'))

class GraphVizCls(Directive):

  required_arguments = 0
  optional_arguments = 0
  final_argument_whitespace = True
  option_spec = {
    'alt': directives.unchanged,
    'height': directives.nonnegative_int,
    'width': directives.nonnegative_int,
    'scale': directives.nonnegative_int,
    'align': align,
    'class': directives.class_option,
  }
  has_content = True # node_class = nodes.note

  def run(self):
    self.assert_has_content()
    text = '\n'.join(self.content)
    src = graphviz.Source(text)
    name1 = str(GlobalVariables.counter)+'a.svg'
    src.render(directory=GlobalVariables.fullDirectoryName, 
      outfile=GlobalVariables.fullDirectoryName.joinpath(name1), 
      format='svg', view=False, engine='dot'
    )
    reference = directives.uri(GlobalVariables.directoryName+name1)
    GlobalVariables.counter += 1
    self.options['uri'] = reference
    image_node = nodes.image(
      rawsource=self.block_text,
      classes=self.options.get('class', []),
      **self.options
    )

    # ~ dd = Path.cwd().joinpath(GlobalVariables.directoryName).joinpath(GlobalVariables.mathjaxFileName.name)
    # ~ print('dd', dd)
    # ~ shutil.copy(GlobalVariables.mathjaxFileName, dd)

    return [image_node]

directives.register_directive('yographviz', GraphVizCls)

def checkArgvAndSetVariables(argvs: List[str]) -> List[str]:
  if len(argvs) < 2:
    print(f"Arguments count: {len(argvs)}")
    print('Enter name of slide')
    print('python3 run_slides.py compiler/slide/rd.rst')
    print('./run_slides.py compiler/slide/rd.rst')
    raise SystemExit(f"Usage: {argvs[0]} <rst slide path>")
    for i, arg in enumerate(argvs):
      print(f"Argument {i:>6}: {arg}")  
  path2 = Path(argvs[1]) # path2 = Path.cwd()
  if not path2.exists():
    raise SystemExit(f"Filename not exists. Usage: {path2} <rst slide path>")
  path2 = path2.resolve()# path1 = os.getcwd() + '/';  path1 += '/'.join(str(argvs[1]).split('/')[:-1]);
  GlobalVariables.fullDirectoryName = path2.parent.joinpath(GlobalVariables.directoryName)
  GlobalVariables.counter = 1

  # ~ cmd =  GlobalVariables.fullDirectoryName.joinpath('tex-mml-chtml.js')
  cmd =  '-j' + str(GlobalVariables.mathjaxFileName)
  cmd =  '-j./' + GlobalVariables.directoryName + str(GlobalVariables.mathjaxFileName.name)
  # ~ cmd =  '-j./' + str(GlobalVariables.mathjaxFileName.name)
  # ~ cmd =  '-jtemporary-images/tex-mml-chtml.js'
  # ~ cmd =  ' --js temporary-images/tex-mml-chtml.js'
  cmd = ['--skip-help', str(argvs[1])]
  
  return cmd
  
def createAndCopyDirectoriesAndFiles():
  Path.mkdir(GlobalVariables.fullDirectoryName)
  dd = GlobalVariables.fullDirectoryName.joinpath(GlobalVariables.mathjaxFileName.name)
  shutil.copy(GlobalVariables.mathjaxFileName, dd)
  dd = GlobalVariables.fullDirectoryName.joinpath('output')
  shutil.copytree(GlobalVariables.mathjaxFileName.parent.joinpath('output'), dd)
  
if __name__ == "__main__":
  cmd = checkArgvAndSetVariables(sys.argv)
  try:    
    createAndCopyDirectoriesAndFiles()
    hovercraft.main(cmd)
  finally:
    shutil.rmtree(GlobalVariables.fullDirectoryName)

"""
def old_run_slides_body():
  
  # python3 -m http.server 8002 --bind 127.0.0.1
  # https://docs.python.org/3/library/http.server.html
  # def run(server_class=HTTPServer, handler_class=BaseHTTPRequestHandler):
  import http.server
  import socketserver

  # hovercraft uses 8000 port
  PORT = 8002

  Handler = http.server.SimpleHTTPRequestHandler

  with socketserver.TCPServer(("", PORT), Handler) as httpd:
    print("serving at port", PORT)
    httpd.serve_forever()

"""

'''
output/chtml/fonts/woff-v2/MathJax_Math-Italic.woff
output/chtml/fonts/woff-v2/MathJax_Zero.woff
output/chtml/fonts/woff-v2/MathJax_Main-Regular.woff

/tmp/tmpdznxbzwt/temporary03454-images9877/output/chtml/fonts/woff-v2/MathJax_Math-Italic.woff

'''

