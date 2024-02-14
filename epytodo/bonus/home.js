window.onfocus = load_todos();

function delete_one_todo(id) {
    var xhr = new XMLHttpRequest();
    const token = sessionStorage.getItem("token");

    xhr.open("DELETE", "http://127.0.0.1:3000/todos/" + id);
    xhr.setRequestHeader('Content-Type', 'application/json; charset=UTF-8=');
    xhr.setRequestHeader("Authorization", "Bearer " + token);
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4) {
            if (xhr.status == 200) {
                const res = JSON.parse(xhr.response);
            } else if (xhr.status == 403) {
                alert("Please reconnect");
                window.location.href = "login.html";
            } else {
                alert("An error occured");
            }
        }
    }
    xhr.send();
    var list = document.getElementById("ul_todos");
    list.innerHTML = '';
    load_todos();
}

function load_one_todo(name, description, due_time, status, id_todo) {
    due_time = new Date(due_time);
    due_time = "Due time: " + due_time.toLocaleString();
    // console.log(typeof(due_time));

    var list = document.getElementById("ul_todos");

    var div = document.createElement("div");
    var list_elem = document.createElement("li");
    var img_bin = document.createElement("img");
    var img_modif = document.createElement("img");

    var text1 = document.createTextNode(name);
    var text2 = document.createTextNode(description);
    var text3 = document.createTextNode(due_time);
    var text4 = document.createTextNode(status);
    var div_text_1 = document.createElement("div");
    var div_text_2 = document.createElement("div");
    var div_text_3 = document.createElement("div");
    var div_text_4 = document.createElement("div");

    div_text_1.className = "text_1";
    div_text_2.className = "text_2";
    div_text_3.className = "text_3";
    div_text_4.className = "text_4";
    img_bin.src = "assets/imgs/bin.png";
    img_bin.className = "bin_img";
    img_bin.addEventListener('click', function (ev) {
        delete_one_todo(id_todo);
    }, false);
    img_modif.src = "assets/imgs/pencil.png";
    img_modif.className = "modif_img";
    img_modif.addEventListener('click', function (ev) {
        sessionStorage.setItem("to_modify", id_todo);
        window.location.href = "modify.html";
    }, false);

    div_text_1.appendChild(text1);
    div_text_2.appendChild(text2);
    div_text_3.appendChild(text3);
    div_text_4.appendChild(text4);
    list_elem.appendChild(div_text_1);
    list_elem.appendChild(div_text_2);
    list_elem.appendChild(div_text_3);
    list_elem.appendChild(div_text_4);
    div.appendChild(list_elem);
    div.appendChild(img_bin);
    div.appendChild(img_modif);
    list.appendChild(div);
}

function load_todos() {
    sessionStorage.setItem("to_modify", "");
    var xhr = new XMLHttpRequest();
    const token = sessionStorage.getItem("token");

    xhr.open("GET", "http://127.0.0.1:3000/user/todos");
    xhr.setRequestHeader('Content-Type', 'application/json; charset=UTF-8=');
    xhr.setRequestHeader("Authorization", "Bearer " + token);
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4) {
            if (xhr.status == 200 || xhr.status == 201) {
                const res = JSON.parse(xhr.response);
                for (var i = 0; i < res.length; ++i) {
                    load_one_todo(res[i].title, res[i].description, res[i].due_time, res[i].status, res[i].id);
                }
            } else if (xhr.status == 403) {
                alert("Please reconnect");
                window.location.href = "login.html";
            } else {
                alert("An error occured");
            }
        }
    }
    xhr.send()
}















































var myNodelist = document.getElementsByTagName("LI");
var i;
for (i = 0; i < myNodelist.length; i++) {
    var span = document.createElement("SPAN");
    var txt = document.createTextNode("\u00D7");
    span.className = "close";
    span.appendChild(txt);
    myNodelist[i].appendChild(span);
}

// Click on a close button to hide the current list item
var close = document.getElementsByClassName("close");
var i;
for (i = 0; i < close.length; i++) {
    close[i].onclick = function () {
        var div = this.parentElement;
        div.style.display = "none";
    }
}

// Add a "checked" symbol when clicking on a list item
var list = document.querySelector('ul');
if (list) {
    list.addEventListener('click', function (ev) {
        if (ev.target.tagName === 'LI') {
            ev.target.classList.toggle('checked');
        }
    }, false);
}

// Create a new list item when clicking on the "Add" button
function newElement() {
    var li = document.createElement("li");
    var inputValue = document.getElementById("input_title").value;
    var t = document.createTextNode(inputValue);
    li.appendChild(t);
    if (inputValue === '') {
        alert("You must write something!");
    } else {
        document.getElementById("ul_todos").appendChild(li);
    }
    document.getElementById("input_title").value = "";

    var span = document.createElement("SPAN");
    var txt = document.createTextNode("\u00D7");
    span.className = "close";
    span.appendChild(txt);
    li.appendChild(span);

    for (i = 0; i < close.length; i++) {
        close[i].onclick = function () {
            var div = this.parentElement;
            div.style.display = "none";
        }
    }
}
