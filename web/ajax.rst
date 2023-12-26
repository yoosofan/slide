:data-transition-duration: 1000
:skip-help: true
:css: hovercraft_style.css
:substep: true

.. title: Ajax & JSON (By Ahmad Yoosofan)

:slide-numbers: true

.. role:: ltr
    :class: ltr

.. role:: rtl
    :class: rtl


Ajax & JSON
===================================================
Single Page Application (SPA)
--------------------------------
Ahmad Yoosofan

University of Kashan

Spring 2020

----

Old Ajax Text
==============

.. code:: javascript
    :number-lines:

    var xmlhttp = new XMLHttpRequest();
    xmlhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("demo").innerHTML = this.responseText
      }
    };
    xmlhttp.open("GET", "text_demo.txt", true);
    xmlhttp.send(); 

.. :

  https://www.w3schools.com/js/js_ajax_http_response.asp
  https://www.w3schools.com/xml/ajax_xmlhttprequest_send.asp
  https://www.w3schools.com/xml/ajax_xmlhttprequest_create.asp
  https://www.w3schools.com/xml/xml_http.asp
  https://www.w3schools.com/xml/dom_httprequest.asp
  http://www-db.deis.unibo.it/courses/TW/DOCS/w3schools/ajax/ajax_xmlhttprequest_response.asp.html
  https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/Using_XMLHttpRequest
  https://www.sitepoint.com/xmlhttprequest-vs-the-fetch-api-whats-best-for-ajax-in-2019/

----

Fetch (I)
===============
.. code:: javascript 
    :number-lines:

    fetch('http://yoosofan.github.io/index.html');
  

.. code:: javascript 

    fetch('http://yoosofan.github.io/index.html')
      .then(response => {/* do something */})
  
----


.. code:: javascript 
    :number-lines:

    fetch('http://yoosofan.github.io/index.html')
      .then(response => {console.log(response);})

.. code:: javascript
    :number-lines:

    {
      body: ReadableStream
      bodyUsed: false
      headers: Headers
      ok : true
      redirected : false
      status : 200
      statusText : "OK"
      type : "cors"
      url : "http://some-website.com/some-url"
      __proto__ : Response
    }


----

.. code:: javascript 
    :number-lines:

    fetch('http://yoosofan.github.io/t1.json')
      .then(response => response.json())
      .then(data => {
        console.log(data)
      });


.. code:: javascript
    :number-lines:

    fetch('some-url', options);

----

.. code:: javascript
    :number-lines:

    let content = {some: 'content'};

    // The actual fetch request
    fetch('some-url', {
      method: 'post',
      headers: {
        'Content-Type': 'application/json'
      },
      body: JSON.stringify(content)
    })

.. :

    https://css-tricks.com/using-fetch/

----

.. code:: javascript
    :number-lines:

    fetch('https://jsonplaceholder.typicode.com/todos')
      .then(response => response.json())
      .then(data => console.log(JSON.stringify(data)))

.. :

    https://www.freecodecamp.org/news/a-practical-es6-guide-on-how-to-perform-http-requests-using-the-fetch-api-594c3d91a547/
  
----

.. code:: javascript
    :number-lines:

    fetch('https://jsonplaceholder.typicode.com/users', {
      headers: { "Content-Type": "application/json; charset=utf-8" },
      method: 'POST',
      body: JSON.stringify({
        username: 'Ahmad Yoosofan',
        email: 'yoosofan@myfastmail.com',
      })
    })

.. :

    https://www.freecodecamp.org/news/a-practical-es6-guide-on-how-to-perform-http-requests-using-the-fetch-api-594c3d91a547/

----

.. code:: javascript
    :number-lines:

    fetch('https://jsonplaceholder.typicode.com/users/1', { 
      method: 'DELETE' 
    }); 

.. :

    https://www.freecodecamp.org/news/a-practical-es6-guide-on-how-to-perform-http-requests-using-the-fetch-api-594c3d91a547/

----

.. code:: javascript
    :number-lines:

    // Update user with id 3
    fetch('https://jsonplaceholder.typicode.com/users/3', {
      headers: { "Content-Type": "application/json; charset=utf-8" },
      method: 'PUT',
      body: JSON.stringify({
        username: 'Ahmad Yoosofan',
        email: 'yoosofan@fastmail.fm',
      })
    })
  
.. :

    https://www.freecodecamp.org/news/a-practical-es6-guide-on-how-to-perform-http-requests-using-the-fetch-api-594c3d91a547/


----

.. code:: javascript
    :number-lines:

    fetch('https://api.github.com/users/chrissycoyier/repos')
      .then(response => response.json())
      .then(data => console.log('data is', data))
      .catch(error => console.log('error is', error));

.. :

    https://css-tricks.com/using-fetch/

----

.. code:: javascript
    :number-lines:

    fetch(
        'http://domain/service',
        { method: 'GET' }
      )
      .then( response => response.json() )
      .then( json => console.log(json) )
      .catch( error => console.error('error:', error) );
  
.. :

    https://www.sitepoint.com/xmlhttprequest-vs-the-fetch-api-whats-best-for-ajax-in-2019/
    

----

.. code:: javascript
    :number-lines:

    fetch('some-url')
      .then(response => {
        if (response.ok) {
          return response.json()
        } else {
          // Find some way to get to execute .catch()
        }
      });
  
.. :

    https://css-tricks.com/using-fetch/

----

.. code:: javascript
    :number-lines:

    else {
      throw new Error('something went wrong!')
    }

    // rejecting a Promise
    else {
      return Promise.reject('something went wrong!')
    }

.. :

    https://css-tricks.com/using-fetch/

----

.. code:: javascript
    :number-lines:

    fetch('https://api.github.com/users/chrissycoyier/repos')
      .then(response => {
        if (response.ok) {
          return response.json()
        } else {
          return Promise.reject('something went wrong!')
        }
      })
      .then(data => console.log('data is', data))
      .catch(error => console.log('error is', error));

.. :

    https://css-tricks.com/using-fetch/

----

.. code:: javascript
    :number-lines:

    {
      body: ReadableStream
      bodyUsed: true
      headers: Headers
      ok: false // Response is not ok
      redirected: false
      status: 404 // HTTP status is 404.
      statusText: "Not Found" // Request not found
      type: "cors"
      url: "https://api.github.com/users/chrissycoyier/repos"
    }

.. :

    https://css-tricks.com/using-fetch/

----

.. code:: javascript
    :number-lines:

    fetch('some-url')
      .then(response => {
        if (response.ok) {
          return response.json()
        } else {
          return Promise.reject({
            status: response.status,
            statusText: response.statusText
          })
        }
      })
      .catch(error => {
        if (error.status === 404) {
          // do something about 404
        }
      })
  

.. :

    https://css-tricks.com/using-fetch/

----

.. code:: javascript
    :number-lines:

    res.status(400).send({
      err: 'no first name'
    })


.. :

    https://css-tricks.com/using-fetch/

----

.. code:: javascript
    :number-lines:

    fetch('some-error')
      .then(handleResponse)

    function handleResponse(response) {
      return response.json()
        .then(json => {
          if (response.ok) {
            return json
          } else {
            return Promise.reject(json)
          }
        })
    }

.. :

    https://css-tricks.com/using-fetch/

----

.. code:: javascript
    :number-lines:

    let error = Object.assign({}, json, {
      status: response.status,
      statusText: response.statusText
    })
    return Promise.reject(error)

.. :

    https://css-tricks.com/using-fetch/

----

.. code:: javascript
    :number-lines:

    fetch('some-url')
      .then(handleResponse)
      .then(data => console.log(data))
      .catch(error => console.log(error))
  

.. :

    https://css-tricks.com/using-fetch/

----

.. code:: javascript
    :number-lines:

    .then(response => {
      let contentType = response.headers.get('content-type')

      if (contentType.includes('application/json')) {
        return response.json()
        // ...
      }

      else if (contentType.includes('text/html')) {
        return response.text()
        // ...
      }

      else {
        // Handle other responses accordingly...
      }
    });


.. :

    https://css-tricks.com/using-fetch/

----

.. code:: javascript
    :number-lines:

    fetch('some-url')
      .then(handleResponse)
      .then(data => console.log(data))
      .catch(error => console.log(error))

    function handleResponse (response) {
      let contentType = response.headers.get('content-type')
      if (contentType.includes('application/json')) {
        return handleJSONResponse(response)
      } else if (contentType.includes('text/html')) {
        return handleTextResponse(response)
      } else {
        // Other response types as necessary. I haven't found a need for them yet though.
        throw new Error(`Sorry, content-type ${contentType} not supported`)
      }
    }


.. :

    https://css-tricks.com/using-fetch/

----

.. code:: javascript
    :number-lines:

    function handleJSONResponse (response) {
      return response.json()
        .then(json => {
          if (response.ok) {
            return json
          } else {
            return Promise.reject(Object.assign({}, json, {
              status: response.status,
              statusText: response.statusText
            }))
          }
        })
    }

.. :

    https://css-tricks.com/using-fetch/

----

.. code:: javascript
    :number-lines:

    function handleTextResponse (response) {
      return response.text()
        .then(text => {
          if (response.ok) {
            return text
          } else {
            return Promise.reject({
              status: response.status,
              statusText: response.statusText,
              err: text
            })
          }
        })
    }

.. :

    https://css-tricks.com/using-fetch/

----

.. code:: javascript
    :number-lines:

    fetch('https://api.github.com/orgs/nodejs', {
      headers: new Headers({
        'User-agent': 'Mozilla/4.0 Custom User Agent'
      })
    })
    .then(response => response.json())
    .then(data => {
      console.log(data)
    })
    .catch(error => console.error(error)

.. : 

    https://gist.github.com/justsml/529d0b1ddc5249095ff4b890aad5e801

----

.. code:: javascript
    :number-lines:

    fetch('https://api.github.com/orgs/nodejs', {
      credentials: 'include', // Useful for including session ID (and, IIRC, authorization headers)
    })
    .then(response => response.json())
    .then(data => {
      console.log(data) // Prints result from `response.json()`
    })
    .catch(error => console.error(error))

.. : 

    https://gist.github.com/justsml/529d0b1ddc5249095ff4b890aad5e801

----

.. code:: javascript
    :number-lines:

    postRequest('http://example.com/api/v1/users', {user: 'Dan'})
      .then(data => console.log(data)) // Result from the `response.json()` call
      .catch(error => console.error(error))

    function postRequest(url, data) {
      return fetch(url, {
        credentials: 'same-origin', // 'include', default: 'omit'
        method: 'POST', // 'GET', 'PUT', 'DELETE', etc.
        body: JSON.stringify(data), // Coordinate the body type with 'Content-Type'
        headers: new Headers({
          'Content-Type': 'application/json'
        }),
      })
      .then(response => response.json())
  
.. : 

    https://gist.github.com/justsml/529d0b1ddc5249095ff4b890aad5e801

----

.. code:: javascript
    :number-lines:

    postForm('http://example.com/api/v1/users')
      .then(data => console.log(data))
      .catch(error => console.error(error))

    function postForm(url) {
      const formData = new FormData(document.querySelector('form.edit-user'))

      return fetch(url, {
        method: 'POST', // or 'PUT'
        body: formData  // a FormData will automatically set the 'Content-Type'
      })
      .then(response => response.json())
  
.. : 

    https://gist.github.com/justsml/529d0b1ddc5249095ff4b890aad5e801

----

.. code:: javascript
    :number-lines:

    postFormData('http://example.com/api/v1/users', {user: 'Mary'})
      .then(data => console.log(data))
      .catch(error => console.error(error))

    function postFormData(url, data) {
      return fetch(url, {
        method: 'POST', // 'GET', 'PUT', 'DELETE', etc.
        body: new URLSearchParams(data),
        headers: new Headers({
          'Content-type': 'application/x-www-form-urlencoded; charset=UTF-8'
        })
      })
      .then(response => response.json())
  
.. : 

    https://gist.github.com/justsml/529d0b1ddc5249095ff4b890aad5e801

----

.. code:: html

  <input type='file' multiple class='files' name='files' />

.. code:: javascript
    :number-lines:

    postFile('http://example.com/api/v1/users', 'input[type="file"].avatar')
      .then(data => console.log(data))
      .catch(error => console.error(error))

    function postFile(url, fileSelector) {
      const formData = new FormData()
      const fileField = document.querySelector(fileSelector)
      
      formData.append('username', 'abc123')
      formData.append('avatar', fileField.files[0])

      return fetch(url, {
        method: 'POST', // 'GET', 'PUT', 'DELETE', etc.
        body: formData  // Coordinate the body type with 'Content-Type'
      })
      .then(response => response.json())
    }

.. : 

    https://gist.github.com/justsml/529d0b1ddc5249095ff4b890aad5e801

----

.. code:: javascript
    :number-lines:

    postFile('http://example.com/api/v1/users', 'input[type="file"].files')
      .then(data => console.log(data))
      .catch(error => console.error(error))

    function postFile(url, fileSelector) {
      const formData = new FormData()
      const fileFields = document.querySelectorAll(fileSelector)

      // Add all files to formData
      Array.prototype.forEach.call(fileFields.files, f => formData.append('files', f))
      // Alternatively for PHP peeps, use `files[]` for the name to support arrays
      // Array.prototype.forEach.call(fileFields.files, f => formData.append('files[]', f))
      
      return fetch(url, {
        method: 'POST', // 'GET', 'PUT', 'DELETE', etc.
        body: formData  // Coordinate the body type with 'Content-Type'
      })
      .then(response => response.json())
    }


.. : 

    https://gist.github.com/justsml/529d0b1ddc5249095ff4b890aad5e801

----

.. code:: html
    :number-lines:

    <!DOCTYPE html>
    <html>
      <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width">
        <script type="text/javascript" src="a1.js" />
        <title>Fetch text example</title>

        <link rel="stylesheet" href="style.css">
      </head>

      <body>
        <h1>Fetch text example</h1>
        <ul>
          <li><a data-page="page1">Page 1</a></li>
          <li><a data-page="page2">Page 2</a></li>
          <li><a data-page="page3">Page 3</a></li>
        </ul>
        <article>
        </article>

      </body>
    </html>
  

.. : 

    https://github.com/mdn/fetch-examples/blob/master/fetch-text/index.html

----

.. code:: javascript
    :number-lines:

      var myArticle = document.querySelector('article');
      var myLinks = document.querySelectorAll('ul a');
      for(var i = 0; i <= myLinks.length - 1; i++) {
        myLinks[i].onclick = function(e) {
          e.preventDefault();  var linkData = e.target.getAttribute('data-page');
          getData(linkData);
        }
      };
      function getData(pageId) {
        console.log(pageId);  var myRequest = new Request(pageId + '.txt');

        fetch(myRequest)
        .then(function(response) {
          if (!response.ok) {throw new Error("HTTP error, status = " + response.status);}
          return response.text();
        })   .then(function(text) {
          myArticle.innerHTML = text;
        }) .catch(function(error) {
          myArticle.innerHTML = '';
          myArticle.appendChild(
            document.createTextNode('Error: ' + error.message)
          );
        });
      }

.. : 

    https://github.com/mdn/fetch-examples/blob/master/fetch-text/index.html

----

JSON(I)
============
History
------------
JSON grew out of a need for stateless, real-time server-to-browser communication protocol without using browser plugins such as Flash or Java applets, the dominant methods used in the early 2000s.

----

JSON Values
=================
.. class:: substep

    *   a string
    *   a number
    *   an object (JSON object)
    *   an array
    *   a boolean
    *   null

----

Sample
========
.. code:: javascript
    :number-lines:

    {
      "array": [
        1,
        2,
        3
      ],
      "boolean": true,
      "color": "#82b92c",
      "null": null,
      "number": 123,
      "object": {
        "a": "b",
        "c": "d",
        "e": "f"
      },
      "string": "Hello World"
    }

----

convert javascript to json
====================================

.. code:: javascript
    :number-lines:

    var myObj = {name: "John", age: 31, city: "New York"};
    var myJSON = JSON.stringify(myObj);
    window.location = "demo_json.php?x=" + myJSON;

----

convert json to javascript
============================

.. code:: javascript
    :number-lines:

    var myJSON = '{"name":"John", "age":31, "city":"New York"}';
    var myObj = JSON.parse(myJSON);
    document.getElementById("demo").innerHTML = myObj.name; 

----

storing json
=============

.. code:: javascript
    :number-lines:

    // Storing data:
    myObj = {name: "John", age: 31, city: "New York"};
    myJSON = JSON.stringify(myObj);
    localStorage.setItem("testJSON", myJSON);

    // Retrieving data:
    text = localStorage.getItem("testJSON");
    obj = JSON.parse(text);
    document.getElementById("demo").innerHTML = obj.name; 


----

Json vs XML
=============
.. code:: javascript
    :number-lines:

    {"employees":[
      { "firstName":"John", "lastName":"Doe" },
      { "firstName":"Anna", "lastName":"Smith" },
      { "firstName":"Peter", "lastName":"Jones" }
    ]}


.. code:: xml
    :number-lines:

    <employees>
      <employee>
        <firstName>John</firstName> <lastName>Doe</lastName>
      </employee>
      <employee>
        <firstName>Anna</firstName> <lastName>Smith</lastName>
      </employee>
      <employee>
        <firstName>Peter</firstName> <lastName>Jones</lastName>
      </employee>
    </employees>

----

Ajax json
===========
.. code:: javascript
    :number-lines:

    var xmlhttp = new XMLHttpRequest();
    xmlhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        var myObj = JSON.parse(this.responseText);
        document.getElementById("demo").innerHTML = myObj.name;
      }
    };
    xmlhttp.open("GET", "json_demo.txt", true);
    xmlhttp.send(); 

----

JSON for table
=================

.. code:: javascript
    :number-lines:

    obj = { table: "customers", limit: 20 };
    dbParam = JSON.stringify(obj);
    xmlhttp = new XMLHttpRequest();
    xmlhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        myObj = JSON.parse(this.responseText);
        txt += "<table border='1'>"
        for (x in myObj) {
          txt += "<tr><td>" + myObj[x].name + "</td></tr>";
        }
        txt += "</table>"
        document.getElementById("demo").innerHTML = txt;
      }
    }
    xmlhttp.open("POST", "json_demo_db_post.php", true);
    xmlhttp.setRequestHeader("Content-type", 
        "application/x-www-form-urlencoded");
    xmlhttp.send("x=" + dbParam); 

----

sql
====
.. code:: sql
    :number-lines:

    select json_build_object( 'name ', name) 
    from customer  limit 20;

.. code:: python
    :number-lines:

    qs ="select json_build_object( 'name ', name) "
    qs+=" from " + table_name + "limit " 
    qs+= record_limit + ";"
    res= await self.db.q(qs,'a')
    self.write(tornado.escape.json_encode(res))

----

Ajax
===========
* Send and receive part of html
* Send and receive Json

cons
-----
* Search Enginges cannot index website 
* Search Engine Optimization(SEO)
    * surferseo.com

----

.. code:: javascript
    :number-lines:

    //Create the XHR Object
    const xhr = new XMLHttpRequest;
    //Call the open function, GET-type of request, url, true-asynchronous
    xhr.open('GET', 'https://api.github.com/users', true)
    //call the onload 
    xhr.onload = function() 
        {
            //check if the status is 200(means everything is okay)
            if (this.status === 200) 
                {
                    //return server response as an object with JSON.parse
                    console.log(JSON.parse(this.responseText));
        }
                }
    //call send
    xhr.send();
    //Common Types of HTTP Statuses
    // 200: OK
    // 404: ERROR
    // 403: FORBIDDEN

----

.. code:: javascript
    :number-lines:

    fetch('https://api.github.com/users')
    .then(res => res.json())//response type
    .then(data => console.log(data)); //log the data;

----

.. code:: javascript
    :number-lines:

    async function getData(){
            //await the response of the fetch call
           let response = await fetch('https://api.github.com/users');
            //proceed once the first promise is resolved.
           let data = await response.json()
            //proceed only when the second promise is resolved
            return data;
        }
    getData()    //call getData function
    .then(data => console.log(data));//log the data

----

.. code:: javascript
    :number-lines:

    var foo = null;
    fetch('https://jsonplaceholder.typicode.com/posts/1')
       .then(resp => resp.json())
       .then(obj => foo = obj)

----

.. code:: javascript
    :number-lines:

    fetch('http://example.com/movies.json')
      .then((response) => {
        return response.json();
      })
      .then((myJson) => {
        console.log(myJson);
      });

----

.. code:: javascript
    :number-lines:

    async function postData(url = '', data = {}) { // Example POST method implementation:
      // Default options are marked with *
      const response = await fetch(url, {
        method: 'POST', // *GET, POST, PUT, DELETE, etc.
        mode: 'cors', // no-cors, *cors, same-origin
        cache: 'no-cache', // *default, no-cache, reload, force-cache, only-if-cached
        credentials: 'same-origin', // include, *same-origin, omit
        headers: {
          'Content-Type': 'application/json'
          // 'Content-Type': 'application/x-www-form-urlencoded',
        },
        redirect: 'follow', // manual, *follow, error
        referrerPolicy: 'no-referrer', // no-referrer, *client
        body: JSON.stringify(data) // body data type must match "Content-Type" header
      });
      return await response.json(); // parses JSON response into native JavaScript objects
    }

    postData('https://example.com/answer', { answer: 42 })
      .then((data) => {
        console.log(data); // JSON data parsed by `response.json()` call
      });

----

.. code:: javascript
    :number-lines:

        const data = { username: 'example' };

        fetch('https://example.com/profile', {
          method: 'POST', // or 'PUT'
          headers: {
            'Content-Type': 'application/json',
          },
          body: JSON.stringify(data),
        })
        .then((response) => response.json())
        .then((data) => {
          console.log('Success:', data);
        })
        .catch((error) => {
          console.error('Error:', error);
        });

----

.. code:: javascript
    :number-lines:

    const formData = new FormData();
    const fileField = document.querySelector('input[type="file"]');

    formData.append('username', 'abc123');
    formData.append('avatar', fileField.files[0]);

    fetch('https://example.com/profile/avatar', {
      method: 'PUT',
      body: formData
    })
    .then((response) => response.json())
    .then((result) => {
      console.log('Success:', result);
    })
    .catch((error) => {
      console.error('Error:', error);
    });

----

.. code:: javascript
    :number-lines:

    const formData = new FormData();
    const photos = document.querySelector('input[type="file"][multiple]');

    formData.append('title', 'My Vegas Vacation');
    for (let i = 0; i < photos.files.length; i++) {
      formData.append('photos', photos.files[i]);
    }

    fetch('https://example.com/posts', {
      method: 'POST',
      body: formData,
    })
    .then((response) => response.json())
    .then((result) => {
      console.log('Success:', result);
    })
    .catch((error) => {
      console.error('Error:', error);

----

.. code:: javascript
    :number-lines:

    async function* makeTextFileLineIterator(fileURL) {
      const utf8Decoder = new TextDecoder('utf-8');
      const response = await fetch(fileURL);
      const reader = response.body.getReader();
      let { value: chunk, done: readerDone } = await reader.read();
      chunk = chunk ? utf8Decoder.decode(chunk) : '';

      const re = /\n|\r|\r\n/gm;      let startIndex = 0;      let result;
      for (;;) {
        let result = re.exec(chunk);
        if (!result) {
          if (readerDone) { break;}
          let remainder = chunk.substr(startIndex);
          ({ value: chunk, done: readerDone } = await reader.read());
          chunk = remainder + (chunk ? utf8Decoder.decode(chunk) : '');
          startIndex = re.lastIndex = 0;
          continue;
        }
        yield chunk.substring(startIndex, result.index);
        startIndex = re.lastIndex;
      }
      if (startIndex < chunk.length) {  // last line didn't end in a newline char
        yield chunk.substr(startIndex);
      }
    }
    async function run() {
      for await (let line of makeTextFileLineIterator(urlOfFile)) {processLine(line);}
    }
    run();

----

.. code:: javascript
    :number-lines:

    fetch('flowers.jpg')
      .then((response) => {
        if (!response.ok) {
          throw new Error('Network response was not ok');
        }
        return response.blob();
      })
      .then((myBlob) => {
        myImage.src = URL.createObjectURL(myBlob);
      })
      .catch((error) => {
        console.error('There has been a problem with your fetch operation:', error);
      });

----
      
.. code:: javascript
    :number-lines:

    const myHeaders = new Headers();

    const myRequest = new Request('flowers.jpg', {
      method: 'GET',
      headers: myHeaders,
      mode: 'cors',
      cache: 'default',
    });

    fetch(myRequest)
      .then((response) => response.blob())
      .then((myBlob) => {
        myImage.src = URL.createObjectURL(myBlob);
      });

----

.. code:: javascript
    :number-lines:

    const content = 'Hello World';
    const myHeaders = new Headers();
    myHeaders.append('Content-Type', 'text/plain');
    myHeaders.append('Content-Length', content.length.toString());
    myHeaders.append('X-Custom-Header', 'ProcessThisImmediately');

----

.. code:: javascript
    :number-lines:

    const myHeaders = new Headers({
      'Content-Type': 'text/plain',
      'Content-Length': content.length.toString(),
      'X-Custom-Header': 'ProcessThisImmediately'
    });

----

.. code:: javascript
    :number-lines:

    console.log(myHeaders.has('Content-Type')); // true
    console.log(myHeaders.has('Set-Cookie')); // false
    myHeaders.set('Content-Type', 'text/html');
    myHeaders.append('X-Custom-Header', 'AnotherValue');

    console.log(myHeaders.get('Content-Length')); // 11
    console.log(myHeaders.get('X-Custom-Header')); // ['ProcessThisImmediately', 'AnotherValue']

    myHeaders.delete('X-Custom-Header');
    console.log(myHeaders.get('X-Custom-Header')); // [ ]

----

.. code:: javascript
    :number-lines:

    const myResponse = Response.error();
    try {
      myResponse.headers.set('Origin', 'http://mybank.com');
    } catch (e) {
      console.log('Cannot pretend to be a bank!');
    }

----

.. code:: javascript
    :number-lines:

    fetch(myRequest)
      .then((response) => {
         const contentType = response.headers.get('content-type');
         if (!contentType || !contentType.includes('application/json')) {
           throw new TypeError("Oops, we haven't got JSON!");
         }
         return response.json();
      })
      .then((data) => {
          /* process your data further */
      })
      .catch((error) => console.error(error));

----
  
.. code:: javascript
    :number-lines:

    const myBody = new Blob();

        addEventListener('fetch', function(event) {
          // ServiceWorker intercepting a fetch
          event.respondWith(
            new Response(myBody, {
              headers: { 'Content-Type': 'text/plain' }
            })
          );
        });

----

.. code:: javascript
    :number-lines:

    const form = new FormData(document.getElementById('login-form'));
    fetch('/login', {
      method: 'POST',
      body: form
    });

----

END

.. note:

    .. image:: img/memory_precess_addressing_parts.png
       :align: center
    https://www.w3schools.com/js/js_json_xml.asp
    https://developer.mozilla.org/en-US/docs/Web/API/Window/sessionStorage
    https://stackoverflow.com/questions/26337969/how-to-decode-an-email-attachment-received-as-a-base64-text
    https://en.wikipedia.org/wiki/Base64
    https://ietf.org/
    https://superuser.com/questions/213563/how-can-i-extract-an-attachment-from-the-email-body-encoded-as-base64
    https://en.wikipedia.org/wiki/JSON
    https://www.w3schools.com/js/js_json_intro.asp
    https://www.w3schools.com/js/js_ajax_intro.asp
    https://www.ecma-international.org/publications/standards/Ecma-262.htm
    https://en.wikipedia.org/wiki/JSON
    https://www.w3schools.com/js/js_json_intro.asp    
    https://bob.ippoli.to/archives/2005/12/05/remote-json-jsonp/
    https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/JSON
    https://jsoneditoronline.org/
    https://www.quora.com/How-do-I-send-a-person-details-and-several-images-via-JSON-in-Android
    https://dotnetcoretutorials.com/2018/07/21/uploading-images-in-a-pure-json-api/
    https://stackoverflow.com/questions/34485420/how-do-you-put-an-image-file-in-a-json-object
    

    json
    https://www.w3schools.com/php/php_json.asp
    
    xmlhttrequest third parameters
    https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/open
    https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/Synchronous_and_Asynchronous_Requests
    https://javascript.info/xmlhttprequest
    https://www.w3schools.com/xml/ajax_xmlhttprequest_send.asp
    https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest
    
    
    https://blog.logrocket.com/how-to-make-http-requests-like-a-pro-with-axios/
    http://zetcode.com/javascript/axios/
    
