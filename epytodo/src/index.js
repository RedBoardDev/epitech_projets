/*
** EPITECH PROJECT, 2021
** epytodo
** File description:
** index.js
*/

const express = require('express');
var glob = require('./config/global');

/*          app config              */
glob.app.use(glob.bodyParser.urlencoded({ extended: false }));
glob.app.use(glob.bodyParser.json());

glob.con.connect(function(err) {
    if (err) res.status(500).json({ msg: "Internal server error" });
    console.log("Connecté à la base de données " + glob.myenv.MYSQL_DATABASE);
});

/*          routes                */
glob.app.get("/", (req, res) => {
    res.send("Epytodo");
});

require('./routes/tests/date.js')(glob.app);
require('./routes/tests/names.js')(glob.app);
require('./routes/tests/get.js')(glob.app, glob.con);
require('./routes/tests/post.js')(glob.app, glob.con);

require('./routes/auth/register.js')(glob.app, glob.con);
require('./routes/auth/login.js')(glob.app, glob.con);

require('./routes/user/user.js')(glob.app, glob.con);
require('./routes/user/user_id.js')(glob.app, glob.con);

require('./routes/todos/todos_id.js')(glob.app, glob.con);
require('./routes/todos/todos.js')(glob.app, glob.con);

glob.app.use(express.json());
glob.app.use(express.static('bonus'));

glob.app.listen(glob.port, () => {
    console.log(`App listening at http://localhost:${glob.port}`);
});
