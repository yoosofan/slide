var yoosofan_changed_script= new Array()
function onChange(locationOfChange,param1){
  var scripts1 = document.getElementsByTagName("script");
  for(var i=0;i<scripts1.length;i++){
    if(scripts1[i].getAttribute("type") == "syntaxhighlighter"){
      var m1=scripts1[i].innerHTML.trim();
      m1=m1.substring(m1.indexOf('/*')+2).trim();
      m1=m1.substring(0, m1.indexOf('*/')).trim();
      if(m1==locationOfChange){
        yoosofan_changed_script.push(i)
        scripts1[i].innerHTML=param1;
      }
    }
  }
}
window.onload = function(){
  var myIds2Examples = new Array();
  var scripts1 = document.getElementsByTagName("script");
  for(var i=0;i<scripts1.length;i++){
    if(scripts1[i].getAttribute("type") == "syntaxhighlighter"){
      if(yoosofan_changed_script.indexOf(i)<0){
        var m1=scripts1[i].innerHTML.trim();
        m1=m1.substring(m1.indexOf('/*')+2).trim();
        m1=m1.substring(0, m1.indexOf('*/')).trim();
        if(myIds2Examples.indexOf(m1)<0){
          myIds2Examples.push(m1)
          simpleUploadFile(m1,"onChange", m1);
        }
      }
    }
  }
}

//document.addEventListener( "DOMContentLoaded", SyntaxHighlighter.all, false )
