const express = require('express');
const app = express();

app.listen(3000, () => console.log('The server has started.'));

app.get('/', (req, res) => res.send('Hello World!'));
