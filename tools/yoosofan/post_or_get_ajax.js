
/* The ajax tool
     Ahmad Yoosofan
     Date :: jalaji(shamsi) :1388/03/11  milady(georgian):2009/06/1
     This tool is prepared for ajax. The code is combined from several site:
     ----------------------
http://www.openjs.com/articles/ajax_xmlhttp_using_post.php
---------------------
  http://www.captain.at/howto-ajax-form-post-request.php
  ------------------------------
  */

   var pleaseWait='لطفا کمی صبر کنید....' ;

function binaryLength_UTF8(str){
   var bytes, charCode, a, len;
   bytes = 0;
   for (a = 0, len = str.length; a < len; a++)  {
      charCode = str.charCodeAt(a);
      if (charCode < 128)     bytes += 1; //2^7
      else if (charCode < 2048)  bytes += 2; // 2^11
      else if (charCode < 65536)    bytes += 3; // 2^16
      else        bytes += 4;
   }
   return bytes;
}
var http_handle = false;
function create_http_handle(TYPE){
   http_handle = false;
   if (window.XMLHttpRequest){
      http_handle = new XMLHttpRequest();
      if (http_handle.overrideMimeType){
         if (TYPE == "XML"){
            http_handle.overrideMimeType('text/xml');
         } else {
            http_handle.overrideMimeType('text/html');
         }
      }
   } else if (window.ActiveXObject){
      try {
         http_handle = new ActiveXObject("Msxml2.XMLHTTP");
      } catch (e) {
         try {
            http_handle = new ActiveXObject("Microsoft.XMLHTTP");
         } catch (e) {}
      }
   }
   if (!http_handle){
      alert("We are sorry but you are using an outdated browser.  To view this site you must update your browser.");
      http_handle =false;
   } /*else {
      return http_handle;
   }*/
}
/*
function alertContents() {
      if (http_handle.readyState == 4) {
         if (http_handle.status == 200) {
            result = http_handle.responseText;
            document.getElementById('myspan').innerHTML = result;
         }else if (http_handle.status == 404)
            alert("Request URL does not exist");
         else {
            alert('There was a problem with the request.');
         }
      }
}
*/
function sendHTTPrequest(URL, PARAMETERS, ONCHANGE,METHOD, TYPE , section_change){ //
   if (TYPE == "") TYPE = "HTML";
   create_http_handle(TYPE);
   http_handle.onreadystatechange = function() {
      if (http_handle.readyState == 4) {
         if (http_handle.status == 200) {
            var result = http_handle.responseText;
            eval(ONCHANGE + '(result,section_change);');
         }else if (http_handle.status == 404)
            alert("Request URL does not exist");
         else {
            alert('There was a problem with the request.');
         }
      }
   }

   //Kill the Cache problem in IE.
   var now = "upid=" + new Date().getTime();
   if (METHOD == "POST")
      PARAMETERS += (PARAMETERS.indexOf("=")+1) ? "&" : "?";
   else
      PARAMETERS += (PARAMETERS.indexOf("?")+1) ? "&" : "?";
   PARAMETERS += now;
   if (METHOD == "POST"){

      http_handle.open('POST', URL , true);
      http_handle.setRequestHeader("Content-type", "application/x-www-form-URLencoded");
      http_handle.setRequestHeader("Content-length", binaryLength_UTF8(PARAMETERS)); //http_handle.setRequestHeader("Content-length", PARAMETERS.length);
      http_handle.setRequestHeader("Connection", "close");
      http_handle.send(PARAMETERS);
   } else {
      //alert(URL + PARAMETERS);
      http_handle.open('GET', URL + PARAMETERS, true);
      http_handle.send(null);
   }
}
//https://developer.mozilla.org/en/docs/AJAX
//http://www.ajaxf1.com/tutorial.html
/// The forgoing function run only on firefox and opera
 function simpleUploadFile(page_name , myOnChange, section_change){
   var  TYPE = "HTML";
   var copy_page_name= page_name;
   create_http_handle(TYPE);
    //if(navigator.appName == 'Opera'){
      var ind = location.href.lastIndexOf('/')
      if(ind >=0)
         page_name = location.href.substr(0,ind+1)+ page_name ;
      else
         alert('Can not open file')
      http_handle.open("GET", page_name, true);
      http_handle.send(); //null
      var ii=0;      for(ii=0; ii <10000 && http_handle.readyState != 4 ; ii++)          ;
      if(http_handle.readyState == 4)
         eval(myOnChange+"(section_change,http_handle.responseText);");
      else alert('File not found :: '+ page_name);
   return false;
}
