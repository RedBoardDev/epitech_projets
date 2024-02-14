function add_new_todo() {
    var xhr = new XMLHttpRequest();
    const token = sessionStorage.getItem("token");

    xhr.open("POST", "http://127.0.0.1:3000/todos");
    xhr.setRequestHeader('Content-Type', 'application/json; charset=UTF-8=');
    xhr.setRequestHeader("Authorization", "Bearer " + token);
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4) {
            if (xhr.status == 200 || xhr.status == 201) {
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
