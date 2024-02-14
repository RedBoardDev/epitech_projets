const jwt = require('jsonwebtoken');
const fs = require('fs');
const path = require('path');

const express = require('express');
const router = express.Router();
require('dotenv').config();

const JWT_SECRET_KEY = process.env.JWT_SECRET_KEY;

function readEmployees() {
    try {
        const data = fs.readFileSync('data/employees.json', 'utf8');
        return JSON.parse(data);
    } catch (error) {
        console.error('Error while reading employees data:', error);
        return [];
    }
}

function writeEmployees(employees) {
    fs.writeFileSync('./data/employees.json', JSON.stringify(employees, null, 2), 'utf8');
}

function addEmployee(employee) {
    const employees = readEmployees();
    employees.push(employee);
    writeEmployees(employees);
}

function updateEmployee(employeeId, updatedData) {
    const employees = readEmployees();
    const index = employees.findIndex(emp => emp.id === employeeId);

    if (index !== -1) {
        for (const key in updatedData) {
            employees[index][key] = updatedData[key];
        }
        writeEmployees(employees);
        return employees[index];
    }
    return null;
}

function getAllEmployees() {
    return readEmployees();
}

function getEmployeeById(employeeId) {
    const employees = readEmployees();
    return employees.find(emp => emp.id === employeeId);
}

function getEmployeeByEmail(employeeEmail) {
    const employees = readEmployees();
    return employees.find(emp => emp.email === employeeEmail);
}

// endpoints

function authenticateJWT(req, res, next) {
    const bearerHeader = req.headers['authorization'];
    if (typeof (bearerHeader) !== 'undefined') {
        const bearer = bearerHeader.split(' ');
        const bearerToken = bearer[1];
        req.token = bearerToken;

        try {
            const decoded = jwt.verify(req.token, JWT_SECRET_KEY);
            req.user = decoded;
            next();
        } catch (err) {
            return res.status(401).json({ detail: 'Invalid or expired token.' });
        }
    } else {
        return res.status(401).json({ detail: 'Authorization token is missing.' });
    }
}

router.get('/employees', authenticateJWT, async (req, res) => {
    const employees = getAllEmployees();

    const actualTime = new Date();
    employees.forEach(employee => {
        employee.status = employee.status !== 0 ? ((60000 * 2) < (actualTime - new Date(employee.status)) ? 0 : 1) : 0;
    });
    res.json(employees);
});

router.post('/employees/login', async (req, res) => {
    const { email, password } = req.body;

    const employee = getEmployeeByEmail(email);

    if (!employee || password !== 'password') {
        return res.status(401).json({ detail: 'Invalid Email and Password combination.' });
    }

    const token = jwt.sign({ id: employee.id, email: employee.email }, JWT_SECRET_KEY, {
        expiresIn: '672h',
    });
    res.status(200).json({ access_token: token });
});

router.get('/employees/me', authenticateJWT, async (req, res) => {
    const { id } = req.user;

    const employee = getEmployeeById(id);

    if (!employee) {
        return res.status(404).json({ detail: 'Employee not found.' });
    }

    const actualTime = new Date();
    const employeeResponse = {
        id: employee.id,
        email: employee.email,
        name: employee.name,
        surname: employee.surname,
        birth_date: employee.birth_date,
        gender: employee.gender,
        work: employee.work,
        subordinates: employee.subordinates,
        status : employee.status !== 0 ? ((60000 * 2) < (actualTime - new Date(employee.status)) ? 0 : 1) : 0,
    };

    res.status(200).json(employeeResponse);
});

router.get('/employees/leaders', authenticateJWT, async (req, res) => {
    const allEmployees = getAllEmployees();
    const leaders = allEmployees.filter(employee => employee.work === 'CEO');

    res.status(200).json(leaders);
});

router.get('/employees/:employee_id', authenticateJWT, async (req, res) => {
    const employeeId = parseInt(req.params.employee_id);

    const employee = getEmployeeById(employeeId);

    if (!employee) {
        return res.status(404).json({ detail: 'Employee requested doesn\'t exist.' });
    }

    const actualTime = new Date();
    const simplifiedEmployee = {
        id: employee.id,
        email: employee.email,
        name: employee.name,
        surname: employee.surname,
        birth_date: employee.birth_date,
        gender: employee.gender,
        work: employee.work,
        subordinates: employee.subordinates,
        status : employee.status !== 0 ? ((60000 * 2) < (actualTime - new Date(employee.status)) ? 0 : 1) : 0,
    };

    res.status(200).json(simplifiedEmployee);
});

router.get('/employees/:employee_id/image', async (req, res) => {
    const employeeId = parseInt(req.params.employee_id);

    const employee = getEmployeeById(employeeId);

    if (!employee) {
        return res.status(404).json({ detail: "Employee requested doesn't exist" });
    }
    const imagePath = path.join(__dirname, `../../data/images/${employee.id}.png`);
    res.sendFile(imagePath);
});

router.post('/employees/status/:employee_id/:status', authenticateJWT, async (req, res) => {
    const employeeId = parseInt(req.params.employee_id);

    let employee = getEmployeeById(employeeId);
    const status = parseInt(req.params.status);

    if (!employee) {
        return res.status(404).json({ detail: "Employee requested doesn't exist" });
    }

    employee.status = status !== 0 ? new Date() : 0;
    updateEmployee(employeeId, employee);

    res.status(200).json('Status changed')
})

router.get('/', async (req, res) => {
    res.status(200).json('trombinoscope endpoint');
});

module.exports = router;
