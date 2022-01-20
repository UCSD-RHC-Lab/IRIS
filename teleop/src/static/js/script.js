/***************************************
 * Filename: script.js
 * Students: Aayush Naik, Rebecca Kreitinger, Daniel Koohmarey
 * HRI Final Project
 * 
 * Description: Add dynamic callbacks to send messages when a control direction is
 * pressed or released.
 * How to use: see README.md
 *******************************************/

var pendingResponses = 0;
var activeElement = null;

function postAction(action)
{
    var http = new XMLHttpRequest();
    var url = '/action';
    var params = 'action='+action;
    http.open('POST', url, false); // send synch to prevent out of order

    //Send the proper header information along with the request
    http.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');

    http.send(params);
}

function mouseDown(e){
  var target = (e.target) ? e.target : e.srcElement;
  // handle callback for curve instead of arrow
  if(target.classList.contains('curve')){
    // arrow is parent span
    target = target.parentElement;
  }
  target.classList.add("active");
  activeElement = target;
  postAction(target.id);
  e.preventDefault();
  //console.log('down on: ' + target.id);
};

function mouseUp(e){
  var target = (e.target) ? e.target : e.srcElement;
  // handle callback for curve instead of arrow
  if(target.classList.contains('curve')){
    // arrow is parent span
    target = target.parentElement;
  }
  target.classList.remove("active");
  postAction('stop-'+target.id);
  e.preventDefault();
  //console.log('up on: ' + window.activeElement.id);
};

window.onload = function() {
    // wait for page to load to register callbacks
    var arrows = document.getElementsByClassName("arrow");
    for (arrow of arrows) {
      arrow.addEventListener("mousedown", mouseDown);
      arrow.addEventListener("touchstart", mouseDown);
	  arrow.addEventListener("mouseup", mouseUp);
	  arrow.addEventListener("touchend", mouseUp);
    };
    var curves = document.getElementsByClassName("curve");
    for (curve of curves) {
      curve.addEventListener("mousedown", mouseDown);
      curve.addEventListener("touchstart", mouseDown);
	  curve.addEventListener("mouseup", mouseUp);
	  curve.addEventListener("touchend", mouseUp);
    }
    
	var stop = document.getElementById("stop");
	stop.addEventListener("mousedown", mouseDown);
	stop.addEventListener("touchstart", mouseDown);
	stop.addEventListener("mouseup", mouseUp);
	stop.addEventListener("touchend", mouseUp);	
}
