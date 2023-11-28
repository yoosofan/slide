:data-transition-duration: 1000
:skip-help: true
:css: assets/hovercraft.css assets/javascript1.css

.. title: javascript1 (By Ahmad Yoosofan)

:slide-numbers: true

.. role:: ltr
    :class: ltr

.. role:: rtl
    :class: rtl

.. role:: raw-html(raw)
   :format: html

Javascript
======================
Ahmad Yoosofan

http://yoosofan.github.io/

Search "Ahmad Yoosofan"

----

:class: t2c

Script
========
.. include:: src/javascript/2444.html
    :code: html
    :number-lines:

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/javascript/2444.html" title="description" class="output-of-html">
   </iframe>

----

Document Object Manipulation
=================================
.. image:: img/800px-DOM-model.svg.png
  :height: 400px

`wikipedia <https://en.wikipedia.org/wiki/Document_Object_Model>`_

----

:class: t2c

Examine Document Object(I)
===========================
.. include:: src/javascript/2516.html
    :code: html
    :number-lines:

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/javascript/2516.html" title="description" class="output-of-html">
   </iframe>


----

:class: t2c

Examine Document Object(II)
===========================
.. include:: src/javascript/2523.html
    :code: html
    :number-lines:

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/javascript/2523.html" title="description" class="output-of-html">
   </iframe>

----

:class: t2c

Examine Document Object(III)
=============================
.. include:: src/javascript/2525.html
    :code: html
    :number-lines:

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/javascript/2525.html" title="description" class="output-of-html">
   </iframe>

----

:class: t2c

Examine Document Object(IV)
=============================
.. include:: src/javascript/2527.html
    :code: html
    :number-lines:

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/javascript/2527.html" title="description" class="output-of-html">
   </iframe>


----

:class: t2c

Examine Document Object(V)
=============================
.. include:: src/javascript/2642.html
    :code: html
    :number-lines:

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/javascript/2642.html" title="description" class="output-of-html">
   </iframe>


----

Get Eelement By Id
========================
.. code:: javascript

  console.log(document.getElementById('header-title'));
  let headerTitle = document.getElementById('header-title');
  let header = document.getElementById('main-header');
  console.log(headerTitle);
  headerTitle.textContent = 'Hello';
  headerTitle.innerText = 'Goodbye';
  console.log(headerTitle.innerText);
  headerTitle.innerHTML = '<h3>Hello</h3>';
  header.style.borderBottom = 'solid 3px #000';

.. :

  https://stackoverflow.com/questions/35213147/difference-between-textcontent-vs-innertext
  https://betterprogramming.pub/whats-best-innertext-vs-innerhtml-vs-textcontent-903ebc43a3fc
  https://dev.to/mohananagavenkat/textcontent-vs-innertext-1i83
  https://wiki.selfhtml.org/wiki/JavaScript/DOM/Node/textContent
  https://www.mediaevent.de/javascript/DOM-W3C.html
  https://developer.mozilla.org/en-US/docs/Web/API/Node/textContent

----

GET ELEMENTS BY CLASS NAME
=============================
.. code:: javascript

  let items = document.getElementsByClassName('list-group-item');
  console.log(items);
  console.log(items[1]);
  items[1].textContent = 'Hello 2';
  items[1].style.fontWeight = 'bold';
  items[1].style.backgroundColor = 'yellow';

  // Gives error
  //items.style.backgroundColor = '#f4f4f4';

  for(let i = 0; i < items.length; i++){
    items[i].style.backgroundColor = '#f4f4f4';
  }

----

GET ELEMENTS BY TAG NAME
================================
.. code:: javascript

  let li = document.getElementsByTagName('li');
  console.log(li);
  console.log(li[1]);
  li[1].textContent = 'Hello 2';
  li[1].style.fontWeight = 'bold';
  li[1].style.backgroundColor = 'yellow';

  // Gives error
  //items.style.backgroundColor = '#f4f4f4';

  for(let i = 0; i < li.length; i++){
    li[i].style.backgroundColor = '#f4f4f4';
  }

----

:class: t2c

InnerText vs innerContent
=============================
.. include:: src/javascript/2672.html
    :code: html
    :number-lines:

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/javascript/2672.html" title="description" class="output-of-html">
   </iframe>

----

QUERY SELECTOR
=======================
.. code:: javascript

  let header = document.querySelector('#main-header');
  header.style.borderBottom = 'solid 4px #ccc';
  let input = document.querySelector('input');
  input.value = 'Hello World'
  let submit = document.querySelector('input[type="submit"]');
  submit.value="SEND"
  let item = document.querySelector('.list-group-item');
  item.style.color = 'red';
  let lastItem = document.querySelector('.list-group-item:last-child');
  lastItem.style.color = 'blue';
  let secondItem = document.querySelector('.list-group-item:nth-child(2)');
  secondItem.style.color = 'coral';

----

QUERY SELECTOR ALL
===========================
.. code:: javascript

  var titles = document.querySelectorAll('.title');
  console.log(titles);
  titles[0].textContent = 'Hello';
  var odd = document.querySelectorAll('li:nth-child(odd)');
  var even= document.querySelectorAll('li:nth-child(even)');
  for(var i = 0; i < odd.length; i++){
    odd[i].style.backgroundColor = '#f4f4f4';
    even[i].style.backgroundColor = '#ccc';
  }

----

TRAVERSING DOM
======================
.. code:: javascript
  :number-lines: 

  let itemList = document.querySelector('#items');
  console.log(itemList.parentNode);
  itemList.parentNode.style.backgroundColor = '#f4f4f4';
  console.log(itemList.parentNode.parentNode.parentNode);

  // parentElement
  console.log(itemList.parentElement);
  itemList.parentElement.style.backgroundColor = '#f4f4f4';
  console.log(itemList.parentElement.parentElement.parentElement);

  //childNodes
  console.log(itemList.childNodes);

  console.log(itemList.children);
  console.log(itemList.children[1]);
  itemList.children[1].style.backgroundColor = 'yellow';

----

.. code:: javascript

  // FirstChild
  console.log(itemList.firstChild);
  // firstElementChild
  console.log(itemList.firstElementChild);
  itemList.firstElementChild.textContent = 'Hello 1';
  // lastChild
  console.log(itemList.lastChild);
  // lastElementChild
  console.log(itemList.lastElementChild);
  itemList.lastElementChild.textContent = 'Hello 4';
  // nextSibling
  console.log(itemList.nextSibling);
  // nextElementSibling
  console.log(itemList.nextElementSibling);
  // previousSibling
  console.log(itemList.previousSibling);
  // previousElementSibling
  console.log(itemList.previousElementSibling);itemList.previousElementSibling.style.color = 'green';

----

Create Element
========================
.. code:: javascript

  // Create a div
  var newDiv =  document.createElement('div');
  // Add class
  newDiv.className= 'hello';
  // Add id
  newDiv.id = 'hello1';
  // Add attr
  newDiv.setAttribute('title', 'Hello Div');
  // Create text node
  var newDivText = document.createTextNode('Hello World');
  // Add text to div
  newDiv.appendChild(newDivText);
  var container = document.querySelector('header .container');
  var h1 = document.querySelector('header h1');
  console.log(newDiv);
  newDiv.style.fontSize = '30px';
  container.insertBefore(newDiv, h1);

----

:class: t2c

Click
=================================
.. include:: src/javascript/event1.html
    :code: html
    :number-lines:

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/javascript/event1.html" title="description" class="output-of-html">
   </iframe>


----

:class: t2c

this
=================================
.. include:: src/javascript/event2.html
    :code: html
    :number-lines:

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/javascript/event2.html" title="description" class="output-of-html">
   </iframe>

----

:class: t2c

function
=================================
.. include:: src/javascript/event3.html
    :code: html
    :number-lines:

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/javascript/event3.html" title="description" class="output-of-html">
   </iframe>

----

EVENTS
==============
.. code:: javascript

  var button = document.getElementById('button').
    addEventListener('click', buttonClick);
  function buttonClick(e){
    console.log('Button clicked');
    document.getElementById('header-title').textContent = 'Changed';
    document.querySelector('#main').style.backgroundColor = '#f4f4f4';
    console.log(e);
    console.log(e.target);
    console.log(e.target.id);
    console.log(e.target.className);
    console.log(e.target.classList);
    var output = document.getElementById('output');
    output.innerHTML = '<h3>'+e.target.id+'</h3>';
    console.log(e.type);
    console.log(e.clientX);
    console.log(e.clientY);
    console.log(e.offsetX);
    console.log(e.offsetY);
    console.log(e.altKey);
    console.log(e.ctrlKey);
    console.log(e.shiftKey);
  }

----

.. code:: javascript

  var button = document.getElementById('button');
  var box = document.getElementById('box');

  button.addEventListener('click', runEvent);
  button.addEventListener('dblclick', runEvent);
  button.addEventListener('mousedown', runEvent);
  button.addEventListener('mouseup', runEvent);
  box.addEventListener('mouseenter', runEvent);
  box.addEventListener('mouseleave', runEvent);
  box.addEventListener('mouseover', runEvent);
  box.addEventListener('mouseout', runEvent);
  box.addEventListener('mousemove', runEvent);

----

.. code:: javascript

  var itemInput = document.querySelector('input[type="text"]');
  var form = document.querySelector('form');
  var select = document.querySelector('select');
  itemInput.addEventListener('keydown', runEvent);
  itemInput.addEventListener('keyup', runEvent);
  itemInput.addEventListener('keypress', runEvent);
  itemInput.addEventListener('focus', runEvent);
  itemInput.addEventListener('blur', runEvent);
  itemInput.addEventListener('cut', runEvent);
  itemInput.addEventListener('paste', runEvent);
  itemInput.addEventListener('input', runEvent);
  select.addEventListener('change', runEvent);
  select.addEventListener('input', runEvent);

----

.. code:: javascript

  form.addEventListener('submit', runEvent);
  function runEvent(e){
    e.preventDefault();
    console.log('EVENT TYPE: '+e.type);
    console.log(e.target.value);
    document.getElementById('output').innerHTML = 
      '<h3>'+e.target.value+'</h3>';

    output.innerHTML = '<h3>MouseX: '+e.offsetX+
      ' </h3><h3>MouseY: '+e.offsetY+'</h3>';
    document.body.style.backgroundColor = 
      "rgb("+e.offsetX+","+e.offsetY+", 40)";
  }

----

:class: t2c

.. include:: src/javascript/event_click.html
    :code: html
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 21
  
.. include:: src/javascript/event_click.html
    :code: html
    :number-lines: 22
    :class: ltr
    :start-line: 22
    :end-line: 45

----

:class: t2c

.. include:: src/javascript/event_click.html
    :code: html
    :number-lines: 2
    :class: ltr
    :start-line: 1
    :end-line: 25

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/javascript/event_click.html" title="description" class="output-of-html">
   </iframe>

----

:class: t2c

.. include:: src/javascript/event_onsubmit.html
    :code: html
    :number-lines:
    :class: ltr
    :start-line: 0
    :end-line: 22
  
.. include:: src/javascript/event_onsubmit.html
    :code: html
    :number-lines: 23
    :class: ltr
    :start-line: 22
    :end-line: 45

----

:class: t2c

.. include:: src/javascript/event_onsubmit.html
    :code: html
    :number-lines: 2
    :class: ltr
    :start-line: 1
    :end-line: 25

.. raw:: html

   <iframe src="http://127.0.0.1:8002/src/javascript/event_onsubmit.html" title="description" class="output-of-html">
   </iframe>

----

Jalali Date
==================
* http://amib.ir/weblog/%d9%85%d9%86%d8%a7%d8%a8%d8%b9-%d8%a8%d8%b1%d9%86%d8%a7%d9%85%d9%87%e2%80%8c%d9%86%d9%88%db%8c%d8%b3%db%8c/%d8%aa%d9%82%d9%88%db%8c%d9%85-%d9%81%d8%a7%d8%b1%d8%b3%db%8c-%d8%ac%d8%a7%d9%88%d8%a7%d8%a7%d8%b3%da%a9%d8%b1%db%8c%d9%be%d8%aa/

----

LibreJS
===========
https://www.gnu.org/software/librejs/

GNU LibreJS aims to address the JavaScript problem described in Richard Stallman's article The JavaScript Trap. LibreJS is a free add-on for GNU IceCat and other Mozilla-based browsers. It blocks nonfree nontrivial JavaScript while allowing JavaScript that is free and/or trivial.

----

END
