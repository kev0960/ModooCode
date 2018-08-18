const express = require('express');
const app = express();

app.listen(80, () => console.log('The server has started.'));

app.get('/', (res, res) => res.send('Hello World!'));