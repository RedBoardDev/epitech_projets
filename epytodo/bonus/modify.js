window.onfocus = w_on_focus();

addEventListener('keypress', function (e) {
    if (e.key === 'Enter') {
        modify_todo();
    }
});

function set_inputs(res) {
    document.getElementById("input_title").value = res.title;
    document.getElementById("input_description").value = res.description;
    document.getElementById("input_date").value = res.due_time.split('T')[0];
    document.getElementById("input_time").value = res.due_time.split('T')[1].split('Z')[0];
    document.getElementById("input_status").value = res.status;
}

function w_on_focus() {
    var xhr = new XMLHttpRequest();
    const token = sessionStorage.getItem("token");

    xhr.open("GET", "http://127.0.0.1:3000/user");
    xhr.setRequestHeader('Content-Type', 'application/json; charset=UTF-8=');
    xhr.setRequestHeader("Authorization", "Bearer " + token);
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4) {
            if (xhr.status == 403) {
                alert("Please reconnect");
                window.location.href = "login.html";
            } else if (xhr.status != 200) {
                alert("An error occured");
            }
        }
    }
    xhr.send();

    const id_todo = sessionStorage.getItem("to_modify");
    var xhr2 = new XMLHttpRequest();

    xhr2.open("GET", "http://127.0.0.1:3000/todos/" + id_todo);
    xhr2.setRequestHeader('Content-Type', 'application/json; charset=UTF-8=');
    xhr2.setRequestHeader("Authorization", "Bearer " + token);
    xhr2.onreadystatechange = function() {
        if (xhr2.readyState == 4) {
            if (xhr2.status == 200 || xhr2.status == 201) {
                const res = JSON.parse(xhr2.response);
                console.log(res);
                set_inputs(res);
            } else if (xhr2.status == 403) {
                alert("Please reconnect");
                window.location.href = "login.html";
            } else {
                alert("An error occured");
            }
        }
    }
    xhr2.send();
}

function modify_todo() {
    const id_todo = sessionStorage.getItem("to_modify");
    const token = sessionStorage.getItem("token");
    var xhr = new XMLHttpRequest();

    xhr.open("PUT", "http://127.0.0.1:3000/todos/" + id_todo);
    xhr.setRequestHeader('Content-Type', 'application/json; charset=UTF-8=');
    xhr.setRequestHeader("Authorization", "Bearer " + token);
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4) {
            if (xhr.status == 200 || xhr.status == 201) {
                sessionStorage.setItem("to_modify", "");
                window.location.href = "home.html";
            } else if (xhr.status == 403) {
                alert("Please reconnect");
                window.location.href = "login.html";
            } else {
                alert("An error occured");
            }
        }
    }
    var date = document.getElementById("input_date").value + " " + document.getElementById("input_time").value;
    xhr.send(JSON.stringify({
        "title": document.getElementById("input_title").value,
        "description": document.getElementById("input_description").value,
        "due_time": date,
        "status": document.getElementById("input_status").value
    }));
}
