function sendAction()
{
    var actionSelect = document.getElementById("action");
    var action = actionSelect.options[actionSelect.selectedIndex].value;

    var http = new XMLHttpRequest();
    var url = '/timer';
    var params = 'action='+action;
    http.open('POST', url);
    http.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');

    http.onload = function () {
        var span = document.getElementById("result");
        span.innerHTML = this.responseText;
    };

    http.send(params);
}
window.onload = function() {
    var button = document.getElementById("button");
    button.onclick = sendAction;
}