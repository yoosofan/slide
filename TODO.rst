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

Add to the style.css
^^^^^^^^^^^^^^^^^^^^
* https://docs.yugabyte.com 
* https://github.com/yugabyte/yugabyte-db
* https://docs.yugabyte.com/preview/api/ysql/the-sql-language/with-clause/with-clause-syntax-semantics/#common-table-expression

Sample
``````
* db/sq.rst (With Diagram)
* db/style.css


.. code:: css

    svg.rrdiagram{max-width:100%}
    svg.rrdiagram .connector{fill:none;stroke:#222}
    svg.rrdiagram .text{fill:#000;font-family:Verdana,sans-serif;font-size:12px}
    svg.rrdiagram .literal{fill:#90d9ff;stroke:#222}
    svg.rrdiagram .rule{fill:#d3f0ff;stroke:#222}

Related tools
``````````````
* Generate railroad diagrams from code or BNF

* http://tabatkins.github.io/railroad-diagrams/README-py.html
* https://github.com/tabatkins/railroad-diagrams
* https://tabatkins.github.io/railroad-diagrams/generator.html#Diagram(%0A%20%20Optional('%2B'%2C%20'skip')%2C%0A%20%20Choice(0%2C%0A%20%20%20%20NonTerminal('name-start%20char')%2C%0A%20%20%20%20NonTerminal('escape'))%2C%0A%20%20ZeroOrMore(%0A%20%20%20%20Choice(0%2C%0A%20%20%20%20%20%20NonTerminal('name%20char')%2C%0A%20%20%20%20%20%20NonTerminal('escape'))))
* https://pypi.org/project/railroad-diagrams/

* https://www.xanthir.com/etc/railroad-diagrams/example.html
* https://www.xanthir.com/etc/railroad-diagrams/generator.html

* https://github.com/Chrriis/RRDiagram
* https://github.com/Chrriis/rrdiagram-js

* https://github.com/GuntherRademacher/rr
* https://www.bottlecaps.de/rr/ui
* https://discuss.python.org/t/railroad-diagrams-for-python-grammar/1017

* https://stackoverflow.com/questions/796824/tool-for-generating-railroad-diagram-used-on-json-org
* https://news.ycombinator.com/item?id=38877399

* https://pikchr.org/home/doc/trunk/doc/download.md 

* https://www.hwaci.com/sw/index.html

* https://wiki.documentfoundation.org/Documentation/SyntaxDiagrams
* https://en.wikipedia.org/wiki/Syntax_diagram
* https://en.wikipedia.org/wiki/Extended_Backus%E2%80%93Naur_form

* https://github.com/prantlf/railroad-diagrams 
* https://www.npmjs.com/package/@prantlf/railroad-diagrams

* https://www.w3.org/TR/2010/REC-xquery-20101214/#EBNFNotation

* https://karmin.ch/ebnf/index#download_and_install
* https://www.dokuwiki.org/plugin:ebnf
* https://github.com/tscherter/dokuwiki-plugin-ebnf/

* https://blog.mbless.de/railroad-diagrams

* https://katef.github.io/kgt/
* https://github.com/katef/kgt
* https://katef.github.io/kgt/doc/gallery/c89-ebnf.html


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

Learn more about Hovercraft and change its code
-----------------------------------------------
* https://www.strangegizmo.com/products/restxsl/
* https://stackoverflow.com/questions/2746692/restructuredtext-tool-support
* https://docutils.sourceforge.io/docs/user/links.html


Other Slide Show
---------------------
* https://github.com/adamzap/landslide

* https://github.com/shower/core
* https://github.com/shower/shwr.me

* https://github.com/gnab/remark
* https://github.com/gnab/remark/wiki
* https://github.com/gnab/remark
* https://remarkjs.com

Tools
------
Editors
^^^^^^^^
* geany.org
* https://github.com/retext-project/retext
* python.net/~gherman/ReSTedit.html


Check these
-----------
Creating pdf
^^^^^^^^^^^^
* https://copyprogramming.com/howto/python-convert-html-to-pdf
* https://forum.xojo.com/t/alternative-solutions-for-converting-html-to-pdf/69155/25
* https://stackoverflow.com/questions/73819036/how-to-convert-html-to-pdf-using-selenium-3-141-59
* https://pypi.org/project/pdfgen/
* https://pyppeteer.github.io/pyppeteer/index.html
* https://dev.to/bschoeneweis/converting-html-to-a-pdf-using-python-aws-lambda-and-wkhtmltopdf-3mdh
* https://github.com/kumaF/pyhtml2pdf
* https://www.reddit.com/r/learnpython/comments/15yxc4f/whre_i_can_download_pythonladp_for_windowns/
* https://www.reddit.com/r/voidlinux/comments/165uz0m/how_can_i_install_fluidsynthdssi/
* https://stackoverflow.com/questions/46026987/selenium-gives-selenium-common-exceptions-webdriverexception-message-unknown

More Graphic library
---------------------
PyCairo
^^^^^^^
* https://www.cairographics.org/pycairo/
* https://github.com/pygobject/pycairo
* https://pycairo.readthedocs.io/en/latest/
* https://pycairo.readthedocs.io/en/latest/tutorial/index.html

MathPlotLib
^^^^^^^^^^^
* https://matplotlib.org/
* https://matplotlib.org/stable/gallery/index



