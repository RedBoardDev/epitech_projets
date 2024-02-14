/*
** EPITECH PROJECT, 2021
** epytodo
** File description:
** date.js
*/

function get_today_date_str() {
    var today = new Date();
    var dd = String(today.getDate()).padStart(2, '0');
    var mm = String(today.getMonth() + 1).padStart(2, '0');
    var yyyy = today.getFullYear();

    today = yyyy + '-' + mm + '-' + dd;
    return today;
}

module.exports = function(app) {
    app.get("/date", (req, res) => {
        res.send(get_today_date_str());
    });
}
