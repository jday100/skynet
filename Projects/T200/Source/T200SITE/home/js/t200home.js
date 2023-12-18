function forward(action) {
    $.id('main').innerHTML = `<div><div class="form_redirect"><a href="${action}">Redirect</a></div></div>`;
    $.win.location = action;
}