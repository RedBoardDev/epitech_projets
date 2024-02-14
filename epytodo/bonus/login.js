addEventListener('keypress', function (e) {
    if (e.key === 'Enter') {
        login_get_token();
    }
});

function login_get_token() {
    var xhr = new XMLHttpRequest();
    const email = document.getElementById('input_email').value;
    const password = document.getElementById('input_pass').value;

    xhr.open("POST", "http://127.0.0.1:3000/login");
    xhr.setRequestHeader('Content-Type', 'application/json; charset=UTF-8=');
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4) {
            if (xhr.status == 200 || xhr.status == 201) {
                const res = JSON.parse(xhr.response);
                sessionStorage.setItem("token", res.token);
                window.location.href = "home.html";
            } else {
                alert("Wrong email or password, try again");
            }
        }
    }
    xhr.send(JSON.stringify({
        "email": email,
        "password": password
    }));
}
