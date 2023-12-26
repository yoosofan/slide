function onBodyLoad(){
  let myLinks = document.querySelectorAll('ul a');
  for(let i = 0; i <= myLinks.length - 1; i++) {
    myLinks[i].onclick = function(e) {
      e.preventDefault();  var linkData = e.target.getAttribute('data-page');
      getData(linkData);
    };
  }
}
function getData(pageId) {
  console.log(pageId);  var myRequest = new Request(pageId + '.txt');
  var myArticle = document.querySelector('article');
  fetch(myRequest)
  .then(function(response) {
    if (!response.ok)
    {throw new Error("HTTP error, status = " + response.status);}
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

