import mysql from "mysql2";
import dotenv from "dotenv";

dotenv.config();

class DbManager {
    constructor() {
        this.con = mysql.createConnection({
            host: process.env.MYSQL_HOST,
            user: process.env.MYSQL_USER_OTHER,
            password: process.env.MYSQL_PASSWORD,
            database: process.env.MYSQL_DATABASE,
        });

        this.con.connect((err) => {
            if (err) throw new Error(`Failed to connect to database ${process.env.MYSQL_DATABASE}`);
            console.log('Successfully connected to the database ' + process.env.MYSQL_DATABASE);
        });
    }

    destructor() {
        this.closeConnection();
    }

    closeConnection() {
        this.con.end();
        console.log('Disconnecting from the MySQL database');
    }

    executeQuery(query, values) {
        return new Promise((resolve, reject) => {
            this.con.query(query, values, (err, rows) => {
                if (err) {
                    reject(err);
                } else {
                    resolve(rows);
                }
            });
        });
    }

    getAllUsers(withPassword = false) {
        const query = `SELECT ${withPassword ? '*' : 'id, email, lastname, firstname, profile_img, created_at'} FROM user;`;
        const values = [];
        return this.executeQuery(query, values);
    }

    getUserById(id, withPassword = false) {
        const query = `SELECT ${withPassword ? '*' : 'id, email, lastname, firstname, profile_img, created_at'} FROM user WHERE id = ?;`;
        const values = [id];
        return this.executeQuery(query, values);
    }

    getUserByEmail(email, withPassword = false) {
        const query = `SELECT ${withPassword ? '*' : 'id, email, lastname, firstname, profile_img, created_at'} FROM user WHERE email = ?;`;
        const values = [email];
        return this.executeQuery(query, values);
    }

    getUserByEmailOrId(str, withPassword = false) {
        const query = `SELECT ${withPassword ? '*' : 'id, email, lastname, firstname, profile_img, created_at'} FROM user WHERE id = ? OR email = ?;`;
        const values = [str, str];
        return this.executeQuery(query, values);
    }

    insertUser(email, passwordHash, lastname, firstname, authType) {
        const query = 'INSERT INTO user(email, password, lastname, firstname, auth_type) VALUES (?, ?, ?, ?, ?)';
        const values = [email, passwordHash ?? null, lastname, firstname, authType];
        return this.executeQuery(query, values);
    }

    updateUser(id, lastname, firstname) {
        const query = `UPDATE user SET lastname = ?, firstname = ? WHERE id = ?;`;
        const values = [lastname, firstname, id];
        return this.executeQuery(query, values);
    }

    deleteUser(id) {
        const query = `DELETE FROM user WHERE id = ?;`;
        const values = [id];
        return this.executeQuery(query, values);
    }

    getAutomations(userId) {
        const query = `SELECT * FROM automation WHERE user_id = ?;`;
        const values = [userId];
        return this.executeQuery(query, values);
    }

    insertAutomation(userId, triggerServiceId, triggerId, triggerParams, reactionServiceId, reactionId, reactionParams) {
        const query = `INSERT INTO automation(user_id, trigger_service_id, trigger_id, trigger_params, reaction_service_id, reaction_id, reaction_params) VALUES (?, ?, ?, ?, ?, ?, ?);`;
        const values = [userId, triggerServiceId, triggerId, triggerParams, reactionServiceId, reactionId, reactionParams];
        return this.executeQuery(query, values);
    }

    updateAutomation(userId, automationId, updateQueryString) {
        const query = `UPDATE automation SET ${updateQueryString} WHERE user_id = ? AND id = ?;`;
        const values = [userId, automationId];
        return this.executeQuery(query, values);
    }

    deleteAutomation(userId, automationId) {
        const query = `DELETE FROM automation WHERE user_id = ? AND id = ?;`;
        const values = [userId, automationId];
        return this.executeQuery(query, values);
    }

    getServiceOauth(userId, serviceId) {
        const query = `SELECT * FROM service_oauth WHERE user_id = ? AND service_id = ?;`;
        const values = [userId, serviceId];
        return this.executeQuery(query, values);
    }

    insertServiceOauth(userId, serviceId, token) {
        const query = `INSERT INTO service_oauth(user_id, service_id, token) VALUES (?, ?, ?);`;
        const values = [userId, serviceId, token];
        return this.executeQuery(query, values);
    }

    updateServiceOauth(userId, serviceId, token) {
        const query = `UPDATE service_oauth SET token = ? WHERE user_id = ? AND service_id = ?;`;
        const values = [token, userId, serviceId];
        return this.executeQuery(query, values);
    }

    deleteServiceOauth(userId, serviceId) {
        const query = `DELETE FROM service_oauth WHERE user_id = ? AND service_id = ?;`;
        const values = [userId, serviceId];
        return this.executeQuery(query, values);
    }
}

export default DbManager;
