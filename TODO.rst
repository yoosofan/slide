Short Term todo
-----------------
* Adding docs for each folder
* Making a html foldes contain the html coverted form hovercraft files
* Repalcing offline tools like slide.py for converting dot graphviz to image by an online one like d3-graphviz javascript library. Bad internet connection in my classes and in Iran in general and blocking many websites forced me to use more offline approaches which is time consuming.

    .. code:: html
    
        <script src="https://d3js.org/d3.v5.min.js"></script>
        <script src="https://unpkg.com/@hpcc-js/wasm@0.3.11/dist/index.min.js"></script>
        <script src="https://unpkg.com/d3-graphviz@3.0.5/build/d3-graphviz.js"></script>

* Adding descriptions for each folders

Test the follwoing changes
------------------------------
Using PrismJS instead of HighlightJS
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Some html based slides needs a tool for code highlighting. HighlightJS was my choice but it is big and it lacks some feature like line-number. 
Converting a code to a highlighted one by tools like pygment was not a good choice because changing the code leads to make more and more replacing by hands instead of automatic changes.

* https://github.com/PrismJS/prism
* https://prismjs.com/plugins/line-highlight/
* https://prismjs.com/
* https://www.eddymens.com/blog/highlightjs-add-line-numbers
* https://github.com/wcoder/highlightjs-line-numbers.js
* http://wcoder.github.io/highlightjs-line-numbers.js/
