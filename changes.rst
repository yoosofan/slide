Removed Tools
-----------------
Javascript Libraries
^^^^^^^^^^^^^^^^^^^^
It is better to use less javascript libraries because of 

* Being online
* Security
* Unspecified reduction of performance and increasing memory usage

d3-graphviz
```````````
* Repalcing offline tools like slide.py for converting dot graphviz to image by an online one like d3-graphviz javascript library. Bad internet connection in my classes and in Iran in general and blocking many websites forced me to use more offline approaches which is time consuming.

    .. code:: html
    
        <script src="https://d3js.org/d3.v5.min.js"></script>
        <script src="https://unpkg.com/@hpcc-js/wasm@0.3.11/dist/index.min.js"></script>
        <script src="https://unpkg.com/d3-graphviz@3.0.5/build/d3-graphviz.js"></script>
.. :

    .. raw:: html

        <script src="https://d3js.org/d3.v5.min.js"></script>
        <script src="https://unpkg.com/@hpcc-js/wasm@0.3.11/dist/index.min.js"></script>
        <script src="https://unpkg.com/d3-graphviz@3.0.5/build/d3-graphviz.js"></script>

.. :

  https://github.com/magjac/d3-graphviz
  https://bl.ocks.org/magjac/a23d1f1405c2334f288a9cca4c0ef05b
  https://codepen.io/tlk/pen/rOpaEr
  http://viz-js.com/
  https://stackoverflow.com/questions/6344318/pure-javascript-graphviz-equivalent
  https://stackoverflow.com/questions/18444406/how-do-i-use-special-characters-in-a-dot-file-node-id
  https://www.geeksforgeeks.org/bottom-up-or-shift-reduce-parsers-set-2/
  https://renenyffenegger.ch/notes/tools/Graphviz/examples/index
  https://sketchviz.com/graphviz-examples
  https://github.com/Chiel92/graphviz/blob/master/doc/Dot.ref
  https://github.com/timtadh/dot
  https://stackoverflow.com/questions/49224484/how-to-specify-in-dot-file-that-edges-go-upwards/49226085
  https://en.wikipedia.org/wiki/DOT_(graph_description_language)
  https://en.wikipedia.org/wiki/DOT_(graph_description_language)
  https://renenyffenegger.ch/notes/tools/Graphviz/examples/index
  https://sketchviz.com/graphviz-examples
  dot convert to image

